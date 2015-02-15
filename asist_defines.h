#ifndef ASIST_DEFINES_H_
#define ASIST_DEFINES_H_

#define RETURN_TRUE_IF(x)        if((x)){return true;}
#define RETURN_TRUE_IF_NOT(x)        if((!x)){return true;}

#define RETURN_FALSE_IF(x)        if((x)){return false;}
#define RETURN_FALSE_IF_NOT(x)    if(!(x)){return false;}

#define RETURN_TRUE_IF_(x,y)     if((x)){(y); return true;}
#define RETURN_TRUE_IF_NOT_(x,y) if(!(x)){(y); return true;}

#define RETURN_FALSE_IF_(x,y)     if((x)){(y); return false;}
#define RETURN_FALSE_IF_NOT_(x,y) if(!(x)){(y); return false;}

#define RETURN_IF(x)           if((x)){ return ;}
#define RETURN_IF_NOT(x)           if(!(x)){ return ;}

#define RETURN_IF_(x,y)           if((x)){(y); return ;}
#define RETURN_IF_NOT_(x,y)           if(!(x)){(y); return ;}

#define RETURN_INT_IF(x,y)    if((x)){ return (y);}
#define RETURN_INT_IF_NOT(x,y)    if(!(x)){ return (y);}

#define RETURN_INT_IF_(x,y,z)    if((x)){(y);return (z);}
#define RETURN_INT_IF_NOT_(x,y,z)    if(!(x)){(y);return (z);}

#endif // ASIST_DEFINES_H_
