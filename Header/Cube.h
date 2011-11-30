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



    class Cube: public Game::GameObject
	{
    public:

	//struct EdgeFaces;

	Cube();
	Cube(float size);
	Cube(float size, Vertex v);

	void Draw();
	virtual ~Cube();

	/*Vertex varr[8];
	Edge earr[18];
	Face farr[12];*/
	GameObject ButterflySubSpaceDivisionold();

    private:
	void init(float size, Vertex v);
	int r[12], g[12], b[12];
	Vertex ButterflyCalculateNewVertex(ControlPoints controlPoints);
	//EdgeFaces* FindEdgeFaces(int el, int fl, Edge earr[], Face farr[]);
	};
    }

#endif /* CUBE_H_ */
