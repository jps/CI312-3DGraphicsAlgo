/*
 * GameObject.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#include "GameObject.h"



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
		    glColor3ub(i%256,i%256,i%256);
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

