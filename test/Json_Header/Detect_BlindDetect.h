#pragma once
#include "JObject_NetSDK.h"
#include "EventHandler.h"
NS_NETSDK_CFG_BEGIN

#define JK_Detect_BlindDetect "Detect.BlindDetect" 
class Detect_BlindDetect : public JObject //视频遮挡
{
public:
	JBoolObj		Enable;
	EventHandler		mEventHandler;
	JIntObj		Level;

public:
	Detect_BlindDetect(JObject *pParent = NULL, const char *szName = JK_Detect_BlindDetect):
	JObject(pParent,szName),
	Enable(this, "Enable"),
	mEventHandler(this, "EventHandler"),
	Level(this, "Level"){
	};

	~Detect_BlindDetect(void){};
};

NS_NETSDK_CFG_END