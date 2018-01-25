
#include "../../main.h"
#include "qWidget.h"
#include "../interpreter.h"

// qWidget.cpp

extern long _qCustomizeWindowHint		;
extern long _qWindowTitleHint			;
extern long _qWindowMaximizeButtonHint	;
extern long _qWindowMinimizeButtonHint	;
extern long _qWindowCloseButtonHint		; 


// qWidget.cpp
// qWidgetConst.c

static const long qWidget 		=        _qWidget ; 
static const long qWindow 		=        _qWindow ;   
static const long qPushButton 	=        _qPushButton ;    
static const long qLabel 		=        _qLabel ;  

static const long qClick  		=        _qClick ;   
static const long qKey	  		=        _qKey ;  

int qfEventLoop=1; 
 

// SpecialKey

static const long qKey_Shift  	=        _qKey_Shift ;   
static const long qKey_Control	=        _qKey_Control ;  
static const long qKey_Meta  	=        _qKey_Meta ;   
static const long qKey_Alt		=        _qKey_Alt ;  
static const long qKey_AltGr 	=        _qKey_AltGr ;   
  
// Key

static const long qKey_F1	= _qKey_F1;	 
static const long qKey_F2	= _qKey_F2; 
static const long qKey_F3	= _qKey_F3;	 
static const long qKey_F4	= _qKey_F4;	 
static const long qKey_F5	= _qKey_F5;	 
static const long qKey_F6	= _qKey_F6;	 
static const long qKey_F7	= _qKey_F7; 
static const long qKey_F8	= _qKey_F8;	 
static const long qKey_F9	= _qKey_F9;	 
static const long qKey_F10  = _qKey_F10 ;	 
static const long qKey_F11  = _qKey_F11 ;	 
static const long qKey_F12  = _qKey_F12 ;

static const long qKey_Escape  		= _qKey_Escape ;
static const long qKey_Tab  		= _qKey_Tab ;
static const long qKey_Backtab 		= _qKey_Backtab ;
static const long qKey_Backspace 	= _qKey_Backspace ;	 
static const long qKey_Return 		= _qKey_Return ;

static const long qKey_Enter 	 	= _qKey_Enter ;
static const long qKey_Insert 		= _qKey_Insert ;
static const long qKey_Delete		=  _qKey_Delete	 ;
static const long qKey_Pause		= _qKey_Pause	; 
static const long qKey_Print  		= _qKey_Print ;

static const long qKey_SysReq	 	= _qKey_SysReq	; 

static const long qKey_Clear 		= _qKey_Clear ;
static const long qKey_Home 		= _qKey_Home ;
static const long qKey_End	 		= _qKey_End	 ;

static const long qKey_Left 		= _qKey_Left ;
static const long qKey_Up  			= _qKey_Up ;
static const long qKey_Right 		= _qKey_Right ;
static const long qKey_Down			= _qKey_Down ;	 
static const long qKey_PageUp		= _qKey_PageUp ;	 
static const long qKey_PageDown 	= _qKey_PageDown ; 

static const long qKey_CapsLock 	 = _qKey_CapsLock ;
static const long qKey_NumLock	 	 = _qKey_NumLock ;
static const long qKey_ScrollLock	 = _qKey_ScrollLock ; 

// ********** 
// extern
// ********** 

