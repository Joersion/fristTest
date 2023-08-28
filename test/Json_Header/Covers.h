#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_Covers "Covers" 
class Covers : public JObject
{
public:
	JStrObj					BackColor;				///< ����ĺ�MakeRGB����͸����
	JBoolObj				EncodeBlend;			///< �������
	JStrObj					FrontColor;				///< �����ǰ��MakeRGB����͸����
	JBoolObj				PreviewBlend;			///< Ԥ������,�Ƿ���ʾ��1����ʾ 0������
	JObjArray<JIntObj>		RelativePos;			///< ����߾��������ı���*8191

public:
    Covers(JObject *pParent = NULL, const char *szName = JK_Covers):
    JObject(pParent,szName),
	BackColor(this, "BackColor"),
	EncodeBlend(this, "EncodeBlend"),
	FrontColor(this, "FrontColor"),
	PreviewBlend(this, "PreviewBlend"),
	RelativePos(this, "RelativePos"){
	};

    ~Covers(void){};
};

NS_NETSDK_CFG_END