///*
// * ButterflySubspaceDivision.h
// *
// *  Created on: Nov 29, 2011
// *      Author: Panda
// */
//
//#ifndef BUTTERFLYSUBSPACEDIVISION_H_
//#define BUTTERFLYSUBSPACEDIVISION_H_
//
//#include "Vertex.h"
//#include "Edge.h"
//#include "Face.h"
//#include <vector>
//#include "EdgesFaces.h"
//#include <stdlib.h>
//#include "GameObject.h"
//
//namespace Game
//    {
//
//    class ButterflySubspaceDivision
//	{
//	struct ControlPoints
//		{
//		    Vertex a[2];
//		    Vertex b[2];
//		    Vertex c[4];
//		    //Vertex d[2];
//		};
//
//	struct EdgeEdges
//		{
//		    Edge parent; //TODO: these can be pointers
//		    Edge children[2];
//		};
//
//	struct FaceSplit
//	    {
//	    //TODO: Review could this be a collection of pointers to the new object to minimize memory consuption.
//		bool direction[3];
//		//Edge nes[9];
//		Face nfs[4];
//		Vertex nvs[3];
//		Vertex ovs[3];
//	    };
//
//
//    public://tesselate
//	static GameObject Tessellate(const GameObject & got );
//
///*	ButterflySubspaceDivision();
//	virtual ~ButterflySubspaceDivision();*/
//    private:
//	static Vertex ButterflyCalculateNewVertex(ControlPoints controlPoints);
//
//	};
//
//    }
//
//#endif /* BUTTERFLYSUBSPACEDIVISION_H_ */
