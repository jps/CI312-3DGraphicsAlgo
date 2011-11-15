/*
 * Edge.h
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "Vertex.h"
#include <string>

#ifndef EDGE_H_
#define EDGE_H_



using namespace std;

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


	string ToString();
	bool operator==(Edge &inV);
	bool operator!=(Edge &inV);


    private:



	};
};
#endif /* EDGE_H_ */
