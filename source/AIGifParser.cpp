#include "AIGifParser.h"

#include <iostream>
#include <cstring>
#include "AIGifHdr.h"

CAiGifParser::CAiGifParser(void)
	: m_bGifVarified(false), m_uLogicalWidth(0), m_uLogicalHeight(0)
{
}

CAiGifParser::~CAiGifParser(void)
{
}

int CAiGifParser::ParseGifData(char *pBuf, const int nSize, const int nOffset)
{
	int nRet = 0;

	if (m_bGifVarified == false)
	{
		//! check GIF Signature and Version
		if (memcmp(pBuf, strGif, 3) == 0)
		{
			pBuf += 3;
			if (memcmp(pBuf, str87a, 3) == 0)
				cout << str87a << endl;
			else if (memcmp(pBuf, str89a, 3) == 0)
				cout << str89a << endl;
			else
			{
				cout << "Unknown GIF Version: ";
				cout.write(pBuf, 3) << endl;
				nRet = -1;
			}
		}
	}
	else
	{

	}

	return nRet;
}