#ifndef ht_trade_gateway_REMOVEABLE_LOCK_H_
#define ht_trade_gateway_REMOVEABLE_LOCK_H_

#include "pthread.h"

class RemoveableMutex
{
public:
        RemoveableMutex() :
                is_removed( false )
        {
                pthread_mutex_init(&mutex, NULL);
        }
        ~RemoveableMutex()
        {
                pthread_mutex_destroy(&mutex);
        }
        void lock(){
                if ( is_removed ) {
                        return ;
                }
                pthread_mutex_lock(&mutex);
        }
        void unlock(){
                pthread_mutex_unlock(&mutex);
        }
        void unlock_forever()
        {
                is_removed = true;
        }
private:
        bool is_removed;
        pthread_mutex_t mutex;
};

#endif // ht_trade_gateway_REMOVEABLE_LOCK_H_
