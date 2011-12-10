///* ctrl+a then ctrl + / slash to comment all
// * ButterflySubspaceDivision.cpp
// *
// *  Created on: Nov 29, 2011
// *      Author: Panda
// */
//
//#include "../Header/ButterflySubspaceDivision.h"
//
////#define PrintToConsole
//
//namespace Game
//    {
//
//    Vertex ButterflySubspaceDivision::ButterflyCalculateNewVertex(ControlPoints controlPoints)
//		{
//		//TODO: not happy with this would rather it be in one line.
//		float w = 0.0625;//tension of control net // 1 will equate to plane teseleation ie just increase poly count;
//		float w2 = w*2;
//		float h = 0.5;
//		Vertex v1 = (controlPoints.a[0] + controlPoints.a[1]) * h;
//		Vertex v2 = (controlPoints.b[0]+controlPoints.b[1])*w2;
//		Vertex v3 = (controlPoints.c[0] + controlPoints.c[1] + controlPoints.c[2] + controlPoints.c[3])* w;
//
//		return v1 + v2 - v3;
//
//		}
//
//	GameObject ButterflySubspaceDivision::Tessellate(const GameObject& got)
//		{
//		GameObject NGO;
//
//#ifdef PrintToConsole
//				cout << "entered subspace division method \n";
//#endif
//			GameObject go = got;
//
//			int fl = go.farr.size();
//			int el = go.earr.size();
//			//NGO.varr = go.varr;//assign current vertices to the new object as none of these will change.
//			EdgeEdges edgeEdges[el];
//
//
//#ifdef PrintToConsole
//			cout << "About to find edge faces \n";
//#endif
//			EdgesFaces ef = EdgesFaces(go.earr, go.farr); //this could be stored on object creation...
//#ifdef PrintToConsole
//			cout << "Edge faces found \n";
//#endif
//			FaceSplit fs[fl];
//
//			for(int fi = 0, ec = 0; fi < fl  ; ++fi )
//			{
//#ifdef PrintToConsole
//		cout << "on face: "<< fi+1 << " of " << fl << "\n";
//#endif
//			//FaceSplit fs;
//
//			for(int ei = 0; ei < 3; ++ei)
//			{
//#ifdef PrintToConsole
//			cout << "on edge: "<< ei+1 << " of " << 3 << " is forward :" << go.farr[fi].isForward(ei) << " Edge Direction :" << go.farr[fi].edgeDirection << "\n";
//#endif
//
//			if(go.farr[fi].isForward(ei))
//				{
//				ControlPoints cps;
//				fs[fi].ovs[ei] = *go.farr[fi].earr[ei]->a;
//				fs[fi].direction[ei] = true;
//				/*
//	control point positions labeled for reference
//
//					 c1     b1     c2
//					/  \f10/  \ f2/  \
//				   / f9 \ / f1 \ / f3 \
//				 d1---- -a1--*--a2----d2
//				   \ f8 / \ f6 / \ f4 /
//					\  /f7 \  / f5\  /
//					 c4     b2     c3
//				 */
//				//a1 /a[0]
//				cps.a[0] = *go.farr[fi].earr[ei]->a;
//
//				//a1 /a[1]
//				cps.a[1] = *go.farr[fi].earr[ei]->b;
//
//				//b1 /b[0]
//				cps.b[0] = go.farr[fi].LocateFinalVertex(*go.farr[fi].earr[ei]);
//
//				//b1
//				Face f1 = ef.FindFace(*go.farr[fi].earr[ei], go.farr[fi]);
//				cps.b[1] = f1.LocateFinalVertex(*go.farr[fi].earr[ei]);
//
//				//c1 - neighbors f10 - b1 and a1 are known
//				Edge e1 = go.farr[fi].LocateEdge(cps.a[0],cps.b[0]);
//				Face f10 = ef.FindFace(e1,go.farr[fi]);
//				cps.c[0] = f10.LocateFinalVertex(e1);
//
//				//c2 - neighbors f2 - b1 and a2 are known
//				Edge e2 = go.farr[fi].LocateEdge(cps.a[1],cps.b[0]);
//				Face f2 = ef.FindFace(e2,go.farr[fi]);
//				cps.c[1] = f2.LocateFinalVertex(e2);
//
//				//c3 - neighbors f2 - b2 and a2 are known
//				Edge e3 = f1.LocateEdge(cps.a[1],cps.b[1]);
//				Face f5 = ef.FindFace(e3,f1);
//				cps.c[2] = f5.LocateFinalVertex(e3);
//
//				//c4 - neighbors f7 - b2 and a1 are known
//				Edge e4 = f1.LocateEdge(cps.a[0], cps.b[1]);
//				Face f7 = ef.FindFace(e4, f1);
//				cps.c[3] = f7.LocateFinalVertex(e4);
//
//#ifdef PrintToConsole
//				cout << "a[0] Located :"<< cps.a[0].ToString() <<"\n";
//				cout << "a[1] Located :"<< cps.a[1].ToString() <<"\n";
//				cout << "b[0] Located :"<< cps.b[0].ToString() <<"\n";
//				cout << "b[1] Located :"<< cps.b[1].ToString() <<"\n";
//				cout << "c[0] Located :"<< cps.c[0].ToString() <<"\n";
//				cout << "c[1] Located :"<< cps.c[1].ToString() <<"\n";
//				cout << "c[2] Located :"<< cps.c[2].ToString() <<"\n";
//				cout << "c[3] Located :"<< cps.c[3].ToString() <<"\n";
//#endif
//				fs[fi].nvs[ei] = ButterflyCalculateNewVertex(cps);
//				//this list is build to help shared edges find new points
//				edgeEdges[ec].parent = *go.farr[fi].earr[ei];//TODO: this should be handled with pointers to minimize memory consumption
//				edgeEdges[ec].children[0] = Edge(go.farr[fi].earr[ei]->a, &fs[fi].nvs[ei]);
//				edgeEdges[ec].children[1] = Edge(&fs[fi].nvs[ei],&*go.farr[fi].earr[ei]->b);
//				++ec;
//#ifdef PrintToConsole
//		cout << " New vertex calculated " << ButterflyCalculateNewVertex(cps).ToString() << "\n";
//#endif
//				}
//				else
//				{		    //end if forward
//				fs[fi].direction[ei] = false; //set backwards
//				fs[fi].ovs[ei] = *go.farr[fi].earr[ei]->b;
//				//find the corresponding control point and edges here from using the edge array and edgeedges list and add it to the facesplit object.
//				for(int i = 0; i < ec; ++i)
//				  {
//					  if(*go.farr[fi].earr[ei] == edgeEdges[i].parent)
//						  {
//						  fs[fi].nvs[ei] = *edgeEdges[i].children[1].a;
//	#ifdef PrintToConsole
//						  cout << "edge Edges is found \n";
//						  cout << "fs.nvs["<<ei<<"]"<< fs[fi].nvs[ei].ToString() << "\n";
//	#endif
//							  break;
//	#ifdef PrintToConsole
//					  }else if(i == ec-1)
//					  {
//
//						  cout << "edge Edges not found \n";
//	#endif
//					  }
//				  }
//				}
//#ifdef PrintToConsole
//			cout << "\n";
//#endif
//
//			}
//			//end edge loop
//#ifdef PrintToConsole
//			cout << "\n\n";
//#endif
//	/*
//	* triforce!!!
//		    /\
//	ne2    /__\	ne3
//   		  /\  /\
//	ne1  /__\/_ \ ne4
//
//		ne6    ne5
//
//	*/
//
//				Vertex * ovs0 = new Vertex(fs[fi].ovs[0]);
//				Vertex * ovs1 = new Vertex(fs[fi].ovs[1]);
//				Vertex * ovs2 = new Vertex(fs[fi].ovs[2]);
//				Vertex * nvs0 = new Vertex(fs[fi].nvs[0]);
//				Vertex * nvs1 = new Vertex(fs[fi].nvs[1]);
//				Vertex * nvs2 = new Vertex(fs[fi].nvs[2]);
//
//				Edge * ne0 = new Edge( *ovs0, *nvs0);
//				Edge * ne1 = new Edge( *nvs0, *ovs1);
//				Edge * ne2 = new Edge( *ovs1, *nvs1);
//				Edge * ne3 = new Edge( *nvs1, *ovs2);
//				Edge * ne4 = new Edge( *ovs2, *nvs2);
//				Edge * ne5 = new Edge( *nvs2, *ovs0);
//				Edge * ne6 = new Edge( *nvs0, *nvs1);
//				Edge * ne7 = new Edge( *nvs1, *nvs2);
//				Edge * ne8 = new Edge( *nvs2, *nvs0);
//
//				Face * nf0 = new Face(*ne0, *ne8, *ne5, FBF);
//				Face * nf1 = new Face(*ne1, *ne2, *ne6);
//				Face * nf2 = new Face(*ne3, *ne4, *ne7);
//				Face * nf3 = new Face(*ne6, *ne7, *ne8);
//
//				NGO.varr.push_back(*ovs0);
//				NGO.varr.push_back(*ovs1);
//				NGO.varr.push_back(*ovs2);
//				NGO.varr.push_back(*nvs0);
//				NGO.varr.push_back(*nvs1);
//				NGO.varr.push_back(*nvs2);
//
//				NGO.earr.push_back(*ne0);
//				NGO.earr.push_back(*ne1);
//				NGO.earr.push_back(*ne2);
//				NGO.earr.push_back(*ne3);
//				NGO.earr.push_back(*ne4);
//				NGO.earr.push_back(*ne5);
//				NGO.earr.push_back(*ne6);
//				NGO.earr.push_back(*ne7);
//				NGO.earr.push_back(*ne8);
//
//				NGO.farr.push_back(*nf0);
//				NGO.farr.push_back(*nf1);
//				NGO.farr.push_back(*nf2);
//				NGO.farr.push_back(*nf3);
//
//
//#ifdef SPrintToConsole
//		std::cout << "Vertex Pointer Value Check face "<< fi << "\n";
//
//		std::cout << "new vertex 0 "<< fs[fi].nvs[0].ToString() << " Edge  \n";
//		std::cout << "new vertex 1 "<< fs[fi].nvs[1].ToString() << " Edge  \n";
//		std::cout << "new vertex 2 "<< fs[fi].nvs[2].ToString() << " Edge  \n";
//		std::cout << "old vertex 0 "<< fs[fi].ovs[0].ToString() << " Edge  \n";
//		std::cout << "old vertex 1 "<< fs[fi].ovs[1].ToString() << " Edge  \n";
//		std::cout << "old vertex 2 "<< fs[fi].ovs[2].ToString() << " Edge  \n";
//
//		std::cout << "new edge 1 "<< ne[1].ToString() << " Edge  \n";
//		std::cout << "new edge 2 "<< ne[2].ToString() << " Edge  \n";
//		std::cout << "new edge 3 "<< ne[3].ToString() << " Edge  \n";
//		std::cout << "new edge 4 "<< ne[4].ToString() << " Edge  \n";
//		std::cout << "new edge 5 "<< ne[5].ToString() << " Edge  \n";
//		std::cout << "new edge 6 "<< ne[6].ToString() << " Edge  \n";
//		std::cout << "new edge 7 "<< ne[7].ToString() << " Edge  \n";
//		std::cout << "new edge 8 "<< ne[8].ToString() << " Edge  \n";
//#endif
//
//
//		}//end face loop
//#ifdef DPrintToConsole
//		cout << "exiting method \n";
//		for(unsigned int i = 0; i < NGO.farr.size(); i++)
//		std::cout << i <<'/'<< NGO.farr.size() << NGO.farr[i].ToString() << "\n";
//#endif
//
//			return NGO ;
//		}
//
//
//    }
//
//
///*
//	if(fs.direction[0] && fs.direction[2])
//	    nf[0] = Face(ne[0], ne[8], ne[5], FFF);
//	else if(!fs.direction[0] && fs.direction[2])
//	    nf[0] = Face(ne[0], ne[8], ne[5], BFF);
//	else if(fs.direction[0] && !fs.direction[2])
//	    nf[0] = Face(ne[0], ne[8], ne[5], FFB);
//	else
//	    nf[0] = Face(ne[0], ne[8], ne[5], BFB);*/
///*
//	if(fs.direction[0] && fs.direction[1])
//	  nf[1] = Face(ne[1], ne[2], ne[6]);
//	else if(!fs.direction[0] && fs.direction[1])
//	  nf[1] = Face(ne[1], ne[2], ne[6], BFF);
//	else if(fs.direction[0] && !fs.direction[1])
//	  nf[1] = Face(ne[1], ne[2], ne[6], FFB);
//	else
//	  nf[1] = Face(ne[1], ne[2], ne[6], BFB);
//*/
//
//	//Face nf = Face(ne1, ne9, ne6);
//	/* use the facesplit object to create the 4 new faces and place them in the NGO object */
//
//	 //3 new edges will still need to be created here!!! nes7 nes8 nes9 these are the edges of the internal tri!
//	//nes7 is a linking of nvs[0] and nvs[1]
//	//nes8 is a linking of nvs[1] and nvs[2]
//	//nes9 is a linking of nvs[2] and nvs[0]
//
//	//NGO.varr.assign(varr, varr+vl)
//	//NGO.varr.assign(ne, ne+9)
