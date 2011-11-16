/*
 * Face.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "../Header/Face.h"

namespace Game
    {


    Face::Face()
    {

    }

    Face::Face(Edge A, Edge B, Edge C)
    {
    earr[0] = A;
    earr[1] = B;
    earr[2] = C;
    edgeDirection = FFF;
    }

    Face::Face(Edge A, Edge B, Edge C, EdgeDirection EdgeDirection)
    {
    earr[0] = A;
    earr[1] = B;
    earr[2] = C;
    edgeDirection = EdgeDirection;
    }

    void Face::Draw()
    {
	switch(edgeDirection)
	    {
	case FFB:

	    glVertex3f(earr[0].a.GetX(),earr[0].a.GetY(),earr[0].a.GetZ());
	    glVertex3f(earr[1].a.GetX(),earr[1].a.GetY(),earr[1].a.GetZ());
	    glVertex3f(earr[2].b.GetX(),earr[2].b.GetY(),earr[2].b.GetZ());
	break;
	case BFF:
	    glVertex3f(earr[0].b.GetX(),earr[0].b.GetY(),earr[0].b.GetZ());
	    glVertex3f(earr[1].a.GetX(),earr[1].a.GetY(),earr[1].a.GetZ());
	    glVertex3f(earr[2].a.GetX(),earr[2].a.GetY(),earr[2].a.GetZ());
	break;
	case FBF:
	    glVertex3f(earr[0].a.GetX(),earr[0].a.GetY(),earr[0].a.GetZ());
	    glVertex3f(earr[1].b.GetX(),earr[1].b.GetY(),earr[1].b.GetZ());
	    glVertex3f(earr[2].a.GetX(),earr[2].a.GetY(),earr[2].a.GetZ());
	break;
	case FBB:
	    glVertex3f(earr[0].a.GetX(),earr[0].a.GetY(),earr[0].a.GetZ());
	    glVertex3f(earr[1].b.GetX(),earr[1].b.GetY(),earr[1].b.GetZ());
	    glVertex3f(earr[2].b.GetX(),earr[2].b.GetY(),earr[2].b.GetZ());
	break;
	case BFB:
	    glVertex3f(earr[0].b.GetX(),earr[0].b.GetY(),earr[0].b.GetZ());
	    glVertex3f(earr[1].a.GetX(),earr[1].a.GetY(),earr[1].a.GetZ());
	    glVertex3f(earr[2].b.GetX(),earr[2].b.GetY(),earr[2].b.GetZ());
	break;
	case BBF:
	    glVertex3f(earr[0].b.GetX(),earr[0].b.GetY(),earr[0].b.GetZ());
	    glVertex3f(earr[1].b.GetX(),earr[1].b.GetY(),earr[1].b.GetZ());
	    glVertex3f(earr[2].a.GetX(),earr[2].a.GetY(),earr[2].a.GetZ());

	break;
	case BBB:
	    glVertex3f(earr[0].b.GetX(),earr[0].b.GetY(),earr[0].b.GetZ());
	    glVertex3f(earr[1].b.GetX(),earr[1].b.GetY(),earr[1].b.GetZ());
	    glVertex3f(earr[2].b.GetX(),earr[2].b.GetY(),earr[2].b.GetZ());
	break;
	default:
	    glVertex3f(earr[0].a.GetX(),earr[0].a.GetY(),earr[0].a.GetZ());
	    glVertex3f(earr[0].b.GetX(),earr[0].b.GetY(),earr[0].b.GetZ());
	    glVertex3f(earr[1].b.GetX(),earr[1].b.GetY(),earr[1].b.GetZ());
	    }
    }

    Vertex Face::LocateFinalVertex(Edge e)
    {
#ifdef PrintToConsole
	std::cout << "Locate final vertex called edge provided is " << e.ToString();
#endif

	for(int i = 0; i <3; i++)
	    {
	    if(earr[i] != e) // a more efficient implementation of this can be implemented if current array location is provided saving potential 1/3 time
		{
		    if( earr[i].a != e.a)
			{
			if( earr[i].a != e.b)
			    {
#ifdef PrintToConsole
	std::cout << "Final vertex found given vertex is : " << earr[i].a.ToString() << "\n" ;
#endif
			    return earr[i].a;
			    }
			}
		    else if(earr[i].b != e.a)
			{
			if( earr[i].b != e.b)
			    {
#ifdef PrintToConsole
	std::cout << "Final vertex found given vertex is : " << earr[i].b.ToString() << "\n" ;
#endif
			    return earr[i].b;
			    }
			}
		}
	    }

#ifdef PrintToConsole
	std::cout << "Final vertex no vertex found found!!!!!!!!!!!!! \n" ;
#endif
	//return NULL;
    }


    Edge Face::LocateEdge(Vertex a, Vertex b)
	{
#ifdef PrintToConsole
	std::cout << "Locate Edge called \n" ;
#endif
	    for(int i = 0; i < 3; ++i)
		{
#ifdef PrintToConsole
	std::cout << "Locate Edge iteration" << i << "of 3 \n" ;
	std::cout << "If "<< earr[i].a.ToString() << " == " << a.ToString() << " && " <<   earr[i].b.ToString() << " == " << b.ToString() << "\n";
	std::cout << "If "<< earr[i].a.ToString() << " == " << b.ToString() << " && " <<   earr[i].b.ToString() << " == " << a.ToString() << "\n";
#endif
		if(((earr[i].a == a) && (earr[i].b == b)) || ((earr[i].a == b) && (earr[i].b == a)))
		    return earr[i];
		}
	    throw -1;
	}

    int Face::LocateEdgeIndex(Vertex a, Vertex b)
	{
	    for(int i = 0; i < 3; ++i)
		{
		if(((earr[i].a == a) && (earr[i].b == b)) || ((earr[i].a == b) && (earr[i].b == a)))
		    return i;
		}
	    throw -1;
	}



    bool Face::Contains( Edge e)
	{
	    for(int i = 0; i < 3; i++)
		{
		    if(earr[i] == e)
			return true;
		}
	    return false;
	}

    string Face::ToString()
	{
	return " Face: "+ earr[0].ToString() + earr[1].ToString() + earr[2].ToString() + "\n";
	}

    bool Face::operator==(Face &inV)
    {
	return earr[0] == inV.earr[0] && earr[1] == inV.earr[1] && earr[2] == inV.earr[2] ? true : false;
	/* Lazy way is slow way...
	    for(int i = 0; i < 3; ++i)
		{
		earr[i] == inV.earr[i];
	}*/
    }
    bool Face::operator!=(Face &inV)
    {
	return earr[0] == inV.earr[0] && earr[1] == inV.earr[1] && earr[2] == inV.earr[2] ? false : true;
    }
    Face::~Face()
    {
    // TODO Auto-generated destructor stub
    }


}
