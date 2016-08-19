#ifndef LOCK_H_
#define LOCK_H_

#include "pthread.h"

class Mutex{
private:
	pthread_mutex_t mutex;
public:
	Mutex(){
		pthread_mutex_init(&mutex, NULL);
	}
	~Mutex(){
		pthread_mutex_destroy(&mutex);
	}
	void lock(){
		pthread_mutex_lock(&mutex);
	}
	void unlock(){
		pthread_mutex_unlock(&mutex);
	}
};

class Locking{
private:
	Mutex *mutex;
	// No copying allowed
	Locking(const Locking&);
	void operator=(const Locking&);
public:
	Locking(Mutex *mutex){
		this->mutex = mutex;
		this->mutex->lock();
	}
	~Locking(){
		this->mutex->unlock();
	}

};

#endif // LOCK_H_
