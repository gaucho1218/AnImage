#include "AIGifParser.h"

#include <iostream>
#include <cstring>
#include "DebugPrint.h"
#include "AIGifHdr.h"

CAiGifParser::CAiGifParser(void)
	: m_uLogicalWidth(0), m_uLogicalHeight(0),
	m_nParserState(AIGIFPARSER_STATE_NONE), m_pGifGlobal(nullptr)
{
	m_pGifGlobal = (SAiGifGlobal *)malloc(sizeof(SAiGifGlobal));
}

CAiGifParser::~CAiGifParser(void)
{
	if (m_pGifGlobal != nullptr)
	{
		free(m_pGifGlobal);
		m_pGifGlobal = nullptr;
	}
}

int CAiGifParser::ParseGifData(char *pBuf, const int nSize, const int nOffset, int &nSkip)
{
	if (pBuf == nullptr || nSize <= 0 || nOffset < 0)
		return -1;

	int nRet = 0;

	if ((m_nParserState & AIGIFPARSER_STATE_HDR) != AIGIFPARSER_STATE_HDR)
		nRet = ParseHeader(pBuf, nSize, nOffset);
	else if ((m_nParserState & AIGIFPARSER_STATE_LSCRDESC) != AIGIFPARSER_STATE_LSCRDESC)
		nRet = ParseLogicalScreenDesc(pBuf, nSize, nOffset, nSkip);

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

int CAiGifParser::ParseLogicalScreenDesc(char *pBuf, const int nSize, const int nOffset, int &nSkip)
{
	int nRet = 0;

	if (nSize >= sizeof(SAiGifGlobal) && m_pGifGlobal != nullptr)
	{
		memcpy(m_pGifGlobal, pBuf, sizeof(SAiGifGlobal));

		AIDebugPrint("Width: %u, Height: %u\n", m_pGifGlobal->uLogicalScreenWidth, m_pGifGlobal->uLogicalScreenHeight);
		AIDebugPrint("GCT Flag: %d\n", m_pGifGlobal->nGCTFlag);
		AIDebugPrint("Color Resolution: %d\n", m_pGifGlobal->nColorResolution);
		AIDebugPrint("Sort Flag: %d\n", m_pGifGlobal->nSortFlag);
		AIDebugPrint("Size of GCT: %d\n", m_pGifGlobal->nSizeOfGct);
		AIDebugPrint("Background Index: %d\n", m_pGifGlobal->nBackgroundColorIndex);
		AIDebugPrint("Pixel Aspect Ratio: %d\n", m_pGifGlobal->nPixelAspectRatio);

		if (m_pGifGlobal->nGCTFlag == 1)
			nSkip = (3 * (2 << m_pGifGlobal->nSizeOfGct));
	}

	return nRet;
}