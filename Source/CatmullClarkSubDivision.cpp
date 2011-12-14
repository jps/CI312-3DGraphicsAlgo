/*
 * CatnullClarkSubDivision.cpp
 *
 *  Created on: Nov 29, 2011
 *      Author: Panda
 */

#include "../Header/CatmullClarkSubDivision.h"

namespace Game
    {

/*-
	GameObject CatmullClarkSubDivision::Subdivide4()
	{


	}
*/
    GameObject CatmullClarkSubDivision::Subdivide(GameObject &go)
    {


    	vector<Vertex> faceCentroids;
    	vector<Vertex> edgeMidpoints = FindEdgeMidpoints(go);
		vector<NewControlPoints3> newControlPoints;
		vector<NewControlPoints4> newControlPoints4;
    	bool F4;
    	if(go.farr4.size() != 0)
    	{
    		F4 = true;
    		faceCentroids = Findcentroids4(go);

    		for(unsigned int fi = 0;fi < go.farr4.size();fi++)
			{
				NewControlPoints4 newPoints;
    			for(unsigned int ei = 0; ei < 4; ei++)
    			{

					int VertexID = go.farr4[fi].isForward(ei) ? go.earr[go.farr4[fi].earr[ei]].a : go.earr[go.farr4[fi].earr[ei]].b;
					vector<unsigned int> fCentroids;
					vector<unsigned int> eMidpoints;
					fCentroids.push_back(fi);
					eMidpoints.push_back(go.farr4[fi].earr[ei]);
					unsigned int LastEdge, LastFace;
					LastEdge = go.farr4[fi].earr[ei];
					LastFace = fi;
					bool finished, br;
					finished = false;
					while(!finished)
					{
						br = false;
						for(unsigned int faceindex = 0; faceindex < go.farr4.size() ; ++faceindex) //foreach face
						{
							if(faceindex != LastFace) // if its not the last face
							for(unsigned int edgeindex = 0; edgeindex < 4; ++edgeindex) //foreach edges face
							{
								if(go.farr4[faceindex].earr[edgeindex] == LastEdge || go.farr4[faceindex].earr[edgeindex] == LastEdge) //if edge is last edge
								{
									if(faceindex != fi)//if it's the starting face break out
									{
										for(int feindex = 0; feindex < 4; feindex++) //find the next edge in the face
										{
											if(go.farr4[faceindex].earr[feindex] != LastEdge) // if it's not the last edge
												if(go.earr[go.farr4[faceindex].earr[feindex]].a == VertexID || go.earr[go.farr4[faceindex].earr[feindex]].b == VertexID)//if the vertex is found
												{
													fCentroids.push_back(faceindex); //add the face index
													LastFace = faceindex;
													eMidpoints.push_back(go.farr4[faceindex].earr[feindex]);
													LastEdge = go.farr4[faceindex].earr[feindex];
													br = true;
													break;
												}
										}
										//LastFace = faceindex;
										if(br)break;
									}else{
										br =finished = true;
									}
								}
								if(br)break;
							}
							if(br)break;
						}
					}
					//foreach edge in face
					newPoints.varr[ei] = Vertex(CalculateNewPoint(go, faceCentroids, edgeMidpoints, eMidpoints, fCentroids, VertexID));
				}

				newControlPoints4.push_back(newPoints);
			}

    	}else{
    		F4 = false;
    		faceCentroids = Findcentroids3(go);
    		//foreach face in game object
			for(unsigned int fi = 0;fi < go.farr.size();fi++)
				{
				NewControlPoints3 newPoints;
				//foreach edge in face
				for(int ei = 0;ei < 3;ei++)
					{
					//take facepoint
					int & currentEdge = go.farr[fi].earr[ei];
					bool isForward = go.farr[fi].isForward(ei);
					int VertexId = isForward ? go.earr[go.farr[fi].earr[ei]].a : go.earr[go.farr[fi].earr[ei]].b;
					int nextEdge, EdgeID;
					unsigned int currentFace = fi;
					unsigned int nextFace = -1;
					vector<unsigned int> edgePoints;
					vector<unsigned int> facePoints;
					edgePoints.push_back(go.farr[fi].earr[ei]); //add current edged to midpoint list
					facePoints.push_back(fi); //add current face point
					while(nextFace != fi)
						{
						bool br = false;
						for(unsigned int _fi = 0;_fi < go.farr.size();_fi++)
							{
							if(_fi != currentFace && fi != _fi)
								{
								for(int _ei = 0;_ei < 3;_ei++)
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
							if(br)
								break;
							}

						if(!br)
							break;

						nextEdge = FindNextEdge3f(EdgeID, go, nextFace, VertexId);
						edgePoints.push_back(nextEdge);

						currentEdge = nextEdge;
						currentFace = nextFace;
						}

//
					newPoints.varr[ei] = Vertex(CalculateNewPoint(go, faceCentroids, edgeMidpoints, edgePoints, facePoints, VertexId));
					}
				newControlPoints.push_back(newPoints);
				}
    	}





        //build the new object
        GameObject ngo;
        //foreach face
        if(F4)
        {
            for(unsigned int fi = 0;fi < go.farr4.size();fi++)
            {
                            int estart = ngo.earr.size();

                            int nvi[6];

                            for(int cpi = 0; cpi < 3; ++cpi)
                            {
                            	bool notFound = true;
            					for(unsigned int vi = 0; vi < ngo.varr.size(); vi++)
            					{
            						if(ngo.varr[vi].EqualTo(newControlPoints4[fi].varr[cpi]))
            						{
            							notFound = false;
            							nvi[cpi] = vi;
            							break;
            						}
                            	}
            					if(notFound)
            					{
            						nvi[cpi] = ngo.varr.size();
            						Vertex * ncp = new Vertex (newControlPoints4[fi].varr[cpi]);
            						ngo.varr.push_back(*ncp);
            					}
            					notFound = true;
            					for(unsigned int vi = 0; vi < ngo.varr.size(); vi++)
            					{
            						if(ngo.varr[vi].EqualTo(edgeMidpoints[go.farr4[fi].earr[cpi]]))
            						{
            							notFound = false;
            							nvi[cpi+3] = vi;
            							break;
            						}
            					}
            					if(notFound)
            					{
            						nvi[cpi+3] = ngo.varr.size();
            						Vertex * nem = new Vertex(edgeMidpoints[go.farr4[fi].earr[cpi]]);
            						ngo.varr.push_back(*nem);

            					}
                            }

                            nvi[6] = ngo.varr.size();
                            Vertex * fcen = new Vertex(faceCentroids[fi]);
            				ngo.varr.push_back(*fcen);

                            Edge ne[9];
                            int nei[9]; //new edge index
                            bool ned[9];

                			ne[0] = Edge(nvi[0], nvi[4]); // a -> ab 0
                			ne[1] = Edge(nvi[4], nvi[1]); // ab -> b 1
                			ne[2] = Edge(nvi[1], nvi[5]); // b -> bc 2
                			ne[3] = Edge(nvi[5], nvi[2]); // bc -> c 3
                			ne[4] = Edge(nvi[2], nvi[3]); // c -> ac 4
                			ne[5] = Edge(nvi[3], nvi[0]); // ac -> a 5
                			ne[6] = Edge(nvi[4], nvi[6]); // ab ->ce 6
                			ne[7] = Edge(nvi[6], nvi[5]); // ce ->bc 7
                			ne[8] = Edge(nvi[3], nvi[6]); // ac ->ce 8

                			for(int ei = 0; ei < 9; ++ei)
                			{
                				bool notFound = true;
                				for(unsigned int i = 0; i < ngo.earr.size(); ++i)
                				{
                					int CompareResult = ngo.earr[i].Compare(ne[ei]);
                					if(CompareResult == 2)
                					{
            							nei[ei] = i;
            							ned[ei] = true;
            							notFound = false;
            							break;
                					}else if(CompareResult == 1)
                					{
                						nei[ei] = i;
                						ned[ei] = false;
                						notFound = false;
                						break;
                					}
                				}
                				if(notFound)
                				{
                					nei[ei] = ngo.earr.size();
                					ned[ei] = true;
                					Edge * _ne = new Edge(ne[ei].a, ne[ei].b);
                					ngo.earr.push_back(*_ne);
                				}
                			}

                			Face4 * f1 = new Face4(nei[0], nei[6], nei[8], nei[5], ned[0], ned[6], !ned[8], ned[5]);
            				Face4 * f2 = new Face4(nei[1], nei[2], nei[7], nei[6], ned[1], ned[2], !ned[7], !nei[6]);
            				Face4 * f3 = new Face4(nei[7], nei[3], nei[4], nei[8], ned[7], ned[3], ned[4], ned[8]);

            				ngo.farr4.push_back(*f1);
                			ngo.farr4.push_back(*f2);
                			ngo.farr4.push_back(*f3);
				}
        }else{

            for(unsigned int fi = 0;fi < go.farr.size();fi++)
            	{

                int nvi[6];

                for(int cpi = 0; cpi < 3; ++cpi)
                {
                	bool notFound = true;
					for(unsigned int vi = 0; vi < ngo.varr.size(); vi++)
					{
						if(ngo.varr[vi].EqualTo(newControlPoints[fi].varr[cpi]))
						{
							notFound = false;
							nvi[cpi] = vi;
							break;
						}
                	}
					if(notFound)
					{
						nvi[cpi] = ngo.varr.size();
						Vertex * ncp = new Vertex (newControlPoints[fi].varr[cpi]);
						ngo.varr.push_back(*ncp);
					}
					notFound = true;
					for(unsigned int vi = 0; vi < ngo.varr.size(); vi++)
					{
						if(ngo.varr[vi].EqualTo(edgeMidpoints[go.farr[fi].earr[cpi]]))
						{
							notFound = false;
							nvi[cpi+3] = vi;
							break;
						}
					}
					if(notFound)
					{
						nvi[cpi+3] = ngo.varr.size();
						Vertex * nem = new Vertex(edgeMidpoints[go.farr[fi].earr[cpi]]);
						ngo.varr.push_back(*nem);

					}
                }

                nvi[6] = ngo.varr.size();
                Vertex * fcen = new Vertex(faceCentroids[fi]);
				ngo.varr.push_back(*fcen);

                Edge ne[9];
                int nei[9]; //new edge index
                bool ned[9];

    			ne[0] = Edge(nvi[0], nvi[4]); // a -> ab 0
    			ne[1] = Edge(nvi[4], nvi[1]); // ab -> b 1
    			ne[2] = Edge(nvi[1], nvi[5]); // b -> bc 2
    			ne[3] = Edge(nvi[5], nvi[2]); // bc -> c 3
    			ne[4] = Edge(nvi[2], nvi[3]); // c -> ac 4
    			ne[5] = Edge(nvi[3], nvi[0]); // ac -> a 5
    			ne[6] = Edge(nvi[4], nvi[6]); // ab ->ce 6
    			ne[7] = Edge(nvi[6], nvi[5]); // ce ->bc 7
    			ne[8] = Edge(nvi[3], nvi[6]); // ac ->ce 8

    			for(int ei = 0; ei < 9; ++ei)
    			{
    				bool notFound = true;
    				for(unsigned int i = 0; i < ngo.earr.size(); ++i)
    				{
    					int CompareResult = ne[ei].Compare(ngo.earr[i]);//ngo.earr[i].Compare(ne[ei]);
    					if(CompareResult == 2)
    					{
							nei[ei] = i;
							ned[ei] = true;
							notFound = false;
							break;
    					}else if(CompareResult == 1)
    					{
    						nei[ei] = i;
    						ned[ei] = false;
    						notFound = false;
    						break;
    					}
    				}
    				if(notFound)
    				{
    					nei[ei] = ngo.earr.size();
    					ned[ei] = true;
    					Edge * _ne = new Edge(ne[ei].a, ne[ei].b);
    					ngo.earr.push_back(*_ne);
    				}
    			}

    			Face4 * f1 = new Face4(nei[0], nei[6], nei[8], nei[5], ned[0], ned[6], !ned[8], ned[5]);
				Face4 * f2 = new Face4(nei[1], nei[2], nei[7], nei[6], ned[1], ned[2], !ned[7], !nei[6]);
				Face4 * f3 = new Face4(nei[7], nei[3], nei[4], nei[8], ned[7], ned[3], ned[4], ned[8]);
    			/*
    			Face4 * f1 = new Face4(nei[0], nei[6], nei[8], nei[5], true, true, false, true);
    			Face4 * f2 = new Face4(nei[1], nei[2], nei[7], nei[6], true, true, false, false);
    			Face4 * f3 = new Face4(nei[7], nei[3], nei[4], nei[8], true, true, true, true);
*/
    			ngo.farr4.push_back(*f1);
    			ngo.farr4.push_back(*f2);
    			ngo.farr4.push_back(*f3);
    			}
        }

		return ngo;
	}


	vector<Vertex> CatmullClarkSubDivision::Findcentroids3(GameObject &go)
		{
		//for each face3 in the object calculate the centroid
			vector<Vertex> faceCentroids;

			for(unsigned int i = 0; i < go.farr.size(); ++i)
			{
				faceCentroids.push_back(Vertex(FindCentroid3(go, i)));
			}

			return faceCentroids;
		}

	vector<Vertex> CatmullClarkSubDivision::Findcentroids4(GameObject &go)
		{
		//for each face4 in the object calculate the centroid
			vector<Vertex> faceCentroids;

			for(unsigned int i = 0; i < go.farr4.size(); ++i)
			{
				faceCentroids.push_back(Vertex(FindCentroid4(go, i)));
			}

			return faceCentroids;
		}

    vector<Vertex> CatmullClarkSubDivision::FindEdgeMidpoints(GameObject & go)
    {
        //for each edge in the game object find the midpoint
    	vector<Vertex> edgeMidpoints;
        for(unsigned int i = 0;i < go.earr.size();++i){
            Vertex edgeMidpoint = Vertex((go.varr[go.earr[i].a] + go.varr[go.earr[i].b]).Divide(2));
            edgeMidpoints.push_back(edgeMidpoint);
        }
        return edgeMidpoints;
    }

	Vertex CatmullClarkSubDivision::FindCentroid3(GameObject &go, int Face)
		{
			Vertex centroid;
			centroid = go.varr[go.earr[go.farr[Face].earr[0]].a] + go.varr[go.earr[go.farr[Face].earr[0]].b];
			//find last vertex in the second edge
			centroid = go.earr[go.farr[Face].earr[0]].a != go.earr[go.farr[Face].earr[1]].a &&
						go.earr[go.farr[Face].earr[0]].b != go.earr[go.farr[Face].earr[1]].a ?
								centroid + go.varr[go.earr[go.farr[Face].earr[0]].a] :
								centroid + go.varr[go.earr[go.farr[Face].earr[1]].b];
				centroid = centroid.Divide(3);
			return centroid;
		}

	Vertex CatmullClarkSubDivision::FindCentroid4(GameObject &go, int Face)
		{
			int points[4]; //can be optimized to work without this array but the solution isn't clean...
			points[0] = go.earr[go.farr4[Face].earr[0]].a;
			points[1] = go.earr[go.farr4[Face].earr[0]].b;
			points[2] = go.earr[go.farr4[Face].earr[0]].a != go.earr[go.farr4[Face].earr[1]].a &&
						go.earr[go.farr4[Face].earr[0]].b != go.earr[go.farr4[Face].earr[1]].a
							? go.earr[go.farr4[Face].earr[1]].a : go.earr[go.farr4[Face].earr[1]].b;

			points[3] = points[0] != go.earr[go.farr4[Face].earr[2]].a &&
						 points[1] != go.earr[go.farr4[Face].earr[2]].a &&
						 points[2] != go.earr[go.farr4[Face].earr[2]].a ?
						 go.earr[go.farr4[Face].earr[1]].a :
						 points[0] != go.earr[go.farr4[Face].earr[2]].b &&
						 points[1] != go.earr[go.farr4[Face].earr[2]].b &&
						 points[2] != go.earr[go.farr4[Face].earr[2]].b ?
						 go.earr[go.farr4[Face].earr[1]].b :
					   	 points[0] != go.earr[go.farr4[Face].earr[3]].a &&
					 	 points[1] != go.earr[go.farr4[Face].earr[3]].a &&
					     points[2] != go.earr[go.farr4[Face].earr[3]].a ?
						 go.earr[go.farr4[Face].earr[3]].a :
			 	 	 	 go.earr[go.farr4[Face].earr[3]].b ;
			return (go.varr[points[0]] + go.varr[points[1]] + go.varr[points[2]] + go.varr[points[3]]).Divide(4);
		}

	Vertex CatmullClarkSubDivision::CalculateNewPoint(GameObject &go, vector<Vertex> &FaceCentroids, vector<Vertex> &EdgeMidPoints, vector<unsigned int> &EdgePoints, vector<unsigned int> &FacePoints, int ControlPoint)
		{
			//(Q/n) + (2R/n) + (S(n-3)/n)
			//where q is the average of the surrounding facepoints
			//r is the average of the surrounding edge midpoints
			//s is the control point

			int n = FacePoints.size();
			Vertex q = FaceCentroids[FacePoints[0]];
			Vertex r = EdgeMidPoints[EdgePoints[0]];
			Vertex s = go.varr[ControlPoint];
			for(unsigned int i = 1; i < n; ++i )
			{
				q = q + FaceCentroids[FacePoints[i]];
				r = r + EdgeMidPoints[EdgePoints[i]];
			}
			q = q.Divide(n*n);
			r = r.Divide(n).Multiply(2).Divide(n);
			s = s.Multiply((n-3)).Divide(n);

			return r + q + s;
		}

		int CatmullClarkSubDivision::FindNextEdge3f(int EdgeID, GameObject & go, unsigned int & nextFace, int & VertexId)
		{
			for(int _ei = 0;_ei < 3;_ei++)
				if(EdgeID != _ei)
					if(go.earr[go.farr[nextFace].earr[_ei]].a == VertexId || go.earr[go.farr[nextFace].earr[_ei]].b == VertexId)
					{
						return go.farr[nextFace].earr[_ei];
					}
		}

		int CatmullClarkSubDivision::FindNextEdge4f(int EdgeID, GameObject & go, unsigned int & nextFace, int & VertexId)
		{
			for(int _ei = 0;_ei < 4;_ei++)
				if(EdgeID != _ei)
					if(go.earr[go.farr4[nextFace].earr[_ei]].a == VertexId || go.earr[go.farr4[nextFace].earr[_ei]].b == VertexId)
					{
						return go.farr4[nextFace].earr[_ei];
					}
			return -1;//hack
		}



    }
