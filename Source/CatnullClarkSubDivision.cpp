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

		for(int i = 0; i < go.farr; i++)
		    go.farr[i].CaluclateCenteroid();

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