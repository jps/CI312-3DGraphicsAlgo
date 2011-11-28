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

//#define PrintToConsole

using namespace std;
using namespace Game;

#define window_width  800
#define window_height 600


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
	    Cube CubeTest = Cube(5.0f,vt);
	    GameObject go, go1, go2;
	    signed int ButtonPause = 0;
	    float RotationX, RotationY, RotationZ;
	    float Zoom = -5;
	    //int drawOnly = 0;
	    bool wireframe = false, hasDevided = false, go1on = false;//cheap way of chosing which object to draw TODO: change to something more suitable
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
			if(go1on)
			    go1.Draw();
			else
			    go.Draw();
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
		    if( key[SDLK_w]) {
			wireframe =  !wireframe;
			if( ButtonPause == 0)
			    {
			    if(!wireframe)
				glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
			    else
				glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
			    ButtonPause = 30;
			    }
		    }

		    ButtonPause = ButtonPause > 0 ? --ButtonPause : ButtonPause; //buffer to stop method being spammed cheap but it works...
		    if( key[SDLK_a])
			{
			if( ButtonPause == 0)
			    {
			    cout << "ButterflySubSpaceDivision Called \n";
			    //if(!hasDevided)
			    if(hasDevided)
				{
				go1 = go.ButterflySubSpaceDivision();
std::cout << "Object returned"; //TODO: wtf is going on here....
				go1on = true;
				//hasDevided = !hasDevided;
				ButtonPause = 30;
			    }else{
				go = CubeTest.ButterflySubSpaceDivision();
#ifdef PrintToConsole
std::cout << "Checking the provided edge list" << "\n";
for(unsigned int i = 0; i < go.earr.size(); i++)
    {
    std::cout << go.earr[i].a.ToString();
    std::cout << go.earr[i].b.ToString();
    }
#endif

				go.init();
				go.init();
				go.init();
				go.init();
				go.init();
				go.init();
				hasDevided = !hasDevided;
				ButtonPause = 30;
				}
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
	    glEnable(GL_POLYGON_SMOOTH);
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

