/*
 * main.cpp
 *
 *  Created on: 20 de mar de 2017
 *      Author: mathias
 */

#include <iostream>
#include "ExpDistribuition.h"
#include "Queue.h"
#include "Task.h"

#define HUGE_VAL 1000000
#define TMAX 100

double meanArrival;
double meanProcessing;

double simTime = 0.0;
double nextDeparture = HUGE_VAL;
double nextArrival;

using namespace std;

enum serverState {
	IDLE,BUSY
};

int state = IDLE;

ExpDistribuition exp;
Queue<10> queue;


int main(){

	nextArrival = exp.getValue(meanArrival);

	while(simTime < TMAX){
		if(nextArrival < nextDeparture){
			simTime = nextArrival;
			if(state == IDLE){
				state = BUSY;
				nextDeparture = simTime + exp.getValue(meanProcessing);
			}else{
				queue.push(new Task(simTime));
			}
			nextArrival = simTime + exp.getValue(meanArrival);
		}else{
			simTime = nextDeparture;
			if(queue.length() == 0){
				state = IDLE;
				nextDeparture = HUGE_VAL;
			}else{
				Task t = queue.pop();
				nextDeparture = simTime + exp.getValue(meanProcessing);
			}
		}
	}

}



