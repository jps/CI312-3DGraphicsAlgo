/*
 * ObjectManager.h
 *
 *  Created on: Dec 8, 2011
 *      Author: Panda
 */

#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_

#include "GameObject.h"

using namespace std;

namespace Game
{

class ObjectManager
{
public:
	ObjectManager();
	virtual ~ObjectManager();
	//Vector<GameObject> GameObjects;
};

}

#endif /* OBJECTMANAGER_H_ */
