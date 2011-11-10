/*
 * Cube.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#include "Cube.h"

namespace Game
    {

    Cube::Cube()
	{
	Vertex v = Vertex(0, 0, 0);
	init(0.5, v);//default to a size one cube
	}

    Cube::Cube(float size)
	{

	Vertex v = Vertex(0, 0, 0);
	init(size/2, v );//default to a size one cube
	}


    Cube::Cube(float size, Vertex position)
	{
	init(size/2, position);
	}


    void Cube::init(float size, Vertex v)
	{

	    varr[0] = Vertex(-size,-size,-size); //Front Face Bottom Left
	    varr[1] = Vertex(-size, size,-size); //Front Face Top Left
	    varr[2] = Vertex( size, size,-size); //Front Face Top Right
	    varr[3] = Vertex( size,-size,-size); //Front Face Bottom Right
	    varr[4] = Vertex(-size, size, size); //Top Face Top Left
	    varr[5] = Vertex( size, size, size); //Top Face Top Right
	    varr[6] = Vertex( size,-size, size); //Right Face Bottom Right
	    varr[7] = Vertex(-size,-size, size); //Back Face Bottom Right (if facing)

	    earr[0] = Edge(varr[0], varr[1]); //Front Face Left
	    earr[1] = Edge(varr[1], varr[2]); //Front Face Top
	    earr[2] = Edge(varr[2], varr[0]); //Front Face Diagonal
	    earr[3] = Edge(varr[2], varr[3]); //Front Face Right
	    earr[4] = Edge(varr[3], varr[0]); //Front Face Bottom
	    earr[5] = Edge(varr[1], varr[4]); //Top Face Left
	    earr[6] = Edge(varr[4], varr[5]); //Top Face Top
	    earr[7] = Edge(varr[5], varr[1]); //Top Face Diagonal
	    earr[8] = Edge(varr[5], varr[2]); //Top Face Right
	    earr[9] = Edge(varr[5], varr[3]); //Right Face Diagonal
	    earr[10] = Edge(varr[5], varr[6]); //Right Face Right
	    earr[11] = Edge(varr[6], varr[3]); //Right Face Bottom
	    earr[12] = Edge(varr[4], varr[6]); //Rear Diagonal
	    earr[13] = Edge(varr[4], varr[7]); //Rear Right (if facing)
	    earr[14] = Edge(varr[7], varr[6]); //Rear Bottom
	    earr[15] = Edge(varr[1], varr[7]); //Left Diagonal
	    earr[16] = Edge(varr[0], varr[7]); //Left Bottom
	    earr[17] = Edge(varr[3], varr[7]); //Bottom diagonal

	    farr[0] = Face(earr[0],earr[1],earr[2]);      //Front Face Left Tri
	    farr[1] = Face(earr[2],earr[3],earr[4], BFF); //Front Face Right Tri
	    farr[2] = Face(earr[5], earr[6], earr[7]);    //Top Face Left Tri
	    farr[3] = Face(earr[7], earr[8], earr[1], BFB); //Top Face Right
	    farr[4] = Face(earr[3], earr[8] ,earr[9] , BBF); //Right Face Left
	    farr[5] = Face(earr[9], earr[10] ,earr[11] , BFF); //Right Face Right
	    farr[6] = Face(earr[10], earr[6], earr[12], BBF); //Back Face Left
	    farr[7] = Face(earr[12], earr[13], earr[14], BFF); //Back Face Right
	    farr[8] = Face(earr[13], earr[5], earr[15] , BBF); //Left Face Left
	    farr[9] = Face(earr[15], earr[0] , earr[16] , BBF); //Left Face Right
	    farr[10] = Face(earr[16], earr[4] , earr[17] , BBF); //Bottom Face Left
	    farr[11] = Face(earr[17], earr[11] ,earr[14] , BBB); //Bottom Face Right

	    for( int i = 0; i < 12 ; ++i)
		{
		    r[i] = rand() % 255;
		    g[i] = rand() % 255;
		    b[i] = rand() % 255;
		}
	}

    void Cube::Draw()
	{
	    for(int i = 0; i < 12; ++i)
		{
		    glColor3ub(r[i],g[i],b[i]);
		    farr[i].Draw();
		}
	}

    Cube::~Cube()
	{
	// TODO Auto-generated destructor stub
	}

    }
