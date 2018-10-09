#include "AIGifParser.h"

#include <iostream>
#include <cstring>
#include "AIGifHdr.h"

CAiGifParser::CAiGifParser(void)
	: m_uLogicalWidth(0), m_uLogicalHeight(0),
	m_nParserState(AIGIFPARSER_STATE_NONE)
{
}

CAiGifParser::~CAiGifParser(void)
{
}

int CAiGifParser::ParseGifData(char *pBuf, const int nSize, const int nOffset)
{
	if (pBuf == nullptr || nSize <= 0 || nOffset < 0)
		return -1;

	int nRet = 0;

	if ((m_nParserState & AIGIFPARSER_STATE_HDR) != AIGIFPARSER_STATE_HDR)
		nRet = ParseHeader(pBuf, nSize, nOffset);
	else if ((m_nParserState & AIGIFPARSER_STATE_LSCRDESC) != AIGIFPARSER_STATE_LSCRDESC)
		nRet = ParseLogicalScreenDesc(pBuf, nSize, nOffset);

	return nRet;
}

int CAiGifParser::ParseHeader(char *pBuf, const int nSize, const int nOffset)
{
	int nRet = 0;

	if (memcmp(pBuf, strGif, 3) == 0)
	{
		pBuf += 3;
		nRet = 6;
		m_nParserState |= AIGIFPARSER_STATE_HDR;

		if (memcmp(pBuf, str87a, 3) == 0)
			cout << str87a << endl;
		else if (memcmp(pBuf, str89a, 3) == 0)
			cout << str89a << endl;
		else
		{
			cout << "Unknown GIF Version: ";
			m_nParserState = AIGIFPARSER_STATE_NONE;
			cout.write(pBuf, 3) << endl;
			nRet = -1;
		}
	}

	return nRet;
}

int CAiGifParser::ParseLogicalScreenDesc(char *pBuf, const int nSize, const int nOffset)
{
	int nRet = 0;

	SAiGifGlobal *pDesc;
	if (nSize >= sizeof(SAiGifGlobal))
	{
		//! @todo copy
		pDesc = (SAiGifGlobal *)pBuf;
	}

	return nRet;
}