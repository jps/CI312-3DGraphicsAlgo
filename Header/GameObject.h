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
#include "Face3.h"
#include "Face4.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "EdgesFaces.h"
#include <stdlib.h>

namespace Game
    {

    class GameObject
	{
	    public:
	struct ControlPoints
		{
		    Vertex a[2];
		    Vertex b[2];
		    Vertex c[4];
		    //Vertex d[2];
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
		Face3 nfs[4];
		Vertex nvs[3];
		Vertex ovs[3];
	    };


	struct FaceColor
	    {
	    int r;
	    int g;
	    int b;
	    };



	GameObject();
	GameObject(const Vertex *Varr,const Edge *Earr, const Face3 *Farr);
	virtual ~GameObject();

	bool visible;
	Vertex transformBy;

	vector<Vertex> varr;
	vector<Edge> earr;
	vector<Face3> farr;
	vector<Face4> farr4;//this isn't very clean but will hold for now


	void Transform(Vertex v);

	void Draw();

	GameObject ButterflySubSpaceDivision();


	void init();
	protected:
	vector<FaceColor> faceColors;
	private:

	};





    }

#endif /* GAMEOBJECT_H_ */