void qWdigetSetupFunc(Picoc *pc)
{
	// Widgets
	
    VariableDefinePlatformVar(pc, NULL, "qWidget"		, &pc->IntType, (union AnyValue *)&qWidget		, FALSE);	
    VariableDefinePlatformVar(pc, NULL, "qWindow"		, &pc->IntType, (union AnyValue *)&qWindow		, FALSE);
    VariableDefinePlatformVar(pc, NULL, "qPushButton"	, &pc->IntType, (union AnyValue *)&qPushButton	, FALSE);
    VariableDefinePlatformVar(pc, NULL, "qLabel"		, &pc->IntType, (union AnyValue *)&qLabel		, FALSE);

	// Events
		
	VariableDefinePlatformVar(pc, NULL, "qClick"		, &pc->IntType, (union AnyValue *)&qClick, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey"			, &pc->IntType, (union AnyValue *)&qKey, FALSE);
	
	// Flags

	VariableDefinePlatformVar(pc, NULL, "qCustomizeWindowHint"		, &pc->IntType, (union AnyValue *)&_qCustomizeWindowHint		, FALSE);	
	VariableDefinePlatformVar(pc, NULL, "qWindowTitleHint"			, &pc->IntType, (union AnyValue *)&_qWindowTitleHint			, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qWindowMaximizeButtonHint"	, &pc->IntType, (union AnyValue *)&_qWindowMaximizeButtonHint	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qWindowMinimizeButtonHint"	, &pc->IntType, (union AnyValue *)&_qWindowMinimizeButtonHint	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qWindowCloseButtonHint"	, &pc->IntType, (union AnyValue *)&_qWindowCloseButtonHint		, FALSE);
	
	// SpecialKey

	VariableDefinePlatformVar(pc, NULL, "qKey_Shift"		, &pc->IntType, (union AnyValue *)&qKey_Shift	, FALSE);	
	VariableDefinePlatformVar(pc, NULL, "qKey_Control"		, &pc->IntType, (union AnyValue *)&qKey_Control	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Ctrl"			, &pc->IntType, (union AnyValue *)&qKey_Control	, FALSE);	
	VariableDefinePlatformVar(pc, NULL, "qKey_Meta"			, &pc->IntType, (union AnyValue *)&qKey_Meta	, FALSE);	
	VariableDefinePlatformVar(pc, NULL, "qKey_Alt"			, &pc->IntType, (union AnyValue *)&qKey_Alt		, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_AltGr"		, &pc->IntType, (union AnyValue *)&qKey_AltGr	, FALSE);	
 
	
	// Key


	VariableDefinePlatformVar(pc, NULL, "qKey_F1"		, &pc->IntType, (union AnyValue *)&qKey_F1	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F2"		, &pc->IntType, (union AnyValue *)&qKey_F2	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F3"		, &pc->IntType, (union AnyValue *)&qKey_F3	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F4"		, &pc->IntType, (union AnyValue *)&qKey_F4	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F5"		, &pc->IntType, (union AnyValue *)&qKey_F5	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F6"		, &pc->IntType, (union AnyValue *)&qKey_F6	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F7"		, &pc->IntType, (union AnyValue *)&qKey_F7	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F8"		, &pc->IntType, (union AnyValue *)&qKey_F8	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F9"		, &pc->IntType, (union AnyValue *)&qKey_F9	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F10"		, &pc->IntType, (union AnyValue *)&qKey_F10	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F11"		, &pc->IntType, (union AnyValue *)&qKey_F11	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_F12"		, &pc->IntType, (union AnyValue *)&qKey_F12	, FALSE);
 	
	
 	VariableDefinePlatformVar(pc, NULL, "qKey_Escape"		, &pc->IntType, (union AnyValue *)&qKey_Escape	, FALSE);	
	VariableDefinePlatformVar(pc, NULL, "qKey_Tab"			, &pc->IntType, (union AnyValue *)&qKey_Tab		, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Backtab"		, &pc->IntType, (union AnyValue *)&qKey_Backtab	, FALSE);	
	VariableDefinePlatformVar(pc, NULL, "qKey_Backspace"	, &pc->IntType, (union AnyValue *)&qKey_Backspace		, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Return"		, &pc->IntType, (union AnyValue *)&qKey_Return	, FALSE);

	VariableDefinePlatformVar(pc, NULL, "qKey_Enter"		, &pc->IntType, (union AnyValue *)&qKey_Enter 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Insert"		, &pc->IntType, (union AnyValue *)&qKey_Insert 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Delete"		, &pc->IntType, (union AnyValue *)&qKey_Delete 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Pause"		, &pc->IntType, (union AnyValue *)&qKey_Pause 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Print"		, &pc->IntType, (union AnyValue *)&qKey_Print 	, FALSE);
 
	VariableDefinePlatformVar(pc, NULL, "qKey_SysReq"		, &pc->IntType, (union AnyValue *)&qKey_SysReq 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Clear"		, &pc->IntType, (union AnyValue *)&qKey_Clear 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Home"			, &pc->IntType, (union AnyValue *)&qKey_Home 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_End"			, &pc->IntType, (union AnyValue *)&qKey_End 	, FALSE);
	
	VariableDefinePlatformVar(pc, NULL, "qKey_Up "		, &pc->IntType, (union AnyValue *)&qKey_Up  	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Left"		, &pc->IntType, (union AnyValue *)&qKey_Left 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Right"	, &pc->IntType, (union AnyValue *)&qKey_Right 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_Down"		, &pc->IntType, (union AnyValue *)&qKey_Down 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_PageUp"	, &pc->IntType, (union AnyValue *)&qKey_PageUp 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_PageDown"	, &pc->IntType, (union AnyValue *)&qKey_PageDown, FALSE);

	VariableDefinePlatformVar(pc, NULL, "qKey_CapsLock"		, &pc->IntType, (union AnyValue *)&qKey_CapsLock 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_NumLock"		, &pc->IntType, (union AnyValue *)&qKey_NumLock 	, FALSE);
	VariableDefinePlatformVar(pc, NULL, "qKey_ScrollLock"	, &pc->IntType, (union AnyValue *)&qKey_ScrollLock	, FALSE);	
	
	
	
}


 