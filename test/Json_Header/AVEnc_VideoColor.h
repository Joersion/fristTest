#pragma once
#include "JObject_NetSDK.h"
#include "VideoColorParam.h"

NS_NETSDK_CFG_BEGIN

#define JK_AVEnc_VideoColor "AVEnc.VideoColor" 
class AVEnc_VideoColor : public JObject
{
public:
	JObjArray<JObjArray<JStrObj> >	TimeSection;			///// ʱ���
	JIntObj							Enable;					///// ʹ��:0,1
	VideoColorParam					m_VideoColorParam;		///// ��ɫ����
	
public:
    AVEnc_VideoColor(JObject *pParent = NULL, const char *szName = JK_AVEnc_VideoColor):
    JObject(pParent,szName),
	TimeSection(this, "TimeSection"),
	Enable(this, "Enable"),
	m_VideoColorParam(this, "VideoColorParam"){
	};

    ~AVEnc_VideoColor(void){};
};

NS_NETSDK_CFG_END