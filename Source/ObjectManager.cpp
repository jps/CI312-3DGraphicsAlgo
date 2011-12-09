/*
 * ObjectManager.cpp
 *
 *  Created on: Dec 8, 2011
 *      Author: Panda
 */

#include "../Header/ObjectManager.h"

namespace Game
{

	ObjectManager::ObjectManager()
	{

	}

	ObjectManager* ObjectManager::pInstance = NULL;

	ObjectManager* ObjectManager::Inst()
	{
		if(pInstance == NULL)
		{
			pInstance = new ObjectManager();
		}
		  return pInstance;
	}


	void ObjectManager::Draw()
	{
		for (vector<GameObject>::iterator it = GameObjects.begin(); it!=GameObjects.end(); ++it) {
			if(it->visible)
				it->Draw();
		}
	}

	ObjectManager::~ObjectManager()
	{

		// TODO Auto-generated destructor stub
	}

}
