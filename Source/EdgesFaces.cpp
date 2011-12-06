/*
 * EdgesFaces.cpp
 *
 *  Created on: Nov 14, 2011
 *      Author: Panda
 */



#include "../Header/EdgesFaces.h"

//#define Debug

namespace Game
    {

	EdgeFace::EdgeFace()
	{

	}

	EdgeFace::EdgeFace(Edge E, Face Faces[2])
	{
		e = E;
		f[0] = Faces[0];
		f[1] = Faces[1];
	}

	EdgeFaceCentroid::EdgeFaceCentroid()
	{

	}

	EdgeFaceCentroid::EdgeFaceCentroid(Edge E, FaceCentroid Faces[2])
	{
		//EdgeFace(E, Faces);
		e = E;
		f[0] = Faces[0];
		f[1] = Faces[1];
	}

/*	EdgesFaces::EdgesFaces(vector<Edge> earr, vector<Face> farr)
	{
		EdgesFaces(earr,farr, false);
	}*/

	EdgesFaces::EdgesFaces()
	{


	}

    EdgesFaces::EdgesFaces(vector<Edge> earr, vector<Face> farr)
	{
	    //std::vector<EdgeFaces> efs;
	    //EdgeFaces efs[el];
	    //ControlPoints cps[el];
#ifdef Debug
			cout << "About to find edge faces \n";
			cout << "earr size" << earr.size() << " farr size " << farr.size() << "\n";
#endif
			//TODO: this is all still very hacky memory is being copied all over the place this will need major cleaning up to get
			//to a nice optimized state.
	    //TODO: refactor and consider optimizing
	    //find edge faces
	    //for each face edge //find face that contains edge, then find other edge
	   // EdgeFaces efs[el];

	    for(unsigned int i = 0; i < earr.size(); ++i)
			{
			bool ab = false, br = false;
#ifdef Debug
	std::cout << "Edge face construction iteration of edge:" << i << "\n";
	std::cout << "ab == " << ab << "br == " << br << "\n";
#endif
			EdgeFaces nef;
			nef.e = earr[i];
			//efs[i].e = earr[i];
			for(unsigned int j = 0; j < farr.size(); ++j)
			{
				for(int k = 0; k < 3; ++k)
				{
					if(*farr[j].earr[k] == earr[i])
					{
#ifdef Debug
	std::cout << "Edge match! " << farr[j].earr[k].ToString() << "==" << earr[i].ToString();
#endif
						if(!ab) //assign first face
						{
						//efs[i].f[0] = farr[j];
						nef.f[0] = farr[j];
						ab = true;
#ifdef Debug
	std::cout << "Face 1 assigned edge "<< i <<"/" << earr.size() <<" face "<< j << "/" <<farr.size() << "edge:" << k << "/3 \n";
	std::cout << "ab == " << ab << "\n";
#endif
						}
						else   //assign second face
						{
						//efs[i].f[1] = farr[j];
						nef.f[1] = farr[j];
						br = true;
#ifdef Debug
	std::cout << "Face 2 assigned edge "<< i <<"/" << earr.size() <<" face "<< j << "/" <<farr.size() << "edge:" << k << "/3 \n";
	std::cout << "ab == " << ab << "\n";
#endif
						break;
						}
					}
					if( j == (farr.size() - 1) && k == 2 )
					{
#ifdef Debug
				std::cout << "edge faces has failed on edge "<< i <<"/" << earr.size() <<" face "<< j+1 << "/" <<farr.size() << "edge:" << k+1 << "/3 \n";
#endif
						throw 1/0;
					}
				}
				if(br == true)
				break;
			}
			efsv.push_back(nef); //TODO: optimize put directly into efsv?
	    }
	    //efsv = efs;
	    //efsv.assign(efs, efs+el);
	}

    Face EdgesFaces::FindFace(Edge e, Face f)
	{

#ifdef Debug
	    std::cout << "Find Face called" << e.ToString() << f.ToString() << "\n";
	    for(unsigned int i = 0; i < efsv.size(); ++i)
		{
		std::cout << "Find Face Collection Check element :" << i << "Edge: " << efsv[i].e.ToString() << "\n Face a: " << efsv[i].f[0].ToString() << "\n Face b: " << efsv[i].f[0].ToString();
		}
		//std::cout << "FindFace checking iterations current : "<< i << " of " << efsv.size() << "\n";
#endif
	    for(unsigned int i = 0; i < efsv.size(); ++i) //TODO: issue here
		{
		    if(efsv[i].e == e)
			{
#ifdef Debug
	std::cout << "edge match inputed edge: "<< e.ToString() << "matches edge" << efsv[i].e.ToString() << "\n";
#endif
			if(efsv[i].f[0] != f)
			    {
#ifdef Debug
	std::cout << "find face found:" << efsv[i].f[0].ToString() << "\n";
#endif
			    return efsv[i].f[0];
			    }
			if(efsv[i].f[1] != f)
			    {
#ifdef Debug
	std::cout << "find face found:" << efsv[i].f[1].ToString() << "\n";
#endif
			    return efsv[i].f[1];
			    }
			else
			    {
			    throw "Edge match but no face match?";
			    }
			}
		}
	    throw "No Match!? ";
	}




    EdgesFaces::~EdgesFaces()
	{
    	//efsv.clear();
    	//TODO: Memleak here
    	// TODO Auto-generated destructor stub
	}

    EdgesFacesCentroid::EdgesFacesCentroid()
    {

    }

    EdgesFacesCentroid::~EdgesFacesCentroid()
    {

    }

    EdgesFacesCentroid::EdgesFacesCentroid(vector<Edge> earr, vector<FaceCentroid> farr)
   	{
   	    std::vector<EdgeFaceCentroid> efs;
   	    //EdgeFaces efs[el];
   	    //ControlPoints cps[el];
   #ifdef Debug
   			cout << "About to find edge faces \n";
   			cout << "earr size" << earr.size() << " farr size " << farr.size() << "\n";
   #endif
   			//TODO: this is all still very hacky memory is being copied all over the place this will need major cleaning up to get
   			//to a nice optimized state.
   	    //TODO: refactor and consider optimizing
   	    //find edge faces
   	    //for each face edge //find face that contains edge, then find other edge
   	   // EdgeFaces efs[el];

   	    for(unsigned int i = 0; i < earr.size(); ++i)
   	    {
   	    bool ab = false, br = false;
   #ifdef Debug
   	std::cout << "Edge face construction iteration of edge:" << i << "\n";
   	std::cout << "ab == " << ab << "br == " << br << "\n";
   #endif
		EdgeFaceCentroid nef;
   	    nef.e = earr[i];
   	    //efs[i].e = earr[i];
   		for(unsigned int j = 0; j < farr.size(); ++j)
   		{
   		    for(int k = 0; k < 3; ++k)
   		    {
   			if(*farr[j].earr[k] == earr[i])
   			{
   #ifdef Debug
   	std::cout << "Edge match! " << farr[j].earr[k].ToString() << "==" << earr[i].ToString();
   #endif
   			    if(!ab) //assign first face
   			    {
   				//efs[i].f[0] = farr[j];
   				nef.f[0] = farr[j];
   				ab = true;
   #ifdef Debug
   	std::cout << "Face 1 assigned edge "<< i <<"/" << earr.size() <<" face "<< j << "/" <<farr.size() << "edge:" << k << "/3 \n";
   	std::cout << "ab == " << ab << "\n";
   #endif
   			    }
   			    else   //assign second face
   			    {
   				//efs[i].f[1] = farr[j];
   				nef.f[1] = farr[j];
   				br = true;

   				//set the midpoint

   				//nef.edgeControlPoint = (nef.f[1].centroid + nef.f[2].centroid + nef.e.a + nef.e.b) / 4;

   				//TODO: Replace
   				//nef.edgeControlPoint = Vertex::Divide(nef.f[1].centroid + nef.f[2].centroid + nef.e.a + nef.e.b, 4);
   				//TODO: Remove horrible horrible hack as operator overloading was not working from this method for some uknow reason...

   #ifdef Debug
   	std::cout << "Face 2 assigned edge "<< i <<"/" << earr.size() <<" face "<< j << "/" <<farr.size() << "edge:" << k << "/3 \n";
   	std::cout << "ab == " << ab << "\n";
   #endif
   				break;
   			    }
   			}
   		    if( j == (farr.size() - 1) && k == 2 )
   			{
   #ifdef Debug
   			    std::cout << "edge faces has failed on edge "<< i <<"/" << earr.size() <<" face "<< j+1 << "/" <<farr.size() << "edge:" << k+1 << "/3 \n";
   #endif
   			    throw 1;
   			}
   		    }
   		    if(br == true)
   		    break;
   		}
   		efsv.push_back(nef); //TODO: optimize put directly into efsv?
   	    }
   	    //efsv = efs;
   	    //efsv.assign(efs, efs+el);
   	}


    Vertex EdgesFacesCentroid::FindFaceCentroid(Edge e, Face f)
	{

#ifdef Debug
	    std::cout << "Find Face called" << e.ToString() << f.ToString() << "\n";
	    for(unsigned int i = 0; i < efsv.size(); ++i)
		{
		std::cout << "Find Face Collection Check element :" << i << "Edge: " << efsv[i].e.ToString() << "\n Face a: " << efsv[i].f[0].ToString() << "\n Face b: " << efsv[i].f[0].ToString();
		}
		//std::cout << "FindFace checking iterations current : "<< i << " of " << efsv.size() << "\n";
#endif
	    for(unsigned int i = 0; i < efsv.size(); ++i) //TODO: issue here
		{
		    if(efsv[i].e == e)
			{
#ifdef Debug
	std::cout << "edge match inputed edge: "<< e.ToString() << "matches edge" << efsv[i].e.ToString() << "\n";
#endif
			if(efsv[i].f[0] != f)
			    {
#ifdef Debug
	std::cout << "find face found:" << efsv[i].f[0].ToString() << "\n";
#endif
			    return efsv[i].f[0].centroid;
			    }
			if(efsv[i].f[1] != f)
			    {
#ifdef Debug
	std::cout << "find face found:" << efsv[i].f[1].ToString() << "\n";
#endif
			    return efsv[i].f[1].centroid;
			    }
			else
			    {
			    throw "Edge match but no face match?";
			    }
			}
		}
	    throw "No Match!? ";
	}


    }
