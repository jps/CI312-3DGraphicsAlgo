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
	//Edge(Vertex& A, Vertex& B);
	//Edge(Vertex* A, Vertex* B);
	Edge(int a, int b);

	Vertex MidPoint();

	virtual ~Edge();

	//TODO: should this be broken to getterSetter for protection...
//	Vertex* a;
//	Vertex* b;
	int a;
	int b;


	string ToString();
	bool operator==(Edge &inV);
	bool operator!=(Edge &inV);
	int Compare (Edge &inV);

    private:



	};
};
#endif /* EDGE_H_ */
