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
		vector<FaceCentroid> faceCentroids;

		for(unsigned int i = 0; i < go.farr.size(); ++i)
		    faceCentroids.push_back(FaceCentroid(go.farr[i]));



		EdgesFacesCentroid ef = EdgesFacesCentroid(go.earr, faceCentroids);


		for(unsigned int fi = 0; fi < go.farr.size(); ++fi)
		{

			Vertex EdgePoints[3];
			for(unsigned int ei = 0; fi < 3; ei++)
			{
				//Have created a new object face centroid object inheriting from face which will allow me to work with this struct still -- should really move the face edge vertex struct to pointers at some point
				//EdgePoints[ei] = (ef.FindFaceCentroid(go.farr[fi].earr[ei], go.farr[fi]) + faceCentroids[fi].centroid + go.farr[fi].earr[ei].a  + go.farr[fi].earr[ei].b);
				//EdgePoints[ei] = Vertex::Divide(ef.FindFaceCentroid(go.farr[fi].earr[ei], go.farr[fi]) + faceCentroids[fi].centroid + go.farr[fi].earr[ei].a  + go.farr[fi].earr[ei].b,4);
				//TODO: attempt to revert back to operator overload... this works for now
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
