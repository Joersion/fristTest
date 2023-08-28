#pragma once
#ifndef _XNetSDKSyn_H_
#define _XNetSDKSyn_H_
#include "XNetSDK.h"
/*************************************************************************************
*同步接口定义
***************************************************************************************/

#ifdef __cplusplus             
extern "C"{
#endif

XSDK_API XSDK_HANDLE CALLBACK XSDK_DevLoginSyn(SXSDKLoginParam *pParam, int nTimeout);

// 设备系统&通道配置相关
XSDK_API int CALLBACK XSDK_DevGetSysConfigSyn(XSDK_HANDLE hDevice, const char *szCommandName, char *pOutBuffer, int *pInOutBufferSize, int nTimeout, int nCommand = EXCMD_CONFIG_GET);

// 设备通道配置获取
XSDK_API int CALLBACK XSDK_DevGetChnConfigSyn(XSDK_HANDLE hDevice, int nChannel, const char *szCommandName, char *pOutBuffer, int *pInOutBufferSize, int nTimeout, int nCommand = EXCMD_CONFIG_GET);

// 设备系统配置设置
XSDK_API int CALLBACK XSDK_DevSetSysConfigSyn(XSDK_HANDLE hDevice, const char *szCommandName, const char *pConfig, int nConfigLen, char *pOutBuffer, int *pInOutBufferSize, int nTimeout, int nCommand = EXCMD_CONFIG_SET);

// 设备通道配置设置
XSDK_API int CALLBACK XSDK_DevSetChnConfigSyn(XSDK_HANDLE hDevice, int nChannel, const char *szCommandName, const char *pConfig, int nConfigLen, char *pOutBuffer, int *pInOutBufferSize, int nTimeout, int nCommand = EXCMD_CONFIG_SET);

// 设备局域网搜索
XSDK_API int CALLBACK XSDK_SearchDevicesSyn(SXSDK_CONFIG_NET_COMMON *pRet, int nMaxCount);

//设备端抓图
XSDK_API int CALLBACK XSDK_XSDK_DevSnapSyn(XSDK_HANDLE hDevice, int nChannel, const char* szPicType, unsigned char* pOutBuffer, int* pInOutBufferSize);

//查找录像文件
XSDK_API int CALLBACK XSDK_DevFindFileSyn(XSDK_HANDLE hDevice, SXSDKQueryRecordReq* pParam, SXSDKQueryRecordRes* pFiles, int nMaxCount, int nTimeout);

//按时间查找录像文件对应每分钟
XSDK_API int CALLBACK XSDK_DevFindFileByTimeSyn(XSDK_HANDLE hDevice, SXSDKSearchByTimeReq* pParam, SXSDKSearchByTimeRes* pFiles, int nTimeout);

//查询录像日历
XSDK_API int CALLBACK XSDK_SearchCalendarSyn(XSDK_HANDLE hDevice, SXSDKSearchCalendarReq* pParam, SXSDKSearchCalendarRes * pCalendarInfo, int nTimeout);

#ifdef __cplusplus
}
#endif

#endif //_XNetSDKSyn_H_
