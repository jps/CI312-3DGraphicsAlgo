/*
 * Cube.h
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "GameObject.h"
#include <stdlib.h>

#define PrintToConsole
#include <iostream>

using namespace std;

namespace Game
    {

struct ControlPoints
	{
	    Vertex a[2];
	    Vertex b[2];
	    Vertex c[4];
	    Vertex d[2];
	};

struct EdgeEdges
	{
	    Edge parent; //TODO: these can be pointers
	    Edge children[2];
	};

struct FaceSplit
    {
    //TODO: Review could this be a collection of pointers to the new object to minimize memory consuption.
	bool direction[3];
	Edge nes[9];
	Face nfs[4];
	Vertex nvs[3];
	Vertex ovs[3];
    };


    class Cube: public Game::GameObject
	{
    public:

	//struct EdgeFaces;

	Cube();
	Cube(float size);
	Cube(float size, Vertex v);

	void Draw();
	virtual ~Cube();

	Vertex varr[8];
	Edge earr[18];
	Face farr[12];
	GameObject ButterflySubSpaceDivision();

    private:
	void init(float size, Vertex v);
	int r[12], g[12], b[12];
	Vertex ButterflyCalculateNewVertex(ControlPoints controlPoints);
	//EdgeFaces* FindEdgeFaces(int el, int fl, Edge earr[], Face farr[]);
	};
    }

#endif /* CUBE_H_ */
