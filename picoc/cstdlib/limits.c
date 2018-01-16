/* */
#include "../../main.h"
#include <limits.h>
#include "../interpreter.h"
#include "../platform.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef CHAR_BIT
static const int CHAR_BITValue = CHAR_BIT;
#endif

#ifdef SCHAR_MIN
static const int SCHAR_MINValue = SCHAR_MIN;
#endif

#ifdef SCHAR_MAX
static const int SCHAR_MAXValue = SCHAR_MAX;
#endif

#ifdef UCHAR_MAX
static const int UCHAR_MAXValue = UCHAR_MAX;
#endif

#ifdef CHAR_MIN
static const int CHAR_MINValue = CHAR_MIN;
#endif

#ifdef CHAR_MAX
static const int CHAR_MAXValue = CHAR_MAX;
#endif
/*
#ifdef MB_MAX_LEN
static const int MB_MAX_LENValue = MB_MAX_LEN;
#endif
*/
#ifdef SHRT_MIN
static const int SHRT_MINValue = SHRT_MIN;
#endif

#ifdef SHRT_MAX
static const int SHRT_MAXValue = SHRT_MAX;
#endif

#ifdef USHRT_MAX
static const int USHRT_MAXValue = USHRT_MAX;
#endif

#ifdef INT_MIN
static const int INT_MINValue = INT_MIN;
#endif

#ifdef INT_MAX
static const int INT_MAXValue = INT_MAX;
#endif

#ifdef UINT_MAX
static const int UINT_MAXValue = UINT_MAX;
#endif

#ifdef LONG_MIN
static const long LONG_MINValue = LONG_MIN;
#endif

#ifdef LONG_MAX
static const long LONG_MAXValue = LONG_MAX;
#endif

#ifdef ULONG_MAX
static const unsigned long  ULONG_MAXValue = ULONG_MAX;
#endif


void StdLimitsSetupFunc(Picoc *pc) 
{
#ifdef CHAR_BIT
     VariableDefinePlatformVar(pc, NULL, "CHAR_BIT", &pc->IntType,(union AnyValue *) &CHAR_BITValue, false);
#endif

#ifdef SCHAR_MIN
     VariableDefinePlatformVar(pc, NULL, "SCHAR_MIN", &pc->IntType,(union AnyValue *) &SCHAR_MINValue, false);
#endif

#ifdef SCHAR_MAX
     VariableDefinePlatformVar(pc, NULL, "SCHAR_MAX", &pc->IntType, (union AnyValue *) &SCHAR_MAXValue, false);
#endif

#ifdef UCHAR_MAX
     VariableDefinePlatformVar(pc, NULL, "UCHAR_MAX", &pc->IntType, (union AnyValue *) &UCHAR_MAXValue, false);
#endif

#ifdef CHAR_MIN
     VariableDefinePlatformVar(pc, NULL, "CHAR_MIN", &pc->IntType,  (union AnyValue *) &CHAR_MINValue, false);
#endif

#ifdef CHAR_MAX
     VariableDefinePlatformVar(pc, NULL, "CHAR_MAX", &pc->IntType,  (union AnyValue *) &CHAR_MAXValue, false);
#endif
/*
#ifdef MB_MAX_LEN
     VariableDefinePlatformVar(pc, NULL, "MB_MAX_LEN", &pc->IntType, (union AnyValue *) &LENValue = MB, false);
#endif
*/
#ifdef SHRT_MIN
     VariableDefinePlatformVar(pc, NULL, "SHRT_MIN", &pc->IntType, (union AnyValue *) &SHRT_MINValue, false);
#endif

#ifdef SHRT_MAX
     VariableDefinePlatformVar(pc, NULL, "SHRT_MAX", &pc->IntType, (union AnyValue *) &SHRT_MAXValue, false);
#endif

#ifdef USHRT_MAX
     VariableDefinePlatformVar(pc, NULL, "USHRT_MAX", &pc->IntType,   (union AnyValue *) &USHRT_MAXValue, false);
#endif

#ifdef INT_MIN
     VariableDefinePlatformVar(pc, NULL, "INT_MIN", &pc->IntType,  (union AnyValue *) &INT_MINValue, false);
#endif

#ifdef INT_MAX
     VariableDefinePlatformVar(pc, NULL, "INT_MAX", &pc->IntType,   (union AnyValue *) &INT_MAXValue, false);
#endif

#ifdef UINT_MAX
     VariableDefinePlatformVar(pc, NULL, "UINT_MAX", &pc->IntType,  (union AnyValue *) &UINT_MAXValue, false);
#endif

#ifdef LONG_MIN
VariableDefinePlatformVar(pc, NULL, "LONG_MIN", &pc->IntType, (union AnyValue *) &LONG_MINValue, false);
#endif

#ifdef LONG_MAX
VariableDefinePlatformVar(pc, NULL, "LONG_MAX", &pc->IntType, (union AnyValue *) &LONG_MAXValue, false);
#endif

#ifdef ULONG_MAX
VariableDefinePlatformVar(pc, NULL, "ULONG_MAX", &pc->IntType,  (union AnyValue *) &ULONG_MAXValue, false);
#endif
}
