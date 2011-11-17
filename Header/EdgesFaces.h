/*
 * EdgesFaces.h
 *
 *  Created on: Nov 14, 2011
 *      Author: Panda
 */

#ifndef EDGESFACES_H_
#define EDGESFACES_H_

#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include <vector>
#include "EdgeFaces.h"

//#define PrintToConsole
#include <iostream>

using namespace std;

namespace Game
    {

    class EdgesFaces
	{
    public:
	std::vector<EdgeFaces> efsv;
	EdgesFaces(vector<Edge> earr, vector<Face> farr);
	EdgesFaces(Edge earr[], Face farr[], int el, int fl);
	virtual ~EdgesFaces();
	Face FindFace(Edge e, Face f);
	};

    }

#endif /* EDGESFACES_H_ */
