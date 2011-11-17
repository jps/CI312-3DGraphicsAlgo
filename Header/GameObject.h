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
#include <stdlib.h>

namespace Game
    {

    class GameObject
	{

	struct FaceColor
	    {
	    int r;
	    int g;
	    int b;
	    };


    public:
	GameObject();
	GameObject(const Vertex *Varr,const Edge *Earr, const Face *Farr);
	virtual ~GameObject();

	bool visible;
	Vertex transformBy;

	vector<Vertex> varr;
	vector<Edge> earr;
	vector<Face> farr;


	void Transform(Vertex v);

	void Draw();

	GameObject SubspaceDivision();

	void init();
	private:
	vector<FaceColor> faceColors;
	};





    }

#endif /* GAMEOBJECT_H_ */
