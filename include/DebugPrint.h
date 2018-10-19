#ifndef AI_DEBUGPRINT_H
#define AI_DEBUGPRINT_H

#if defined(DEBUG) || defined(_DEBUG)
#include <stdio.h>
#ifdef _WIN32
#define AIDebugPrint(fmt, ...)  fprintf(stderr, "[%s, %d]: " fmt, __FILE__, __LINE__, __VA_ARGS__)
#else
#define AIDebugPrint(fmt, args...)  fprintf(stderr, "[%s, %d]: " fmt, __FILE__, __LINE__, ##args)
#endif
#else
DebugPrint(...)
#endif

#endif /* AI_DEBUGPRINT_H */
