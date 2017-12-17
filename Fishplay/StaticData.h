//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : StaticData.h
//  @ Date : 2017/9/29
//  @ Author : linshougui
//
//


#if !defined(_STATICDATA_H)
#define _STATICDATA_H

#include<string>
#include"cocos2d.h"
using namespace std;

USING_NS_CC;

// using cocos2d::CCDictionary;
// using cocos2d::CCPointFromString;
// using cocos2d::CCRectFromString;
// using cocos2d::CCSizeFromString;

#define STATIC_DATA_FILENAME "static_data.plist"
#define STATIC_DATA_STRING(key) StaticData::sharedStaticData()->stringValueFromKey(key)
#define STATIC_DATA_INT(key) StaticData::sharedStaticData()->intValueFromKey(key)
#define STATIC_DATA_FlOAT(key) StaticData::sharedStaticData()->floatValueFromKey(key)
#define STATIC_DATA_BOOL(key) StaticData::sharedStaticData()->booleanFromKey(key)
#define STATIC_DATA_POINT(key) StaticData::sharedStaticData()->pointFromKey(key)
#define STATIC_DATA_RECT(key) StaticData::sharedStaticData()->rectFromKey(key)
#define STATIC_DATA_SIZE(key) StaticData::sharedStaticData()->sizeFromKey(key)



class StaticData:
    public CCObject{
public:
	static StaticData* sharedStaticData();
	static void purge();
	int intValueFromKey(const std::string &key);
	const char* stringValueFromKey(const std::string &key);
	float floatValueFromKey(const std::string &key);
	bool booleanFromKey(const std::string &key);
	cocos2d::CCPoint pointFromKey(const std::string &key);
	cocos2d::CCRect rectFromKey(const std::string &key);
	cocos2d::CCSize sizeFromKey(const std::string &key);
protected:
	cocos2d::CCDictionary* _dictionary;
	std::string _staticFileName;
	bool init();
private:
	~StaticData();
	StaticData();
};

#endif  //_STATICDATA_H