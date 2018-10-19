#ifndef _AI_GIF_PARSER_H__
#define _AI_GIF_PARSER_H__

#include <stdint.h>

using namespace std;

#define AIGIFPARSER_STATE_NONE		0x00000000
#define AIGIFPARSER_STATE_HDR		0x00000001
#define AIGIFPARSER_STATE_LSCRDESC	0x00000002
#define AIGIFPARSER_STATE_GCT		0x00000004
#define AIGIFPARSER_STATE_IMGDESC	0x00000008
#define AIGIFPARSER_STATE_LCT		0x00000010

struct SAiGifGlobal;

class CAiGifParser
{
public:
	CAiGifParser(void);
	virtual ~CAiGifParser(void);

	virtual int ParseGifData(char *pBuf, const int nSize, const int nOffset, int &nSkip);

protected:
	virtual int ParseHeader(char *pBuf, const int nSize, const int nOffset);
	//! skip size means GCT
	virtual int ParseLogicalScreenDesc(char *pBuf, const int nSize, const int nOffset, int &nSkip);

	uint16_t	m_uLogicalWidth;
	uint16_t	m_uLogicalHeight;

	int32_t		m_nParserState;

	SAiGifGlobal	*m_pGifGlobal;
};

#endif