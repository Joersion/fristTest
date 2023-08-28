#pragma once
#ifndef _XNetSDK_H_
#define _XNetSDK_H_

#ifdef __cplusplus             
extern "C"{
#endif

#if (defined(WIN32)||defined(_WIN32) ||defined(__WIN32__)||defined(__NT__)||defined(_WIN64))
#define OS_WINDOWS
#endif

#ifdef OS_WINDOWS
#ifdef XNETSDK_EXPORTS
#define XSDK_API extern "C" __declspec(dllexport)
#define CALLBACK __stdcall
#else
#define XSDK_API extern "C" __declspec(dllimport)
#define CALLBACK __stdcall
#endif
#else
#define XSDK_API
#define CALLBACK
#endif

#include "XNetSDKDefine.h"

#define XSDK_HANDLE int
typedef int (CALLBACK *PXSDK_MessageCallBack) (XSDK_HANDLE hDevice, int nMsgId, int nParam1, int nParam2, int nParam3, const char *szString, void *pObject, int nSeq, void *pUserData);

////////////////////////////About XSDK////////////////////////////
typedef struct SXSDKInitParam
{
	int nLogLevel;
	PXSDK_MessageCallBack pMsgCallBack;
	void *pUserData;
}SXSDKInitParam;

////////////////////////////About Device////////////////////////////
typedef int (CALLBACK *PXSDK_MediaCallBack) (XSDK_HANDLE hMedia, const unsigned char *pData, int nDataLen, int nDataType, void *pDataInfo, int nDataInfoSize, void *pUserData);
typedef struct SXMediaRealPlayReq 
{
	int nChannel;
	int nStreamType;
	int nRequestType;		// 0：原始码流回调 1：按帧回调(见枚举：EXSDK_DATA_FORMATE)
	PXSDK_MediaCallBack pMediaCallback;
	void *pUserData;
}SXMediaRealPlayReq;

typedef struct SXMediaFaceImageReq 
{
	int nChannel;
	int nImgTypeMsk;		// 3
	char szIntelType[64];   // Face
	PXSDK_MediaCallBack pMediaCallback;
	void *pUserData;
}SXMediaFaceImageReq;

typedef struct SXMediaRecordReq 
{
	int nChannel;
	int nStreamType;
	char sBeginTime[32];
	char sEndTime[32];
	char sFileName[64];		// 文件名称
	int nRequestType;		// 0：原始码流回调 1：按帧回调
	char sIntelligentPlayBackEvent[64];
	int nIntelligentPlayBackSpeed;
	PXSDK_MediaCallBack pMediaCallback;
	void *pUserData;
}SXMediaRecordReq;

typedef struct SXMediaTalkReq 
{
	int nBitRate;			///< 码流大小，kbps为单位，比如192kbps，128kbps
	int nSampleRate;		///< 采样率，Hz为单位，比如44100Hz
	int nSampleBit;			///< 采样的位深
	char nEncodeType[64];	///< 编码方式，-------G711_ALAW
	int nRequestType;		///< 0：原始码流回调 1：按帧回调(见枚举：EXSDK_DATA_FORMATE)
	PXSDK_MediaCallBack pMediaCallback;
	void *pUserData;
}SXMediaTalkReq;

typedef struct SXCloudUpgradeVersion
{
	char name[128];			// 版本名
	char date[12];			//版本日期，格式:"2014-08-26"
	unsigned int length;	// 升级文件长度
}SXCloudUpgradeVersion;

// SDK 初始化&反初始化
XSDK_API int CALLBACK XSDK_Init(SXSDKInitParam *pParam);
XSDK_API int CALLBACK XSDK_InitAppInfo(SXSDK_APPUserInfo *pParam);
XSDK_API void CALLBACK XSDK_UnInit();

XSDK_API int CALLBACK XSDK_SetSDKIntAttr(int nAttrKey, int nValue);
XSDK_API int CALLBACK XSDK_GetSDKIntAttr(int nAttrKey, int nDefaultValue);

XSDK_API int CALLBACK XSDK_SetSDKStrAttr(int nAttrKey, const char *szValue);
XSDK_API const char *CALLBACK XSDK_GetSDKStrAttr(int nAttrKey, char *pResult, int nMaxSize);

XSDK_API int CALLBACK XSDK_SetObjIntAttr(XSDK_HANDLE hObject, int nAttrKey, int nValue);
XSDK_API int CALLBACK XSDK_GetObjIntAttr(XSDK_HANDLE hObject, int nAttrKey, int nDefaultValue);

XSDK_API int CALLBACK XSDK_SetObjStrAttr(XSDK_HANDLE hObject, int nAttrKey, const char *szValue);
XSDK_API const char *CALLBACK XSDK_GetObjStrAttr(XSDK_HANDLE hObject, int nAttrKey, char *pResult, int nMaxSize);

// 设备登录、登出
// MsgId:ESXSDK_DEV_LOGIN
XSDK_API XSDK_HANDLE CALLBACK XSDK_DevLogin(SXSDKLoginParam *pParam, int nTimeout, int nSeq);
XSDK_API void CALLBACK XSDK_DevLogout(XSDK_HANDLE hDevice);

// 设备系统&通道配置相关
//ESXSDK_DEV_GET_SYS_CONFIG  = 12007,		// 设备系统配置获取
XSDK_API int CALLBACK XSDK_DevGetSysConfig(XSDK_HANDLE hDevice, const char *szCommandName, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_GET);
//ESXSDK_DEV_GET_CHN_CONFIG  = 12009,		// 设备通道配置获取
XSDK_API int CALLBACK XSDK_DevGetChnConfig(XSDK_HANDLE hDevice, int nChannel, const char *szCommandName, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_GET);
// ESXSDK_DEV_SET_SYS_CONFIG  = 12008,		// 设备系统配置设置
XSDK_API int CALLBACK XSDK_DevSetSysConfig(XSDK_HANDLE hDevice, const char *szCommandName, const char *pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_SET);
// ESXSDK_DEV_SET_CHN_CONFIG  = 12010,		// 设备通道配置设置
XSDK_API int CALLBACK XSDK_DevSetChnConfig(XSDK_HANDLE hDevice, int nChannel, const char *szCommandName, const char *pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand = EXCMD_CONFIG_SET);

// 向设备发送数据（异步）
// nMsgId:用户自定义返回消息ID值 要求范围 nMsgId >= ESXSDK_DEV_USER_COMMAND_BEGIN && nMsgId <ESXSDK_DEV_GENERAL_COMMAND_END1 || nMsgId == ESXSDK_DEV_GENERAL_COMMAND
XSDK_API int CALLBACK XSDK_DevSendData(XSDK_HANDLE hDevice, const char *szCommandName, const char *pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand, int nMsgId = ESXSDK_DEV_GENERAL_COMMAND);
XSDK_API int CALLBACK XSDK_DevSendDataEx(XSDK_HANDLE hDevice, const char *szCommandName, const char *pConfig, int nConfigLen, int nSeq, int nTimeout, int nCommand, int nMsgId = ESXSDK_DEV_GENERAL_COMMAND, unsigned char nChannelOrTotalPacket = 0, unsigned char nEndFlagOrCurPacket = 0, unsigned char nReserved1 = 0, unsigned char nReserved2 = 0);

// 开启或关闭设备报警回调
// 结果在PXSDK_MessageCallBack函数中回调
// MsgId:EXCMD_ALARM_REQ = 1504
// szString:报警消息(Json格式)
XSDK_API int CALLBACK XSDK_DevSetAlarmListener(XSDK_HANDLE hDevice, int bListener);

// ESXSDK_ON_SEARCH_DEVICES   = 13001,		// 局域网设备搜索
// param2:返回个数
XSDK_API int CALLBACK XSDK_SearchDevices(int nTimeout);

////////////////////////////////////////////云台方向控制控制////////////////////////////////////////////
// szPTZCommand：操作命令(枚举如下)
#define S_XPTZ_DirectionLeftUp	"DirectionLeftUp"
#define S_XPTZ_DirectionUp		"DirectionUp"
#define S_XPTZ_DirectionRightUp "DirectionRightUp"
#define S_XPTZ_DirectionLeft	"DirectionLeft"
#define S_XPTZ_DirectionRight	"DirectionRight"
#define S_XPTZ_DirectionLeftDown "DirectionLeftDown"
#define S_XPTZ_DirectionDown	"DirectionDown"
#define S_XPTZ_DirectionRightDown "DirectionRightDown"
#define S_XPTZ_IrisSmall	"IrisSmall"
#define S_XPTZ_IrisLarge	"IrisLarge"
#define S_XPTZ_FocusNear	"FocusNear"
#define S_XPTZ_FocusFar		"FocusFar"
#define S_XPTZ_ZoomWide		"ZoomWide"
#define S_XPTZ_ZoomTile		"ZoomTile"
// nStep：步长
// bStop：开始/停止
XSDK_API int CALLBACK XSDK_DevPtzControl(XSDK_HANDLE hDevice, int nChannel, const char *szPTZCommand, int nStep, bool bStop);

/////////////////云台预置点操作/////////////////
// szPTZCommand：操作命令(枚举如下)
#define S_XPTZ_GotoPreset	"GotoPreset"
#define S_XPTZ_SetPreset	"SetPreset"
#define S_XPTZ_ClearPreset	"ClearPreset"
// nPreset：预置点值
XSDK_API int CALLBACK XSDK_DevPtzPreset(XSDK_HANDLE hDevice, int nChannel, const char *szPTZCommand, int nPreset);

////设置巡航点
///nPresetPoint:巡航点
XSDK_API int CALLBACK XSDK_SetPtzTourPoint(XSDK_HANDLE hDevice, int nChannel, int nPresetPoint, int nStep, int nTourIndex, bool bAdd);

/////////////////云台巡航操作/////////////////
// nPreset：巡航点值
XSDK_API int CALLBACK XSDK_DevPtzTour(XSDK_HANDLE hDevice, int nChannel, int nTourIndex, bool bStart);

///////删除巡航路线值///////
///巡航点值
XSDK_API int CALLBACK XSDK_DeleteDevPtzTour(XSDK_HANDLE hDevice, int nChannel, int nTourIndex);

/////////////////云台巡航点获取/配置等其它通用操作示例/////////////////
//#include "OPPTZControl.h"
//XSDK_CFG::OPPTZControl ptz;
//ptz.Command = "";
//const char *pConfig = ptz.ToString();
//return XSDK_DevSetSysConfig(hDevice, JK_OPPTZControl, pConfig, STRLEN(pConfig), nSeq, nTimeout, EXCMD_PTZ_REQ);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ESXSDK_DEV_FIND_FILE  = 12011,		// 设备录像查询
// 注意函数一次最多返回64条（）
XSDK_API int CALLBACK XSDK_DevFindFile(XSDK_HANDLE hDevice, SXSDKQueryRecordReq *pParam, int nTimeout, int nSeq);

// 时间同步
// 时间格式：2018-07-25 17:20:37; == NULL或""时，默认为当前系统时间
// 返回MsgID:ESXSDK_DEV_SET_SYS_CONFIG  = 12008,		// 设备系统配置设置
// 返回nParam3:EXCMD_SYSMANAGER_RSP
XSDK_API int CALLBACK XSDK_DevSynTime(XSDK_HANDLE hDevice, const char *szTime = "", int nSeq = 0);

// 设备通道抓图
// 功能说明：发送抓图命令给设备，设备抓图后回传。图片大小设备根据自身能力定义
// nChannel：抓图通道号
// szPicType：图片类型，暂时不用
XSDK_API int CALLBACK XSDK_DevSnap(XSDK_HANDLE hDevice, int nChannel, const char *szPicType, int nSeq = 0);

// 强制I帧
// 功能说明：强制生成一个视频关键帧
// nChannel：通道号
// nStreamType：码流类型(0主码流,1子码流)
XSDK_API int CALLBACK XSDK_MakeKeyFrame(XSDK_HANDLE hDevice, int nChannel, int nStreamType);

// 实时媒体播放
// MsgId:ESXSDK_MEDIA_START_REAL_PLAY
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRealPlay(XSDK_HANDLE hDevice, SXMediaRealPlayReq *pParam, int nSeq = 0, int nTimeout = 0);

// 录像回放
// MsgId:ESXSDK_MEDIA_START_RECORD_PLAY
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordPlay(XSDK_HANDLE hDevice,  SXMediaRecordReq* pParam, int nSeq, int nTimeout = 0);

///按文件名称回放
// MsgId:ESXSDK_MEDIA_START_RECORD_PLAY_BYNAME
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordPlayByName(XSDK_HANDLE hDevice, SXMediaRecordReq* pParam, int nSeq, int nTimeout = 0);

// 录像下载
// MsgId:ESXSDK_MEDIA_DOWN_RECORD_FILE
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordDownload(XSDK_HANDLE hDevice,  SXMediaRecordReq* pParam, int nSeq, int nTimeout = 0);

// 按文件名称下载
// MsgId:ESXSDK_MEDIA_DOWN_IMAGE_FILE
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaRecordDownloadByName(XSDK_HANDLE hDevice, SXMediaRecordReq* pParam, int nSeq, int nTimeout = 0);

// 录像回放/下载控制->暂停/继续
XSDK_API int CALLBACK XSDK_MediaPause(XSDK_HANDLE hMedia, bool bPause);

// 录像回放跳转
// szTime:YYYY-MM-DD HH:mm:SS
XSDK_API int CALLBACK XSDK_MediaSeekToTime(XSDK_HANDLE hMedia, const char *szTime);

// 回放速度控制
// -1~-4:慢放1~4档
// 1~4：快放1~4档
// 0:恢复
XSDK_API int CALLBACK XSDK_MediaSetSpeed(XSDK_HANDLE hMedia, int nSpeed);

// 人脸识别图片回调
// MsgId:ESXSDK_MEDIA_START_FACE_IMAGE
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_MediaGetFaceImage(XSDK_HANDLE hDevice, SXMediaFaceImageReq *pParam, int nSeq = 0, int nTimeout = 0);

// 实时预览/录像回放/下载--停止
XSDK_API void CALLBACK XSDK_MediaStop(XSDK_HANDLE nMediaId);

//对密码进行MD5加密，适用于用户密码修改---加密密码长度最大512
XSDK_API int CALLBACK XSDK_EncryptPassword(const char * inputPswBuf, signed char * outputPswBuf, int PswSize);

//跨网段修改设备IP
// lpInputbuffer-----需要发送的配置SXSDK_CONFIG_NET_COMMON_V2
// >  0:成功
// <= 0:失败
XSDK_API int CALLBACK XSDK_ModifyDevIP(const char* lpInputbuffer, int buffersize, int nTimeout);

//修改设备密码
// pConfig-----需要发送的配置SXSDK_MODIFY_PSW
// ESXSDK_DEV_SET_SYS_CONFIG  = 12008,		// 设备系统配置设置
XSDK_API int CALLBACK XSDK_DevModifyIPConfig(XSDK_HANDLE hDevice, const char *pConfig, int nConfigLen, int nSeq, int nTimeout);

//升级设备
// MsgId:ESXSDK_DEV_UPGRADE
// >  0 : 成功
// <= 0 : 失败
XSDK_API XSDK_HANDLE CALLBACK XSDK_DevUpgrade(XSDK_HANDLE hDevice, const char * fileName, int nSeq, int nTimeout);


// 开启/关闭设备主动注册服务
// szServerIP ：服务器IP
// nServerPort: 监听端口
// MsgId:ESXSDK_ON_DAS_SERVER_START
// 返回：此服务操作句柄，可用来关闭服务
// 注意：如果端口被占用，SDK内部会不断重试，直到成功
XSDK_API XSDK_HANDLE CALLBACK XSDK_StartDASServer(const char *szServerIP, int nServerPort);
XSDK_API void CALLBACK XSDK_StopDASServer(XSDK_HANDLE hServer);

// 通过设备DeviceId（可以在DAS配置中设置），获取设备登录句柄
XSDK_API XSDK_HANDLE CALLBACK XSDK_GetDASDevHandle(const char *szDeviceId);

// 打开对讲功能
// MsgId:ESXSDK_MEDIA_START_TALK
XSDK_API XSDK_HANDLE CALLBACK XSDK_StartTalk(XSDK_HANDLE hDevice, SXMediaTalkReq *pParam);

//发送对讲数据
// MsgId:ESXSDK_DEV_SET_SYS_CONFIG
XSDK_API XSDK_HANDLE CALLBACK XSDK_SendTalkData(XSDK_HANDLE hMedia, const char *pBuffer, int nBufLen);

/////////////////透明串口通道/////////////////
// szComType：串口类型
#define S_XTRANS_COMM_RS232	"RS232"
#define S_XTRANS_COMM_RS485	"RS485"
XSDK_API XSDK_HANDLE CALLBACK XSDK_OpenTransCom(XSDK_HANDLE hDevice, const char *szComType);

//关闭透明串口
XSDK_API void CALLBACK XSDK_CloseTransCom(XSDK_HANDLE hTranport);

//向串口写数据
//nSerialType---------0:RS232;1:RS485
XSDK_API int CALLBACK XSDK_TransComWrite(XSDK_HANDLE hDevice, int nSerialType, const char *pBuffer, int nBufLen, int nSeq);

//获取重置密码相关信息
//
XSDK_API int CALLBACK XSDK_GetResetPswInfo(int nDevPort, const char * sDevId, const char *szCommandName, int nSeq, int nTimeout);

//设置重置密码相关信息
//
XSDK_API int CALLBACK XSDK_SetResetPswInfo(int nDevPort, const char * sDevId, const char *szCommandName, const char *pConfig, int nConfigLen, int nSeq, int nTimeout);


/////发送文件数据到设备上（目前主要用于发送自定义报警语音文件）
XSDK_API XSDK_HANDLE CALLBACK XSDK_SendFileToDev(XSDK_HANDLE hDevice, const char* fileName, int nSeq, int nTimeout);

/////对讲NVR所连接的IPC前端
XSDK_API XSDK_HANDLE CALLBACK XSDK_Talk_NVRCrossIPC(XSDK_HANDLE hDevice, int nChannel, SXMediaTalkReq* pParam);

//////云升级设备固件
XSDK_API XSDK_HANDLE CALLBACK XSDK_Upgrade_Cloud(XSDK_HANDLE hDevice, SXCloudUpgradeVersion * pParam);

//////停止云升级
XSDK_API void CALLBACK XSDK_Stop_Upgrade_Cloud(XSDK_HANDLE hDevUpgrade);

/// <summary>
/// 说明：异步获取指定序列号设备的服务状态（XTC/XTS/DSS等服务状态，不是本地登录状态）
///       异步回调消息ID：ESXSDK_DEV_ON_GET_STATE
///       调用后，该SN自动加入服务状态的监听队列，变更时会通过消息ESXSDK_DEV_UPDATE_DEVSTATUS通知
///       XSDK_CancelDevServerStatusListen函数取消监听设备服务状态
/// </summary>
/// <param name="sDeviceSn">设备序列号，多个设备以";"分隔开</param>
/// <param name="nSeq">返回Seq</param>
/// <param name="nTimeout">超时时间，默认为10秒</param>
XSDK_API int CALLBACK XSDK_GetDevServerStatus(const char* sDeviceSn, int nSeq = 0, int nTimeout = 10);

/// <summary>
/// 说明：取消监听设备服务状态
/// </summary>
/// <param name="sDeviceSn">设备序列号，多个设备以";"分隔开</param>
XSDK_API void CALLBACK XSDK_CancelDevServerStatusListen(const char* sDeviceSn);

/////从设备上导出文件
XSDK_API XSDK_HANDLE CALLBACK XSDK_ExportFileFromDev(XSDK_HANDLE hDevice, const char* sFileName, int nFileSize, int nSeq, int nTimeout);

#ifdef __cplusplus
}
#endif

#endif //_XNetSDK_H_
