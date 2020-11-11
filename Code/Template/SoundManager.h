#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <map>

class SoundManager {
private:
	struct WaveHeaderType {
		char chunkId[4];
		unsigned long chunkSize;
		char format[4];
		char subChunkId[4];
		unsigned long subChunkSize;
		unsigned short audioFormat;
		unsigned short numChannels;
		unsigned long sampleRate;
		unsigned long bytePerSecond;
		unsigned short blockAlign;
		unsigned short bitsPerSample;
		char dataChunkId[4];
		unsigned long dataSize;
	};
	IDirectSound8* directSound = nullptr;
	IDirectSoundBuffer* primaryBuffer = nullptr;
	std::map<const char*, IDirectSoundBuffer*> soundMap;

public:
	SoundManager();
	~SoundManager();

	bool Initialize(HWND hWnd);
	void Shutdown();

	bool InitializeDirectSound(HWND hWnd);
	void ShutdownDirectSound();

	bool LoadWaveFile(const char* path, const char* soundName);
	void ShutdownWaveFile(const char* soundName);

	bool PlayWaveFile(const char * soundName);
};