/*
 * CatnullClarkSubDivision.cpp
 *
 *  Created on: Nov 29, 2011
 *      Author: Panda
 */

#include "../Header/CatmullClarkSubDivision.h"

namespace Game
    {




	GameObject CatmullClarkSubDivision::Subdivide(GameObject go)
		{
			//for each face in the object calculate the centroid
			vector<Vertex> faceCentroids;
			vector<NewControlPoints> newControlPoints;

			for(unsigned int i = 0; i < go.farr.size(); ++i)
			{
				Vertex * centroid = new Vertex(FindCentroid(go, i));
				faceCentroids.push_back(*centroid);

			}
			vector<Vertex> edgeMidpoints;
			for(unsigned int i = 0; i < go.earr.size(); ++i)
			{
				Vertex * edgeMidpoint = new Vertex((go.varr[go.earr[i].a] + go.varr[go.earr[i].b]).Divide(2));
				edgeMidpoints.push_back(*edgeMidpoint);
			}

			//vector<Vertex> newPoints;

			//foreach face
			for(unsigned int fi = 0;fi < go.farr.size(); fi++)
			{
				NewControlPoints newPoints;

				//foreach edge in faces
				for(int ei = 0; ei < 3; ei++)
				{
					//take facepoint
					int & currentEdge = go.farr[fi].earr[ei];
					bool isForward = go.farr[fi].isForward(ei);
					int VertexId = isForward ? go.earr[go.farr[fi].earr[ei]].a : go.earr[go.farr[fi].earr[ei]].b;
					int nextEdge, EdgeID;
					int currentFace = fi;
					int valance = 1;
					int nextFace = -1;

					vector<int> edgePoints;
					vector<int> facePoints;

					edgePoints.push_back(ei);
					facePoints.push_back(fi);

					while(nextFace != fi)
					{
						bool br = false;
						for(unsigned int _fi = 0; _fi < go.farr.size() && !br; _fi++)
						{
							if(_fi != currentFace && fi != _fi)//fi != _fi && _fi != nextFace))
							{
								for(int _ei = 0; _ei < 3; _ei++)
								{
									if(go.farr[_fi].earr[_ei] == currentEdge)
									{
										EdgeID = _ei;
										nextFace = _fi;
										facePoints.push_back(_fi);
										br = true;
										break;
									}
								}
							}
							else if(br)
							{
								break;
							}
						}

						if(!br)
						break;


						for(int _ei = 0; _ei < 3; _ei++)
							if(EdgeID != _ei)
								if(go.earr[go.farr[nextFace].earr[_ei]].a == VertexId || go.earr[go.farr[nextFace].earr[_ei]].b == VertexId)
								{
									nextEdge = go.farr[nextFace].earr[_ei];
									edgePoints.push_back(_ei);
								}


						currentEdge = nextEdge;
						currentFace = nextFace;
							//if(go.earr[go.farr[nextFace].earr[_ei]]. //if is forward
					}

					Vertex * newPoint = new Vertex(CalculateNewPoint(go, faceCentroids, edgeMidpoints, edgePoints, facePoints, VertexId));

					std::cout<< "new point"<< newPoint->ToString() <<"\n";

					newPoints.varr[ei]= *newPoint;
				}
					newControlPoints.push_back(newPoints);
			}




			GameObject ngo;

			for(int fi = 0; fi < go.farr.size(); fi++)
			{
				int vstart = ngo.varr.size();
				int estart = ngo.earr.size();
//				ngo.varr.push_back(newControlPoints[fi].varr[0]);         //a   0
//				ngo.varr.push_back(newControlPoints[fi].varr[1]);         //b   1
//				ngo.varr.push_back(newControlPoints[fi].varr[2]);         //c   2
//				ngo.varr.push_back(edgeMidpoints[go.farr[fi].earr[0]]);   //ea  3
//				ngo.varr.push_back(edgeMidpoints[go.farr[fi].earr[1]]);   //eb  4
//				ngo.varr.push_back(edgeMidpoints[go.farr[fi].earr[2]]);   //ec  5
//				ngo.varr.push_back(faceCentroids[fi]); 				//centroid  6



				Vertex * nv0 = new Vertex(newControlPoints[fi].varr[0]);         //a   0
				Vertex * nv1 = new Vertex(newControlPoints[fi].varr[1]);         //b   1
				Vertex * nv2 = new Vertex(newControlPoints[fi].varr[2]);         //c   2
				Vertex * nv3 = new Vertex(edgeMidpoints[go.farr[fi].earr[0]]);   //ea  3




				Vertex * nv4 = new Vertex(edgeMidpoints[go.farr[fi].earr[1]]);   //eb  4
				Vertex * nv5 = new Vertex(edgeMidpoints[go.farr[fi].earr[2]]);   //ec  5
				Vertex * nv6 = new Vertex(faceCentroids[fi]); 				//centroid  6

				std::cout << nv0->ToString() << "/n";
				std::cout << nv1->ToString() << "/n";
				std::cout << nv2->ToString() << "/n";
				std::cout << nv3->ToString() << "/n";
				std::cout << nv4->ToString() << "/n";
				std::cout << nv5->ToString() << "/n";
				std::cout << nv6->ToString() << "/n";

				ngo.varr.push_back(*nv0);
				ngo.varr.push_back(*nv1);
				ngo.varr.push_back(*nv2);
				ngo.varr.push_back(*nv3);
				ngo.varr.push_back(*nv4);
				ngo.varr.push_back(*nv5);
				ngo.varr.push_back(*nv6);

				Edge * ne0 = new Edge(vstart,   vstart+3); // a -> ea 0
				Edge * ne1 = new Edge(vstart+3, vstart+1); // ea -> b 1
				Edge * ne2 = new Edge(vstart+1, vstart+4); // b -> eb 2
				Edge * ne3 = new Edge(vstart+4, vstart+2); // eb -> c 3
				Edge * ne4 = new Edge(vstart+2, vstart+5); // c -> ec 4
				Edge * ne5 = new Edge(vstart+5, vstart);   // ec -> a 5
				Edge * ne6 = new Edge(vstart+3, vstart+6); // ea ->ce 6
				Edge * ne7 = new Edge(vstart+6, vstart+4); // ce ->eb 7
				Edge * ne8 = new Edge(vstart+5, vstart+6); // ec ->ce 8

				ngo.earr.push_back(*ne0);
				ngo.earr.push_back(*ne1);
				ngo.earr.push_back(*ne2);
				ngo.earr.push_back(*ne3);
				ngo.earr.push_back(*ne4);
				ngo.earr.push_back(*ne5);
				ngo.earr.push_back(*ne6);
				ngo.earr.push_back(*ne7);
				ngo.earr.push_back(*ne8);

				Face4 * f1 = new Face4(estart, estart+6, estart+8, estart+5, true, true, false, true);
				Face4 * f2 = new Face4(estart+1, estart+2, estart+7, estart+6, true, true, false, false);
				Face4 * f3 = new Face4(estart+7, estart+3, estart+4, estart+8, true, true, true, true);

				//debug points
				ngo.parr.push_back(*nv0);
				ngo.parr.push_back(*nv1);
				ngo.parr.push_back(*nv2);
				ngo.parr.push_back(*nv3);
				ngo.parr.push_back(*nv4);
				ngo.parr.push_back(*nv5);
				ngo.parr.push_back(*nv6);

				//go.earr[go.farr[i]]

				ngo.farr4.push_back(*f1);
				ngo.farr4.push_back(*f2);
				ngo.farr4.push_back(*f3);





			}

//
//			Vertex * a = new Vertex(-1, 0, 0);
//			Vertex * b = new Vertex(0, 1, 0);
//			Vertex * c = new Vertex(1, 0, 0);
//			Vertex * h = new Vertex(1, 1, 0);
//
//			Edge * d = new Edge( 0, 1);
//			Edge * e = new Edge( 1, 2);
//			Edge * f = new Edge( 2, 0);
//			Edge * i = new Edge( 2, 3);
//			Edge * j = new Edge( 3, 0);
//
//			Face3 * g = new Face3(0 , 1, 2);
//			Face4 * k = new Face4(0 , 1, 4, 5);
//
//			ngo.varr.push_back(*a );
//			ngo.varr.push_back(*b );
//			ngo.varr.push_back(*c );
//			ngo.varr.push_back(*h );
//
//			ngo.earr.push_back(*d );
//			ngo.earr.push_back(*e );
//			ngo.earr.push_back(*f );
//			ngo.earr.push_back(*i );
//			ngo.earr.push_back(*j );
//
//			ngo.farr.push_back( *g );
//			ngo.farr4.push_back(*k );

			return ngo;
	    }

	Vertex CatmullClarkSubDivision::FindCentroid(GameObject &go, int Face)
	{
		//Method is broken!
		Vertex centroid;
		centroid = go.varr[go.earr[go.farr[Face].earr[0]].a] + go.varr[go.earr[go.farr[Face].earr[0]].b];
		//find last vertex in the second edge
		centroid = go.earr[go.farr[Face].earr[0]].a != go.earr[go.farr[Face].earr[1]].a && go.earr[go.farr[Face].earr[0]].b != go.earr[go.farr[Face].earr[1]].a ? centroid + go.varr[go.earr[go.farr[Face].earr[0]].a] : centroid + go.varr[go.earr[go.farr[Face].earr[1]].b];
		centroid = centroid.Divide(3);
		return centroid;
	}

	Vertex CatmullClarkSubDivision::CalculateNewPoint(GameObject &go, vector<Vertex> &FaceCentroids, vector<Vertex> &EdgeMidPoints, vector<int> &EdgePoints, vector<int> &FacePoints, int ControlPoint)
	{
		//(Q/n) + (2R/n) + (S(n-3)/n)
		//where q is the average of the surrounding facepoints
		//r is the average of the surrounding edge midpoints
		//s is the control point

		int n = FacePoints.size();
		Vertex q = FaceCentroids[FacePoints[0]];
		Vertex r = EdgeMidPoints[EdgePoints[0]];
		Vertex s = go.varr[ControlPoint].Multiply(n-3);

		for(unsigned int i = 1; i < FacePoints.size(); ++i )
		{
			q = q + FaceCentroids[FacePoints[i]];
		}

		for(unsigned int i = 1; i < EdgePoints.size(); ++i )
		{
			r = r + EdgeMidPoints[EdgePoints[i]];
		}
		r = r.Multiply(2);//.Divide(n);
		r = r.Divide(n);
		q = q.Divide(n);
		s = s.Divide(n);

		return (r + q + s);
	}


    /*CatnullClarkSubDivision::CatnullClarkSubDivision()
	{
	// TODO Auto-generated constructor stub

	}

    CatnullClarkSubDivision::~CatnullClarkSubDivision()
	{
	// TODO Auto-generated destructor stub
	}
*/
    }
