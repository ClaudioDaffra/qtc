#include <stdio.h>
#include <stdint.h>

int  main ( void ) 
{
    int8_t i8 ;
	int16_t i16 ;
	int32_t i32 ;
	//int64_t i64 ;	
 
    uint8_t ui8 ;
	uint16_t ui16 ;
	uint32_t ui32 ;
	//uint64_t ui64 ;	
	
    int_least8_t i8l ;
	int_least16_t i16l ;
	int_least32_t i32l ;	
	//int_least64_t i64l ;	
	
    uint_least8_t ui8l ;
	uint_least16_t ui16l ;
	uint_least32_t ui32l ;	
	//uint_least64_t ui64l ;	
	
    int_fast8_t i8f ;
	int_fast16_t i16f ;
	int_fast32_t i32f ;	
	//int_fast64_t i64f ;	
	
    uint_fast8_t ui8f ;
	uint_fast16_t ui16f ;
	uint_fast32_t ui32f ;	
	//uint_fast64_t ui64f ;		
	
	
	printf ( "\n %d %d %d %d  \n ",sizeof(i8),sizeof(ui16),sizeof(ui32l),sizeof(ui32f)  );
	

	return 0 ;
}
