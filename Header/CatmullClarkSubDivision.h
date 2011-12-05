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
/*
		struct ControlPoint
		{
			Vertex NewEdgePoint[3]; //Might want to set this to 4 to allow for f4
		};
*/
		class CatmullClarkSubDivision
		{
		public:
		GameObject SubdivideGameObject(GameObject go);
		//CatmullClarkSubDivision();//not needed at this is going to be a static method
		//virtual ~CatnullClarkSubDivision();
		};

	}

#endif /* CATNULLCLARKSUBDIVISION_H_ */
