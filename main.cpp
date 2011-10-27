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

#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

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
	    float RotationX, RotationY, RotationZ;
	    while( events() )
	    {
		    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		    glLoadIdentity();
		    glTranslatef(0,0, -10);
		    glRotatef(RotationX,RotationY, 0, 1);

		    glBegin(GL_TRIANGLES);

		    Vertex varr[8];
		    Edge earr[18];
		    Face farr[8];

		    //TODO: Fore now i have stored these both in array and as objects consider moving just to array


		    Vertex v1 = varr[0] = Vertex(-1,-1,-1); //Front Face Bottom Left
		    Vertex v2 = varr[1] = Vertex(-1, 1,-1); //Front Face Top Left
		    Vertex v3 = varr[2] = Vertex( 1, 1,-1); //Front Face Top Right
		    Vertex v4 = varr[3] = Vertex( 1,-1,-1); //Front Face Bottom Right
		    Vertex v5 = varr[4] = Vertex(-1, 1, 1); //Top Face Top Left
		    Vertex v6 = varr[5] = Vertex( 1, 1, 1); //Top Face Top Right
		    Vertex v7 = varr[6] = Vertex( 1,-1, 1); //Right Face Bottom Right
		    Vertex v8 = varr[7] = Vertex(-1,-1, 1); //Back Face Bottom Right (if facing)

		    Edge e1 = evarr[0] = Edge(v1, v2); //Front Face Left
		    Edge e2 = evarr[1] =Edge(v2, v3); //Front Face Top
		    Edge e3 = evarr[2] =Edge(v3, v1); //Front Face Diagonal
		    Edge e4 = evarr[3] =Edge(v3, v4); //Front Face Right
		    Edge e5 = evarr[4] =Edge(v4, v1); //Front Face Bottom
		    Edge e6 = evarr[5] =Edge(v2, v5); //Top Face Left
		    Edge e7 = evarr[6] =Edge(v5, v6); //Top Face Top
		    Edge e8 = evarr[7] =Edge(v6, v2); //Top Face Diagonal
		    Edge e9 = evarr[8] =Edge(v6, v3); //Top Face Right
		    Edge e10 = evarr[9] =Edge(v6, v4); //Right Face Diagonal
		    Edge e11 = evarr[10] = Edge(v6, v7); //Right Face Right
		    Edge e12 = evarr[11] = Edge(v7, v4); //Right Face Bottom
		    Edge e13 = evarr[12] = Edge(v5, v7); //Rear Diagonal
		    Edge e14 = evarr[13] = Edge(v5, v8); //Rear Right (if facing)
		    Edge e15 = evarr[14] = Edge(v8, v7); //Rear Bottom
		    Edge e16 = evarr[15] = Edge(v2, v8); //Left Diagonal
		    Edge e17 = evarr[16] = Edge(v1, v8); //Left Bottom
		    Edge e18 = evarr[17] = Edge(v4, v8); //Bottom diagonal

		    Face f1 = farr[0] = Face(e1,e2,e3);      //Front Face Left Tri
		    Face f2 = farr[1] = Face(e3,e4,e5, BFF); //Front Face Right Tri
		    Face f3 = farr[2] = Face(e6, e7, e8);    //Top Face Left Tri
		    Face f4 = farr[3] = Face(e8, e9, e2, BFB); //Top Face Right
		    Face f5 = farr[4] = Face(e4, e9 ,e10 , BBF); //Right Face Left
		    Face f6 = farr[5] = Face(e10, e11 ,e12 , BFF); //Right Face Right
		    Face f7 = farr[6] = Face(e11, e7, e13, BBF); //Back Face Left
		    Face f8 = farr[7] = Face(e13, e14, e15, BFF); //Back Face Right
		    Face f9 = farr[8] = Face(e14, e6, e16 , BBF); //Left Face Left
		    Face f10 = farr[9] = Face(e16, e1 , e17 , BBF); //Left Face Right
		    Face f11 = farr[10] = Face(e17, e5 , e18 , BBF); //Bottom Face Left
		    Face f12 = farr[11] = Face(e18, e12 ,e15 , BBB); //Bottom Face Right

		    glColor3ub(255, 000, 000);
		    //FrontFace
		    //-left-tri
		    f1.Draw();
		    glColor3ub(111,111,111);
		    f2.Draw();
		    glColor3ub(111,255,64);
		    f3.Draw();
		    glColor3ub(255,255,64);
		    f4.Draw();
		    glColor3ub(64,255,64);
		    f5.Draw();
		    glColor3ub(124,69,231);
		    f6.Draw();
		    glColor3ub(40,200,80);
		    f7.Draw();
		    glColor3ub(120,200,1);
		    f8.Draw();
		    glColor3ub(1,89,70);
		    f9.Draw();
		    glColor3ub(196,2,40);
		    f10.Draw();
		    glColor3ub(200,42,169);
		    f11.Draw();
		    glColor3ub(18,60,24);
		    f12.Draw();


/*		    glColor3ub(255, 255, 000);
		    //FrontFace
		    //-left-tri
		    glVertex3f(1,1,-1);
		    glVertex3f(1,1,1);
		    glVertex3f(1,-1,-1);
		    //right-tri
		    glVertex3f(1,-1,-1);
		    glVertex3f(1,1,1);
		    glVertex3f(1,-1,1);
		    //BackFace
		    glColor3ub(127, 127, 255);
		    //FrontFace
		    //-left-tri
		    glVertex3f(1,-1,1);
		    glVertex3f(1,1,1);
		    glVertex3f(-1,-1,1);
		    //right-tri
		    glVertex3f(-1,-1,1);
		    glVertex3f(-1,1,1);
		    glVertex3f(1,1,1);
		    //TopFace
		    glColor3ub(000, 255, 255);
		    //FrontFace
		    //-left-tri
		    glVertex3f(1,1,1);
		    glVertex3f(1,1,-1);
		    glVertex3f(-1,1,-1);
		    //right-tri
		    glVertex3f(-1,1,-1);
		    glVertex3f(-1,1,1);
		    glVertex3f(1,1,1);
		    //LeftFace
		    glColor3ub(255, 0, 128);
		    //FrontFace
		    //-left-tri
		    glVertex3f(-1,1,1);
		    glVertex3f(-1,-1,1);
		    glVertex3f(-1,-1,-1);
		    //right-tri
		    glVertex3f(-1,-1,-1);
		    glVertex3f(-1,1,-1);
		    glVertex3f(-1,1,1);

		    //BottomFace
		    glColor3ub(255, 128, 128);
		    //FrontFace
		    //-left-tri
		    glVertex3f(-1,-1,1);
		    glVertex3f(1,-1,1);
		    glVertex3f(1,-1,-1);
		    //right-tri
		    glVertex3f(1,-1,-1);
		    glVertex3f(-1,-1,-1);
		    glVertex3f(-1,-1,1);

*/

		    // this should be the main gl draw loop here.
		    // ie all object within the game object manager that have visibility set to to true draw!




		    glEnd();
		    SDL_GL_SwapBuffers();
		    // Check keypresses
		    if( key[SDLK_RIGHT] ){ RotationX-=0.5; }
		    if( key[SDLK_LEFT ] ){ RotationX+=0.5; }
		    if( key[SDLK_UP] ){ RotationY-=0.5; }
		    if( key[SDLK_DOWN ] ){ RotationY+=0.5; }
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

