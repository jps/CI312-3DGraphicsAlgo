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
			for(unsigned int i = 0; i < go.farr.size(); ++i)
				faceCentroids.push_back(FindCentroid(go, i));

			vector<Vertex> edgeMidpoints;
			for(unsigned int i = 0; i < go.earr.size(); ++i)
				edgeMidpoints.push_back((go.varr[go.earr[i].a] + go.varr[go.earr[i].b]).Divide(2));

			vector<NewControlPoints> newControlPoints;
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






			}


			Vertex * a = new Vertex(-1, 0, 0);
			Vertex * b = new Vertex(0, 1, 0);
			Vertex * c = new Vertex(1, 0, 0);

			Edge * d = new Edge( 0, 1);
			Edge * e = new Edge( 1, 2);
			Edge * f = new Edge( 2, 0);

			Face * g = new Face(0 , 1, 2);

			ngo.varr.push_back(*a );
			ngo.varr.push_back(*b );
			ngo.varr.push_back(*c );
			ngo.earr.push_back(*d );
			ngo.earr.push_back(*e );
			ngo.earr.push_back(*f );
			ngo.farr.push_back(*g );

			return ngo;
	    }

	Vertex CatmullClarkSubDivision::FindCentroid(GameObject &go, int Face)
	{
		Vertex centroid;
		centroid = go.varr[go.earr[go.farr[Face].earr[0]].a] + go.varr[go.earr[go.farr[Face].earr[0]].a];
		//find last vertex in the second edge
		centroid = go.earr[go.farr[Face].earr[0]].a != go.earr[go.farr[Face].earr[1]].a && go.earr[go.farr[Face].earr[0]].b != go.earr[go.farr[Face].earr[1]].a ? centroid + go.varr[go.earr[go.farr[Face].earr[0]].b] : centroid + go.varr[go.earr[go.farr[Face].earr[1]].b];
		centroid = centroid.Divide(4);
		return centroid;
	}

	Vertex CatmullClarkSubDivision::CalculateNewPoint(GameObject &go, vector<Vertex> &FaceCentroids, vector<Vertex> &EdgeMidPoints, vector<int> &EdgePoints, vector<int> &FacePoints, int ControlPoint)
	{
		//(Q/n) + (2R/n) + (S(n-3)/n)
		//where q is the average of the surrounding facepoints
		//r is the average of the surrounding edge midpoints
		//s is the control point

		int n = EdgePoints.size();
		Vertex q = FaceCentroids[FacePoints[0]];
		Vertex r = EdgeMidPoints[EdgePoints[0]];
		Vertex s = go.varr[ControlPoint].Divide(n-3);

		for(unsigned int i = 1; i < FacePoints.size(); ++i )
		{
			q = q + FaceCentroids[FacePoints[i]];
		}

		for(unsigned int i = 1; i < FacePoints.size(); ++i )
		{
			r = r + FaceCentroids[FacePoints[i]];
		}

		q = (q.Divide(n));
		r = (r.Multiply(2)).Divide(n);
		return q + r + s;
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
