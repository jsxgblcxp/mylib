#ifndef ht_trade_gateway_EVENT_H_
#define ht_trade_gateway_EVENT_H_
#include "pthread.h"
#include "errno.h"
#include "sys/time.h"

//
//class Event
//{
//public:
//	Event( bool is_set , bool is_auto_reset ) :
//		is_set( is_set ) , 
//		is_auto_reset( is_auto_reset )
//	{
//		pthread_mutex_init( & mutex , NULL );
//		pthread_cond_init( & cond , NULL );
//	}
//	//void set_resetable(  );
//	void reset()
//	{
//		is_set = false;
//	}
//	void set()
//	{
//		is_set = true;
//		pthread_cond_signal( & cond );
//	}
//	void wait()
//	{
//		if ( ! is_set ) {
//			pthread_cond_wait( & cond , & mutex );
//		}
//		if ( is_auto_reset ) {
//			reset();
//		}
//	}
//
//private:
//	bool is_set;
//	bool is_auto_reset;
//	pthread_mutex_t mutex;
//	pthread_cond_t cond;
//};
void maketimeout( struct timespec * tsp , long second );

#include "pthread.h"

inline void maketimeout( struct timespec * tsp , long second )
{
	struct timeval now;
	gettimeofday( & now , NULL );
	tsp->tv_sec = now.tv_sec;
	tsp->tv_nsec = now.tv_usec * 1000; 
	tsp->tv_sec += second;
}

//class Event
//{
//public:
//	Event( bool is_set , bool is_auto_reset ) :
//		is_set( is_set ) , 
//		is_auto_reset( is_auto_reset )
//	{
//		pthread_mutex_init( & mutex , NULL );
//		pthread_cond_init( & cond , NULL );
//	}
//	void reset()
//	{
//		is_set = false;
//	}
//	void set()
//	{
//		is_set = true;
//		pthread_cond_signal( & cond );
//	}
//	void wait( int second = INF_WAIT_TIME  )
//	{
//		struct timespec wait_time;
//		maketimeout( & wait_time , second );
//		if ( ! is_set ) {
//			pthread_cond_timedwait( & cond ,
//                           & mutex,
//			   & wait_time );
//		}
//		if ( is_auto_reset ) {
//			reset();
//		}
//	}
//
//private:
//	static const int INF_WAIT_TIME = 1000000;
//	bool is_set;
//	bool is_auto_reset;
//	pthread_mutex_t mutex;
//	pthread_cond_t cond;
//};

class Event
{
public:
	Event( bool is_set , bool is_auto_reset ) :
		is_set( is_set ) , 
		is_auto_reset( is_auto_reset )
	{
		pthread_mutex_init( & mutex , NULL );
		pthread_cond_init( & cond , NULL );
	}
	void reset()
	{
		is_set = false;
	}
	void set()
	{
		is_set = true;
		pthread_cond_signal( & cond );
	}
	enum WaitRes
	{
		OK = 0 , 
		TIMED_OUT = -10
	};
	WaitRes wait( int second = INF_WAIT_TIME  )
	{
		if ( is_set ) {
			return OK;
		}
		struct timespec wait_time;
		maketimeout( & wait_time , second );
		int ret = 0;
		ret = pthread_cond_timedwait( & cond , & mutex, & wait_time );
		if ( ETIMEDOUT == ret ) {
			return TIMED_OUT;
		}
		if ( is_auto_reset ) {
			reset();
		}
		return OK;
	}

private:
	static const int INF_WAIT_TIME = 1000000;
	bool is_set;
	bool is_auto_reset;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
};

#endif // ht_trade_gateway_EVENT_H_
