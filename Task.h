/*
 * Task.h
 *
 *  Created on: 23 de mar de 2017
 *      Author: mathias
 */

#ifndef TASK_H_
#define TASK_H_

class Task {
public:
	Task(double simTime){
		this->simTime = simTime;
	};
	virtual ~Task();
private:
	double simTime;
};

#endif /* TASK_H_ */
