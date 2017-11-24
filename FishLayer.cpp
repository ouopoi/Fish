#include "FishLayer.h"
#include "Fish.h"

FishLayer::FishLayer(void)
{
}

bool FishLayer::init()
{
	do 
	{
		if (!CCLayer::init())
		{
			return false;
		}
		_fishes = CCArray::createWithCapacity(FISH_MAX_COUNT);
		CC_SAFE_RETAIN(_fishes);
		srand(time(0));
		for(int i = 0; i < FISH_MAX_COUNT; i++){
			int type = (rand()%100/(double)101) * k_Fish_Type_Count - 1;
			Fish* fish = Fish::create((FishType)type);
			_fishes->addObject(fish);
		}
		this->schedule(schedule_selector(FishLayer::addFish), 3.0f);
		return true;
	} while (0);
	return false;
}

void FishLayer::addFish(float delta)
	{
		int addToCount = (rand()%100/(double)101) * 5 + 1;
		int count = 0;
		 srand(time(0));
		CCObject* obj;
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		CCARRAY_FOREACH(_fishes, obj)
		{
			Fish* fish = (Fish*)obj;
			if(fish->isRunning())
			{
				continue;
			}
			//this->addChild(fish);
			//fish->setPosition(ccp((rand()%100/(double)101)* winSize.width, (rand()%100/(double)101) * winSize.height));
			count++;
			resetFish(fish);
			if(count == addToCount)
			{
				break;
			}
		}
}

FishLayer::~FishLayer(void)
{
}
