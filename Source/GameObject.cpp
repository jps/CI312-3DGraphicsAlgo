/*
 * GameObject.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#include "../Header/GameObject.h"

#define PrintToConsole


//#define hardDebugVertexVals //turn this off!!!!!

namespace Game
    {

    GameObject::GameObject(const Vertex * Varr, const Edge Earr[], const Face3 Farr[])
	{

	    //varr = new Vertex[sizeof( Varr ) / sizeof( Varr[0] )];
	    //earr = new Edge[sizeof( Earr ) / sizeof( Earr[0] )];
	    //farr = new Face[sizeof( Farr ) / sizeof( Farr[0] )];

//	    varr= Varr;

	}

    GameObject::GameObject()
	{
		visible = true;
		transformBy = Vertex( 0.0f,0.0f,0.0f);
	}

    GameObject::~GameObject()
	{
	   // delete farr;
	   // delete earr;
	   // delete varr;
	}

    void GameObject::init()
	{
	   for(unsigned int i = 0; i < varr.size(); ++i)
		{
		    FaceColor fc;
		    fc.r = rand() % 255;
		    fc.g  = rand() % 255;
		    fc.b  = rand() % 255;
		    faceColors.push_back(fc);
		}
	}




    void GameObject::Draw()
	{
	    for(unsigned int i = 0; i < farr.size(); ++i)
		{
	    glColor3ub(faceColors[i].r,faceColors[i].g,faceColors[i].b);
	    if(farr[i].edgeDirection[0])
	    	glVertex3f(varr[earr[farr[i].earr[0]].a].GetX(),varr[earr[farr[i].earr[0]].a].GetY(),varr[earr[farr[i].earr[0]].a].GetZ());
	    else
	    	glVertex3f(varr[earr[farr[i].earr[0]].b].GetX(),varr[earr[farr[i].earr[0]].b].GetY(),varr[earr[farr[i].earr[0]].b].GetZ());
		if(farr[i].edgeDirection[1])
			glVertex3f(varr[earr[farr[i].earr[1]].a].GetX(),varr[earr[farr[i].earr[1]].a].GetY(),varr[earr[farr[i].earr[1]].a].GetZ());
		else
			glVertex3f(varr[earr[farr[i].earr[1]].b].GetX(),varr[earr[farr[i].earr[1]].b].GetY(),varr[earr[farr[i].earr[1]].b].GetZ());
		if(farr[i].edgeDirection[2])
			glVertex3f(varr[earr[farr[i].earr[2]].a].GetX(),varr[earr[farr[i].earr[2]].a].GetY(),varr[earr[farr[i].earr[2]].a].GetZ());
		else
			glVertex3f(varr[earr[farr[i].earr[2]].b].GetX(),varr[earr[farr[i].earr[2]].b].GetY(),varr[earr[farr[i].earr[2]].b].GetZ());
		}
	}


/*
    void GameObject::Draw(int a)
	{

	    for(unsigned int i = 0; i < farr.size(); ++i)
		{

#ifdef hardDebugVertexVals

	    for(unsigned int b = 0; b < 3; ++b)
		{
		farr[i].earr[b].a.ToString();
		farr[i].earr[b].b.ToString();
		}
#endif

		    if(i%a == 0)
		    	glColor3ub(faceColors[i].r,faceColors[i].g,faceColors[i].b);
		    farr[i].Draw();
		}
	}*/


/*
    struct ControlPoints
	{
	    Vertex a[2];
	    Vertex b[2];
	    Vertex c[4];
	    Vertex d[2];
	};
*/
    }

