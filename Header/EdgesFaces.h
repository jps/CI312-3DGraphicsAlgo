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

    struct EdgeFace
	{
	public:
    	EdgeFace();
		EdgeFace(Edge E, Face Faces[2]);
		Edge e;
		Face f[2];
	};

	struct EdgeFaceCentroid : public EdgeFace
	{
		EdgeFaceCentroid();
		EdgeFaceCentroid(Edge E, FaceCentroid Faces[2]);
		Vertex centroid[2];
		Vertex edgeControlPoint;
		FaceCentroid f[2];
	};


    class EdgesFaces
	{
    public:

		vector<EdgeFaces> efsv;
		EdgesFaces();
		EdgesFaces(vector<Edge> earr, vector<Face> farr);
		virtual ~EdgesFaces();
		Face FindFace(Edge e, Face f);
	};

    class EdgesFacesCentroid:EdgesFaces
    {
    public:
    	vector<EdgeFaceCentroid> efsv;
    	EdgesFacesCentroid();
    	Vertex FindFaceCentroid(Edge e, Face f);
    	EdgesFacesCentroid(vector<Edge> earr, vector<FaceCentroid> farr);
		virtual ~EdgesFacesCentroid();
		//Face FindFace(Edge e, Face f);
    };


    }

#endif /* EDGESFACES_H_ */
