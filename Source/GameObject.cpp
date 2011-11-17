/*
 * GameObject.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#include "../Header/GameObject.h"



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

    GameObject GameObject::SubspaceDivision()
	{
	   GameObject NGO = GameObject();



/*
	   int farrLength = sizeof( farr[] ) / sizeof( farr[0] );

	    for(int i = 0; i < farrLength; i++)
		{

		}*/
	    return NGO;
	}

    void GameObject::Draw()
	{
	    for(unsigned int i = 0; i < farr.size(); ++i)
		{
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

