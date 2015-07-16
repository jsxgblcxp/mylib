#ifndef DOUBLE_COMPAIR_H_
#define DOUBLE_COMPAIR_H_

const double EPS = 1e-7;
inline bool zero( double a )
{
	return - EPS < a && a < EPS;
}

inline bool eq( double a , double b )
{
	return zero( a - b );
}

inline bool less( double a , double b ) 
{
	return a < b - EPS;
}

inline bool more( double a , double b )
{
	return a > b + EPS;
}

#endif // DOUBLE_COMPAIR_H_
