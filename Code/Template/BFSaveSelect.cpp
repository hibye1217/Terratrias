#include "stdafx.h"
#include "BFSaveSelect.h"

BFSaveSelect::BFSaveSelect(int n)
{
	name = "save" + std::to_string(n);
	name += ".txt";
	filename = name.c_str();
}

BFSaveSelect::~BFSaveSelect()
{
}

void BFSaveSelect::Do()
{
	appendFileToWorkWith.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
	// 해당 이름의 세이브파일이 존재하는지 확인
	if (!appendFileToWorkWith) {
		appendFileToWorkWith.open(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
		appendFileToWorkWith << "\n";
		appendFileToWorkWith.close();
		save[0][0] = 0;
	}
	// 없으면 만들면 됨

	int n;
	
	appendFileToWorkWith.close();

	FILE* in = fopen(filename, "r");
	fscanf(in, "%d", &n);
	save[0][0] = n;

	for (int i = 0; i < n; i++) {
		fscanf(in, "%d %d", &save[i][0], &save[i][1]);
	}

	// 있으면 불러오면 됨
	savefile = name;
}
