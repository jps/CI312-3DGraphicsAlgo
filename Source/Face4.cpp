/*
 * Face4.cpp
 *
 *  Created on: Dec 10, 2011
 *      Author: Panda
 */

#include "../Header/Face4.h"

namespace Game
{

Face4::Face4()
{
	// TODO Auto-generated constructor stub

}


Face4::Face4(int A, int B, int C, int D)
{
	earr[0] = A;
	earr[1] = B;
	earr[2] = C;
	earr[3] = D;
	edgeDirection[0] = edgeDirection[1] = edgeDirection[2] = edgeDirection[3] = true;
}

Face4::Face4(int A, int B, int C, int D, bool EdgeDirection[4])
{
	earr[0] = A;
	earr[1] = B;
	earr[2] = C;
	earr[3] = D;
	edgeDirection[0] = EdgeDirection[0];
	edgeDirection[1] = EdgeDirection[1];
	edgeDirection[2] = EdgeDirection[2];
	edgeDirection[3] = EdgeDirection[3];
}


Face4::Face4(int A, int B, int C, int D, bool EDA, bool EDB, bool EDC, bool EDD)
{
    earr[0] = A;
    earr[1] = B;
    earr[2] = C;
    earr[3] = D;
    edgeDirection[0] = EDA;
	edgeDirection[1] = EDB;
	edgeDirection[2] = EDC;
	edgeDirection[3] = EDD;
}

Face4::~Face4()
{
	// TODO Auto-generated destructor stub
}

}
