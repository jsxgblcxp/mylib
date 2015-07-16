#ifndef ht_trade_gateway_EVENT_MANAGER_H_
#define ht_trade_gateway_EVENT_MANAGER_H_


#include <map>
#include <string>
#include "event.h"
#include "sim/util/thread.h"



class EventManager
{
public:
	int add_event( const std::string & key_str , void * p_data = NULL )
	{
		Locking lock( & event_map_mutex );
		std::map< std::string , Event * >::iterator it;
		it = event_map.find( key_str );
		RETURN_VAL_IF( event_map.end() != it , -1 );
		Event * p_event = new Event( false , false );
		RETURN_VAL_IF_NULL( p_event , -2 );
		event_map[ key_str ] = p_event;
		data_point_map[ key_str ] = p_data;
		return 0;
	}

	/* make return code of this event as enum */
	int wait_event( const std::string & key_str , int wait_sec = -1 )
	{
		Event * p_event;
		{
			Locking lock( & event_map_mutex );
			std::map< std::string , Event * >::iterator it;
			it = event_map.find( key_str );
			RETURN_VAL_IF( event_map.end() == it , -3 );
			p_event = it->second;
		}
		Event::WaitRes wait_ret = Event::OK;
		wait_ret = p_event->wait( -1 == wait_ret ? wait_sec : default_wait_sec  );
		{
			Locking lock( & event_map_mutex );
			event_map.erase( key_str );
			data_point_map.erase( key_str );
		}
		delete p_event;
		return wait_ret;
	}

	void * get_data_point( const std::string & key_str )
	{
		Locking lock( & event_map_mutex );
		std::map< std::string , void * >::iterator it;
		it = data_point_map.find( key_str );
		RETURN_VAL_IF( data_point_map.end() != it , it->second );
		return NULL;
	}

	/* release data point */
	/* before realse the lock cannot release */
	int set_event( const std::string & key_str )
	{
		Event * p_event;
		{
			Locking lock( & event_map_mutex );
			std::map< std::string , Event * >::iterator it;
			it = event_map.find( key_str );
			RETURN_VAL_IF( event_map.end() == it , -3 );
			p_event = it->second;
		}
		p_event->set();
		return 0;
	}

private:

	static const int default_wait_sec = 10;
	std::map< std::string , Event * > event_map; 
	std::map< std::string , void * > data_point_map; 
	Mutex event_map_mutex;
};

extern EventManager g_event_manager;

#endif // ht_trade_gateway_EVENT_MANAGER_H_
