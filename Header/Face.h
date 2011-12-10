/*
 * Face.h
 *
 *  Created on: Dec 10, 2011
 *      Author: Panda
 */

#include "Edge.h"
#include "Vertex.h"

#ifndef FACE_H_
#define FACE_H_

namespace Game
{

class Face
{
public:
	bool edgeDirection[4];
	int earr[4];
	Face();
	virtual ~Face();
};

}

#endif /* FACE_H_ */
