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
		bool operator==(Vertex &inV);
		bool operator!=(Vertex &inV);
		Vertex operator +(Vertex &inV);
		Vertex operator +(Vertex *inV);
		Vertex operator -(Vertex &inV);
		Vertex operator *(Vertex &inV);
		Vertex operator *(int &inV);
		Vertex operator *(float &inV);
		Vertex operator /(Vertex &inV);
		Vertex operator /(Vertex *inV);
		Vertex operator /(int inV);
		//Vertex Divide(Vertex &inV);
		Vertex Divide(int inV);
		Vertex Multiply(int inV);
		static Vertex Divide(Vertex a , int b);//TODO: remove!
	private:
		float x,y,z;
		};
    }
#endif /* VERTEX_H_ */
