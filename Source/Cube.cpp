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

			earr.push_back(Edge(0,1)); //Front Face Left               \\0
			earr.push_back(Edge(1,2)); //F2ront Face Top               \\1
			earr.push_back(Edge(2,0)); //Front Face Diagonal           \\2
			earr.push_back(Edge(2,3)); //Front Face Right              \\3
			earr.push_back(Edge(3,0)); //Front Face Bottom             \\4
			earr.push_back(Edge(1,4)); //Top Face Left                 \\5
			earr.push_back(Edge(4,5)); //Top Face Top                  \\6
			earr.push_back(Edge(5,1)); //Top Face Diagonal             \\7
			earr.push_back(Edge(5,2)); //Top Face Right                \\8
			earr.push_back(Edge(5,3)); //Right Face Diagonal           \\9
			earr.push_back(Edge(5, 6)); //Right Face Right             \\10
			earr.push_back(Edge(6, 3)); //Right Face Bottom            \\11
			earr.push_back(Edge(4, 6)); //Rear Diagonal                \\12
			earr.push_back(Edge(4, 7)); //Rear Right (if facing)       \\13
			earr.push_back(Edge(7, 6)); //Rear Bottom                  \\14
			earr.push_back(Edge(1, 7)); //Left Diagonal                \\15
			earr.push_back(Edge(0, 7)); //Left Bottom                  \\16
			earr.push_back(Edge(3, 7)); //Bottom diagonal              \\17

/*
			farr4.push_back(Face4(0,1,3,4)); 								//front
			farr4.push_back(Face4(5,6,8,1, true, true, true, false));       //top
			farr4.push_back(Face4(3,8,10,11,false,false,true, true));       //right
			farr4.push_back(Face4(10,6,13,14, false, false, true, true ));  //back
			farr4.push_back(Face4(13,5,0,16, false,false,false,true));
			farr4.push_back(Face4(16,4,11,14,false,false,false,false));
*/

			farr.push_back(Face3(0, 1, 2));                       //Front Face Left Tri
			farr.push_back(Face3(2, 3, 4,  false, true, true));   //Front Face Right Tri
			farr.push_back(Face3(5, 6, 7));    					  //Top Face Left Tri
			farr.push_back(Face3(7, 8, 1,  false, true,  false)); //Top Face Right
			farr.push_back(Face3(3, 8, 9,  false, false, true));  //Right Face Left
			farr.push_back(Face3(9, 10,11, false, true,  true));  //Right Face Right
			farr.push_back(Face3(10,6, 12, false, false, true));  //Back Face Left
			farr.push_back(Face3(12,13,14, false, true,  true));  //Back Face Right
			farr.push_back(Face3(13,5, 15, false, false, true));  //Left Face Left
			farr.push_back(Face3(15,0, 16, false, false, true));  //Left Face Right
			farr.push_back(Face3(16,4, 17, false, false,  true));  //Bottom Face Left
			farr.push_back(Face3(17,11,14, false, false, false)); //Bottom Face Right


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
