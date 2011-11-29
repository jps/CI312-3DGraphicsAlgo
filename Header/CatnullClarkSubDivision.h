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

    class CatnullClarkSubDivision
	{
    public:
	GameObject SubdivideFromArrays(Face* farr, Edge* earr, Vertex* varr);
	GameObject SubdivideGameObject(GameObject go);
	//CatnullClarkSubDivision();//not needed at this is going to be a static method
	//virtual ~CatnullClarkSubDivision();
	};

    }

#endif /* CATNULLCLARKSUBDIVISION_H_ */
