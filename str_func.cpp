#include "str_func.h"


void str_split( std::vector< std::string > & res_vec , std::string str , char IPS = ' ' )
{
        str += IPS;

        size_t pos = 0;
        size_t begin_pos = 0;
        std::string tmp = " ";
        while ( std::string::npos != ( pos = str.find( IPS , pos ) ) )
        {
                res_vec.push_back( str.substr( begin_pos , pos - begin_pos ) );
                begin_pos = pos + 1;
                ++ pos;
        }
}

void remove_char( std::string & str  , char c )
{
        for ( size_t i = 0 ; i < str.length() ;  )
                if ( str[ i ] == c ) {
                        str.erase( i , 1 );
                } else {
                        ++ i;
                }
}

std::string str_join( std::vector< std::string > vecStr , char IPS = ' ' )
{
        if ( 0 == vecStr.size() )  return "";
        if ( 1 == vecStr.size() )  return vecStr[ 0 ];

        std::string res = vecStr[ 0 ];
        for ( size_t i = 1 ; i < vecStr.size() ; ++ i )
                res += IPS + vecStr[ i ];
        return res;
}
