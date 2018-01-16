/* Dynamically create intXX_t and uintXX_t types */
#include "../../main.h"
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include "../platform.h"
#include "../interpreter.h"
#include "../picoc.h"

/*
 * Using limits.h here is buggy. A user could include stdint.h then redefine
 * a name in limits.h that stdint.h is using, and get the wrong value. But
 * doing it right would require having two copies of everything. A minor
 * issue in a compiler, but not so much in an interpreter.
 */
static const char intmax_format[] = "\
typedef long intmax_t;\n\
#define INTMAX_MIN %ld\n\
#define INTMAX_MAX %ld\n\
typedef unsigned long uintmax_t;\n\
#define UINTMAX_MAX %lu\n\
";

static const char ptrmax_format[] = "\
typedef %s intptr_t;\n\
#define INTPTR_MIN %ld\n\
#define INTPTR_MAX %ld\n\
typedef unsigned %s uintptr_t;\n\
#define UINTPTR_MAX %lu\n\
";

static const char format[] = "\
typedef signed %s int%s%d_t;\n\
#define INT%s%d_MIN %ld\n\
#define INT%s%d_MAX %lu\n\
typedef unsigned %s uint%s%d_t;\n\
#define UINT%s%d_MAX %lu\n\
";

static const char fn[] = "stdint.h";
#define LEN 2400

#define CHAR  0
#define SHORT 1
#define INT   2
#define LONG  3

static const char *names[] = { "char", "short", "int", "long" } ;

static const unsigned long maxes[][3] = 
{
     {CHAR_MIN, CHAR_MAX, UCHAR_MAX},
     {SHRT_MIN, SHRT_MAX, USHRT_MAX},
     {INT_MIN, INT_MAX, UINT_MAX},
     {LONG_MIN, LONG_MAX, ULONG_MAX}
};

static void make_types(char *buffer, int type, int length, bool exact) 
{
     if (exact) 
	 {
          snprintf(buffer + strlen(buffer), LEN - strlen(buffer), format,
                   names[type], "", length, "", length, maxes[type][0],
                   "", length, maxes[type][1],
                   names[type], "", length, "", length, maxes[type][2]);
     }
	 
     snprintf(buffer + strlen(buffer), LEN - strlen(buffer), format,
              names[type], "_fast", length, "_FAST", length, maxes[type][0],
              "_FAST", length, maxes[type][1],
               names[type], "_fast", length, "_FAST", length, maxes[type][2]);
			   
     snprintf(buffer + strlen(buffer), LEN - strlen(buffer), format,
              names[type], "_least", length, "_LEAST", length, maxes[type][0],
              "_LEAST", length, maxes[type][1],
               names[type], "_least", length, "_LEAST", length, maxes[type][2]);
}


 
	
	void StdintSetupFunc(Picoc *pc)
	{
		 int ptr_type;
		 char buffer[LEN];

		 /* The oddball cases */
		 snprintf(buffer, LEN, intmax_format, LONG_MIN, LONG_MAX, ULONG_MAX);
		 
		 ptr_type = sizeof(short) >= sizeof(void *) ? SHORT
				  : sizeof(int) >= sizeof(void *) ? INT : LONG;
				  
		 snprintf(buffer + strlen(buffer), LEN - strlen(buffer), ptrmax_format,
				  names[ptr_type], maxes[ptr_type][0], maxes[ptr_type][1],
				  names[ptr_type], maxes[ptr_type][2]);

		 /* The easy cases */
		 make_types(buffer, CHAR, 8, CHAR_BIT == 8);
		 make_types(buffer, SHORT, 16, sizeof(short) * CHAR_BIT == 16);

		 /* And now the general cases */
		 if (sizeof(short) * CHAR_BIT >= 32 && sizeof(int) * CHAR_BIT >= 64) 
		 {
			  make_types(buffer, SHORT, 32, sizeof(short) * CHAR_BIT == 32);
			  make_types(buffer, INT, 64, sizeof(int) * CHAR_BIT == 64);
		 } 
		 else 
		 {
			  if (sizeof(int) * CHAR_BIT >= 32) 
			  {
				   make_types(buffer, INT, 32, sizeof(int) * CHAR_BIT == 32);
			  } 
			  else if (sizeof(long) * CHAR_BIT >= 32) 
			  {
				   make_types(buffer, LONG, 32, sizeof(long) * CHAR_BIT == 64);
			  }
			  if (sizeof(long) * CHAR_BIT >= 64) 
			  {
				   make_types(buffer, LONG, 64, sizeof(long) * CHAR_BIT == 64);
			  }
		 }

		 PicocParse(pc, fn, buffer, strlen(buffer), true, false, false, false);
	}

