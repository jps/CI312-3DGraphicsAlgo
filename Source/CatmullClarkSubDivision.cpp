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
		Vertex faceCentroids[go.farr.size()];
		for(unsigned int i = 0; i < go.farr.size(); ++i)
		    faceCentroids[i] = FindCentroid(go, i);

		Vertex edgeMidpoints[go.earr.size()];
		for(unsigned int i = 0; i < go.earr.size(); ++i)
			edgeMidpoints[i] = (go.varr[go.earr[i].a] + go.varr[go.earr[i].b]).Divide(2);



		//foreach face
		for(unsigned int fi = 0;fi < go.farr.size(); fi++)
		{
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

				//currentEdge

				//find edges wing
				//find edge that shares a vertex with the wing

				//find face on other side of the wing

				//find edge that share a vertex with the wing


				//loop until face is equal to the current face!





			}
		}




				//find face that wings both
				//calculate centroid of the edge points

		//faceCentroids.push_back()

			//faceCentroids.push_back(FaceCentroid(go.farr[i]));

		/*vector<Vertex> faceCentroids;
		for(unsigned int i = 0; i < go.farr.size(); ++i)
			faceCentroids.push_back(go.farr[i].CaluclateCenteroid());
		*/


		//EdgesFacesCentroid ef = EdgesFacesCentroid(go.earr, faceCentroids);

		/*
		 * This is real real nasty... I have to build a list a of all edges faces with there coresponding index
		 * this is due to the fact that I can't access the edge by index which would have been allot cheaper an
		 * easier in the long run if the chance arises change pointer references to index's this will be pretty
		 * much a full rewrite... basically shud'a listed to Aiden...
		 */

		for(unsigned int fi = 0; fi < go.farr.size(); ++fi)
		{
			Vertex EdgePoints[3];
			for(unsigned int ei = 0; ei < 3; ei++)
			{
				//Have created a new object face centroid object inheriting from face which will allow me to work with this struct still -- should really move the face edge vertex struct to pointers at some point
				//EdgePoints[ei] = (ef.FindFaceCentroid(go.farr[fi].earr[ei], go.farr[fi]) + faceCentroids[fi].centroid + go.farr[fi].earr[ei].a  + go.farr[fi].earr[ei].b);
				//EdgePoints[ei] = Vertex::Divide(ef.FindFaceCentroid(go.farr[fi].earr[ei], go.farr[fi]) + faceCentroids[fi].centroid + go.farr[fi].earr[ei].a  + go.farr[fi].earr[ei].b,4);
				//TODO: attempt to revert back to operator overload... this works for now
			}
		}

		//vector<//fed>



		GameObject ngo;

		/*ngo.varr.push_back(Vertex(-1, 0, 0));
		ngo.varr.push_back(Vertex(0, 1, 0));
		ngo.varr.push_back(Vertex(1, 0, 0));
		ngo.earr.push_back(Edge(ngo.varr[0], ngo.varr[1]));
		ngo.earr.push_back(Edge(ngo.varr[1], ngo.varr[2]));
		ngo.earr.push_back(Edge(ngo.varr[2], ngo.varr[0]));
		ngo.farr.push_back(Face(&ngo.earr[0],&ngo.earr[1], &ngo.earr[2]));
*/

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
