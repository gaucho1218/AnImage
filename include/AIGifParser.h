#ifndef _AI_GIF_PARSER_H__
#define _AI_GIF_PARSER_H__

#include <stdint.h>

using namespace std;

class CAiGifParser
{
public:
	CAiGifParser(void);
	virtual ~CAiGifParser(void);

	virtual int ParseGifData(char *pBuf, const int nSize, const int nOffset);

protected:
	bool		m_bGifVarified;
	uint16_t	m_uLogicalWidth;
	uint16_t	m_uLogicalHeight;
};

#endif