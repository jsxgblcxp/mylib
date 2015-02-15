#ifndef str_func
#define str_func
#include <string>
#include <vector>


void str_split( std::vector< std::string > & res_vec , std::string str , char IPS = ' ' );
void remove_char( std::string & str  , char c );
std::string str_join( std::vector< std::string > vecStr , char IPS = ' ' );

#endif // str_func
