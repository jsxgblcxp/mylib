
template < typename T1 , typename T2 >
bool getValue( T2 & value , const T1 & key , const map< T1 , T2 > & mapRef  ) 
{
        typename  map< T1 , T2 >::const_iterator it;

        it = mapRef.find( key ); 

        if ( it == mapRef.end() ) {
                return false;
        }

        value = it -> second;
        return true;
}
