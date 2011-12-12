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
			vector<Vertex> faceCentroids;
			vector<Vertex> edgeMidpoints;
			vector<NewControlPoints> newControlPoints;

			//for each face in the object calculate the centroid
			for(unsigned int i = 0; i < go.farr.size(); ++i)
			{
				Vertex * centroid = new Vertex(FindCentroid(go, i));
				faceCentroids.push_back(*centroid);

			}

			//for each edge in the game object find the midpoint
			for(unsigned int i = 0; i < go.earr.size(); ++i)
			{
				Vertex * edgeMidpoint = new Vertex((go.varr[go.earr[i].a] + go.varr[go.earr[i].b]).Divide(2));
				edgeMidpoints.push_back(*edgeMidpoint);
			}

			//foreach face in game object
			for(unsigned int fi = 0;fi < go.farr.size(); fi++)
			{
				NewControlPoints newPoints;

				//foreach edge in face
				for(int ei = 0; ei < 3; ei++)
				{
					//take facepoint
					int & currentEdge = go.farr[fi].earr[ei];
					bool isForward = go.farr[fi].isForward(ei);
					int VertexId = isForward ? go.earr[go.farr[fi].earr[ei]].a : go.earr[go.farr[fi].earr[ei]].b;
					int nextEdge, EdgeID;
					unsigned int currentFace = fi;
					unsigned int nextFace = -1;

					vector<int> edgePoints;
					vector<int> facePoints;
					edgePoints.push_back(go.farr[fi].earr[ei]); //add current edged to midpoint list
					facePoints.push_back(fi); //add current face point

					while(nextFace != fi)
					{
						bool br = false;
						for(unsigned int _fi = 0; _fi < go.farr.size(); _fi++)
						{
							if(_fi != currentFace && fi != _fi)//check that face is not equal to the current face
							{
								for(int _ei = 0; _ei < 3; _ei++) //for each edge in face
								{
									if(go.farr[_fi].earr[_ei] == currentEdge) //compage edge with current edge to find the winging face
									{
										EdgeID = _ei;
										nextFace = _fi;
										facePoints.push_back(_fi);
										br = true;
										break;
									}
								}
							}
							if(br)
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
									edgePoints.push_back(nextEdge);
								}
						currentEdge = nextEdge;
						currentFace = nextFace;
					}

					Vertex * newPoint = new Vertex(CalculateNewPoint(go, faceCentroids, edgeMidpoints, edgePoints, facePoints, VertexId));
					newPoints.varr[ei]= *newPoint;
#ifdef Debug
					std::cout<< "new point"<< newPoint->ToString() <<"\n";
#endif
				}
					newControlPoints.push_back(newPoints);
			}

			GameObject ngo;

			for(unsigned int fi = 0; fi < go.farr.size(); fi++)
			{
				int vstart = ngo.varr.size();
				int estart = ngo.earr.size();

				Vertex * nv0 = new Vertex(newControlPoints[fi].varr[0]);         //a   0
				Vertex * nv1 = new Vertex(newControlPoints[fi].varr[1]);         //b   1
				Vertex * nv2 = new Vertex(newControlPoints[fi].varr[2]);         //c   2
				Vertex * nv3 = new Vertex(edgeMidpoints[go.farr[fi].earr[1]]);   //ea  3
				Vertex * nv4 = new Vertex(edgeMidpoints[go.farr[fi].earr[2]]);   //eb  4 //TODO: review
				Vertex * nv5 = new Vertex(edgeMidpoints[go.farr[fi].earr[0]]);   //ec  5
				Vertex * nv6 = new Vertex(faceCentroids[fi]); 				//centroid  6

#ifdef Debug
				std::cout << "\n printing points for new faces based on face " << fi << "\n";
				std::cout << nv0->ToString() << "\n ";
				std::cout << nv1->ToString() << "\n ";
				std::cout << nv2->ToString() << "\n ";
				std::cout << nv3->ToString() << "\n ";
				std::cout << nv4->ToString() << "\n ";
				std::cout << nv5->ToString() << "\n ";
				std::cout << nv6->ToString() << "\n ";
#endif
				ngo.varr.push_back(*nv0);
				ngo.varr.push_back(*nv1);
				ngo.varr.push_back(*nv2);
				ngo.varr.push_back(*nv3);
				ngo.varr.push_back(*nv4);
				ngo.varr.push_back(*nv5);
				ngo.varr.push_back(*nv6);

				Edge * ne0 = new Edge(vstart,   vstart+3); // a -> ab 0
				Edge * ne1 = new Edge(vstart+3, vstart+1); // ab -> b 1
				Edge * ne2 = new Edge(vstart+1, vstart+4); // b -> bc 2
				Edge * ne3 = new Edge(vstart+4, vstart+2); // bc -> c 3
				Edge * ne4 = new Edge(vstart+2, vstart+5); // c -> ac 4
				Edge * ne5 = new Edge(vstart+5, vstart);   // ac -> a 5
				Edge * ne6 = new Edge(vstart+3, vstart+6); // ab ->ce 6
				Edge * ne7 = new Edge(vstart+6, vstart+4); // ce ->bc 7
				Edge * ne8 = new Edge(vstart+5, vstart+6); // ac ->ce 8

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

				ngo.farr4.push_back(*f1);
				ngo.farr4.push_back(*f2);
				ngo.farr4.push_back(*f3);
			}
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
				//r = r + EdgeMidPoints[go.farr[FacePoints[i]].earr[EdgePoints[i]]];
			}
			for(unsigned int i = 1; i < EdgePoints.size(); ++i )
			{
				r = r + EdgeMidPoints[EdgePoints[i]];
			}
			r = r.Multiply(2);//.Divide(n);
			r = r.Divide(n);
			q = q.Divide(n);

			Vertex x = (r + q + s).Divide(n);

			return (x);
		}


    }
