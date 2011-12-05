/*
 * CatnullClarkSubDivision.cpp
 *
 *  Created on: Nov 29, 2011
 *      Author: Panda
 */

#include "../Header/CatnullClarkSubDivision.h"

namespace Game
    {



/*	GameObject CatnullClarkSubDivision::SubdivideFromArrays(Face* farr, Edge* earr, Vertex* varr)
	    {
		GameObject go;



	    }*/

	GameObject CatnullClarkSubDivision::SubdivideGameObject(GameObject go)
	    {
		//for each face in the object calulcate the centroid
		vector<Vertex> FaceCentroids;

		for(unsigned int i = 0; i < go.farr.size(); i++)
		    go.farr[i].CaluclateCenteroid();

		EdgesFaces ef = EdgesFaces(go.earr, go.farr);



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
