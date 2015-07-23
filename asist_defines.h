#ifndef ASIST_DEFINES_H_
#define ASIST_DEFINES_H_

#define CONTINUE_IF(x)        		if((x)){continue;}
#define CONTINUE_IF_(x,y)        	if((x)){(y);continue;}
#define CONTINUE_IF_NOT(x)      	if(!(x)){continue;}
#define CONTINUE_IF_NOT_(x,y)      	if(!(x)){(y);continue;}

#define BREAK_IF(x) 			if((x)){break;}
#define BREAK_IF_NOT(x) 		if(!(x)){break;}

#define RETURN_TRUE_IF(x)       	if((x)){return true;}
#define RETURN_TRUE_IF_NOT(x)   	if(!(x)){return true;}

#define RETURN_FALSE_IF(x)      	if((x)){return false;}
#define RETURN_FALSE_IF_NOT(x)  	if(!(x)){return false;}

#define RETURN_TRUE_IF_(x,y)    	if((x)){(y); return true;}
#define RETURN_TRUE_IF_NOT_(x,y)	if(!(x)){(y); return true;}

#define RETURN_FALSE_IF_(x,y)   	if((x)){(y); return false;}
#define RETURN_FALSE_IF_NOT_(x,y) 	if(!(x)){(y); return false;}

#define RETURN_IF(x)           		if((x)){ return ;}
#define RETURN_IF_NOT(x)       		if(!(x)){ return ;}

#define RETURN_IF_(x,y)        		if((x)){(y); return ;}
#define RETURN_IF_NOT_(x,y)    		if(!(x)){(y); return ;}


#define RETURN_VAL_IF(x,y)     		if((x)){ return (y);}
#define RETURN_VAL_IF_NOT(x,y) 		if(!(x)){ return (y);}
#define RETURN_VAL_IF_NULL(x,y)		if(NULL==(x)){ return (y);}
#define RETURN_VAL_IF_NULL_(x,y,z) 	if(NULL==(x)){(y);return (z);}

#define RETURN_VAL_IF_(x,y,z)    	if((x)){(y);return (z);}
#define RETURN_VAL_IF_NOT_(x,y,z)    	if(!(x)){(y);return (z);}

#define RETURN_IF_NULL(x)  		if((x)==NULL){ return ;}
#define RETURN_IF_NULL_(x,y)  		if((x)==NULL){ (y); return ;}
#define RETURN_FALSE_IF_NULL(x) 	if((x)==NULL){ return false;}
#define RETURN_FALSE_IF_NULL_(x ,y) 	if((x)==NULL){(y); return false;}

#define DO_IF(x,y)			if ((x)) {(y);}
#define DO_IF_NOT(x,y)			if (!(x)) {(y);}

#include <stdlib.h>
#include <stdio.h>

#define EXIT_IF_NULL(x,y) 		if (NULL==(x)) { fprintf( stderr , "%s:%d \n" , __FILE__ , __LINE__ );exit(y);}
#define EXIT_IF_NULL_(x,y,z) 		if (NULL==(x)) { fprintf( stderr , "%s:%d \n" , __FILE__ , __LINE__ );(y);exit(z);}
#define EXIT_IF_NOT(x,y) 		if(false==(x)) {fprintf( stderr , "%s:%d \n" , __FILE__ , __LINE__ );exit(y);}
#define EXIT_IF_NOT_(x,y,z) 		if(false==(x)) {(y);fprintf( stderr , "%s:%d \n" , __FILE__ , __LINE__ );exit(z);} 

#define DO_NOTHING()

#endif // ASIST_DEFINES_H_
