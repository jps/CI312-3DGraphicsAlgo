/*
 * main.h
 *
 *  Created on: Oct 13, 2011
 *      Author: Panda
 */
#ifndef MAIN_H_
#define MAIN_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
//#include <stdio.h>
//#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Header/Vertex.h"
#include "Header/Edge.h"
#include "Header/Face.h"
#include "Header/GameObject.h"

#include "Header/Cube.h"
#include "Header/ButterflySubspaceDivision.h"
#include "Header/CatmullClarkSubDivision.h"

//using namespace std;

#define window_width  800
#define window_height 600

namespace Game
{
	class main
	{
public:
	//void main_loop_function();
	main();
	virtual ~main();
	};
};

#endif /* MAIN_H_ */


