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
	    Vertex varr[8];
	    Edge earr[18];
	    Face farr[12];

	    int r[12], g[12], b[12];

	    for( int i = 0; i < 12 ; ++i)
		{
		    r[i] = rand() % 255;
		    g[i] = rand() % 255;
		    b[i] = rand() % 255;
		}

	    float RotationX, RotationY, RotationZ;
	    while( events() )
	    {
		    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		    glLoadIdentity();
		    glTranslatef(0,0, -10);
		    glRotatef(RotationX,RotationY, 0, 1);

		    glBegin(GL_TRIANGLES);



		    //TODO: Fore now i have stored these both in array and as objects consider moving just to array


		    varr[0] = Vertex(-1,-1,-1); //Front Face Bottom Left
		    varr[1] = Vertex(-1, 1,-1); //Front Face Top Left
		    varr[2] = Vertex( 1, 1,-1); //Front Face Top Right
		    varr[3] = Vertex( 1,-1,-1); //Front Face Bottom Right
		    varr[4] = Vertex(-1, 1, 1); //Top Face Top Left
		    varr[5] = Vertex( 1, 1, 1); //Top Face Top Right
		    varr[6] = Vertex( 1,-1, 1); //Right Face Bottom Right
		    varr[7] = Vertex(-1,-1, 1); //Back Face Bottom Right (if facing)

		    earr[0] = Edge(varr[0], varr[1]); //Front Face Left
		    earr[1] = Edge(varr[1], varr[2]); //Front Face Top
		    earr[2] = Edge(varr[2], varr[0]); //Front Face Diagonal
		    earr[3] = Edge(varr[2], varr[3]); //Front Face Right
		    earr[4] = Edge(varr[3], varr[0]); //Front Face Bottom
		    earr[5] = Edge(varr[1], varr[4]); //Top Face Left
		    // Edge e6 = Edge(v2, v5); //Top Face Left
		    earr[6] = Edge(varr[4], varr[5]); //Top Face Top
		    earr[7] = Edge(varr[5], varr[1]); //Top Face Diagonal
		    earr[8] = Edge(varr[5], varr[2]); //Top Face Right
		    earr[9] = Edge(varr[5], varr[3]); //Right Face Diagonal
		    earr[10] = Edge(varr[5], varr[6]); //Right Face Right
		    earr[11] = Edge(varr[6], varr[3]); //Right Face Bottom
		    earr[12] = Edge(varr[4], varr[6]); //Rear Diagonal
		    earr[13] = Edge(varr[4], varr[7]); //Rear Right (if facing)
		    earr[14] = Edge(varr[7], varr[6]); //Rear Bottom
		    earr[15] = Edge(varr[1], varr[7]); //Left Diagonal
		    earr[16] = Edge(varr[0], varr[7]); //Left Bottom
		    earr[17] = Edge(varr[3], varr[7]); //Bottom diagonal


		    farr[0] = Face(earr[0],earr[1],earr[2]);      //Front Face Left Tri
		    farr[1] = Face(earr[2],earr[3],earr[4], BFF); //Front Face Right Tri
		    farr[2] = Face(earr[5], earr[6], earr[7]);    //Top Face Left Tri
		    farr[3] = Face(earr[7], earr[8], earr[1], BFB); //Top Face Right
		    farr[4] = Face(earr[3], earr[8] ,earr[9] , BBF); //Right Face Left
		    farr[5] = Face(earr[9], earr[10] ,earr[11] , BFF); //Right Face Right
		    farr[6] = Face(earr[10], earr[6], earr[12], BBF); //Back Face Left
		    farr[7] = Face(earr[12], earr[13], earr[14], BFF); //Back Face Right
		    farr[8] = Face(earr[13], earr[5], earr[15] , BBF); //Left Face Left
		    farr[9] = Face(earr[15], earr[0] , earr[16] , BBF); //Left Face Right
		    //farr[9] = Face(e16, e1 , e17 , BBF); //Left Face Right
		    farr[10] = Face(earr[16], earr[4] , earr[17] , BBF); //Bottom Face Left
		    farr[11] = Face(earr[17], earr[11] ,earr[14] , BBB); //Bottom Face Right

		    for(int i = 0; i < 12; ++i)
			{

			    glColor3ub(r[i],g[i],b[i]);
			    //if(i!= 9)
			    farr[i].Draw();
			}

/*
		    Vertex v1 = Vertex(-1,-1,-1); //Front Face Bottom Left
		    Vertex v2 = Vertex(-1, 1,-1); //Front Face Top Left
		    Vertex v3 = Vertex( 1, 1,-1); //Front Face Top Right
		    Vertex v4 = Vertex( 1,-1,-1); //Front Face Bottom Right
		    Vertex v5 = Vertex(-1, 1, 1); //Top Face Top Left
		    Vertex v6 = Vertex( 1, 1, 1); //Top Face Top Right
		    Vertex v7 = Vertex( 1,-1, 1); //Right Face Bottom Right
		    Vertex v8 = Vertex(-1,-1, 1); //Back Face Bottom Right (if facing)

		    Edge e1 = Edge(v1, v2); //Front Face Left
		    Edge e2 = Edge(v2, v3); //Front Face Top
		    Edge e3 = Edge(v3, v1); //Front Face Diagonal
		    Edge e4 = Edge(v3, v4); //Front Face Right
		    Edge e5 = Edge(v4, v1); //Front Face Bottom
		    Edge e6 = Edge(v2, v5); //Top Face Left
		    Edge e7 = Edge(v5, v6); //Top Face Top
		    Edge e8 = Edge(v6, v2); //Top Face Diagonal
		    Edge e9 = Edge(v6, v3); //Top Face Right
		    Edge e10 = Edge(v6, v4); //Right Face Diagonal
		    Edge e11 = Edge(v6, v7); //Right Face Right
		    Edge e12 = Edge(v7, v4); //Right Face Bottom
		    Edge e13 = Edge(v5, v7); //Rear Diagonal
		    Edge e14 = Edge(v5, v8); //Rear Right (if facing)
		    Edge e15 = Edge(v8, v7); //Rear Bottom
		    Edge e16 = Edge(v2, v8); //Left Diagonal
		    Edge e17 = Edge(v1, v8); //Left Bottom
		    Edge e18 = Edge(v4, v8); //Bottom diagonal

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
*/
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
		    //if( key[SDLK_i] ) { ExecuteSubSpaceDivision(); }

		  //  delete[] varr;
		  //  delete[] earr;
		  //  delete[] farr;
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

