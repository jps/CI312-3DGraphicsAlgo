/*
 * main.cpp
 *
 *  Created on: Oct 13, 2011
 *      Author: Panda
 */

#include "main.h"

using namespace std;
using namespace Game;
//#define PrintToConsole


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
	    ObjectManager * objManager = ObjectManager::Inst(); //create object manager

	    Cube CubeTest = Cube(1.0f,Vertex(0,0,0)); //create cube and push to object manager
	    objManager->GameObjects.push_back(CubeTest);
/*
	    GLfloat ambient[] = { .5f, .5f, .5f, 1.f };
	    GLfloat diffuse[] = { .5f, .5f, .5f, .6f };
	    GLfloat litepos[] = { 0, 2, 3, 1 };
	    GLfloat litepos2[] = { 0, -2, 5, 1 };

	    glPushMatrix();
	 		    	glLoadIdentity();
	 		    	glEnable(GL_LIGHTING);
	 		    	glLightfv(GL_LIGHT0, GL_AMBIENT,  ambient);
	 		    	glLightfv(GL_LIGHT0, GL_DIFFUSE,  diffuse);
	 		    	glLightfv(GL_LIGHT0, GL_POSITION, litepos);
	 		    	glEnable(GL_LIGHT0);

	 		    	glLightfv(GL_LIGHT1, GL_DIFFUSE,  diffuse);
	 		    	glLightfv(GL_LIGHT1, GL_POSITION, litepos2);
	 		    	glEnable(GL_LIGHT1);
	 		    	glPopMatrix();
*/

	    signed int buttonPause, wireframe, CurrentObj;
	    float RotationX, RotationY, RotationZ, Zoom, Size;
	    RotationX = RotationY = RotationZ = buttonPause = wireframe = CurrentObj = 0;
	    Zoom = -3;
	    Size = 5;
	    while( events() )
	    {
		    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		    glLoadIdentity();
		    glTranslatef(0,0, Zoom);
		    glRotatef(RotationX,RotationY, 45,45);
		    glPointSize(Size);


		    objManager->Draw();
		    glEnd();


		    SDL_GL_SwapBuffers();

		    // Check keypresses
		    buttonPause = buttonPause > 0 ? --buttonPause : buttonPause; //buffer to stop method being spammed cheap but it works...

		    if( key[SDLK_RIGHT] ){ RotationX-=0.5; }
		    if( key[SDLK_LEFT ] ){ RotationX+=0.5; }
		    if( key[SDLK_UP] ){ RotationY-=0.5; }
		    if( key[SDLK_DOWN ] ){ RotationY+=0.5; }
		    //if( key[SDLK_l] ) { glRotatef(45,4,0,0); } //>
		    if( key[SDLK_k] ) { RotationZ +=0.5; }
		    if( key[SDLK_i]) { Zoom += 0.1;}
		    if( key[SDLK_o]) { Zoom -= 0.1;}
		    if( key[SDLK_0]){RotationX = RotationY = RotationZ == 0;} //reset to center
		    if( key[SDLK_w])
		    {
		    	if( buttonPause == 0)
			    {
					switch(wireframe)
					{
					case 0:
						glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
						++wireframe;
						break;
					case 1:
						glPolygonMode( GL_FRONT_AND_BACK, GL_POINT );
						++wireframe;
						break;
					default:
						glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
						wireframe = 0;
						break;
					}
					buttonPause = 30;
			    }
		    }
		    if( key[SDLK_c])
			{
		    	if(buttonPause == 0)
			    {
#ifdef PrintToConsole
		    		cout << "Catnell clark called";
#endif
					objManager->GameObjects[CurrentObj].visible = false;
					GameObject _ngobj = CatmullClarkSubDivision().Subdivide(objManager->GameObjects[CurrentObj]);
					GameObject* ngobj = new GameObject(_ngobj);
					ngobj->init();
					objManager->GameObjects.push_back(*ngobj);
					++CurrentObj;
					buttonPause = 30;
			    }
			}
		    if( key[SDLK_a])
			{
		    	if(buttonPause == 0)
		    	{
		    		/*
					objManager->GameObjects[CurrentObj].visible = false;
					GameObject _ngobj = ButterflySubspaceDivision().Tessellate(objManager->GameObjects[CurrentObj]);
					GameObject* ngobj = new GameObject(_ngobj);
					ngobj->init();
					objManager->GameObjects.push_back(*ngobj);
					++CurrentObj;
					buttonPause = 30;*/
		    	}
			}
	    }

	    objManager->~ObjectManager();
    }


    // Initialize OpenGL perspective matrix
    void GL_Setup(int width, int height)
    {
	    glViewport( 0, 0, width, height );
	    glMatrixMode( GL_PROJECTION );
	    glEnable( GL_DEPTH_TEST );
	    glEnable(GL_CULL_FACE);
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
