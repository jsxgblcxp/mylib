#include "typeConvert.h"
        
//for the form of
//2008-02-03 13:23:45.123
int hour( const char * time_stamp )
{
        char hourStr[ 3 ] = { 0 };
        //012345678901234567890
        //2008-02-03 13:23:45.123
        strncpy( hourStr , & time_stamp[ 11 ] , sizeof( char ) * 2 );
        return atoi( hourStr );
}

int minute( const char * time_stamp )
{
        char minuteStr[ 3 ] = { 0 };
        //012345678901234567890
        //2008-02-03 13:23:45.123
        strncpy( minuteStr , & time_stamp[ 14 ] , sizeof( char ) * 2 );
        return atoi( minuteStr );
}

int second( const char * time_stamp )
{
        char secondStr[ 3 ] = { 0 };
        //01234567890123456789012
        //2008-02-03 13:23:45.123
        strncpy( secondStr , & time_stamp[ 17 ] , sizeof( char ) * 2 );
        return atoi( secondStr ) ;
}

int milli_sec( const char * time_stamp )
{
        char milliSecStr[ 4 ] = { 0 };
        //01234567890123456789012
        //2008-02-03 13:23:45.123
        strncpy( milliSecStr , & time_stamp[ 20 ] , sizeof( char ) * 3 );
        return atoi( milliSecStr );
}

int sec_from_day_begin( const char * time_stamp )
{
        return hour( time_stamp ) * MINUTE_PER_HOUER * SECOND_PER_MINUTE + 
               minute( time_stamp ) * SECOND_PER_MINUTE +
               second( time_stamp );
}

