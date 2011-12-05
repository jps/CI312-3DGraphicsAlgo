/*
 * CatnullClarkSubDivision.cpp
 *
 *  Created on: Nov 29, 2011
 *      Author: Panda
 */

#include "../Header/CatmullClarkSubDivision.h"

namespace Game
    {




	GameObject CatmullClarkSubDivision::SubdivideGameObject(GameObject go)
	    {
		//for each face in the object calculate the centroid
		vector<Vertex> faceCentroids;

		for(unsigned int i = 0; i < go.farr.size(); ++i)
		    faceCentroids.push_back(go.farr[i].CaluclateCenteroid());

		EdgesFaces ef = EdgesFaces(go.earr, go.farr);

		for(unsigned int fi = 0; fi < go.farr.size(); ++fi)
		{
			ControlPoint cps;

			for(unsigned int ei = 0; fi < 3; ei++)
			{
				cps.NewEdgePoint[ei] = (faceCentroids[fi] + go.farr[fi].earr[ei].a  + go.farr[fi].earr[ei].b);
				cps.NewEdgePoint[ei] = ef.FindFace(go.farr[fi].earr[ei], go.farr[fi]).LocateFinalVertex(go.farr[fi].earr[ei]).operator +(cps.NewEdgePoint[ei]);

			}
		}

		//vector<//fed>



		GameObject ngo;
		return ngo;
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
