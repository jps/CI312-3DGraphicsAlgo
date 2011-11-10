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
	    delete [] farr;
	    delete [] earr;
	    delete [] varr;
	    /*varr = NULL;
	    earr = NULL;
	    farr = NULL;
*/
	// TODO Auto-generated destructor stub
	}

    GameObject SubspaceDivision()
	{
	   GameObject NGO = GameObject();
/*
	   int farrLength = sizeof( farr[] ) / sizeof( farr[0] );

	    for(int i = 0; i < farrLength; i++)
		{

		}*/
	    return NGO;
	}
    }

