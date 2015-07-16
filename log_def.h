#ifndef LOG_DEF_H
#define LOG_DEF_H
#include "stdio.h"
#define log_msg( msg ) fprintf( stderr , "[%s:%s:%d] %s" , __FILE__ , __FUNCTION__ , __LINE__ , msg );
#endif // LOG_DEF_H
