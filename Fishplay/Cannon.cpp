#include "Cannon.h"

//#include "math.h"
#include <cmath>
using namespace std;
USING_NS_CC;

Cannon::Cannon(void)
{
}


Cannon::~Cannon(void)
{
}
Cannon *Cannon::create(CannonType type)
{
	Cannon *cannon = new Cannon();
	if(cannon&&cannon->init(type))
	{
		cannon->autorelease();
		return cannon;
	}
	else
	{
		CC_SAFE_DELETE(cannon);
		return NULL;
	}
}

bool Cannon::init(CannonType type)
{
	if(!CCNode::init())
	{
		return false;
	}
	_cannonSprites = CCArray::createWithCapacity(k_Cannon_Count);
	for(int i=k_Cannon_Type_1;i<k_Cannon_Count;i++)
	{	
		CCString *fileName = CCString::createWithFormat("actor_cannon1_%d1.png",i+1);
		CCSprite *cannonSprite = CCSprite::createWithSpriteFrameName(fileName->getCString());
		_cannonSprites->addObject(cannonSprite);
		cannonSprite->setAnchorPoint(ccp(0.5,0.5));
	}
	CC_SAFE_RETAIN(_cannonSprites);
	setType(type);
	return true;
}
CannonType Cannon::getType()
{
	return _type;
}
void Cannon::setType(CannonType var)
{
	if(_type==var)
	{
		return;
	}
	if(var<k_Cannon_Type_1)
	{
		var = (CannonType)(k_Cannon_Count-1);
	}else if(var >= k_Cannon_Count)
	{
		var = k_Cannon_Type_1;
	}
	removeChildByTag(_type);
	CCSprite *sprite=(CCSprite*) _cannonSprites->objectAtIndex(var);
	addChild(sprite,0,var);
	_type=var;
}
CCSize Cannon::getSize()
{
	CCSprite *cannonSprite = (CCSprite *) _cannonSprites->objectAtIndex(_type);
	return cannonSprite->getContentSize();
}
float Cannon::getFireRange()
{
	//return 300*(_type+1);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	double temp = pow(winSize.width/2,2)+pow(winSize.height,2);
	double result = sqrt(temp);
	return result/7*(_type+1);


}