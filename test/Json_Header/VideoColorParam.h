#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_VideoColorParam "VideoColorParam" 
class VideoColorParam  : public JObject
{
public:
	JIntObj				Acutance;			///< ���   0-15		
	JIntObj				Brightness;			///< ����	0-100
	JIntObj				Contrast;			///< �Աȶ�	0-100
	JIntObj				Gain;				///< ����	0-100 �ڣ�λ��1��ʾ�Զ�����		
	JIntObj				Hue;				///< ɫ��	0-100
	JIntObj				Saturation;			///< ���Ͷ�	0-100
	JIntObj				Whitebalance;		///< �Զ��׵�ƽ���ƣ�bit7��λ��ʾ�����Զ�����.0x0,0x1,0x2�ֱ�����,��,�ߵȼ�
	
public:
	VideoColorParam (JObject *pParent = NULL, const char *szName = JK_VideoColorParam):
	JObject(pParent,szName),
	Acutance(this, "Acutance"),
	Brightness(this, "Brightness"),
	Contrast(this, "Contrast"),
	Gain(this, "Gain"),
	Hue(this, "Hue"),
	Saturation(this, "Saturation"),
	Whitebalance(this, "Whitebalance"){
	};

	~VideoColorParam (void){};
};

NS_NETSDK_CFG_END