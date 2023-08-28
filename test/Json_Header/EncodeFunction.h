#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_EncodeFunction "EncodeFunction" 
class EncodeFunction : public JObject
{
public:
	JBoolObj		DoubleStream;			///< ˫��������
	JBoolObj		CombineStream;			///< ��ϱ���
	JBoolObj		SnapStream;				///< ץͼ����
	JBoolObj		WaterMark;				///< ˮӡ����------���ܷ���(2016.1.16)
	JBoolObj		IFrameRange;			///< I֡���
	JBoolObj		LowBitRate;				///< �����������ò�Ʒʹ��
	JBoolObj		SmartH264;				///< H264+
	JBoolObj		IntelligentEncode;		///< ���ܱ���
	JBoolObj		SmartH264Plus;			///< H264++
	JBoolObj		SmartH264V2;			//�µ�H264+/H264++
	JBoolObj		CustomChnDAMode;		///< �Զ�����ģ�л�����
	JBoolObj		SmartEncodeDigital;		///Smart��������ͨ��
	JBoolObj		MultiChannel;			///��ͨ������

public:
    EncodeFunction(JObject *pParent = NULL, const char *szName = JK_EncodeFunction):
    JObject(pParent,szName),
	DoubleStream(this, "DoubleStream"),
	CombineStream(this, "CombineStream"),
	SnapStream(this, "SnapStream"),
	WaterMark(this, "WaterMark"),
	IFrameRange(this, "IFrameRange"),
	LowBitRate(this, "LowBitRate"),
	SmartH264(this, "SmartH264"),
	IntelligentEncode(this, "IntelligentEncode"),
	SmartH264Plus(this, "SmartH264Plus"),
	SmartH264V2(this, "SmartH264V2"),
	CustomChnDAMode(this, "CustomChnDAMode"),
	SmartEncodeDigital(this, "SmartEncodeDigital"),
	MultiChannel(this, "MultiChannel"){
	};

    ~EncodeFunction(void){};
};

NS_NETSDK_CFG_END