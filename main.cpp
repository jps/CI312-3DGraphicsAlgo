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
#include "Header/ButterflySubspaceDivision.h"
#include "Header/CatmullClarkSubDivision.h"
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
	    Cube CubeTest = Cube(1.0f,vt);
	    GameObject go, go1, go2;
	    signed int ButtonPause = 0, wireframe = 0;
	    float RotationX, RotationY, RotationZ, Zoom, Size;
	    RotationX = RotationY = RotationZ = 0;
	    Zoom = -10;
	    Size = 10;
	    //int drawOnly = 0;
	    bool hasDevided = false, go1on = false;//cheap way of chosing which object to draw TODO: change to something more suitable
	    while( events() )
	    {
		    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		    glLoadIdentity();
		    glTranslatef(0,0, Zoom);
		    glRotatef(RotationX,RotationY, 45,45);
		    glPointSize(Size);


		    glBegin(GL_TRIANGLES);
		    // this should be the main gl draw loop here.
		    // ie all object within the game object manager that have visibility set to to true draw!

		    if(!hasDevided)
			CubeTest.Draw();
		    else
			{
			if(go1on)
			{
			    go1.Draw();
			}
			else
			    go.Draw();
			}
		    glEnd();
		    SDL_GL_SwapBuffers();
		    // Check keypresses
		    ButtonPause = ButtonPause > 0 ? --ButtonPause : ButtonPause; //buffer to stop method being spammed cheap but it works...

		    if( key[SDLK_RIGHT] ){ RotationX-=0.5; }
		    if( key[SDLK_LEFT ] ){ RotationX+=0.5; }
		    if( key[SDLK_UP] ){ RotationY-=0.5; }
		    if( key[SDLK_DOWN ] ){ RotationY+=0.5; }
		    if( key[SDLK_l] ) { glRotatef(45,4,0,0); }
		    if( key[SDLK_k] ) { RotationZ +=0.5; }

		    if( key[SDLK_i]) { Zoom += 0.5;}
		    if( key[SDLK_o]) { Zoom -= 0.5;}
		    if( key[SDLK_w]) {
			if( ButtonPause == 0)
			    {
			    switch(wireframe)
				{
				case 0:
				    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
				    ++wireframe;
				    break;
				case 1:
				    glPolygonMode( GL_FRONT_AND_BACK, GL_POINT );
				    ++wireframe = 2;
				    break;
				default:
				    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
				    wireframe = 0;
				    break;
				}
			    ButtonPause = 30;
			    }
			if( key[SDLK_q]){
			glEnable(GL_POINT_SPRITE);
			glTexEnvf(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);
			}
		    }
		    if( key[SDLK_c])
			{
			if(ButtonPause == 0)
			    {
#ifdef PrintToConsole
			    cout << "Catnell clark called";
#endif
			    ButtonPause = 30;
			    CatmullClarkSubDivision().SubdivideGameObject(CubeTest);
			    go.init();
			    hasDevided = !hasDevided;
			    }
			}
		    if( key[SDLK_0]) //reset to center
			{RotationX = RotationY = RotationZ == 0;}
		    if( key[SDLK_a])
			{
			if( ButtonPause == 0)
			    {
#ifdef PrintToConsole
			    cout << "ButterflySubSpaceDivision Called \n";
#endif
			    if(hasDevided)
				{
			    go1 = ButterflySubspaceDivision().Tessellate(go);
				//go1 = go.ButterflySubSpaceDivision();
std::cout << "Object returned"; //TODO: wtf is going on here....
				go1on = true;
				go1.init();
				go1.init();
				//hasDevided = !hasDevided;
				ButtonPause = 30;
			    }else{
				go = ButterflySubspaceDivision().Tessellate(CubeTest);
#ifdef PrintToConsole
std::cout << "Checking the provided edge list" << "\n";
for(unsigned int i = 0; i < go.earr.size(); i++)
    {
    std::cout << go.earr[i].a->ToString();
    std::cout << go.earr[i].b->ToString();
    }
#endif
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

