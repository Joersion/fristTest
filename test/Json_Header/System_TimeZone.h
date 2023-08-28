#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

enum TimeZoneType
{
	TimeZone_UTC_N12_00=-1200,			//�ս�����
	TimeZone_UTC_N11_00=-1100,			//��;��,��Ħ��Ⱥ��	
	TimeZone_UTC_N10_00=-1000,			//������
	TimeZone_UTC_N09_00=-900,			//����˹��
	TimeZone_UTC_N08_00=-800,			//̫ƽ��ʱ��(�����ͼ��ô�)
	TimeZone_UTC_N07_00=-700,			//ɽ��ʱ��(�����ͼ��ô�)
	TimeZone_UTC_N06_00=-600,			//�в�ʱ��(�����ͼ��ô�)
	TimeZone_UTC_N05_00=-500,			//����ʱ��(�����ͼ��ô�)
	TimeZone_UTC_N04_00=-400,			//������ʱ��(���ô�)
	TimeZone_UTC_N03_30=-330,			//Ŧ����
	TimeZone_UTC_N03_00=-300,			//��������,���ζ�
	TimeZone_UTC_N02_00=-200,			//�д�����
	TimeZone_UTC_N01_00=-100,			//����Ⱥ��,��ý�Ⱥ��
	TimeZone_UTC_P00_00=0,				//������,�׶�,������
	TimeZone_UTC_P01_00=100,			//����,��ķ˹�ص�,����,����
	TimeZone_UTC_P02_00=200,			//�ŵ�,Ү·����,��˹̹����
	TimeZone_UTC_P03_00=300,			//�͸��,������,Ī˹��
	TimeZone_UTC_P03_30=330,			//�º���
	TimeZone_UTC_P04_00=400,			//��������,�Ϳ�,��˹����
	TimeZone_UTC_P04_30=430,			//������
	TimeZone_UTC_P05_00=500,			//��˹����,������,��ʲ��
	TimeZone_UTC_P05_30=530,			//����,�����˹,�µ���
	TimeZone_UTC_P05_45=545,			//�ӵ�����
	TimeZone_UTC_P06_00=600,			//����ľͼ,������,�￨
	TimeZone_UTC_P06_30=630,			//����
	TimeZone_UTC_P07_00=700,			//����,����,�żӴ�
	TimeZone_UTC_P08_00=800,			//����,��³ľ��,̨��,�¼���
	TimeZone_UTC_P09_00=900,			//����,����,����,����
	TimeZone_UTC_P09_30=930,			//��������,�����
	TimeZone_UTC_P10_00=1000,			//������,ī����,Ϥ��
	TimeZone_UTC_P11_00=1100,			//��ӵ�,������Ⱥ��
	TimeZone_UTC_P12_00=1200,			//�¿���,�����
	TimeZone_UTC_P13_00=1300,			//Ŭ�Ⱒ�巨
	TimeZone_UTCNum,
};

#define JK_System_TimeZone "System.TimeZone"
class System_TimeZone : public JObject 
{
public:
	JBoolObj	FirstUserTimeZone;
	JIntObj		timeMin;

public:
	System_TimeZone(JObject *pParent = NULL, const char *szName = JK_System_TimeZone):
	JObject(pParent,szName),
	FirstUserTimeZone(this, "FirstUserTimeZone"),
	timeMin(this, "timeMin"){
	};

	~System_TimeZone(void){};
};

NS_NETSDK_CFG_END