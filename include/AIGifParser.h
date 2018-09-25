#ifndef _AI_GIF_PARSER_H__
#define _AI_GIF_PARSER_H__

#include <tuple>
#include "AIDll.h"

using namespace std;

enum EGifInfo
{
	EGI_HDR = 0,
	EGI_OFFSET,
	EGO_SIZE
};

using TGifInfo = tuple<EGifInfo, int, short>;

//! parse gif data and return its attributes, offset, size
//! check TGifInfo size part if header type has additional size
AIDLL TGifInfo ParseGifData(const char *pBuf, const int nSize, const int nOffset) noexcept;

#endif