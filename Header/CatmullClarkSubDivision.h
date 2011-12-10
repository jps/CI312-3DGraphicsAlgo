/*
 * CatnullClarkSubDivision.h
 *
 *  Created on: Nov 29, 2011
 *      Author: Panda
 */


#include "GameObject.h"
#include "Vertex.h"
#include "Face.h"
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
		//CatmullClarkSubDivision();//not needed at this is going to be a static method
		//virtual ~CatnullClarkSubDivision();
		private:
		static Vertex FindCentroid(GameObject &go, int Face);

		static Vertex CalculateNewPoint(GameObject &go, vector<Vertex> &FaceCentroids, vector<Vertex> &EdgeMidPoints, vector<int> &EdgePoints, vector<int> &FacePoints, int ControlPoint);


		};

	}

#endif /* CATNULLCLARKSUBDIVISION_H_ */
