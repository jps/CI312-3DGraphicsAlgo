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

/*
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
*/
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

		Edge * d = new Edge( a, b);
		Edge * e = new Edge( b, c);
		Edge * f = new Edge( c, a);

		Face * g = new Face(d , e, f);

		ngo.varr.push_back(*a );
		ngo.varr.push_back(*b );
		ngo.varr.push_back(*c );
		ngo.earr.push_back(*d );
		ngo.earr.push_back(*e );
		ngo.earr.push_back(*f );
		ngo.farr.push_back(*g );

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
