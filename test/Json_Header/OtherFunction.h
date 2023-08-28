#pragma once
#include "JObject_NetSDK.h"
NS_NETSDK_CFG_BEGIN

#define JK_OtherFunction "OtherFunction" 
class OtherFunction : public JObject
{
public:
	JBoolObj DownLoadPause;
	JBoolObj USBsupportRecord;
	JBoolObj SDsupportRecord;
	JBoolObj SupportOnvifClient;
	JBoolObj SupportNetLocalSearch;
	JBoolObj SupportMaxPlayback;
	JBoolObj SupportNVR;
	JBoolObj SupportC7Platform;
	JBoolObj SupportMailTest;
	JBoolObj SupportOSDInfo;
	JBoolObj HideDigital;
	JBoolObj NotSupportAH;							//ˮƽ���AcutanceHorizontal
	JBoolObj NotSupportAV;							//��ֱ���AcutanceVertial
	JBoolObj SupportBT;								//��̬BroadTrends
	JBoolObj NotSupportTalk	;						//�Խ�
	JBoolObj AlterDigitalName;						//֧���޸�����ͨ������
	JBoolObj SupportShowConnectStatus;
	JBoolObj SupportPlayBackExactSeek;
	JBoolObj TitleAndStateUpload;
	JBoolObj NOHDDRECORD;
	JBoolObj MusicFilePlay;
	JBoolObj SupportSetDigIP;
	JBoolObj SupportShowProductType;
	JBoolObj SupportCamareStyle;
	JBoolObj Supportonviftitle;
	JBoolObj SupportDimenCode;
	JBoolObj SupportStorageNAS;
	JBoolObj ShowFalseCheckTime;
	JBoolObj SupportTimeZone;
	JBoolObj ShowAlarmLevelRegion;
	JBoolObj SupportPOS;							//֧��POS
	JBoolObj HddLowSpaceUseMB;						//Ӳ�̿ռ䲻�㱨����MB
	JBoolObj SupportCustomOemInfo;					//����OEM�ͻ��汾��Ϣ
	JBoolObj SupportDigitalEncode;					//����ͨ����������
	JBoolObj SupportResumePtzState;					//�����ָ���̨״̬
	JBoolObj SupportSnapCfg;
	JBoolObj SupportAbnormitySendMail;				//�洢�豸���ڼ��洢�쳣���洢�ռ䲻�㷢�ʼ�}
	JBoolObj SupportDigitalPre;						//����ͨ��֧��Ԥ¼
	JBoolObj SupportWriteLog;						//����ҳ������Ƿ�д��־��ѡ��
	JBoolObj SuppportChangeOnvifPort;				//֧���޸�onvif�˿�
	JBoolObj SupportCommDataUpload;					//֧�ִ�������͸��
	JBoolObj SupportTextPassword;					//������Է������������onvif��Ȩ
	JBoolObj SupportCloudUpgrade;
	JBoolObj SupportUserProgram;					//֧�ֿͻ�����С����
	JBoolObj SupportModifyFrontcfg;					//
	JBoolObj SupportFTPTest;						//ftp����
	JBoolObj SupportPtzIdleState;					//��̨���ж�������
	JBoolObj SupportImpRecord;						//web���Ƿ��ṩ�ؼ�¼������ѡ��
	JBoolObj SupportCameraMotorCtrl;				//IE��֧�ֻ�����������
	JBoolObj SupportEncodeAddBeep;					//���ñ���ÿ��30�����beep��
	JBoolObj SupportFishEye;						//���۹���
	JBoolObj SupportSPVMNNasServer;					//���ճ��嶨��
	JBoolObj SupportSmallChnTitleFont;				//ʹ��12*18��ͨ���������
	JBoolObj SupportCfgCloudupgrad;					//֧�����������������޸�
	JBoolObj SupportStorageFailReboot;
	JBoolObj SupportSplitControl;					//�޸�DVRԤ������ָ�
	JBoolObj SupportRTSPClient;						//����ͨ������RTSPǰ��
	JBoolObj SupportLowLuxMode;						//������Ƿ�֧��΢��ģʽ
	JBoolObj SupportSwitchResolution;				//�޸�ǰ������ͨ���ֱ���	
	JBoolObj SupportSlowMotion;						//������Ƿ�֧��������
	JBoolObj SupportCorridorMode;					//֧������ģʽ
	JBoolObj SupportWIFINVR;						//��WIFINVR�豸
	JBoolObj SupportSnapSchedule;					//�Ƿ�֧�ֶ�ʱץͼ
	JBoolObj SupportPWDSafety;						//�Ƿ�֧�������һ�},
	JBoolObj SupportPlateDetect;					//֧�ֳ������
	JBoolObj SupportBreviary;						//�Ƿ�֧������ͼ
	JBoolObj SupportIntelligentPlayBack;			//�Ƿ�֧�����ܿ��
	JBoolObj SupportFaceDetect;						//�Ƿ�֧������ʶ��
	JBoolObj SupportDeviceInfoNew;					//�Ƿ�֧�����豸��Ϣ
	JBoolObj SupportBallCameraTrackDetect;			//֧���������ʶ��
	JBoolObj SpecialNight;							//ҹ������ģʽ����
	JBoolObj SupportSetHardwareAbility;				//֧�������豸Ӳ��������
	JBoolObj SupportSafetyEmail;					//֧��ͨ��Email�������� 
	JBoolObj SupportSensorAbilitySetting;			///֧�ֺϷ�ģ��֧�ֵ�sensor�ȼ�
	JBoolObj SupportAlarmVoiceTips;
	JBoolObj SupportAlarmLinkLight;	
	JBoolObj SupportSetRtcTime;						//֧��Rtcʱ��У������
	JBoolObj SupportAudioFormat;					//֧����Ƶ����
	JBoolObj SupportSoftPhotosensitive;				//�����
	JBoolObj SupportCloudUpgradeIPC;
	JBoolObj SupportFileUpgradeIPC;					//֧��IE�����ļ�ͨ��NVR��IPC����
	JBoolObj SupportParkingGuide;					//֧�ֳ�λ��������
	JBoolObj SupportLimitNetLoginUsers;				//���������½���û���
	JBoolObj SupportCoaxialParamCtrl;				//ͬ���������
	JBoolObj SupportShowH265X;						//��ʾH265X����
	JBoolObj SupportLogStorageCtrl;					//��־�洢����
	JBoolObj SupportAdminContactInfo;				//֧�����ù���Ա��ϵ��ʽ
	JBoolObj SupportWarnWeakPWD;					//��ʾ����������
	JBoolObj SupportStringChangedXPOE;				//֧��ͨ��ģʽ��ʾΪXPOE
	JBoolObj SupportAlarmVoiceTipsType;				//֧�ֱ�����ʾ�������޸�
	JBoolObj SupportAcrossIPCTalk;					//֧��ǰ��IPC�Խ�
	JBoolObj SupportSetVolume;						//֧��������������
	JBoolObj SupportFaceDetectV2;			
	JBoolObj SupportFaceksHumanDetect;				//֧�ֿ������μ��
	JBoolObj SupportFacekshttpcommunication;		//֧�ֿ���http����
	JBoolObj SupportFaceRecognition;				//֧������ʶ�� 
	JBoolObj SupportCustomizeLpRect;				//�Ƿ�֧��������״�ĳ�λ

public:
    OtherFunction(JObject *pParent = NULL, const char *szName = JK_OtherFunction):
    JObject(pParent,szName),
	DownLoadPause(this, "DownLoadPause"),
	USBsupportRecord(this, "USBsupportRecord"),
	SDsupportRecord(this, "SDsupportRecord"),
	SupportOnvifClient(this, "SupportOnvifClient"),
	SupportNetLocalSearch(this, "SupportNetLocalSearch"),
	SupportMaxPlayback(this, "SupportMaxPlayback"),
	SupportNVR(this, "SupportNVR"),
	SupportC7Platform(this, "SupportC7Platform"),
	SupportMailTest(this, "SupportMailTest"),
	SupportOSDInfo(this, "SupportOSDInfo"),
	HideDigital(this, "HideDigital"),
	NotSupportAH(this, "NotSupportAH"),
	NotSupportAV(this, "NotSupportAV"),
	SupportBT(this, "SupportBT"),
	NotSupportTalk(this, "NotSupportTalk"),
	AlterDigitalName(this, "AlterDigitalName"),
	SupportShowConnectStatus(this, "SupportShowConnectStatus"),
	SupportPlayBackExactSeek(this, "SupportPlayBackExactSeek"),
	TitleAndStateUpload(this, "TitleAndStateUpload"),
	NOHDDRECORD(this, "NOHDDRECORD"),
	MusicFilePlay(this, "MusicFilePlay"),
	SupportSetDigIP(this, "SupportSetDigIP"),
	SupportShowProductType(this, "SupportShowProductType"),
	SupportCamareStyle(this, "SupportCamareStyle"),
	Supportonviftitle(this, "Supportonviftitle"),
	SupportDimenCode(this, "SupportDimenCode"),
	SupportStorageNAS(this, "SupportStorageNAS"),
	ShowFalseCheckTime(this, "ShowFalseCheckTime"),
	SupportTimeZone(this, "SupportTimeZone"),
	ShowAlarmLevelRegion(this, "ShowAlarmLevelRegion"),
	SupportPOS(this, "SupportPOS"),
	HddLowSpaceUseMB(this, "HddLowSpaceUseMB"),
	SupportCustomOemInfo(this, "SupportCustomOemInfo"),
	SupportDigitalEncode(this, "SupportDigitalEncode"),
	SupportResumePtzState(this, "SupportResumePtzState"),
	SupportSnapCfg(this, "SupportSnapCfg"),
	SupportAbnormitySendMail(this, "SupportAbnormitySendMail"),
	SupportDigitalPre(this, "SupportDigitalPre"),
	SupportWriteLog(this, "SupportWriteLog"),
	SuppportChangeOnvifPort(this, "SuppportChangeOnvifPort"),
	SupportCommDataUpload(this, "SupportCommDataUpload"),
	SupportTextPassword(this, "SupportTextPassword"),
	SupportCloudUpgrade(this, "SupportCloudUpgrade"),
	SupportUserProgram(this, "SupportUserProgram"),
	SupportModifyFrontcfg(this, "SupportModifyFrontcfg"),
	SupportFTPTest(this, "SupportFTPTest"),
	SupportPtzIdleState(this, "SupportPtzIdleState"),
	SupportImpRecord(this, "SupportImpRecord"),
	SupportCameraMotorCtrl(this, "SupportCameraMotorCtrl"),
	SupportEncodeAddBeep(this, "SupportEncodeAddBeep"),
	SupportFishEye(this, "SupportFishEye"),
	SupportSPVMNNasServer(this, "SupportSPVMNNasServer"),
	SupportSmallChnTitleFont(this, "SupportSmallChnTitleFont"),
	SupportCfgCloudupgrad(this, "SupportCfgCloudupgrad"),
	SupportStorageFailReboot(this, "SupportStorageFailReboot"),
	SupportSplitControl(this, "SupportSplitControl"),
	SupportRTSPClient(this, "SupportRTSPClient"),
	SupportLowLuxMode(this, "SupportLowLuxMode"),
	SupportSwitchResolution(this, "SupportSwitchResolution"),
	SupportSlowMotion(this, "SupportSlowMotion"),
	SupportCorridorMode(this, "SupportCorridorMode"),
	SupportWIFINVR(this, "SupportWIFINVR"),
	SupportSnapSchedule(this, "SupportSnapSchedule"),
	SupportPWDSafety(this, "SupportPWDSafety"),
	SupportPlateDetect(this, "SupportPlateDetect"),
	SupportBreviary(this, "SupportBreviary"),
	SupportIntelligentPlayBack(this, "SupportIntelligentPlayBack"),
	SupportFaceDetect(this, "SupportFaceDetect"),
	SupportDeviceInfoNew(this, "SupportDeviceInfoNew"),
	SupportBallCameraTrackDetect(this, "SupportBallCameraTrackDetect"),
	SpecialNight(this, "SpecialNight"),
	SupportSetHardwareAbility(this, "SupportSetHardwareAbility"),
	SupportSafetyEmail(this, "SupportSafetyEmail"),
	SupportSensorAbilitySetting(this, "SupportSensorAbilitySetting"),
	SupportAlarmVoiceTips(this, "SupportAlarmVoiceTips"),
	SupportAlarmLinkLight(this, "SupportAlarmLinkLight"),
	SupportSetRtcTime(this, "SupportSetRtcTime"),
	SupportAudioFormat(this, "SupportAudioFormat"),
	SupportSoftPhotosensitive(this, "SupportSoftPhotosensitive"),
	SupportCloudUpgradeIPC(this, "SupportCloudUpgradeIPC"),
	SupportFileUpgradeIPC(this, "SupportFileUpgradeIPC"),
	SupportParkingGuide(this, "SupportParkingGuide"),
	SupportLimitNetLoginUsers(this, "SupportLimitNetLoginUsers"),
	SupportCoaxialParamCtrl(this, "SupportCoaxialParamCtrl"),
	SupportShowH265X(this, "SupportShowH265X"),
	SupportLogStorageCtrl(this, "SupportLogStorageCtrl"),
	SupportAdminContactInfo(this, "SupportAdminContactInfo"),
	SupportWarnWeakPWD(this, "SupportWarnWeakPWD"),
	SupportStringChangedXPOE(this, "SupportStringChangedXPOE"),
	SupportAlarmVoiceTipsType(this, "SupportAlarmVoiceTipsType"),
	SupportAcrossIPCTalk(this, "SupportAcrossIPCTalk"),
	SupportSetVolume(this, "SupportSetVolume"),
	SupportFaceDetectV2(this, "SupportFaceDetectV2"),
	SupportFaceksHumanDetect(this, "SupportFaceksHumanDetect"),
	SupportFacekshttpcommunication(this, "SupportFacekshttpcommunication"),
	SupportFaceRecognition(this, "SupportFaceRecognition"),
    SupportCustomizeLpRect(this, "SupportCustomizeLpRect"){
	};

    ~OtherFunction(void){};
};

NS_NETSDK_CFG_END