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

    GameObject::GameObject(const Vertex * Varr, const Edge Earr[], const Face Farr[])
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


#ifdef hardDebugVertexVals
	    for(unsigned int b = 0; b < 3; ++b)
		{
		cout << farr[i].earr[b].a.ToString() << "\n";
		cout << farr[i].earr[b].b.ToString() << "\n";
		}
#endif

		    glColor3ub(faceColors[i].r,faceColors[i].g,faceColors[i].b);
		    farr[i].Draw();
		}
	}

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
	}


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

