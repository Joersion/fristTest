#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN


////////////////���ص���־�����ַ���ע��/////////////////
#define LogTypeAccountRestore			"AccountRestore"				//�˺Ż�ԭĬ��
#define LogTypeAddGroup					"AddGroup"						//�����
#define LogTypeAddUser					"AddUser"						//�����û�
#define LogTypeClearDriver				"ClearDriver"					//�������������
#define LogTypeClearLog					"ClearLog"						//�����־
#define LogTypeDeleteGroup				"DeleteGroup"					//ɾ����
#define LogTypeDeleteUser				"DeleteUser"					//ɾ���û�
#define LogTypeDiskChanged				"DiskChanged"					//�洢�豸�䶯
#define LogTypeEventLatch				"EventLatch"					//�ӳ��¼�
#define LogTypeEventStart				"EventStart"					//������ʼ
#define LogTypeEventStop				"EventStop"						//��������
#define LogTypeFileAccess				"FileAccess"					//�ļ���ȡ
#define LogTypeFileAccessError			"FileAccessError"				//�ļ����ʳ���
#define LogTypeFileSearch				"FileSearch"					//�ļ���ѯ
#define LogTypeLogIn					"LogIn"							//�û���¼
#define LogTypeLogOut					"LogOut"						//�û��ǳ�
#define LogTypeModifyGroup				"ModifyGroup"					//�޸���
#define LogTypeModifyPassword			"ModifyPassword"				//�޸�����
#define LogTypeModifyTime				"ModifyTime"					//�޸�ϵͳʱ��
#define LogTypeModifyUser				"ModifyUser"					//�޸��û�
#define LogTypePTZTour					"PTZTour"						//Ѳ��·��
#define LogTypeReboot					"Reboot"						//����
#define LogTypeRecord					"Record"						//¼�����
#define LogTypeSaveConfig				"SaveConfig"					//��������
#define LogTypeSetDriverType			"SetDriverType"					//��������������
#define LogTypeShutDown					"ShutDown"						//�ػ�
#define LogTypeStorageDeviceError		"StorageDeviceError"			//�洢�豸����
#define LogTypeUpdate					"Update"						//����
#define LogTypeUpgrade					"Upgrade"						//ϵͳ����
#define LogTypeZeroBitrate				"ZeroBitrate"					//������
#define LogTypeSaveSystemState			"SaveSystemState"				//����ϵͳ״̬
#define LogTypeTimeChanged				"TimeChanged"					//�޸�ʱ��
#define LogTypeSetTime					"SetTime"						//����ʱ��


#define JK_OPLogQueryInfo "OPLogQuery"

class OPLogQueryInfo : public JObject
{
public:
	JStrObj		Data;			///< ��־����
	JIntObj		Position;		///< ���ϴβ�ѯ�Ľ���ʱ����־ָ��
	JStrObj		Time;			///< ��־ʱ��
	JStrObj		Type;			///< ��־����		
	JStrObj		User;			///< ��־�û�

public:
    OPLogQueryInfo(JObject *pParent = NULL, const char *szName = JK_OPLogQueryInfo):
    JObject(pParent,szName),
	Data(this, "Data"),
	Position(this, "Position"),
	Time(this, "Time"),
	Type(this, "Type"),
	User(this, "User"){
	};

    ~OPLogQueryInfo(void){};
};

NS_NETSDK_CFG_END