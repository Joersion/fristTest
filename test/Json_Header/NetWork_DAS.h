#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_NetWork_DAS "NetWork.DAS" 
class NetWork_DAS : public JObject
{
public:
	JStrObj			DeviceID;				//�豸��ID��--���Լ���������
	JBoolObj		Enable;					//�Ƿ���DAS
	JStrObj			Password;				//�豸����
	JIntObj			Port;					//�˿ں�--��Ҫ�����ڼ����Ķ˿�(��XSDK_StartDASServer�ӿڶ˿�һ��)
	JStrObj			ServerAddr;				//��������ַ
	JStrObj			UserName;				//�û���
	
public:
	NetWork_DAS(JObject *pParent = NULL, const char *szName = JK_NetWork_DAS):
	JObject(pParent,szName),
	DeviceID(this, "DeviceID"),
	Enable(this, "Enable"),
	Password(this, "Password"),
	Port(this, "Port"),
	ServerAddr(this, "ServerAddr"),
	UserName(this, "UserName"){
	};

	~NetWork_DAS(void){};
};

NS_NETSDK_CFG_END