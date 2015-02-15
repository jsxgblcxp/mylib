#ifndef STRING_ENCRYPTION_H
#define STRING_ENCRYPTION_H

#include <string>

//the string shorter than 200 
// when define CIPHER_CHAR including a-zA-Z is allowed.

void decipherString( std::string & str );
void cipherString( std::string & str );

//void makeCipherPosiMap( int posiMap[] ,  int strLen );
//void makeDecipherPosiMap( int posiMap[] ,  int strLen );
//
//void charArrCipher( char str[] , int strLen );
//void charArrDecipher( char str[] , int strLen );


#endif // STRING_ENCRYPTION_H
