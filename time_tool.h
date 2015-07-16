#ifndef MY_LIB_TIME_TOOL_H
#define MY_LIB_TIME_TOOL_H

#include "time.h"
#include <string>

std::string what_time_is_it()
{
	time_t current_sec;
	time( & current_sec );
	struct tm * p_current_time = localtime( & current_sec );
	char tmp_str[ 20 ] = {0};
	snprintf( tmp_str ,
           	  sizeof( tmp_str ) ,
           	  "%.4d%.2d%.2d" ,
           	  p_current_time->tm_year + 1900 ,
           	  p_current_time->tm_mon + 1 ,
           	  p_current_time->tm_mday );
	return std::string( tmp_str );
}

#endif //MY_LIB_TIME_TOOL_H 
