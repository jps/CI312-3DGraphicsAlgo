/*
 * Edge.h
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "Vertex.h"

#ifndef EDGE_H_
#define EDGE_H_

namespace Game
{
    class Edge
	{
    public:
	Edge();
	Edge(Vertex A, Vertex B);
	Vertex MidPoint();

	virtual ~Edge();

	//TODO: should this be broken to getterSetter for protection...
	Vertex a;
	Vertex b;

	bool operator==(Edge &inV);
	bool operator!=(Edge &inV);


    private:



	};
};
#endif /* EDGE_H_ */
