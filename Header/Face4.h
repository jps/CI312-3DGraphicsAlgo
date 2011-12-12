/*
 * Face4.h
 *
 *  Created on: Dec 10, 2011
 *      Author: Panda
 */

#ifndef FACE4_H_
#define FACE4_H_

#include "Face.h"

namespace Game
{

class Face4: public Game::Face
{
public:
	Face4(int A, int B, int C, int D);
	Face4(int A, int B, int C, int D, bool EdgeDirection[4]);
	Face4(int A, int B, int C, int D, bool EDA, bool EDB, bool EDC, bool EDD);
	Face4();
	virtual ~Face4();
};

}

#endif /* FACE4_H_ */
