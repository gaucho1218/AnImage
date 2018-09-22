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



#endif