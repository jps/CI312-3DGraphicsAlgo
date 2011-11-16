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
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "EdgesFaces.h"

namespace Game
    {

    class GameObject
	{
    public:
	GameObject();
	GameObject(const Vertex *Varr,const Edge *Earr, const Face *Farr);
	virtual ~GameObject();

	bool visible;
	Vertex transformBy;

	std::vector<Vertex> varr;
	std::vector<Edge> earr;
	std::vector<Face> farr;

//	Vertex varr[];
//	Edge earr[];
//	Face farr[];

	void Transform(Vertex v);

	void Draw();

	GameObject SubspaceDivision();

	};





    }

#endif /* GAMEOBJECT_H_ */
