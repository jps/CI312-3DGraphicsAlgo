/*
 * Cube.h
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "GameObject.h"

namespace Game
    {

    class Cube: public Game::GameObject
	{
    public:
	Cube();
	void Draw();
	virtual ~Cube();
	};

    }

#endif /* CUBE_H_ */
