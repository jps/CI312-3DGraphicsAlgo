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


	bool Edge:: operator==( Edge &inV)
	{
	inV.a == a && inV.b == b ? true : false;
//	return inV.a.GetX() == a.GetX() && inV.a.GetY() == a.GetY() && inV.a.GetZ() == a.GetZ() && inV.b.GetX() == b.GetX() && inV.b.GetY() == b.GetY() && inV.b.GetZ() == b.GetZ()? true : false;
	}

	bool Edge :: operator!=(Edge &inV)
	{
	inV.a != a && inV.b != b ? true : false;
//	return inV.a.GetX() == a.GetX() && inV.a.GetY() == a.GetY() && inV.a.GetZ() == a.GetZ() && inV.b.GetX() == b.GetX() && inV.b.GetY() == b.GetY() && inV.b.GetZ() == b.GetZ()? false : true;
	}


	string Edge::ToString()
	{
	    return "Edge: a=" + a.ToString() + " b=" +b.ToString() +"\n"; //TODO: for each vertex
	}


    Edge::~Edge()
	{
	// TODO Auto-generated destructor stub
	}
}
