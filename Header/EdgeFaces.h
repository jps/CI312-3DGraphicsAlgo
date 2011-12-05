/*
 * EdgeFaces.h
 *
 *  Created on: Nov 14, 2011
 *      Author: Panda
 */

#ifndef EDGEFACES_H_
#define EDGEFACES_H_

#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

namespace Game
{

	class EdgeFaces
	{
	public:
		EdgeFaces();
		EdgeFaces(Edge E, Face Faces[2]);
		Edge e;
		Face f[2];
		virtual ~EdgeFaces();
	};


}

#endif /* EDGEFACES_H_ */
