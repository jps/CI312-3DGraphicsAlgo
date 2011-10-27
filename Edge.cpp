/*
 * Edge.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "Edge.h"

namespace Game
{

    Edge::Edge()
	{

	}

    Edge::Edge(Vertex A, Vertex B)
	{
	    a = A;
	    b = B;
	}

    Vertex Edge::MidPoint()
	{
	    return Vertex(a.GetX()+b.GetX()/2,a.GetY()+b.GetY()/2,a.GetZ()+b.GetZ()/2);
	}

    Edge::~Edge()
	{
	// TODO Auto-generated destructor stub
	}
}
