#include "StringEncryption.h"
#include <string.h>
#include <stdlib.h>
using std::string;

const int basicPosiMap[ 200 ] = { 133 , 74 , 64 , 130 , 24 , 113 , 119 , 63 , 102 , 128 , 121 , 62 , 55 , 118 , 13 , 2 , 105 , 183 , 187 , 27 , 71 , 61 , 4 , 91 , 94 , 48 , 175 , 151 , 192 , 156 , 181 , 58 , 172 , 57 , 141 , 73 , 77 , 147 , 145 , 123 , 97 , 138 , 152 , 79 , 47 , 184 , 26 , 120 , 117 , 140 , 132 , 196 , 186 , 3 , 83 , 107 , 17 , 92 , 35 , 70 , 164 , 19 , 162 , 20 , 182 , 81 , 60 , 37 , 6 , 178 , 189 , 108 , 167 , 90 , 134 , 111 , 126 , 72 , 131 , 9 , 109 , 28 , 46 , 43 , 23 , 191 , 51 , 142 , 50 , 154 , 7 , 96 , 135 , 33 , 104 , 149 , 198 , 153 , 174 , 59 , 127 , 143 , 25 , 45 , 116 , 106 , 165 , 18 , 190 , 180 , 87 , 114 , 170 , 75 , 185 , 49 , 89 , 39 , 136 , 124 , 103 , 166 , 155 , 15 , 158 , 36 , 173 , 88 , 14 , 34 , 41 , 31 , 11 , 163 , 176 , 93 , 139 , 150 , 99 , 122 , 148 , 69 , 40 , 160 , 84 , 66 , 53 , 80 , 112 , 194 , 0 , 98 , 161 , 52 , 32 , 144 , 171 , 56 , 95 , 44 , 30 , 101 , 78 , 177 , 100 , 169 , 8 , 5 , 168 , 82 , 159 , 1 , 21 , 199 , 68 , 146 , 16 , 129 , 65 , 179 , 86 , 67 , 115 , 157 , 76 , 12 , 188 , 85 , 38 , 193 , 10 , 29 , 197 , 110 , 42 , 22 , 195 , 54 , 125 , 137 };

const int charMap[ 52 ] = { 50 , 48 , 41 , 32 , 7 , 14 , 16 , 31 , 2 , 3 , 13 , 17 , 20 , 26 , 30 , 39 , 36 , 38 , 51 , 23 , 49 , 28 , 29 , 0 , 5 , 37 , 18 , 1 , 9 , 6 , 45 , 24 , 47 , 33 , 40 , 42 , 22 , 27 , 21 , 46 , 12 , 44 , 11 , 10 , 15 , 4 , 8 , 34 , 19 , 35 , 25 , 43 };

const int charUnMap[ 52 ]= { 23 , 27 , 8 , 9 , 45 , 24 , 29 , 4 , 46 , 28 , 43 , 42 , 40 , 10 , 5 , 44 , 6 , 11 , 26 , 48 , 12 , 38 , 36 , 19 , 31 , 50 , 13 , 37 , 21 , 22 , 14 , 7 , 3 , 33 , 47 , 49 , 16 , 25 , 17 , 15 , 34 , 2 , 35 , 51 , 41 , 30 , 39 , 32 , 1 , 20 , 0 , 18 };

const int MAX_LENGTH = 200;

int charToInt( char c );
char intToChar( int a );
void charArrDecipher( char str[] , int strLen );
void charArrCipher( char str[] , int strLen );

void makeCipherPosiMap( int posiMap[] ,  int strLen );
void makeDecipherPosiMap( int posiMap[] ,  int strLen );


void map_reverse( int oriMap[] , int strLen );
int cmp( const void * a , const void * b );

void changPosiByMap( char str[] , int posiMap[] , int strLen );

void decipherString( std::string & str )
{
        char tmpStr[ MAX_LENGTH ] = {0};
        strcpy( tmpStr , str.c_str() );
        int posiMap[ MAX_LENGTH ] = {0};
        makeDecipherPosiMap( posiMap , str.length() );
        changPosiByMap( tmpStr , posiMap , str.length() );
        charArrDecipher( tmpStr , str.length() );
        str = tmpStr;
        return ;
}

void cipherString( std::string & str )
{
        char tmpStr[ MAX_LENGTH ] = {0};
        strcpy( tmpStr , str.c_str() );
        int posiMap[ MAX_LENGTH ] = {0};
        makeCipherPosiMap( posiMap , str.length() );
        changPosiByMap( tmpStr , posiMap , str.length() );
        charArrCipher( tmpStr , str.length() );
        str = tmpStr;
        return ;
}

void makeCipherPosiMap( int posiMap[] ,  int strLen )
{
        for ( int i = 0 ; i < strLen ; ++ i )
                posiMap[ i ] = i;
        qsort( posiMap , strLen , sizeof( int ) , cmp );
}

int cmp( const void * a , const void * b )
{
        int l = *( ( int * )a );
        l = basicPosiMap[ l ];
        int r = *( ( int * )b );
        r = basicPosiMap[ r ];
        if ( l == r ) return 0;
        return l < r ? -1 : 1; 
}

void makeDecipherPosiMap( int posiMap[] ,  int strLen )
{
        makeCipherPosiMap( posiMap , strLen );
        map_reverse( posiMap , strLen );
}


void map_reverse( int oriMap[] , int strLen )
{
        int tmpMap[ 200 ] = { 0 };
        memcpy( tmpMap , oriMap , sizeof( int ) * strLen );
        for ( int i = 0 ; i < strLen ; ++ i )
                oriMap[ tmpMap[ i ] ] = i;
}

int isLetter( char c )
{
        return  ( 'a' <= c && c <= 'z' ) || ( 'A' <= c && c <= 'Z' );
}

int charToInt( char c )
{
        if ( c >= 'a' && c <= 'z' ) {
                return c  - 'a';
        } else if ( c >= 'A' && c <= 'Z' ) {
                return c  - 'A' + 26;
        }
        return c;
}

char intToChar( int a )
{
        if ( 0 <= a && a < 26 ) {
                return a + 'a';
        } else {
                return a - 26 + 'A';
        }
        return a;
}

void charArrCipher( char str[] , int strLen )
{
        for ( int i = 0 ; i < strLen ; ++ i )
                if ( isLetter( str[ i ] ) ) {
                        char tmp = str[ i ];
                        tmp = intToChar( charMap[ charToInt( tmp ) ] ); 
                        str[ i ] = tmp;
                }
}

void charArrDecipher( char str[] , int strLen )
{
        for ( int i = 0 ; i < strLen ; ++ i )
                if ( isLetter( str[ i ] ) ) {
                        char tmp = str[ i ];
                        tmp = intToChar( charUnMap[ charToInt( tmp ) ] ); 
                        str[ i ] = tmp;
                }
}

void changPosiByMap( char str[] , int posiMap[] , int strLen )
{
        char tmpStr[ MAX_LENGTH ] = { 0 };
        for ( int i = 0 ; i < strLen ; ++ i )
                tmpStr[ posiMap[ i ] ] = str[ i ];
        memcpy( str , tmpStr , sizeof( int ) * strLen );
}
