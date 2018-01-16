
//********************************
//
// qtc
//
// Claudio Daffra 
// daffra.clauio@gmail.com
// Copyright (c) 2018
//
//********************************

// MINGW 32,64

#if defined(__GNUC__)

#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wclobbered"
#pragma GCC diagnostic ignored "-Wunused-variable"

#endif

// Visual Studio

#ifdef _MSC_VER
#pragma warning(disable: 4706 4115 4100 4201 4214 4054 4996 4311 4312 4267 4244 4013 4047 4013)
#endif 

/**/

#define QTC_VER (char*)"\n-------\nQTC 0.1\n-------\n"
#define QTC_AUTHORS (const char*)"\n2009-2011, Zik Saleeba \n2015, Joseph Poirier \n2017, Mike Meyer \n2018, Claudio Daffra"
#define QTC_EMAIL	(const char*)"\ndaffra.claudio@gmail.com"
#define QTC_LICENSE (const char*)" MIT "

/**/

#define _qWidget 		1000
#define _qWindow 		1000
#define _qPushButton 	1001

#define _qClick		 	2000

/**/


