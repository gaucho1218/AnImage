#ifndef _AI_GIF_HDR_H__
#define _AI_GIF_HDR_H__

#include "AIDll.h"

#include <stdint.h>

#pragma pack(push, 1)

const char *strGif = "GIF";
const char *str87a = "87a";
const char *str89a = "89a";

#define AIGIF_IMG_SEPERATOR		0x2C
#define AIGIF_EXTENSION			0x21
#define AIGIF_GRAPHIC_CONTROL	0xF9
#define AIGIF_COMMENT			0xFE
#define AIGIF_PLAIN_TEXT		0x01
#define AIGIF_APP_EXTENSION		0xFF
#define AIGIF_BLOCK_TERM		0x00

typedef struct SAiGifHdr
{
	char	arrGif[3];		//! GIF
	char	arrVer[3];		//! 87a or 89a
} SAiGifHdr;

typedef struct SAiGifGlobal
{
	uint16_t	uLogicalScreenWidth;
	uint16_t	uLogicalScreenHeight;
	
	//! Packed Field
	int8_t		nGCTFlag : 1;	//! Exist of Global Color Table
	int8_t		nColorResolution : 3;
	int8_t		nSortFlag : 1;
	int8_t		nSizeOfGct : 3;	//! Size of Global Color Table

	int8_t		nBackgroundColorIndex;
	int8_t		nPixelAspectRatio;
} SAiGifGlobal;

typedef struct SAiGifImgDesc
{
	int8_t		nImageSperator;	//! 0x2C
	uint16_t	uImgLeftPosition;
	uint16_t	uImgTopPosition;
	uint16_t	uImgWidth;
	uint16_t	uImgHeight;

	//! Packed Field
	int8_t		nLCTFlag : 1;	//! Exist of Local Color Table
	int8_t		nInterlaceFlag : 1;
	int8_t		nSortFlag : 1;
	int8_t		nReserved : 2;
	int8_t		nSizeOfLct : 3;	//! Size of Local Color Table
} SAiGifImgDesc;

//! Extension Graphic Control
typedef struct SAiGifExtGC
{
	int8_t		nExtIntro;
	int8_t		nGCLable;	//! Graphic Control
	int8_t		nBlockSize;

	//! packed field
	int8_t		nReserved : 3;
	int8_t		nDisposalMethod : 3;
	int8_t		nUserInputFlag : 1;
	int8_t		nTransparentFlag : 1;

	uint16_t	uDelayTime;
	int8_t		nTransparentColorIndex;

	//! data
} SAiGifExtGC;

//! Extension Comment
typedef struct SAiGifExtComment
{
	int8_t		nExtIntro;
	int8_t		nCommentLable;
	//! data
} SAiGifExtComment;

typedef struct SAiGifExtText
{
	int8_t		nExtIntro;
	int8_t		nTextLabel;
	int8_t		nBlockSize;
	int8_t		nTextLeftPos;
	int8_t		nTextTopPos;
	int8_t		nTextWidth;
	int8_t		nTextHeight;
	int8_t		nCharCellWidth;
	int8_t		nCharCellHeight;
	int8_t		nForegroundColorIndex;
	int8_t		nBackgroundColorIndex;
	
	//! text data
} SAiGifExtPlainText;

typedef struct SAiGifExtApp
{
	int8_t		nExtIntro;
	int8_t		nAppLabel;
	int8_t		nBlockSize;
	int64_t		nAppIdentifier;
	int8_t		arrAppCode[3];

	//! data
} SAiGifExtApp;

#pragma pack(pop)

#endif