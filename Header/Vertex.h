/*
 * Vertex.h
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include <string>
#include <iostream>
#include <sstream>

#ifndef VERTEX_H_
#define VERTEX_H_

using namespace std;

namespace Game
    {
    class Vertex
	{
    public:
	Vertex();
	Vertex(float X, float Y, float Z);
	virtual ~Vertex();
	void Set(float X,float Y,float Z);
	void SetX(float X);
	void SetY(float Y);
	void SetZ(float Z);
	float* Get();
	float GetX();
	float GetY();
	float GetZ();
	//float[] Vertex::Get();
	bool EqualTo(Vertex v);
	string ToString();
	bool operator==(const Vertex &inV);
	//bool& operator==( float &inV);
	bool operator!=(const Vertex &inV);
    private:
	float x,y,z;
	};
    }
#endif /* VERTEX_H_ */
