#ifndef __CHAIN_H__
#define __CHAIN_H__
#include <deque>
#include <Eigen/Dense>
#include "StationaryImage.h"
#include "MovingImage.h"
#include "Point.h"
#include <iostream>
#include "Plane.h"


namespace GNEB
{
	class Chain
	{
		static Chain *instance;
		Chain(){};
		std::deque<MovingImage> chain;
		//Point *first, *last;
        StationaryImage	*first, *last;
	public:
		static Chain *getInstance();
		Point getPoint(unsigned int number);
		std::deque<MovingImage>::iterator begin();
		std::deque<MovingImage>::iterator end();
		void addToChain(MovingImage p);
		void addToChain(MovingImage *p);
        void setFirst(StationaryImage *p);
		void setFirst(Point *p);
   		void setLast(StationaryImage *p);
		void setLast(Point *p);
        void checkFirstAndLast();
		void calculateInterpolation(const int Q);
        StationaryImage *getFirst();
        StationaryImage *getLast();
		//calculate interpolation of initial path

		//makes sure points are in order to keep calculation time lower first, we sort by x then by y coordinate. x1<x2 or y1<y2 => P1 < P2
	};
}

#endif //__CHAIN_H__
