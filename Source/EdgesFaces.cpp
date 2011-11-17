/*
 * EdgesFaces.cpp
 *
 *  Created on: Nov 14, 2011
 *      Author: Panda
 */



#include "../Header/EdgesFaces.h"

namespace Game
    {

/*struct EdgeFaces
	{
	    Face f[2];
	    Edge e;
	};
*/

    EdgesFaces::EdgesFaces(vector<Edge> earr, vector<Face> farr)
	{
	Edge* e = &earr[0];
	Face* f = &farr[0];
	EdgesFaces(e,f, earr.size(),farr.size());
	}


    EdgesFaces::EdgesFaces(Edge earr[], Face farr[], int el, int fl)
	{
	    EdgeFaces efs[el];
	    //ControlPoints cps[el];

#ifdef Debug
			cout << "About to find edge faces \n";
#endif

	    //TODO: refactor and consider optimizing
	    //find edge faces
	    //for each face edge //find face that contains edge, then find other edge

	   // EdgeFaces efs[el];

	    for(int i = 0; i < el; ++i)
	    {
	    bool ab = false, br = false;
#ifdef Debug
	std::cout << "Edge face construction iteration of edge:" << i << "\n";
	std::cout << "ab == " << ab << "br == " << br << "\n";
#endif
	    efs[i].e = earr[i];
		for(int j = 0; j < fl; ++j)
		{
		    for(int k = 0; k < 3; ++k)
		    {
			if(farr[j].earr[k] == earr[i])
			{
			    if(!ab) //assign first face
			    {
				efs[i].f[0] = farr[j];
				ab = true;
#ifdef Debug
	std::cout << "Face 1 assigned for:" << i << "\n";
	std::cout << "ab == " << ab << "\n";
#endif
			    }
			    else   //assign second face
			    {
				efs[i].f[1] = farr[j];
				br = true;
#ifdef Debug
	std::cout << "Face 2 assigned for:" << i << "\n";
	std::cout << "ab == " << ab << "\n";
#endif
				break;
			    }
			}
		    }
		    if(br == true)
		    break;
		}
	    }
	    efsv.assign(efs, efs+el);
	}

    Face EdgesFaces::FindFace(Edge e, Face f)
	{

#ifdef Debug
	    std::cout << "Find Face called" << e.ToString() << f.ToString() << "\n";
	    for(unsigned int i = 0; i < efsv.size(); ++i)
		std::cout << "Find Face Collection Check element :" << i << "Edge: " << efsv[i].e.ToString() << "\n Face a: " << efsv[i].f[0].ToString() << "\n Face b: " << efsv[i].f[0].ToString();

		//std::cout << "FindFace checking iterations current : "<< i << " of " << efsv.size() << "\n";
#endif
	    for(unsigned int i = 0; i < efsv.size(); ++i)
		{//TODO: issue here


		    if(efsv[i].e == e)
			{
			if(efsv[i].f[0] != f)
			    return efsv[i].f[0];
			if(efsv[i].f[1] != f)
			    return efsv[i].f[1];
			else
			    throw "Edge match but no face match?";
			}
		}
	    throw "No Match!? ";
	}

    EdgesFaces::~EdgesFaces()
	{
	//TODO: Memleak here
	// TODO Auto-generated destructor stub
	}

    }
