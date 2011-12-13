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

		struct NewControlPoints3
		{
			Vertex varr[3]; //Might want to set this to 4 to allow for f4
		};

		struct NewControlPoints4
		{
			Vertex varr[4]; //Might want to set this to 4 to allow for f4
		};

		class CatmullClarkSubDivision
		{
		public:
		static GameObject Subdivide(GameObject & go);
		private:
		    static vector<Vertex> Findcentroids3(GameObject & go);
		    static vector<Vertex> Findcentroids4(GameObject & go);
		    static Vertex FindCentroid3(GameObject & go, int Face);
		    static Vertex FindCentroid4(GameObject & go, int Face);
		    static Vertex CalculateNewPoint(GameObject & go, vector<Vertex> & FaceCentroids, vector<Vertex> & EdgeMidPoints, vector<int> & EdgePoints, vector<int> & FacePoints, int ControlPoint);
		    static vector<Vertex> FindEdgeMidpoints(GameObject & go);
		    static int FindNextEdge3f(int EdgeID, GameObject & go, unsigned int & nextFace, int & VertexId);
		    static int FindNextEdge4f(int EdgeID, GameObject & go, unsigned int & nextFace, int & VertexId);
		    static vector<NewControlPoints3> FindControlPoints3(GameObject & go, vector<Vertex> & faceCentroids, vector<Vertex> & edgeMidpoints);
		    static void FindControlPoints3(GameObject & go, vector<Vertex> & faceCentroids, vector<Vertex> & edgeMidpoints, vector<NewControlPoints3> & newControlPoints);
		    static vector<NewControlPoints3> FindControls3(GameObject & go, vector<Vertex> & faceCentroids, vector<Vertex> & edgeMidpoints, vector<NewControlPoints3> newControlPoints);


		};

	}

#endif /* CATNULLCLARKSUBDIVISION_H_ */
