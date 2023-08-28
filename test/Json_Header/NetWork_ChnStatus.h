#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_ChnStatus "NetWork.ChnStatus" 
class NetWork_ChnStatus : public JObject
{
public:
	JStrObj		ChnName;
	JStrObj		CurRes;
	JStrObj		MaxRes;
	JStrObj		Status;

public:
    NetWork_ChnStatus(JObject *pParent = NULL, const char *szName = JK_NetWork_ChnStatus):
    JObject(pParent,szName),
	ChnName(this, "ChnName"),
	CurRes(this, "CurRes"),
	MaxRes(this, "MaxRes"),
	Status(this, "Status"){
	};

    ~NetWork_ChnStatus(void){};
};

NS_NETSDK_CFG_END