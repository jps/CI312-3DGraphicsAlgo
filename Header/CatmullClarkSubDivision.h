/*
 * CatnullClarkSubDivision.h
 *
 *  Created on: Nov 29, 2011
 *      Author: Panda
 */


#include "GameObject.h"
#include "Vertex.h"
#include "Face3.h"
#include "Vertex.h"
#include "Edge.h"
#include <stdlib.h>
#include <vector>

#ifndef CATNULLCLARKSUBDIVISION_H_
#define CATNULLCLARKSUBDIVISION_H_

namespace Game
    {

		struct NewControlPoints
		{
			Vertex varr[3]; //Might want to set this to 4 to allow for f4
		};

		class CatmullClarkSubDivision
		{
		public:
		static GameObject Subdivide(GameObject go);
		private:
		    static vector<Vertex> Findcentroids3(GameObject & go);
		    static vector<Vertex> Findcentroids4(GameObject & go);
		    static Vertex FindCentroid3(GameObject & go, int Face);
		    static Vertex FindCentroid4(GameObject & go, int Face);
		    static Vertex CalculateNewPoint(GameObject & go, vector<Vertex> & FaceCentroids, vector<Vertex> & EdgeMidPoints, vector<int> & EdgePoints, vector<int> & FacePoints, int ControlPoint);
		    static vector<Vertex> FindEdgeMidpoints(GameObject & go);


		};

	}

#endif /* CATNULLCLARKSUBDIVISION_H_ */
