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

#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

#include "Cube.h"

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
	    /*Vertex varr[8];
	    Edge earr[18];
	    Face farr[12];
*/
	   /* int r[12], g[12], b[12];

	    for( int i = 0; i < 12 ; ++i)
		{
		    r[i] = rand() % 255;
		    g[i] = rand() % 255;
		    b[i] = rand() % 255;
		}*/
	    Vertex vt = Vertex(0,0,0);
	    Cube CubeTest = Cube(2.5f,vt);


	    float RotationX, RotationY, RotationZ;
	    while( events() )
	    {
		    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		    glLoadIdentity();
		    glTranslatef(0,0, -10);
		    glRotatef(RotationX,RotationY, RotationZ, 1);

		    glBegin(GL_TRIANGLES);
		    // this should be the main gl draw loop here.
		    // ie all object within the game object manager that have visibility set to to true draw!
		    CubeTest.Draw();


		    glEnd();
		    SDL_GL_SwapBuffers();
		    // Check keypresses
		    if( key[SDLK_RIGHT] ){ RotationX-=0.5; }
		    if( key[SDLK_LEFT ] ){ RotationX+=0.5; }
		    if( key[SDLK_UP] ){ RotationY-=0.5; }
		    if( key[SDLK_DOWN ] ){ RotationY+=0.5; }
		    if( key[SDLK_l] ) { RotationZ -=0.5; }
		    if( key[SDLK_k] ) { RotationZ +=0.5; }

			    //if( key[SDLK_i] ) { ExecuteSubSpaceDivision(); }


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

