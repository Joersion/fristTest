#pragma once
#include "JObject_NetSDK.h"
#include "AlarmFunction.h"
#include "CommFunction.h"
#include "EncodeFunction.h"
#include "InputMethod.h"
#include "MobileDVR.h"
#include "NetServerFunction.h"
#include "OtherFunction.h"
#include "PreviewFunction.h"
#include "TipShow.h"
NS_NETSDK_CFG_BEGIN

#define JK_SystemFunction "SystemFunction" 
#define JK_SystemFunction_MsgId 1360
class SystemFunction : public JObject
{
public:
	AlarmFunction		mAlarmFunction;
	CommFunction		mCommFunction;
	EncodeFunction		mEncodeFunction;
	InputMethod		mInputMethod;
	MobileDVR		mMobileDVR;
	NetServerFunction		mNetServerFunction;
	OtherFunction		mOtherFunction;
	PreviewFunction		mPreviewFunction;
	TipShow		mTipShow;

public:
    SystemFunction(JObject *pParent = NULL, const char *szName = JK_SystemFunction):
    JObject(pParent,szName),
	mAlarmFunction(this, "AlarmFunction"),
	mCommFunction(this, "CommFunction"),
	mEncodeFunction(this, "EncodeFunction"),
	mInputMethod(this, "InputMethod"),
	mMobileDVR(this, "MobileDVR"),
	mNetServerFunction(this, "NetServerFunction"),
	mOtherFunction(this, "OtherFunction"),
	mPreviewFunction(this, "PreviewFunction"),
	mTipShow(this, "TipShow"){
	};

    ~SystemFunction(void){};
};

NS_NETSDK_CFG_END