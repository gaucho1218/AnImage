//! test app for AnImage



#include <stdio.h>
#include <cstring>
#include "AIGifParser.h"

#define BUFSIZE	4*1024

int main(int argc, const char * argv[])
{
	printf("testing!\n");

	char arrBuf[BUFSIZE];

	FILE *pFile = nullptr;
	fopen_s(&pFile, "../../Resource/1.Honeycam.gif", "rb");

	int nOffset = 0;
	int nReadSize = 0;
	int nUsed = 0;
	CAiGifParser tParser;

	if (pFile != nullptr)
	{
		while ((nReadSize = fread(arrBuf + nUsed, 1, BUFSIZE - nUsed, pFile)) != 0)
		{
			nReadSize += nUsed;
			nUsed = 0;

			int nRet = 0;

			nRet = tParser.ParseGifData(arrBuf, nReadSize, nOffset);
			if (nRet > 0)
			{
				nOffset += nRet;
				nUsed += nRet;
			}

			memmove(arrBuf, arrBuf + nUsed, BUFSIZ - nUsed);
		}


		fclose(pFile);
		pFile = nullptr;
	}

	return 0;
}