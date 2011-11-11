/*
 * Face.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "Face.h"

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

    Vertex Face::LocateFinalVetex(Edge e)
    {

	for(int i = 0; i <3; i++)
	    {
	    if(earr[i] != e) // a more efficent implentation of this can be provided if current array location is provided saving potential 1/3 time
		{
		    if( earr[i].a != e.a)
			{
			if( earr[i].a != e.b)
			    {
			    //break;
			    return earr[i].a;
			    }
			}
		    else if(earr[i].b != e.a)
			{
			if( earr[i].b != e.b)
			    {
			    return earr[i].b;
			    }
			}
		}
	    }
	/*
	   for(int i = 0; i < 3; i++)
			{
			if(i != ei)// can't be located on current edge - skip
			    {
			    if(farr[fi].earr[i].a != a[0])//consider renaming vars because this looks horrible...
				{
				if(farr[fi].earr[i].b != (a[0]))
				    {
#ifdef PrintToConsole
				    cout << "b[0] has been set for face: "<< fi << " edge:" << ei << "\n";
#endif
				    b[0] = farr[fi].earr[i].a;
				    break;
				    }
				}
			    else if(farr[fi].earr[i].a != (a[1]))
				{
				if(farr[fi].earr[i].b != (a[1]))
				    {
#ifdef PrintToConsole
				    cout << "b[0] has been set for face: "<< fi << " edge:" << ei << "\n";
#endif
				    b[0] = farr[fi].earr[i].b;
				    break;
				    }
				}
			    }
			}
	 */
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
