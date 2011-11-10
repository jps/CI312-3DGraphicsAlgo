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
    a = A;
    b = B;
    c = C;
    edgeDirection = FFF;
    }

    Face::Face(Edge A, Edge B, Edge C, EdgeDirection EdgeDirection)
    {
    a = A;
    b = B;
    c = C;
    edgeDirection = EdgeDirection;

    }

    void Face::Draw()
    {
	switch(edgeDirection)
	    {
	case FFB:
	    glVertex3f(a.a.GetX(),a.a.GetY(),a.a.GetZ());
	    glVertex3f(b.a.GetX(),b.a.GetY(),b.a.GetZ());
	    glVertex3f(c.b.GetX(),c.b.GetY(),c.b.GetZ());
	break;
	case BFF:
	    glVertex3f(a.b.GetX(),a.b.GetY(),a.b.GetZ());
	    glVertex3f(b.a.GetX(),b.a.GetY(),b.a.GetZ());
	    glVertex3f(c.a.GetX(),c.a.GetY(),c.a.GetZ());
	break;
	case FBF:
	    glVertex3f(a.a.GetX(),a.a.GetY(),a.a.GetZ());
	    glVertex3f(b.b.GetX(),b.b.GetY(),b.b.GetZ());
	    glVertex3f(c.a.GetX(),c.a.GetY(),c.a.GetZ());
	break;
	case FBB:
	    glVertex3f(a.a.GetX(),a.a.GetY(),a.a.GetZ());
	    glVertex3f(b.b.GetX(),b.b.GetY(),b.b.GetZ());
	    glVertex3f(c.b.GetX(),c.b.GetY(),c.b.GetZ());
	break;
	case BFB:
	    glVertex3f(a.b.GetX(),a.b.GetY(),a.b.GetZ());
	    glVertex3f(b.a.GetX(),b.a.GetY(),b.a.GetZ());
	    glVertex3f(c.b.GetX(),c.b.GetY(),c.b.GetZ());
	break;
	case BBF:
	    glVertex3f(a.b.GetX(),a.b.GetY(),a.b.GetZ());
	    glVertex3f(b.b.GetX(),b.b.GetY(),b.b.GetZ());
	    glVertex3f(c.a.GetX(),c.a.GetY(),c.a.GetZ());

	break;
	case BBB:
	    glVertex3f(a.b.GetX(),a.b.GetY(),a.b.GetZ());
	    glVertex3f(b.b.GetX(),b.b.GetY(),b.b.GetZ());
	    glVertex3f(c.b.GetX(),c.b.GetY(),c.b.GetZ());
	break;
	default:
	    glVertex3f(a.a.GetX(),a.a.GetY(),a.a.GetZ());
	    glVertex3f(a.b.GetX(),a.b.GetY(),a.b.GetZ());
	    glVertex3f(b.b.GetX(),b.b.GetY(),b.b.GetZ());
	    }
    }

    Face::~Face()
    {
    // TODO Auto-generated destructor stub
    }


}
