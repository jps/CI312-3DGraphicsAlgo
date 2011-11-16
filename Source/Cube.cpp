/*
 * Cube.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#define ExceptionTrapping


#include "../Header/Cube.h"

namespace Game
    {

    Cube::Cube()
	{
	Vertex v = Vertex(0, 0, 0);
	init(1, v);//default to a size one cube
	}

    Cube::Cube(float size)
	{

	Vertex v = Vertex(0, 0, 0);
	init(size, v );//default to a size one cube
	}


    Cube::Cube(float size, Vertex position)
	{
	init(size/2, position);
	}


    void Cube::init(float size, Vertex v)
	{

	    varr[0] = Vertex(-size,-size,-size); //Front Face Bottom Left
	    varr[1] = Vertex(-size, size,-size); //Front Face Top Left
	    varr[2] = Vertex( size, size,-size); //Front Face Top Right
	    varr[3] = Vertex( size,-size,-size); //Front Face Bottom Right
	    varr[4] = Vertex(-size, size, size); //Top Face Top Left
	    varr[5] = Vertex( size, size, size); //Top Face Top Right
	    varr[6] = Vertex( size,-size, size); //Right Face Bottom Right
	    varr[7] = Vertex(-size,-size, size); //Back Face Bottom Right (if facing)

	    earr[0] = Edge(varr[0], varr[1]); //Front Face Left
	    earr[1] = Edge(varr[1], varr[2]); //Front Face Top
	    earr[2] = Edge(varr[2], varr[0]); //Front Face Diagonal
	    earr[3] = Edge(varr[2], varr[3]); //Front Face Right
	    earr[4] = Edge(varr[3], varr[0]); //Front Face Bottom
	    earr[5] = Edge(varr[1], varr[4]); //Top Face Left
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
	    farr[10] = Face(earr[16], earr[4] , earr[17] , BBF); //Bottom Face Left
	    farr[11] = Face(earr[17], earr[11] ,earr[14] , BBB); //Bottom Face Right

	    for( int i = 0; i < 12 ; ++i)
		{
		    r[i] = rand() % 255;
		    g[i] = rand() % 255;
		    b[i] = rand() % 255;
		}
	}

     void Cube::Draw()
	{
	    for(int i = 0; i < 12; ++i)
		{
		    glColor3ub(r[i],g[i],b[i]);
		    farr[i].Draw();
		}
	}




    GameObject Cube::ButterflySubSpaceDivision()
	{

	struct ControlPoints
		{
		    Vertex a[2];
		    Vertex b[2];
		    Vertex c[4];
		    Vertex d[2];
		};

#ifdef PrintToConsole
			    cout << "entered subspace division method \n";
#endif

	    GameObject NGO = GameObject();

	    //TODO: issue here not finding the correct vals. however these are already known.
	    int fl = 12;
	    int el = 18;
	    int vl = 8;
	    //EdgeFaces efs[el];
	    ControlPoints cps[el];
#ifdef PrintToConsole
			cout << "About to find edge faces \n";
#endif
	    EdgesFaces ef = EdgesFaces(earr, farr,el,fl);
#ifdef PrintToConsole
			cout << "Edge faces found \n";
#endif

	    for(int fi = 0; fi < fl; ++fi  )
	    {
#ifdef PrintToConsole
			cout << "on face: "<< fi+1 << " of " << fl << "\n";
#endif
		for(int ei = 0; ei < 3; ++ei)
		{

#ifdef PrintToConsole
			cout << "on edge: "<< ei+1 << " of " << 3 << "\n";
#endif
/*
control point positions labeled for reference

			 c1     b1     c2
			/  \f10/  \ f2/  \
		       / f9 \ / f1 \ / f3 \
		     d1---- -a1--*--a2----d2
		       \ f8 / \ f6 / \ f4 /
			\  /f7 \  / f5\  /
			 c4     b2     c3
*/
		    //a1 /a[0]
		    cps[fi].a[0] = farr[fi].earr[ei].a;


		    //a1 /a[1]
		    cps[fi].a[1] = farr[fi].earr[ei].b;


		    //b1 /b[0]
		    cps[fi].b[0] = farr[fi].LocateFinalVertex(farr[fi].earr[ei]);


		    //b1
		    Face f1 = ef.FindFace(farr[fi].earr[ei], farr[fi]);
		    cps[fi].b[1] = f1.LocateFinalVertex(farr[fi].earr[ei]);

		    //c1 - neighbors f10 - b1 and a1 are known //TODO: check
		    Edge e1 = farr[fi].LocateEdge(cps[fi].a[0],cps[fi].b[0]);
		    Face f10 = ef.FindFace(e1,farr[fi]);
		    cps[fi].c[0] = f10.LocateFinalVertex(e1);

		    //c2 - neighbors f2 - b1 and a2 are known
		    Edge e2 = farr[fi].LocateEdge(cps[fi].a[1],cps[fi].b[0]);
		    Face f2 = ef.FindFace(e2,farr[fi]);
		    cps[fi].c[2] = f2.LocateFinalVertex(e2);

		    //c3 - neighbors f2 - b2 and a2 are known
		    Edge e3 = f1.LocateEdge(cps[fi].a[1],cps[fi].b[1]);
		    Face f5 = ef.FindFace(e3,f1);
		    cps[fi].c[2] = f5.LocateFinalVertex(e3);

		    //c4 - neighbors f7 - b2 and a1 are known
		    Edge e4 = f1.LocateEdge(cps[fi].a[0], cps[fi].b[1]);
		    Face f7 = ef.FindFace(e4, f1);
		    cps[fi].c[3] = f7.LocateFinalVertex(e4);


#ifdef PrintToConsole
		    cout << "a[0] Located :"<< cps[fi].a[0].ToString() <<"\n";
		    cout << "a[1] Located :"<< cps[fi].a[1].ToString() <<"\n";
		    cout << "b[0] Located :"<< cps[fi].b[0].ToString() <<"\n";
		    cout << "b[1] Located  :"<< cps[fi].b[1].ToString() <<"\n";
		    cout << "c[0] Located  :"<< cps[fi].c[0].ToString() <<"\n";
		    cout << "c[1] Located  :"<< cps[fi].c[1].ToString() <<"\n";
		    cout << "c[2] Located  :"<< cps[fi].c[2].ToString() <<"\n";
 		    cout << "c[3] Located  :"<< cps[fi].c[3].ToString() <<"\n";
#endif


#ifdef PrintToConsole
			cout << "\n";
#endif
		}
#ifdef PrintToConsole
			cout << "\n\n";
#endif

	    }
#ifdef PrintToConsole
		cout << "exiting method \n";
#endif
	    return NGO;
	}

    Cube::~Cube()
	{
	// TODO Auto-generated destructor stub
	}

    }
