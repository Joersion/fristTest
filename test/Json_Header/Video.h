#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_Video "Video" 
class Video : public JObject
{
public:
	JIntObj		BitRate;				/// 0-4096k,���б���Ҫ�ɿͻ��˱��棬�豸ֻ����ʵ�ʵ�����ֵ�������±ꡣ
	JStrObj		BitRateControl;			///��������
	JStrObj		Compression;			///ѹ��ģʽ(��Ƶ��ʽ)
	JIntObj		FPS;					///֡��ֵ
	JIntObj		GOP;					///��������I֮֡��ļ��ʱ�䣬2-12 
	JIntObj		Quality;				///�����Ļ��� ����1-6	
	JStrObj		Resolution;				///�ֱ���

public:
	Video(JObject *pParent = NULL, const char *szName = JK_Video):
	JObject(pParent,szName),
	BitRate(this, "BitRate"),
	BitRateControl(this, "BitRateControl"),
	Compression(this, "Compression"),
	FPS(this, "FPS"),
	GOP(this, "GOP"),
	Quality(this, "Quality"),
	Resolution(this, "Resolution"){
	};

	~Video(void){};
};

NS_NETSDK_CFG_END