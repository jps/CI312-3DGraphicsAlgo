/*
 * ButterflySubspaceDivision.cpp
 *
 *  Created on: Nov 29, 2011
 *      Author: Panda
 */

#include "../Header/ButterflySubspaceDivision.h"

#define PrintToConsole

namespace Game
    {
/*
    ButterflySubspaceDivision::ButterflySubspaceDivision()
	{
	// TODO Auto-generated constructor stub

	}

    ButterflySubspaceDivision::~ButterflySubspaceDivision()
	{
	// TODO Auto-generated destructor stub
	}
*/

    Vertex ButterflySubspaceDivision::ButterflyCalculateNewVertex(ControlPoints controlPoints)
	{
	//TODO: not happy with this would rather it be in one line.
	float w =0.0625;
	float w2 = w*2;
	float h = 0.5;
	Vertex v1 = (controlPoints.a[0] + controlPoints.a[1]) * h;
	Vertex v2 = (controlPoints.b[0]+controlPoints.b[1])*w2;
	Vertex v3 = (controlPoints.c[0] + controlPoints.c[1] + controlPoints.c[2] + controlPoints.c[3])* w;

#ifdef PrintToConsole
//		cout << "v1: "<< v1.ToString() << "\n";
//		cout << "v2: "<< v2.ToString() << "\n";
//		cout << "v3: "<< v3.ToString() << "\n";
#endif

	return v1 + v2 - v3;
	}



GameObject ButterflySubspaceDivision::Tessellate(const GameObject& got)
	{
#ifdef PrintToConsole
			    cout << "entered subspace division method \n";
#endif

	    GameObject go = got;

	    GameObject NGO = GameObject();
	    int fl = go.farr.size();
	    int el = go.earr.size();
	    //int vl = go.varr.size();
	    NGO.varr = go.varr;//assign current vertices to the new object as none of these will change.


	    //TODO: issue here not finding the correct vals. however these are already known.
	    //EdgeFaces efs[el];
	    //ControlPoints cps[el];
	    EdgeEdges edgeEdges[el];

#ifdef PrintToConsole
			cout << "About to find edge faces \n";
#endif
	    EdgesFaces ef = EdgesFaces(go.earr, go.farr); //this could be stored on object creation...
#ifdef PrintToConsole
			cout << "Edge faces found \n";
#endif

	    for(int fi = 0, ec = 0; fi < fl && fi < 36; ++fi )
	    {


	    if(fl != 37 ||fl != 38 ||fl != 36 || fl != 39 )
		{

#ifdef PrintToConsole
	    cout << "on face: "<< fi+1 << " of " << fl << "\n";
#endif
	    FaceSplit fs;

		for(int ei = 0; ei < 3; ++ei)
		{
#ifdef PrintToConsole
		    cout << "on edge: "<< ei+1 << " of " << 3 << " is forward :" << go.farr[fi].isForward(ei) << " Edge Direction :" << go.farr[fi].edgeDirection << "\n";
#endif

		if(go.farr[fi].isForward(ei))
		    {
		    ControlPoints cps;
		    fs.ovs[ei] = *go.farr[fi].earr[ei].a;
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
		    cps.a[0] = *go.farr[fi].earr[ei].a;

		    //a1 /a[1]
		    cps.a[1] = *go.farr[fi].earr[ei].b;

		    //b1 /b[0]
		    cps.b[0] = go.farr[fi].LocateFinalVertex(go.farr[fi].earr[ei]);

		    //b1
		    Face f1 = ef.FindFace(go.farr[fi].earr[ei], go.farr[fi]);
		    cps.b[1] = f1.LocateFinalVertex(go.farr[fi].earr[ei]);

		    //c1 - neighbors f10 - b1 and a1 are known
		    Edge e1 = go.farr[fi].LocateEdge(cps.a[0],cps.b[0]);
		    Face f10 = ef.FindFace(e1,go.farr[fi]);
		    cps.c[0] = f10.LocateFinalVertex(e1);

		    //c2 - neighbors f2 - b1 and a2 are known
		    Edge e2 = go.farr[fi].LocateEdge(cps.a[1],cps.b[0]);
		    Face f2 = ef.FindFace(e2,go.farr[fi]);
		    cps.c[1] = f2.LocateFinalVertex(e2);

		    //c3 - neighbors f2 - b2 and a2 are known
		    Edge e3 = f1.LocateEdge(cps.a[1],cps.b[1]);
		    Face f5 = ef.FindFace(e3,f1);
		    cps.c[2] = f5.LocateFinalVertex(e3);

		    //c4 - neighbors f7 - b2 and a1 are known
		    Edge e4 = f1.LocateEdge(cps.a[0], cps.b[1]);
		    Face f7 = ef.FindFace(e4, f1);
		    cps.c[3] = f7.LocateFinalVertex(e4);

#ifdef PrintToConsole
		    cout << "a[0] Located :"<< cps.a[0].ToString() <<"\n";
		    cout << "a[1] Located :"<< cps.a[1].ToString() <<"\n";
		    cout << "b[0] Located :"<< cps.b[0].ToString() <<"\n";
		    cout << "b[1] Located :"<< cps.b[1].ToString() <<"\n";
		    cout << "c[0] Located :"<< cps.c[0].ToString() <<"\n";
		    cout << "c[1] Located :"<< cps.c[1].ToString() <<"\n";
		    cout << "c[2] Located :"<< cps.c[2].ToString() <<"\n";
		    cout << "c[3] Located :"<< cps.c[3].ToString() <<"\n";
#endif

		//Edge ne1 = Edge(farr[fi].earr[ei].a, nv1);
		//Edge ne2 = Edge(nv1,farr[fi].earr[ei].b);

		//this list is build to help shared edges find new points
		fs.nvs[ei] = ButterflyCalculateNewVertex(cps);
		edgeEdges[ec].parent = go.farr[fi].earr[ei];//TODO: this should be handled with pointers to minimize memory consumption
		edgeEdges[ec].children[0] = Edge(&*go.farr[fi].earr[ei].a, &fs.nvs[ei]);
		edgeEdges[ec].children[1] = Edge(&fs.nvs[ei],&*go.farr[fi].earr[ei].b);
		++ec;
		//this object is built to aid the creation of the new faces
		fs.nes[ei*2] = edgeEdges[ec].children[0];
		fs.nes[ei*2+1] = edgeEdges[ec].children[1];
#ifdef PrintToConsole
		cout << " New vertex calculated " << ButterflyCalculateNewVertex(cps).ToString() << "\n";
#endif

		    }else{		    //end if forward
		    fs.direction[ei] = false; //set backwards
		    fs.ovs[ei] = *go.farr[fi].earr[ei].b;
		    //find the corresponding control point and edges here from using the edge array and edgeedges list and add it to the facesplit object.
		    for(int i = 0; i < ec; ++i)
		      {
			  if(go.farr[fi].earr[ei] == edgeEdges[i].parent)
			      {
				  //
				  //can assume is anti clockwise ??? //TODO: review
				  fs.nes[ei*2] = edgeEdges[i].children[0];
				  fs.nes[ei*2+1] = edgeEdges[i].children[1];
				  fs.nvs[ei] = *edgeEdges[i].children[1].a;//TODO:should be provided as a pointer //TODO: another assumption review!!!!!
#ifdef PrintToConsole
			          cout << "edge Edges not found \n";
			      }else{
			          cout << "edge Edges is found \n";
			      }
#endif
		      }

		    }
#ifdef PrintToConsole
			cout << "\n";
#endif

		}
		//end edge loop
#ifdef PrintToConsole
			cout << "\n\n";
#endif
/*
* triforce!!!
       /\
ne2   /__\	ne3
     /\  /\
ne1  /__\/_ \ ne4

	ne6    ne5

*/

#ifdef PrintToConsole
	//		cout << "Verticies for new faces ovs[o] " << fs.ovs[0].ToString() << " ovs[1] " << fs.ovs[1].ToString() << " ovs[2] " << fs.ovs[2].ToString() << "\n" << " nvs[0] " << fs.nvs[0].ToString() << "nvs[1] " << fs.nvs[1].ToString() << " nvs[2] " << fs.nvs[2].ToString() << "\n";
#endif

			Edge ne[9];
			Face nf[4];

			unsigned int startIndex = NGO.varr.size(); //this is the array index of where the first value is inserted into the vertex vector

			NGO.varr.push_back(fs.ovs[0]);//0
			NGO.varr.push_back(fs.ovs[1]);//1
			NGO.varr.push_back(fs.ovs[2]);//2
			NGO.varr.push_back(fs.nvs[0]);//3
			NGO.varr.push_back(fs.nvs[1]);//4
			NGO.varr.push_back(fs.nvs[2]);//5

			ne[0] = Edge(&NGO.varr[startIndex], &NGO.varr[startIndex+3]); //left bottom
			//ne[0] = Edge(&fs.ovs[0], &fs.nvs[0]); //left bottom
			ne[1] = Edge(&NGO.varr[startIndex+3], &NGO.varr[startIndex+1]); //left top
			//ne[1] = Edge(&fs.nvs[0], &fs.ovs[1]); //left top
			ne[2] = Edge(&NGO.varr[startIndex+1], &NGO.varr[startIndex+4]); //right top
			//ne[2] = Edge(&fs.ovs[1], &fs.nvs[1]); //right top
			ne[3] = Edge(&NGO.varr[startIndex+4], &NGO.varr[startIndex+2]); //right bottom
			//ne[3] = Edge(&fs.nvs[1], &fs.ovs[2]); //right bottom
			ne[4] = Edge(&NGO.varr[startIndex+2], &NGO.varr[startIndex+5]); //bottom right
			//ne[4] = Edge(&fs.ovs[2], &fs.nvs[2]); //bottom right
			ne[5] = Edge(&NGO.varr[startIndex+5], &NGO.varr[startIndex+2]); //bottom left
			//ne[5] = Edge(&fs.nvs[2], &fs.ovs[0]); //bottom left
			ne[6] = Edge(&NGO.varr[startIndex+3], &NGO.varr[startIndex+4]); //center top
			//ne[6] = Edge(&fs.nvs[0], &fs.nvs[1]); //center top
			ne[7] = Edge(&NGO.varr[startIndex+4], &NGO.varr[startIndex+5]); //center right
			//ne[7] = Edge(&fs.nvs[1], &fs.nvs[2]); //center right
			ne[8] = Edge(&NGO.varr[startIndex+3], &NGO.varr[startIndex+5]); //center right
			//ne[8] = Edge(&fs.nvs[0], &fs.nvs[2]); //center left
			/*
			ne[0] = Edge(&fs.ovs[0], &fs.nvs[0]); //left bottom
			ne[1] = Edge(&fs.nvs[0], &fs.ovs[1]); //left top
			ne[2] = Edge(&fs.ovs[1], &fs.nvs[1]); //right top
			ne[3] = Edge(&fs.nvs[1], &fs.ovs[2]); //right bottom
			ne[4] = Edge(&fs.ovs[2], &fs.nvs[2]); //bottom right
			ne[5] = Edge(&fs.nvs[2], &fs.ovs[0]); //bottom left
			ne[6] = Edge(&fs.nvs[0], &fs.nvs[1]); //center top
			ne[7] = Edge(&fs.nvs[1], &fs.nvs[2]); //center right
			ne[8] = Edge(&fs.nvs[0], &fs.nvs[2]); //center left
			*/
			nf[0] = Face(ne[0], ne[8], ne[5]);
			nf[1] = Face(ne[1], ne[2], ne[6]);
			nf[2] = Face(ne[3], ne[4], ne[7]);
			nf[3] = Face(ne[6], ne[7], ne[8]);

			for(int i = 0; i < 9; i++)
				NGO.earr.push_back(ne[i]);//TODO: this appears to be putting random values in....

			NGO.farr.push_back(nf[0]);
			NGO.farr.push_back(nf[1]);
			NGO.farr.push_back(nf[2]);
			NGO.farr.push_back(nf[3]);
			/*
			if(fs.direction[0] && fs.direction[2])
			    nf[0] = Face(ne[0], ne[8], ne[5], FFF);
			else if(!fs.direction[0] && fs.direction[2])
			    nf[0] = Face(ne[0], ne[8], ne[5], BFF);
			else if(fs.direction[0] && !fs.direction[2])
			    nf[0] = Face(ne[0], ne[8], ne[5], FFB);
			else
			    nf[0] = Face(ne[0], ne[8], ne[5], BFB);*/
/*
			if(fs.direction[0] && fs.direction[1])
			  nf[1] = Face(ne[1], ne[2], ne[6]);
			else if(!fs.direction[0] && fs.direction[1])
			  nf[1] = Face(ne[1], ne[2], ne[6], BFF);
			else if(fs.direction[0] && !fs.direction[1])
			  nf[1] = Face(ne[1], ne[2], ne[6], FFB);
			else
			  nf[1] = Face(ne[1], ne[2], ne[6], BFB);
*/

			//Face nf = Face(ne1, ne9, ne6);
			/* use the facesplit object to create the 4 new faces and place them in the NGO object */

			 //3 new edges will still need to be created here!!! nes7 nes8 nes9 these are the edges of the internal tri!
			//nes7 is a linking of nvs[0] and nvs[1]
			//nes8 is a linking of nvs[1] and nvs[2]
			//nes9 is a linking of nvs[2] and nvs[0]

			//NGO.varr.assign(varr, varr+vl)
			//NGO.varr.assign(ne, ne+9)

#ifdef PrintToConsole
		std::cout << "Vertex Pointer Value Check face "<< fi << "\n";

		std::cout << "new vertex 0 "<< fs.nvs[0].ToString() << " Edge  \n";
		std::cout << "new vertex 1 "<< fs.nvs[1].ToString() << " Edge  \n";
		std::cout << "new vertex 2 "<< fs.nvs[2].ToString() << " Edge  \n";
		std::cout << "old vertex 0 "<< fs.ovs[0].ToString() << " Edge  \n";
		std::cout << "old vertex 1 "<< fs.ovs[1].ToString() << " Edge  \n";
		std::cout << "old vertex 2 "<< fs.ovs[2].ToString() << " Edge  \n";

//		&fs.nvs[0],
		std::cout << "new edge 0 "<< ne

[0].ToString() << " Edge  \n";
		std::cout << "new edge 1 "<< ne[1].ToString() << " Edge  \n";
		std::cout << "new edge 2 "<< ne[2].ToString() << " Edge  \n";
		std::cout << "new edge 3 "<< ne[3].ToString() << " Edge  \n";
		std::cout << "new edge 4 "<< ne[4].ToString() << " Edge  \n";
		std::cout << "new edge 5 "<< ne[5].ToString() << " Edge  \n";
		std::cout << "new edge 6 "<< ne[6].ToString() << " Edge  \n";
		std::cout << "new edge 7 "<< ne[7].ToString() << " Edge  \n";
		std::cout << "new edge 8 "<< ne[8].ToString() << " Edge  \n";
		//std::cout << "Vertex Pointer Value Check face "<< fi << " Edge " << ei << " \n";


#endif

	    }
	}//end face loop
#ifdef PrintToConsole
		cout << "exiting method \n";
#endif
		std::cout << NGO.farr[0].ToString() << "\n";
		std::cout << NGO.farr[1].ToString() << "\n";
		std::cout << NGO.farr[2].ToString() << "\n";
		std::cout << NGO.farr[3].ToString() << "\n";
		std::cout << NGO.farr[4].ToString() << "\n";
		std::cout << NGO.farr[5].ToString() << "\n";
	    return NGO;
	}
    }

