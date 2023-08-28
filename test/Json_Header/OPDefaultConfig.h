#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OPDefaultConfig "OPDefaultConfig" 
class OPDefaultConfig : public JObject
{
public:
	JBoolObj		Account;			// �û�����
	JBoolObj		Alarm;				// ����
	JBoolObj		CameraPARAM;		// ��������ͷ����
	JBoolObj		CommPtz;			// ��̨������
	JBoolObj		Encode;				// ��������
	JBoolObj		Factory;			// �ָ�������������
	JBoolObj		General;			// ��ͨ����
	JBoolObj		NetCommon;			// ͨ������
	JBoolObj		NetServer;			// �������
	JBoolObj		Preview;			// Ԥ������
	JBoolObj		Record;				// ¼������

public:
	OPDefaultConfig(JObject *pParent = NULL, const char *szName = JK_OPDefaultConfig):
	JObject(pParent,szName),
	Account(this, "Account"),
	Alarm(this, "Alarm"),
	CameraPARAM(this, "CameraPARAM"),
	CommPtz(this, "CommPtz"),
	Encode(this, "Encode"),
	Factory(this, "Factory"),
	General(this, "General"),
	NetCommon(this, "NetCommon"),
	NetServer(this, "NetServer"),
	Preview(this, "Preview"),
	Record(this, "Record"){
		this->Parse("{ \"Name\" : \"OPDefaultConfig\", \"OPDefaultConfig\" : { \"Account\" : false, \"Alarm\" : false, \"CameraPARAM\" : false, \"CommPtz\" : false, \"Encode\" : false, \"Factory\" : false, \"General\" : false, \"NetCommon\" : false, \"NetServer\" : false, \"Preview\" : false, \"Record\" : false }, \"SessionID\" : \"0x4d\" }");
	};

    ~OPDefaultConfig(void){};
};

NS_NETSDK_CFG_END