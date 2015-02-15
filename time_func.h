#ifndef ZCE_QUOTE_REPLY_TYPECONVERT_H_
#define ZCE_QUOTE_REPLY_TYPECONVERT_H_

const int SECOND_PER_MINUTE = 60;
const int MINUTE_PER_HOUER  = 60;

// for the form of 2008-02-03 13:23:45.123
int hour( const char * time_stamp );
int minute( const char * time_stamp );
int second( const char * time_stamp );
int milli_sec( const char * time_stamp );
int sec_from_day_begin( const char * time_stamp );

#endif // ZCE_QUOTE_REPLY_TYPECONVERT_H_
