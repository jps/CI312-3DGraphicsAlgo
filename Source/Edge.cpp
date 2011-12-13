/*
 * Edge.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "../Header/Edge.h"

namespace Game
{

    Edge::Edge()
	{

	}


/*    Edge::Edge(Vertex &A, Vertex &B)
    {
    	a = &A;
    	b = &B;
    }*/
/**/

    Edge::Edge(int A, int B)
	{
	    a = A;
	    b = B;
	}
/*
    Vertex Edge::MidPoint()
	{
	    return Vertex(a->GetX()+b->GetX()/2,a->GetY()+b->GetY()/2,a->GetZ()+b->GetZ()/2);
	}
*/


	bool Edge:: operator==( Edge &inV)
	{
		//TODO: edge compare is could do with limiting to only a = a or b = b
	    //have changed this to allow reverse edges to also be the same...
		//this is a cheap hacky fix to a rather big issue in the subdivision routine...
	return (inV.a == a && inV.b == b) ? true : false;
//	return inV.a.GetX() == a.GetX() && inV.a.GetY() == a.GetY() && inV.a.GetZ() == a.GetZ() && inV.b.GetX() == b.GetX() && inV.b.GetY() == b.GetY() && inV.b.GetZ() == b.GetZ()? true : false;
	}


	int Edge:: Compare (Edge &inV)
	{
		if(inV.a == a && inV.b == b)
			return 2;//same
		if(inV.a == b && inV.b == a)
			return 1;//reverse
		else
			return 0;//no match
	}

	bool Edge :: operator!=(Edge &inV)
	{
	return (inV.a == a && inV.b == b) || (inV.a == b && inV.b == a)? false : true;
	}


	string Edge::ToString()
	{
		//TODO: fix
		return "edge to string needs fixing";
	   // return "Edge: a=" + a + " b=" + b +"\n"; //TODO: for each vertex
	}


    Edge::~Edge()
	{
	// TODO Auto-generated destructor stub
	}
}
