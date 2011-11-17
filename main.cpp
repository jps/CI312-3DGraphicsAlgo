/*
 * main.cpp
 *
 *  Created on: Oct 13, 2011
 *      Author: Panda
 */

//#include "main.h"


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

#include "Header/Cube.h"

using namespace std;
using namespace Game;

#define window_width  640
#define window_height 480


    // Keydown booleans
    bool key[321];
    // Process pending events
    bool events()
    {
	    SDL_Event event;
	    if( SDL_PollEvent(&event) )
	    {
		    switch( event.type )
		    {
		    case SDL_KEYDOWN : key[ event.key.keysym.sym ]=true ;   break;
		    case SDL_KEYUP   : key[ event.key.keysym.sym ]=false;   break;
		    case SDL_QUIT    : return false; break;
		    }
	    }
	    return true;
    }


    void main_loop_function()
    {
	    Vertex vt = Vertex(0,0,0);
	    Cube CubeTest = Cube(2.0f,vt);
	    GameObject go;
	    signed int ButtonPause = 0;
	    float RotationX, RotationY, RotationZ;
	    float Zoom = -5;
	    bool hasDevided = false; //cheap way of chosing which object to draw TODO: change to something more suitable
	    while( events() )
	    {
		    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		    glLoadIdentity();
		    glTranslatef(0,0, Zoom);
		    glRotatef(RotationX,RotationY, 45,45);

		    glBegin(GL_TRIANGLES);
		    // this should be the main gl draw loop here.
		    // ie all object within the game object manager that have visibility set to to true draw!

		    if(!hasDevided)
			CubeTest.Draw();
		    else
			{
			std::cout << go.farr.size() << "\n";
			go.Draw();
			//CubeTest.Draw();
			}


		    glEnd();
		    SDL_GL_SwapBuffers();
		    // Check keypresses
		    if( key[SDLK_RIGHT] ){ RotationX-=0.5; }
		    if( key[SDLK_LEFT ] ){ RotationX+=0.5; }
		    if( key[SDLK_UP] ){ RotationY-=0.5; }
		    if( key[SDLK_DOWN ] ){ RotationY+=0.5; }
		    if( key[SDLK_l] ) { RotationZ -=0.5; }
		    if( key[SDLK_k] ) { RotationZ +=0.5; }
		    if( key[SDLK_i]) { Zoom += 0.5;}
		    if( key[SDLK_o]) { Zoom -= 0.5;}
		    ButtonPause = ButtonPause > 0 ? --ButtonPause : ButtonPause; //buffer to stop method being spammed cheap but it works...
		    if( key[SDLK_a])
			{
			if( ButtonPause == 0)
			    {
			    cout << "ButterflySubSpaceDivision Called \n";
			    //if(!hasDevided)
			    if(hasDevided)
				go = go.ButterflySubSpaceDivision();
			    else
			    go = CubeTest.ButterflySubSpaceDivision();
			    go.init();
			    hasDevided = !hasDevided;
			    ButtonPause = 30;
			    }
			}
	    }
    }


    // Initialze OpenGL perspective matrix
    void GL_Setup(int width, int height)
    {
	    glViewport( 0, 0, width, height );
	    glMatrixMode( GL_PROJECTION );
	    glEnable( GL_DEPTH_TEST );
	    gluPerspective( 45, (float)width/height, 0.1, 100 );
	    glMatrixMode( GL_MODELVIEW );
    }
    int main()
    {
	    //Random Number seed
	    srand ( time(NULL) );
	    // Initialize SDL with best video mode
	    SDL_Init(SDL_INIT_VIDEO);
	    const SDL_VideoInfo* info = SDL_GetVideoInfo();
	    int vidFlags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER;
	    if (info->hw_available) {vidFlags |= SDL_HWSURFACE;}
	    else {vidFlags |= SDL_SWSURFACE;}
	    int bpp = info->vfmt->BitsPerPixel;
	    SDL_SetVideoMode(window_width, window_height, bpp, vidFlags);
	    GL_Setup(window_width, window_height);
	    main_loop_function();
    }

