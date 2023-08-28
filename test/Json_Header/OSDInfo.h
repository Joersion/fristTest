#pragma once
#include "JObject_NetSDK.h"
#include "OSDInfoWidget.h"
NS_NETSDK_CFG_BEGIN

#define JK_OSDInfo "OSDInfo" 
class OSDInfo : public JObject
{
public:
	JObjArray<JStrObj>	Info;	/// ������Ϣ��������12�У�ÿ�����64���ַ�
	OSDInfoWidget		mOSDInfoWidget;
	
public:
	OSDInfo(JObject *pParent = NULL, const char *szName = JK_OSDInfo):
	JObject(pParent,szName),
	Info(this, "Info"),
	mOSDInfoWidget(this, "OSDInfoWidget"){
	};

	~OSDInfo(void){};
};

NS_NETSDK_CFG_END