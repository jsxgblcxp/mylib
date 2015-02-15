#ifndef CONFIG_READER_H_
#define CONFIG_READER_H_
#include <string>
#include <map>

#include <fstream>

using std::string;
using std::map;
using std::ifstream;

class CConfigReader
{
        public :
                CConfigReader( const string fileName );
                /* return whther the data in or not ,we do not make sure the confirm is right */
                bool getStringConfig( string & config_value,  const string config_key );
                bool getDoubleConfig( double & config_value , const string config_key );
                bool getIntConfig( int & config_value ,  const string config_key );
                bool getCharConfig( char & config_value ,  const string config_key );
                bool iniDone();
        private :
                void readConfigLineByLine();
                ifstream m_configFile;
                map< string , string > m_config_data;
                bool m_iniDone;
};

#endif // CONFIG_READER_H_

/* here we just accept the form of 
/* [ key ]=[ value ]*/
/* here we read a line each time and the string before the 1st = is reagarded as key , all spaces and tabs will be ignored.*/
/* while setting more than one value for one key,only the 1st value will be get*/
/* all the data could is stored as string,howevery , it could be ansi to duoble , int , float , char , and string */

