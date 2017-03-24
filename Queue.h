/*
 * Queue.h
 *
 *  Created on: 2 de out de 2016
 *      Author: mathias
 */

#include "Task.h"

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <string.h>

template<unsigned int SIZE>
class Queue {
public:
	Queue(){
		memset(buffer, 0, SIZE*sizeof(Task));
		this->head = 0;
		this->tail = 0;
		this->size = 0;
	}
	void push(Task * t){
		if(((tail + 1) == head) || (((tail + 1) == SIZE) && (head == 0)))
			return;
		buffer[tail] = t;
		tail = (tail+1) % SIZE;
		size++;
		return;
	}
	char pop(){
		char value = 0;
		if(tail == head)
			return value;
		value = buffer[head];
		head = (head+1) % SIZE;
		size--;
		return value;
	}
	int length(){
		return size;
	}
private:
	int head,tail,size;
	Task * buffer[SIZE];
};

#endif /* QUEUE_H_ */
