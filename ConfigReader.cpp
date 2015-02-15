#include "ConfigReader.h"

#include "asist_defines.h"
#include <cstdlib>


CConfigReader::CConfigReader( const  string fileName ):
        m_iniDone( false )
{
        m_configFile.open( fileName.c_str() );
        readConfigLineByLine();
        /* here constructor shall throw someting when file does not exist  */
}

bool CConfigReader::getStringConfig( string & config_value,  const string config_key )
{
        map< string , string >::iterator it = m_config_data.find( config_key );
        if ( m_config_data.end() == it ) {
                return false;
        }
        config_value = it -> second;
        return true;
}

bool CConfigReader::getDoubleConfig( double & config_value , const string config_key )
{
        string tmp_str;
        RETURN_FALSE_IF( getStringConfig( tmp_str , config_key ) );
        config_value = atof( tmp_str.c_str() );
        return true;
}

bool CConfigReader::getIntConfig( int & config_value ,  const string config_key )
{
        string tmp_str;
        RETURN_FALSE_IF( getStringConfig( tmp_str , config_key ) );
        config_value = atoi( tmp_str.c_str() );
        return true;
}

bool CConfigReader::getCharConfig( char & config_value ,  const string config_key )
{
        string tmp_str;
        RETURN_FALSE_IF( getStringConfig( tmp_str , config_key ) );
        RETURN_FALSE_IF( tmp_str.length() == 0 );
        config_value = tmp_str[ 0 ];
        return true;
}

void CConfigReader::readConfigLineByLine()
{
        RETURN_IF_( false == m_configFile.good() , m_iniDone = false );
        string tmp_str;

        while ( false == m_configFile.eof() )
        {
                getline( m_configFile , tmp_str );
                size_t pos = tmp_str.find( "=" );
                if ( string::npos == pos ) {
                        continue;
                }
                string key_str = tmp_str.substr( 0 , pos );
                string value_str = tmp_str.substr( pos + 1 , tmp_str.length() - pos );
                if ( m_config_data.end() != m_config_data.find( key_str ) ) {
                        continue;/* the data exist */
                }
                m_config_data[ key_str ] = value_str;
        }
}
