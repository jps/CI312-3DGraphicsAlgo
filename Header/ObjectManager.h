/*
 * ObjectManager.h
 *
 *  Created on: Dec 8, 2011
 *      Author: Panda
 */

#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_

#include "GameObject.h"
#include <vector>

using namespace std;

namespace Game
{

class ObjectManager
{
public:
	static ObjectManager* Inst();
	void Initialize();
	virtual ~ObjectManager();
	void Draw();
	vector<GameObject> GameObjects;

protected:
	ObjectManager();
private:
	static ObjectManager* pInstance;
};

}

#endif /* OBJECTMANAGER_H_ */



/*


class Log {
  public:
    //void Logging(string message);

    ~Log();
  protected:
    Log(); // constructor
  private:
    static Log* pInstance;
};
*/
