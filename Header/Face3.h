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
#include "Face.h"

//#define PrintToConsole
#include <iostream>

#ifndef FACE3_H_
#define FACE3_H_

using namespace std;

namespace Game
    {
	// change to an array of bits
    //enum EdgeDirection { FFF, BFF, FBF, FFB, BBF, FBB, BFB, BBB};//not entirely sure if this is the best approach... bit array would be cheaper

    class Face3
	{
    public:
		Face3();
	/*
		Face(Edge& A, Edge& B, Edge& C);
		Face(Edge* A, Edge* B, Edge* C); //TODO: Remove Deprecated pass by reference is safer
		Face(Edge* A, Edge* B, Edge* C, EdgeDirection faceDirection);//TODO: Remove Deprecated pass by reference is safer
		Face(Edge& A, Edge& B, Edge& C, EdgeDirection faceDirection);*/
		bool edgeDirection[3];
		Face3(int A, int B, int C);
		Face3(int A, int B, int C, bool EdgeDirection[3]);
		Face3(int A, int B, int C, bool EDA, bool EDB, bool EDC);
		virtual ~Face3();
		//void Draw();
		int earr[3];
		/*Edge LocateEdge(Vertex a, Vertex b);
		Vertex LocateFinalVertex(Edge e);
		Vertex CaluclateCenteroid();*/
		bool isForward (int EdgeIndex);
		int LocateEdgeIndex(int a, int b);
		bool Contains(int e);
		string ToString();
		/*bool operator==(Face &inV);
		bool operator!=(Face &inV);
*/
    private:
	//implemented only for triangles at the moment. huh ?
	//Edge a;
	//Edge b;
	//Edge c;
	};



    }
#endif /* FACE_H_ */
