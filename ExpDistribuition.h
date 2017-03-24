/*
 * ExpDistribuition.h
 *
 *  Created on: 23 de mar de 2017
 *      Author: mathias
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef EXPDISTRIBUITION_H_
#define EXPDISTRIBUITION_H_

class ExpDistribuition {
public:
	ExpDistribuition();
	virtual ~ExpDistribuition();
	double getValue(double meanValue){
		int uniformRandom = rand()%1;
		return exp = (1-uniformRandom)/meanValue;
	};
};

#endif /* EXPDISTRIBUITION_H_ */
