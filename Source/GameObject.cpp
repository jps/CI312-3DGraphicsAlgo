/*
 * GameObject.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: Panda
 */

#include "../Header/GameObject.h"

#define PrintToConsole


//#define hardDebugVertexVals //turn this off!!!!!

namespace Game
    {

    GameObject::GameObject(const Vertex * Varr, const Edge Earr[], const Face Farr[])
	{

	    //varr = new Vertex[sizeof( Varr ) / sizeof( Varr[0] )];
	    //earr = new Edge[sizeof( Earr ) / sizeof( Earr[0] )];
	    //farr = new Face[sizeof( Farr ) / sizeof( Farr[0] )];

//	    varr= Varr;

	}

    GameObject::GameObject()
	{
		visible = true;
		transformBy = Vertex( 0.0f,0.0f,0.0f);
	}

    GameObject::~GameObject()
	{
	   // delete farr;
	   // delete earr;
	   // delete varr;
	}

    void GameObject::init()
	{
	   for(unsigned int i = 0; i < varr.size(); ++i)
		{
		    FaceColor fc;
		    fc.r = rand() % 255;
		    fc.g  = rand() % 255;
		    fc.b  = rand() % 255;
		    faceColors.push_back(fc);
		}
	}


    GameObject GameObject::ButterflySubSpaceDivision()
  	{
  #ifdef PrintToConsole
  			    cout << "entered subspace division method \n";
  #endif

  	    GameObject NGO = GameObject();
  	    vector<Face> faces;
  	    int fl = farr.size();
  	    int el = earr.size();// edge array isn't popluated currently

  	    //TODO:readd this method
  	    //NGO.varr.assign(varr, varr.size());//assign current vertices to the new object as none of these will change.
  	    //TODO: issue here not finding the correct vals. however these are already known.
  	    //EdgeFaces efs[el];

  	    ControlPoints cps[fl];
  	    EdgeEdges edgeEdges[el];

  #ifdef PrintToConsole
  			cout << "About to find edge faces \n";
  #endif

  		//EdgesFaces ef = EdgesFaces(earr2, farr);
  	   EdgesFaces ef = EdgesFaces(earr, farr); //this could be stored on object creation but makes sense to do it here.
  #ifdef HardDebug
  			cout << "Edge faces found \n";

  			for(unsigned int i = 0; i < ef.efsv.size(); ++i)
  			    {
  			std::cout << "edge faces " << i << "\n";
  			std::cout << "edge:" << ef.efsv[i].e.ToString() << "\n";
  			std::cout << "face a:" << ef.efsv[i].f[0].ToString() << "\n";
  			std::cout << "edge b:" << ef.efsv[i].f[1].ToString() << "\n";
  			    }

  #endif

  	    for(int fi = 0, ec = 0; fi < fl; ++fi )
  	    {
  #ifdef PrintToConsole
  	    cout << "on face: "<< fi+1 << " of " << fl << "\n";
  #endif
  	    FaceSplit fs;

  		for(int ei = 0; ei < 3; ++ei)
  		{
  #ifdef PrintToConsole
  		    cout << "on edge: "<< ei+1 << " of " << 3 << " is forward :" << farr[fi].isForward(ei) << " Edge Direction :" << farr[fi].edgeDirection << "\n";
  #endif

  		if(farr[fi].isForward(ei))
  		    {
  		    fs.ovs[ei] = farr[fi].earr[ei].a;
  		    fs.direction[ei] = true;
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

  		    //c1 - neighbors f10 - b1 and a1 are known
  		    Edge e1 = farr[fi].LocateEdge(cps[fi].a[0],cps[fi].b[0]);
  		    Face f10 = ef.FindFace(e1,farr[fi]);
  		    cps[fi].c[0] = f10.LocateFinalVertex(e1);

  		    //c2 - neighbors f2 - b1 and a2 are known
  		    Edge e2 = farr[fi].LocateEdge(cps[fi].a[1],cps[fi].b[0]);
  		    Face f2 = ef.FindFace(e2,farr[fi]);
  		    cps[fi].c[1] = f2.LocateFinalVertex(e2);

  		    //c3 - neighbors f2 - b2 and a2 are known
  		    Edge e3 = f1.LocateEdge(cps[fi].a[1],cps[fi].b[1]);
  		    Face f5 = ef.FindFace(e3,f1);
  		    cps[fi].c[2] = f5.LocateFinalVertex(e3);

  		    //c4 - neighbors f7 - b2 and a1 are known
  		    Edge e4 = f1.LocateEdge(cps[fi].a[0], cps[fi].b[1]);
  		    Face f7 = ef.FindFace(e4, f1);
  		    cps[fi].c[3] = f7.LocateFinalVertex(e4);

  #ifdef HardDebug
  		    cout << "a[0] Located :"<< cps[fi].a[0].ToString() <<"\n";
  		    cout << "a[1] Located :"<< cps[fi].a[1].ToString() <<"\n";
  		    cout << "b[0] Located :"<< cps[fi].b[0].ToString() <<"\n";
  		    cout << "b[1] Located :"<< cps[fi].b[1].ToString() <<"\n";
  		    cout << "c[0] Located :"<< cps[fi].c[0].ToString() <<"\n";
  		    cout << "c[1] Located :"<< cps[fi].c[1].ToString() <<"\n";
  		    cout << "c[2] Located :"<< cps[fi].c[2].ToString() <<"\n";
  		    cout << "c[3] Located :"<< cps[fi].c[3].ToString() <<"\n";
  #endif

  		//this list is built to help shared edges find new points.
  		fs.nvs[ei] = ButterflyCalculateNewVertex(cps[fi]);
  		edgeEdges[ec].parent = farr[fi].earr[ei];//TODO: this should be handled with pointers to minimize memory consumption
  		edgeEdges[ec].children[0] = Edge(farr[fi].earr[ei].a, fs.nvs[ei]);
  		edgeEdges[ec].children[1] = Edge(fs.nvs[ei],farr[fi].earr[ei].b);
  		++ec;
  		//this object is built to aid the creation of the new faces
  		fs.nes[ei*2] = edgeEdges[ec].children[0];
  		fs.nes[ei*2+1] = edgeEdges[ec].children[1];
  #ifdef PrintToConsole
  		cout << " New vertex calculated " << ButterflyCalculateNewVertex(cps[fi]).ToString() << "\n";
  #endif
  		    }else{		    //end if forward
  		    fs.direction[ei] = false;
  		    fs.ovs[ei] = farr[fi].earr[ei].b;
  		    //find the corresponding control point and edges here from using the edge array and edgeedges list and add it to the facesplit object.
  		    for(int i = 0; i < ec; ++i)
  		      {
  			  if(farr[fi].earr[ei] == edgeEdges[i].parent)
  			      {
  				  //can assume is anti clockwise ??? //TODO: review
  				  fs.nes[ei*2] = edgeEdges[i].children[1];
  				  fs.nes[ei*2+1] = edgeEdges[i].children[0];
  				  fs.nvs[ei] = edgeEdges[i].children[0].b;//TODO:should be provided as a pointer //TODO: another assumption review!!!!!
  			      }
  		      }

  		    }
  #ifdef PrintToConsole
  			cout << "\n";
  #endif
  		}//end edge loop
  #ifdef PrintToConsole
  			cout << "\n\n";
  #endif
  /*
   * triforce!!!
             /\
      ne2   /__\ ne3
           /\  /\
     ne1  /__\/_ \ ne4

  	ne6    ne5

  */
  			Edge ne[9];
  			Face nf[4];

			ne[0] = Edge(fs.ovs[0], fs.nvs[0]); //left bottom
			ne[1] = Edge(fs.nvs[0], fs.ovs[1]); //left top
			ne[2] = Edge(fs.ovs[1], fs.nvs[1]); //right top
			ne[3] = Edge(fs.nvs[1], fs.ovs[2]); //right bottom
			ne[4] = Edge(fs.ovs[2], fs.nvs[2]); //bottom right
			ne[5] = Edge(fs.nvs[2], fs.ovs[0]); //bottom left
			ne[6] = Edge(fs.nvs[0], fs.nvs[1]); //center top
			ne[7] = Edge(fs.nvs[1], fs.nvs[2]); //center right
			ne[8] = Edge(fs.nvs[0], fs.nvs[2]); //center left

			nf[0] = Face(ne[0], ne[8], ne[5]);
			nf[1] = Face(ne[1], ne[2], ne[6]);
			nf[2] = Face(ne[3], ne[4], ne[7], FFB);
			nf[3] = Face(ne[6], ne[7], ne[8]);

  			//TODO: selection block bellow can be optimized!
/*
  			if(fs.direction[0] && fs.direction[2])
  			    nf[0] = Face(ne[0], ne[8], ne[5], FFF);
  			else if(!fs.direction[0] && fs.direction[2])
  			    nf[0] = Face(ne[0], ne[8], ne[5], BFF);
  			else if(fs.direction[0] && !fs.direction[2])
  			    nf[0] = Face(ne[0], ne[8], ne[5], FFB);
  			else
  			    nf[0] = Face(ne[0], ne[8], ne[5], BFB);

  			if(fs.direction[0] && fs.direction[1])
  			  nf[1] = Face(ne[1], ne[2], ne[6]);
  			else if(!fs.direction[0] && fs.direction[1])
  			  nf[1] = Face(ne[1], ne[2], ne[6], BFF);
  			else if(fs.direction[0] && !fs.direction[1])
			  nf[1] = Face(ne[1], ne[2], ne[6], FFB);
  			else
  			  nf[1] = Face(ne[1], ne[2], ne[6], BFB);
*/

			faces.push_back(nf[0]);
			faces.push_back(nf[1]);
			faces.push_back(nf[2]);
			faces.push_back(nf[3]);
  			/*
  			NGO.farr.push_back(nf[0]);
  			NGO.farr.push_back(nf[1]);
  			NGO.farr.push_back(nf[2]);
  			NGO.farr.push_back(nf[3]);
*/

  	    }//end face loop
//delete[] cps;
//delete[] edgeEdges;
  #ifdef PrintToConsole
  		cout << "exiting method \n";
  #endif
  	    GameObject go =GameObject();
  	    go.farr = faces;
	    //EdgesFaces.
  	    //ef.~EdgesFaces();//EdgesFaces;
  	    return go;
  	    //return NGO;*
  	}

    void GameObject::Draw()
	{
	    for(unsigned int i = 0; i < farr.size(); ++i)
		{


#ifdef hardDebugVertexVals
	    for(unsigned int b = 0; b < 3; ++b)
		{
		cout << farr[i].earr[b].a.ToString() << "\n";
		cout << farr[i].earr[b].b.ToString() << "\n";
		}
#endif

		    glColor3ub(faceColors[i].r,faceColors[i].g,faceColors[i].b);
		    farr[i].Draw();
		}
	}

    void GameObject::Draw(int a)
	{

	    for(unsigned int i = 0; i < farr.size(); ++i)
		{



#ifdef hardDebugVertexVals

	    for(unsigned int b = 0; b < 3; ++b)
		{
		farr[i].earr[b].a.ToString();
		farr[i].earr[b].b.ToString();
		}
#endif

		    if(i%a == 0)
		    glColor3ub(faceColors[i].r,faceColors[i].g,faceColors[i].b);
		    farr[i].Draw();
		}
	}


    Vertex GameObject::ButterflyCalculateNewVertex(ControlPoints cps)
	{
	//TODO: not happy with this would rather it be in one line.
	float w =0.0625;
	float w2 = w*2;
	float h = 0.5;
	Vertex v1 = (cps.a[0] + cps.a[1]) * h;
	Vertex v2 = (cps.b[0]+cps.b[1])*w2;
	Vertex v3 = (cps.c[0] + cps.c[1] + cps.c[2] + cps.c[3])* w;

#ifdef PrintToConsole
//		cout << "v1: "<< v1.ToString() << "\n";
//		cout << "v2: "<< v2.ToString() << "\n";
//		cout << "v3: "<< v3.ToString() << "\n";
#endif

	return v1 + v2 - v3;
	}
/*
    struct ControlPoints
	{
	    Vertex a[2];
	    Vertex b[2];
	    Vertex c[4];
	    Vertex d[2];
	};
*/
    }

