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

			earr.push_back(Edge(&varr[0], &varr[1])); //Front Face Left
			earr.push_back(Edge(&varr[1], &varr[2])); //Front Face Top
			earr.push_back(Edge(&varr[2], &varr[0])); //Front Face Diagonal
			earr.push_back(Edge(&varr[2], &varr[3])); //Front Face Right
			earr.push_back(Edge(&varr[3], &varr[0])); //Front Face Bottom
			earr.push_back(Edge(&varr[1], &varr[4])); //Top Face Left
			earr.push_back(Edge(&varr[4], &varr[5])); //Top Face Top
			earr.push_back(Edge(&varr[5], &varr[1])); //Top Face Diagonal
			earr.push_back(Edge(&varr[5], &varr[2])); //Top Face Right
			earr.push_back(Edge(&varr[5], &varr[3])); //Right Face Diagonal
			earr.push_back( Edge(&varr[5], &varr[6])); //Right Face Right
			earr.push_back( Edge(&varr[6], &varr[3])); //Right Face Bottom
			earr.push_back( Edge(&varr[4], &varr[6])); //Rear Diagonal
			earr.push_back( Edge(&varr[4], &varr[7])); //Rear Right (if facing)
			earr.push_back( Edge(&varr[7], &varr[6])); //Rear Bottom
			earr.push_back( Edge(&varr[1], &varr[7])); //Left Diagonal
			earr.push_back( Edge(&varr[0], &varr[7])); //Left Bottom
			earr.push_back( Edge(&varr[3], &varr[7])); //Bottom diagonal

			farr.push_back(Face(&earr[0], &earr[1],  &earr[2]));      //Front Face Left Tri
			farr.push_back(Face(&earr[2], &earr[3],  &earr[4],BFF)); //Front Face Right Tri
			farr.push_back(Face(&earr[5], &earr[6],  &earr[7]));    //Top Face Left Tri
			farr.push_back(Face(&earr[7], &earr[8],  &earr[1],BFB)); //Top Face Right
			farr.push_back(Face(&earr[3], &earr[8],  &earr[9],BBF)); //Right Face Left
			farr.push_back(Face(&earr[9], &earr[10], &earr[11],BFF)); //Right Face Right
			farr.push_back(Face(&earr[10],&earr[6],  &earr[12],BBF)); //Back Face Left
			farr.push_back(Face(&earr[12],&earr[13], &earr[14],BFF)); //Back Face Right
			farr.push_back(Face(&earr[13],&earr[5],  &earr[15],BBF)); //Left Face Left
			farr.push_back(Face(&earr[15],&earr[0],  &earr[16],BBF)); //Left Face Right
			farr.push_back(Face(&earr[16],&earr[4],  &earr[17],BBF)); //Bottom Face Left
			farr.push_back(Face(&earr[17],&earr[11], &earr[14],BBB)); //Bottom Face Right

		   for(unsigned int i = 0; i < varr.size(); ++i)
			{
				FaceColor fc;
				fc.r = rand() % 255;
				fc.g  = rand() % 255;
				fc.b  = rand() % 255;
				faceColors.push_back(fc);
			}
		}

		void Cube::Draw()
		{
			for(int i = 0; i < 12; ++i)
			{
				glColor3ub(faceColors[i].r, faceColors[i].g, faceColors[i].b);
				farr[i].Draw();
			}
		}

		Cube::~Cube()
		{
		// TODO Auto-generated destructor stub
		}

    }
