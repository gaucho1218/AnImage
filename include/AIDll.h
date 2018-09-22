//
//  AIDllDll.h
//
//  Created by gaucho1218 on 2018. 9. 22..
//  Copyright © 2018 gaucho1218. All rights reserved.
//

#ifndef AI_DLL_h
#define AI_DLL_h

#ifdef _WIN32
#ifdef _WINDLL
#define AIDLL	__declspec(dllexport)
#else
#define AIDLL	__declspec(dllimport)
#endif
#else	//! other platform
#define AIDLL
#endif

#endif /* AI_DLL_h */
