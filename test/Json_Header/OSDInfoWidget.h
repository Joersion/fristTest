#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OSDInfoWidget "OSDInfoWidget" 
class OSDInfoWidget : public JObject
{
public:
	JStrObj		BackColor;		/// ����ĺ�MakeRGB����͸����
	JBoolObj	EncodeBlend;	/// �������
	JStrObj		FrontColor;		/// �����ǰ��MakeRGB����͸����
	JBoolObj	PreviewBlend;	/// Ԥ������
	JObjArray<JIntObj>	RelativePos;	/// ����߾��������ı���*8191([���ϣ��ң���])

public:
	OSDInfoWidget(JObject *pParent = NULL, const char *szName = JK_OSDInfoWidget):
	JObject(pParent,szName),
	BackColor(this, "BackColor"),
	EncodeBlend(this, "EncodeBlend"),
	FrontColor(this, "FrontColor"),
	PreviewBlend(this, "PreviewBlend"),
	RelativePos(this, "RelativePos"){
	};

	~OSDInfoWidget(void){};
};

NS_NETSDK_CFG_END