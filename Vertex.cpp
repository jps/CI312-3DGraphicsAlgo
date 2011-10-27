/*
 * Vertex.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "Vertex.h"

namespace Game
    {

    Vertex::Vertex()
	{
	z = y = x = 0;
	}

    Vertex::Vertex(float X, float Y, float Z)
	{
	x = X;
	y = Y;
	z = Z;
	}

    void Vertex::Set(float X, float Y, float Z)
	{
	x = X;
	y = Y;
	z = Z;
	}

    void Vertex::SetX(float X)
	{
	x = X;
	}

    void Vertex::SetY(float Y)
	{
	y = Y;
	}

    void Vertex::SetZ(float Z)
	{
	z = Z;
	}

    float* Vertex::Get()
	{
	static float arr[3] = {x , y, z};
	return arr;
	}

    float Vertex::GetX()
	{
	return x;
	}

    float Vertex::GetY()
	{
	return y;
	}

    float Vertex::GetZ()
	{
	return z;
	}

    Vertex::~Vertex()
	{

	}
    }
