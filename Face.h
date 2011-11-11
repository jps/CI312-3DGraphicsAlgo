/*
 * Face.h
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */
#include "Edge.h"
#include "Vertex.h"
#include <GL/gl.h>

#ifndef FACE_H_
#define FACE_H_

namespace Game
    {

    enum EdgeDirection { FFF, BFF, FBF, FFB, BBF, FBB, BFB, BBB};//not entirely sure if this is the best approach...

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
	bool Contains(Edge e);

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
