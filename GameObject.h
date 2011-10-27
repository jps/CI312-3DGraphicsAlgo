/*
 * GameObject.h
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

namespace Game
    {

    class GameObject
	{
    public:
	GameObject();
	virtual ~GameObject();

	Vertex varr[8];
	Edge earr[18];
	Face farr[8];

	void Draw();

	};

    }

#endif /* GAMEOBJECT_H_ */
