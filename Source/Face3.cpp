/*
 * Face.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "../Header/Face3.h"

//#define PrintToConsole

namespace Game
    {


    Face3::Face3()
    {

    }


    Face3::Face3(int A, int B, int C, bool EdgeDirection[3])
    {
    earr[0] = A;
    earr[1] = B;
    earr[2] = C;
    edgeDirection[0] = EdgeDirection[0];
	edgeDirection[1] = EdgeDirection[1];
	edgeDirection[2] = EdgeDirection[2];
    }

    Face3::Face3(int A, int B, int C, bool EDA, bool EDB, bool EDC)
    {
    earr[0] = A;
    earr[1] = B;
    earr[2] = C;
    edgeDirection[0] = EDA;
	edgeDirection[1] = EDB;
	edgeDirection[2] = EDC;
    }


    Face3::Face3(int A, int B, int C)
    {
    earr[0] = A;
    earr[1] = B;
    earr[2] = C;
    edgeDirection[0] = true;
	edgeDirection[1] = true;
	edgeDirection[2] = true;
    }

/*
    void Face::Draw()
    {
	switch(edgeDirection)
	    {
	case FFB:

	    glVertex3f(earr[0]->a->GetX(),earr[0]->a->GetY(),earr[0]->a->GetZ());
	    glVertex3f(earr[1]->a->GetX(),earr[1]->a->GetY(),earr[1]->a->GetZ());
	    glVertex3f(earr[2]->b->GetX(),earr[2]->b->GetY(),earr[2]->b->GetZ());
	break;
	case BFF:
	    glVertex3f(earr[0]->b->GetX(),earr[0]->b->GetY(),earr[0]->b->GetZ());
	    glVertex3f(earr[1]->a->GetX(),earr[1]->a->GetY(),earr[1]->a->GetZ());
	    glVertex3f(earr[2]->a->GetX(),earr[2]->a->GetY(),earr[2]->a->GetZ());
	break;
	case FBF:
	    glVertex3f(earr[0]->a->GetX(),earr[0]->a->GetY(),earr[0]->a->GetZ());
	    glVertex3f(earr[1]->b->GetX(),earr[1]->b->GetY(),earr[1]->b->GetZ());
	    glVertex3f(earr[2]->a->GetX(),earr[2]->a->GetY(),earr[2]->a->GetZ());
	break;
	case FBB:
	    glVertex3f(earr[0]->a->GetX(),earr[0]->a->GetY(),earr[0]->a->GetZ());
	    glVertex3f(earr[1]->b->GetX(),earr[1]->b->GetY(),earr[1]->b->GetZ());
	    glVertex3f(earr[2]->b->GetX(),earr[2]->b->GetY(),earr[2]->b->GetZ());
	break;
	case BFB:
	    glVertex3f(earr[0]->b->GetX(),earr[0]->b->GetY(),earr[0]->b->GetZ());
	    glVertex3f(earr[1]->a->GetX(),earr[1]->a->GetY(),earr[1]->a->GetZ());
	    glVertex3f(earr[2]->b->GetX(),earr[2]->b->GetY(),earr[2]->b->GetZ());
	break;
	case BBF:
	    glVertex3f(earr[0]->b->GetX(),earr[0]->b->GetY(),earr[0]->b->GetZ());
	    glVertex3f(earr[1]->b->GetX(),earr[1]->b->GetY(),earr[1]->b->GetZ());
	    glVertex3f(earr[2]->a->GetX(),earr[2]->a->GetY(),earr[2]->a->GetZ());
	break;
	case BBB:
	    glVertex3f(earr[0]->b->GetX(),earr[0]->b->GetY(),earr[0]->b->GetZ());
	    glVertex3f(earr[1]->b->GetX(),earr[1]->b->GetY(),earr[1]->b->GetZ());
	    glVertex3f(earr[2]->b->GetX(),earr[2]->b->GetY(),earr[2]->b->GetZ());
	break;
	default:
	    glVertex3f(earr[0]->a->GetX(),earr[0]->a->GetY(),earr[0]->a->GetZ());
	    glVertex3f(earr[0]->b->GetX(),earr[0]->b->GetY(),earr[0]->b->GetZ());
	    glVertex3f(earr[1]->b->GetX(),earr[1]->b->GetY(),earr[1]->b->GetZ());
	    }
    }
*/
    /*
    Vertex Face::LocateFinalVertex(Edge e)
    {
#ifdef PrintToConsole
	std::cout << "Locate final vertex called edge provided is " << e.ToString();
#endif

	for(int i = 0; i <3; i++)
	    {
	    if(*earr[i] != e) // a more efficient implementation of this can be implemented if current array location is provided saving potential 1/3 time
		{
		    if( earr[i]->a != e.a)
			{
			if( earr[i]->a != e.b)
			    {
#ifdef PrintToConsole
	std::cout << "Final vertex found given vertex is : " << earr[i].a.ToString() << "\n" ;
#endif
			    return *earr[i]->a;
			    }
			}
		    else if(earr[i]->b != e.a)
			{
			if( earr[i]->b != e.b)
			    {
#ifdef PrintToConsole
	std::cout << "Final vertex found given vertex is : " << earr[i].b.ToString() << "\n" ;
#endif
			    return *earr[i]->b;
			    }
			}
		}
	    }

#ifdef PrintToConsole
	std::cout << "Final vertex no vertex found found!!!!!!!!!!!!! \n" ;
#endif
	throw "Final Vertex not found invalid edge passed into face";
    }

    Vertex Face::CaluclateCenteroid()
	{
	//TODO: review Alternately could find midpoint of all edges and then find the midpoint of all edges then divide by 3
	if( earr[1]->a != earr[0]->a && earr[1]->a != earr[0]->b)
	    return Vertex(earr[0]->a->GetX() + earr[0]->b->GetX() + earr[1]->a->GetX() / 3, earr[0]->a->GetY() + earr[0]->b->GetY() + earr[1]->a->GetY() / 3,earr[0]->a->GetZ() + earr[0]->b->GetZ() + earr[1]->a->GetZ() /3 );
	if( earr[1]->b != earr[0]->a && earr[1]->b != earr[0]->b)
	    return Vertex(earr[0]->a->GetX() + earr[0]->b->GetX() + earr[1]->b->GetX() / 3, earr[0]->a->GetY() + earr[0]->b->GetY() + earr[1]->b->GetY() / 3,earr[0]->a->GetZ() + earr[0]->b->GetZ() + earr[1]->b->GetZ() /3 );
	std::cout << "Calculating the centeroid has failed..... edges provided" << earr[0]->ToString() << earr[0]->ToString() << earr[0]->ToString() << "\n";
	throw "calculating centroid has failed";
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
		if(((*earr[i]->a == a) && (*earr[i]->b == b)) || ((*earr[i]->a == b) && (*earr[i]->b == a)))
		    return *earr[i];
		}
	    throw -1;
	}
*/
    int Face3::LocateEdgeIndex(int a, int b)
	{
	    for(int i = 0; i < 3; ++i)
		{
		if(((earr[i] == a) && (earr[i] == b)) || ((earr[i] == b) && (earr[i] == a)))
		    return i;
		}
	    throw -1;
	}

    bool Face3::Contains(int e)
	{
	    for(int i = 0; i < 3; i++)
		{
		    if(earr[i] == e)
			return true;
		}
	    return false;
	}

//#define isForwardDebug

    bool Face3::isForward (int EdgeIndex)
	{
		return edgeDirection[EdgeIndex];
	}

    string Face3::ToString()
	{
    	//todo: fix
	return " Face edges : a: broken fix";//"+ earr[0] + " b: " + earr[1] + " c: " +  earr[2] + "\n";
	}
/*
    bool Face::operator==(Face &inV)
    {
	return earr[0] == inV.earr[0] && earr[1] == inV.earr[1] && earr[2] == inV.earr[2] ? true : false;
	/* Lazy way is slow way...
	    for(int i = 0; i < 3; ++i)
		{
		earr[i] == inV.earr[i];
	}*/
  /*  }
    bool Face::operator!=(Face &inV)
    {
	return earr[0] == inV.earr[0] && earr[1] == inV.earr[1] && earr[2] == inV.earr[2] ? false : true;
    }*/
    Face3::~Face3()
    {
    // TODO Auto-generated destructor stub
    }
/*
    FaceCentroid::FaceCentroid(Face f)
    {
    	earr[0] = f.earr[0];
    	earr[1] = f.earr[1];
    	earr[2] = f.earr[2];
    	edgeDirection = f.edgeDirection;
    	centroid = f.CaluclateCenteroid();
    }*/



}
