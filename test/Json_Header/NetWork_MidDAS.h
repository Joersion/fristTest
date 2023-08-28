#pragma once
#include "JObject_NetSDK.h"

NS_NETSDK_CFG_BEGIN

#define JK_NetWork_MidDAS "NetWork.MidDAS" 
class NetWork_MidDAS : public JObject
{
public:
	JBoolObj		Enable;				//DAS�����Ƿ���
	JBoolObj		MidEnable;			//���ķ������Ƿ���Ч�������Ч�������ķ������ṩ��ip�Ͷ˿ںţ��������Ч�������õ�ֱ��ip�Ͷ˿ں�
	JStrObj			UserName;			//�û���
	JStrObj			Password;			//����
	JStrObj			ServerAddr;			//��Ⱥ��������ַ
	
public:
    NetWork_MidDAS(JObject *pParent = NULL, const char *szName = JK_NetWork_MidDAS):
    JObject(pParent,szName),
	Enable(this, "Enable"),
	MidEnable(this, "MidEnable"),
	UserName(this, "UserName"),
	Password(this, "Password"),
	ServerAddr(this, "ServerAddr"){
	};

    ~NetWork_MidDAS(void){};
};

NS_NETSDK_CFG_END