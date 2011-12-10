/*
 * Cube.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#define ExceptionTrapping


#include "../Header/Cube.h"

namespace Game
    {
		Cube::Cube()
		{
		Vertex v = Vertex(0, 0, 0);
		init(1, v);//default to a size one cube
		}

		Cube::Cube(float size)
		{

		Vertex v = Vertex(0, 0, 0);
		init(size, v );//default to a size one cube
		}


		Cube::Cube(float size, Vertex position)
		{
		init(size/2, position);
		}


		void Cube::init(float size, Vertex v)
		{

			visible = true;

			varr.push_back(Vertex(-size,-size,-size)); //Front Face Bottom Left
			varr.push_back(Vertex(-size, size,-size)); //Front Face Top Left
			varr.push_back(Vertex( size, size,-size)); //Front Face Top Right
			varr.push_back(Vertex( size,-size,-size)); //Front Face Bottom Right
			varr.push_back(Vertex(-size, size, size)); //Top Face Top Left
			varr.push_back(Vertex( size, size, size)); //Top Face Top Right
			varr.push_back(Vertex( size,-size, size)); //Right Face Bottom Right
			varr.push_back(Vertex(-size,-size, size)); //Back Face Bottom Right (if facing)

			earr.push_back(Edge(0,1)); //Front Face Left
			earr.push_back(Edge(1,2)); //Front Face Top
			earr.push_back(Edge(2,0)); //Front Face Diagonal
			earr.push_back(Edge(2,3)); //Front Face Right
			earr.push_back(Edge(3,0)); //Front Face Bottom
			earr.push_back(Edge(1,4)); //Top Face Left
			earr.push_back(Edge(4,5)); //Top Face Top
			earr.push_back(Edge(5,1)); //Top Face Diagonal
			earr.push_back(Edge(5,2)); //Top Face Right
			earr.push_back(Edge(5,3)); //Right Face Diagonal
			earr.push_back(Edge(5, 6)); //Right Face Right
			earr.push_back(Edge(6, 3)); //Right Face Bottom
			earr.push_back(Edge(4, 6)); //Rear Diagonal
			earr.push_back(Edge(4, 7)); //Rear Right (if facing)
			earr.push_back(Edge(7, 6)); //Rear Bottom
			earr.push_back(Edge(1, 7)); //Left Diagonal
			earr.push_back(Edge(0, 7)); //Left Bottom
			earr.push_back(Edge(3, 7)); //Bottom diagonal

			farr.push_back(Face3(0,1,2));      //Front Face Left Tri
			farr.push_back(Face3(2,3,4,BFF)); //Front Face Right Tri
			farr.push_back(Face3(5,6,7));    //Top Face Left Tri
			farr.push_back(Face3(7,8,1,BFB)); //Top Face Right
			farr.push_back(Face3(3,8,9,BBF)); //Right Face Left
			farr.push_back(Face3(9,10,11,BFF)); //Right Face Right
			farr.push_back(Face3(10,6,12,BBF)); //Back Face Left
			farr.push_back(Face3(12,13,14,BFF)); //Back Face Right
			farr.push_back(Face3(13,5,15,BBF)); //Left Face Left
			farr.push_back(Face3(15,0,16,BBF)); //Left Face Right
			farr.push_back(Face3(16,4,17,BBF)); //Bottom Face Left
			farr.push_back(Face3(17,11,14,BBB)); //Bottom Face Right

		   for(unsigned int i = 0; i < varr.size(); ++i)
			{
				FaceColor fc;
				fc.r = rand() % 255;
				fc.g  = rand() % 255;
				fc.b  = rand() % 255;
				faceColors.push_back(fc);
			}
		}

		Cube::~Cube()
		{
		// TODO Auto-generated destructor stub
		}

    }
