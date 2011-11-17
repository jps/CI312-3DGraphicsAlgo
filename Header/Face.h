/*
 * Face.h
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */
#include "Edge.h"
#include "Vertex.h"
#include <GL/gl.h>
#include <string>

//#define PrintToConsole
#include <iostream>

#ifndef FACE_H_
#define FACE_H_

using namespace std;

namespace Game
    {

    enum EdgeDirection { FFF, BFF, FBF, FFB, BBF, FBB, BFB, BBB};//not entirely sure if this is the best approach... bit array would be cheaper

    class Face
	{
    public:
	Face();
	Face(Edge A, Edge B, Edge C);
	Face(Edge A, Edge B, Edge C, EdgeDirection faceDirection);
	virtual ~Face();
	void Draw();
	EdgeDirection edgeDirection;
	Edge earr[3];
	Vertex LocateFinalVertex(Edge e);
	Edge LocateEdge(Vertex a, Vertex b);
	int LocateEdgeIndex(Vertex a, Vertex b);
	bool isForward (int EdgeIndex);
	bool Contains(Edge e);
	string ToString();
	bool operator==(Face &inV);
	bool operator!=(Face &inV);

    private:
	//implemented only for triangles at the moment. huh ?
	//Edge a;
	//Edge b;
	//Edge c;
	};
    }
#endif /* FACE_H_ */
