//! test app for AnImage



#include <stdio.h>
#include "AIGifParser.h"

int main(int argc, const char * argv[])
{
	printf("testing!\n");

	char arrBuf[4096];

	FILE *pFile = nullptr;
	fopen_s(&pFile, "../../Resource/1.Honeycam.gif", "rb");

	if (pFile != nullptr)
	{
		int nReadSize = fread(arrBuf, 1, 4096, pFile);

		CAiGifParser tParser;
		tParser.ParseGifData(arrBuf, nReadSize, 0);


		fclose(pFile);
		pFile = nullptr;
	}

	return 0;
}