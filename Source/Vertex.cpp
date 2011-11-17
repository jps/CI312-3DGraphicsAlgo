/*
 * Vertex.cpp
 *
 *  Created on: Oct 19, 2011
 *      Author: Panda
 */

#include "../Header/Vertex.h"

namespace Game
    {
//Change to array based structure if opportunity/necessity calls for it
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

    string Vertex::ToString()
	{
	 stringstream ss (stringstream::in | stringstream::out);
	 ss << " Vertex: x=" << x << " y=" << y << " z="<< z;
	 return ss.str();
	}

    bool Vertex::operator==(Vertex &inV)
	{
	if(x == inV.x && y == inV.y && z == inV.z)
	    return true;
	return false;
	}

    bool Vertex::operator!=(Vertex &inV)
	{
	if(x == inV.x && y == inV.y && z == inV.z)
	    return false;
	return true;
	}

    Vertex Vertex::operator +(Vertex &inV)
	{
	    return Vertex( x + inV.GetX(), y + inV.GetY(), z + inV.GetZ());
	}

    Vertex Vertex::operator -(Vertex &inV)
	{
	return Vertex( x - inV.GetX(), y - inV.GetY(), z - inV.GetZ());
	}

    Vertex Vertex::operator *(Vertex &inV)
	{
	return Vertex( x * inV.GetX(), y * inV.GetY(), z * inV.GetZ());
	}

    Vertex Vertex::operator *(float &inV)
	{
	return Vertex( x * inV, y * inV, z * inV);
	}

    Vertex Vertex::operator /(Vertex &inV)
    	{
    	return Vertex( x / inV.GetX(), y / inV.GetY(), z / inV.GetZ());
    	}


    //efectivly deprectated by operator overload
    bool Vertex::EqualTo(Vertex v)
	{
	if(x == v.x && y == v.y && z == v.z)
	    return true;
	return false;
	}


    Vertex::~Vertex()
	{

	}
    }
