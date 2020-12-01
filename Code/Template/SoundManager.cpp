#include "stdafx.h"
#include "SoundManager.h"

SoundManager::SoundManager() {
	Initialize(hWnd);
}

SoundManager::~SoundManager() {
	Shutdown();
}

bool SoundManager::Initialize(HWND hWnd) {
	if (!InitializeDirectSound(hWnd)) {
		return false;
	}
	return true;
}

void SoundManager::Shutdown() {
	ShutdownDirectSound();
}

bool SoundManager::InitializeDirectSound(HWND hWnd) {
	if (FAILED(DirectSoundCreate8(NULL, &directSound, NULL))) {
		return false;
	}

	// Set the cooperative level to priority so the format of the primary sound buffer can be modified.
	if (FAILED(directSound->SetCooperativeLevel(hWnd, DSSCL_PRIORITY))) {
		return false;
	}

	// Setup the primary buffer description.
	DSBUFFERDESC bufferDesc;
	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes = 0;
	bufferDesc.dwReserved = 0;
	bufferDesc.lpwfxFormat = NULL;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	// Get control of the primary sound buffer on the default sound device.
	if (FAILED(directSound->CreateSoundBuffer(&bufferDesc, &primaryBuffer, NULL))) {
		return false;
	}

	// Setup the format of the primary sound bufffer.
	// In this case it is a .WAV file recorded at 44,100 samples per second in 16-bit stereo (cd audio format).
	WAVEFORMATEX waveFormat;
	waveFormat.wFormatTag = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec = 44100;
	waveFormat.wBitsPerSample = 16;
	waveFormat.nChannels = 2;
	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize = 0;

	// Set the primary buffer to be the wave format specified.
	if (FAILED(primaryBuffer->SetFormat(&waveFormat))) {
		return false;
	}

	return true;
}

void SoundManager::ShutdownDirectSound() {
	if (primaryBuffer) {
		SAFE_RELEASE(primaryBuffer);
	}

	if (directSound) {
		SAFE_RELEASE(directSound);
	}
}

bool SoundManager::LoadWaveFile(const char* path, const char* soundName) {
	FILE* filePtr = nullptr;
	int error = fopen_s(&filePtr, path, "rb");
	if (error != 0) {
		return false;
	}

	// Read in the wave file header.
	WaveHeaderType waveFileHeader;
	unsigned int count = fread(&waveFileHeader, sizeof(waveFileHeader), 1, filePtr);
	if (count != 1) {
		return false;
	}
	printf("1");
	// Check that the chunk ID is the RIFF format.
	if ((waveFileHeader.chunkId[0] != 'R') || (waveFileHeader.chunkId[1] != 'I') ||
		(waveFileHeader.chunkId[2] != 'F') || (waveFileHeader.chunkId[3] != 'F')) {
		return false;
	}
	printf("2");
	// Check that the file format is the WAVE format.
	if ((waveFileHeader.format[0] != 'W') || (waveFileHeader.format[1] != 'A') ||
		(waveFileHeader.format[2] != 'V') || (waveFileHeader.format[3] != 'E')) {
		return false;
	}
	printf("3");
	// Check that the sub chunk ID is the fmt format.
	if ((waveFileHeader.subChunkId[0] != 'f') || (waveFileHeader.subChunkId[1] != 'm') ||
		(waveFileHeader.subChunkId[2] != 't') || (waveFileHeader.subChunkId[3] != ' ')) {
		return false;
	}
	printf("4");
	// Set the wave format of secondary buffer that this wave file will be loaded onto.
	WAVEFORMATEX waveFormat;
	waveFormat.wFormatTag = waveFileHeader.audioFormat;
	waveFormat.nSamplesPerSec = waveFileHeader.sampleRate;
	waveFormat.wBitsPerSample = waveFileHeader.bitsPerSample;
	waveFormat.nChannels = waveFileHeader.numChannels;
	waveFormat.nBlockAlign = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize = 0;
	printf("5");
	// Set the buffer description of the secondary sound buffer that the wave file will be loaded onto.
	DSBUFFERDESC bufferDesc;
	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes = waveFileHeader.dataSize;
	bufferDesc.dwReserved = 0;
	bufferDesc.lpwfxFormat = &waveFormat;
	bufferDesc.guid3DAlgorithm = GUID_NULL;
	printf("6");
	// Create a temporary sound buffer with the specific buffer settings.
	IDirectSoundBuffer* tempBuffer = nullptr;
	if (FAILED(directSound->CreateSoundBuffer(&bufferDesc, &tempBuffer, NULL))) {
		return false;
	}
	printf("7");
	IDirectSoundBuffer8* tmpBuffer = nullptr;
	// Test the buffer format against the direct sound 8 interface and create the secondary buffer.
	if (FAILED(tempBuffer->QueryInterface(IID_IDirectSoundBuffer8, (void**)&*&tmpBuffer))) {
		return false;
	}
	printf("8");
	soundMap[soundName] = tmpBuffer;
	// Release the temporary buffer.
	tempBuffer->Release();
	tempBuffer = 0;
	printf("9");
	// Move to the beginning of the wave data which starts at the end of the data chunk header.
	fseek(filePtr, sizeof(WaveHeaderType), SEEK_SET);

	// Create a temporary buffer to hold the wave file data.
	unsigned char* waveData = new unsigned char[waveFileHeader.dataSize];
	if (!waveData) {
		return false;
	}
	printf("a");
	// Read in the wave file data into the newly created buffer.
	count = fread(waveData, 1, waveFileHeader.dataSize, filePtr);
	if (count != waveFileHeader.dataSize) {
		return false;
	}
	printf("b");
	// Close the file once done reading.
	error = fclose(filePtr);
	if (error != 0) {
		return false;
	}
	printf("c");
	// Lock the secondary buffer to write wave data into it.
	unsigned char* bufferPtr = nullptr;
	unsigned long bufferSize = 0;
	if (FAILED(soundMap[soundName]->Lock(0, waveFileHeader.dataSize, (void**)&bufferPtr, (DWORD*)&bufferSize, NULL, 0, 0))) {
		return false;
	}
	printf("d");
	// Copy the wave data into the buffer.
	memcpy(bufferPtr, waveData, waveFileHeader.dataSize);
	printf("e");
	// Unlock the secondary buffer after the data has been written to it.
	if (FAILED(soundMap[soundName]->Unlock((void*)bufferPtr, bufferSize, NULL, 0))) {
		return false;
	}
	printf("f");
	SAFE_DELETE_ARRAY(waveData);
	return true;
}

void SoundManager::ShutdownWaveFile(const char* soundName) {
	if (soundMap[soundName]) {
		soundMap[soundName]->Stop();
	}
}

bool SoundManager::PlayWaveFile(const char * soundName) {
	if (FAILED(soundMap[soundName]->SetCurrentPosition(0))) {
		return false;
	}

	if (FAILED(soundMap[soundName]->SetVolume(DSBVOLUME_MAX))) {
		return false;
	}

	if (FAILED(soundMap[soundName]->Play(0, 0, 0))) {
		return false;
	}
	return true;
}