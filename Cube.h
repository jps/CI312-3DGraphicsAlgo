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


using namespace std;

namespace Game
    {

    class Cube: public Game::GameObject
	{
    public:
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
	};
    }

#endif /* CUBE_H_ */
