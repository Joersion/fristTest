#pragma once
#include "JObject_NetSDK.h"
#include "EncodeInfo.h"
#include "CombEncodeInfo.h"
NS_NETSDK_CFG_BEGIN

struct ConfigPair
{
	const char* name;
	int value;
};

/// ����ѹ����ʽ����
enum CaptureCompressType 
{
	CAPTURE_COMPRESS_DIVX_MPEG4,	///< DIVX MPEG4��
	CAPTURE_COMPRESS_MS_MPEG4,		///< MS MPEG4��		(������)
	CAPTURE_COMPRESS_MPEG2,			///< MPEG2��
	CAPTURE_COMPRESS_MPEG1,			///< MPEG1��
	CAPTURE_COMPRESS_H263,			///< H.263
	CAPTURE_COMPRESS_MJPG,			///< MJPG
	CAPTURE_COMPRESS_FCC_MPEG4,		///< FCC MPEG4		(������)
	CAPTURE_COMPRESS_H264,			///< H.264
	CAPTURE_COMPRESS_H265,			///< H.265
	CAPTURE_COMPRESS_NR				///< ö�ٵ�ѹ����׼��Ŀ��
};

static ConfigPair CompressionMap[] = 
{
	{"MPEG4", CAPTURE_COMPRESS_DIVX_MPEG4},
	{" ", CAPTURE_COMPRESS_MS_MPEG4},
	{"MPEG2", CAPTURE_COMPRESS_MPEG2},
	{"MPEG1", CAPTURE_COMPRESS_MPEG1},
	{"H.263", CAPTURE_COMPRESS_H263},
	{"MJPG", CAPTURE_COMPRESS_MJPG},
	{" ", CAPTURE_COMPRESS_FCC_MPEG4},
	{"H.264", CAPTURE_COMPRESS_H264},
	{"H.265", CAPTURE_COMPRESS_H265},
	{NULL, }
};

/// ����ֱ�������
enum CaptureImageSize 
{
	CAPTURE_IMAGE_SIZE_D1,			///< 704*576(PAL)	704*480(NTSC)
	CAPTURE_IMAGE_SIZE_HD1,			///< 704*288(PAL)	704*240(NTSC)
	CAPTURE_IMAGE_SIZE_BCIF,		///< 352*576(PAL)	352*480(NTSC)
	CAPTURE_IMAGE_SIZE_CIF,			///< 352*288(PAL)	352*240(NTSC)
	CAPTURE_IMAGE_SIZE_QCIF,		///< 176*144(PAL)	176*120(NTSC)
	CAPTURE_IMAGE_SIZE_VGA,			///< 640*480(PAL)	640*480(NTSC)
	CAPTURE_IMAGE_SIZE_QVGA,		///< 320*240(PAL)	320*240(NTSC)
	CAPTURE_IMAGE_SIZE_SVCD,		///< 480*480(PAL)	480*480(NTSC)
	CAPTURE_IMAGE_SIZE_QQVGA,		///< 160*128(PAL)	160*128(NTSC)
	CAPTURE_IMAGE_SIZE_NR = 9,      ///< ö�ٵ�ͼ�δ�С�������Ŀ��
	CAPTURE_IMAGE_SIZE_ND1 = 9,     ///< 240*192
	CAPTURE_IMAGE_SIZE_650TVL,      ///< 926*576
	CAPTURE_IMAGE_SIZE_720P,        ///< 1280*720
	CAPTURE_IMAGE_SIZE_1_3M,        ///< 1280*960
	CAPTURE_IMAGE_SIZE_UXGA ,       ///< 1600*1200
	CAPTURE_IMAGE_SIZE_1080P,       ///< 1920*1080
	CAPTURE_IMAGE_SIZE_WUXGA,       ///< 1920*1200
	CAPTURE_IMAGE_SIZE_2_5M,        ///< 1872*1408
	CAPTURE_IMAGE_SIZE_3M,          ///< 2048*1536
	CAPTURE_IMAGE_SIZE_5M,          ///< 3744*1408
	CAPTURE_IMAGE_SIZE_EXT_NR = 19,
	CAPTURE_IMAGE_SIZE_1080N = 19,     	///< 960*1080
	CAPTURE_IMAGE_SIZE_4M,        		///< 2592*1520
	CAPTURE_IMAGE_SIZE_6M,				///< 3072��2048
	CAPTURE_IMAGE_SIZE_8M,				///< 3264��2448
	CAPTURE_IMAGE_SIZE_12M,				///< 4000*3000
	CAPTURE_IMAGE_SIZE_4K,				///< 4096 * 2160/3840*2160
	CAPTURE_IMAGE_SIZE_EXT_V2_NR =25,
	CAPTURE_IMAGE_SIZE_720N = 25,  		///< 640*720
	CAPTURE_IMAGE_SIZE_WSVGA,       	///< 1024*576
	CAPTURE_IMAGE_SIZE_NHD,				///< Wifi IPC 640*360
	CAPTURE_IMAGE_SIZE_3M_N,			///< 1024*1536
	CAPTURE_IMAGE_SIZE_4M_N,			///< 1296*1520
	CAPTURE_IMAGE_SIZE_5M_N,			///< 1872*1408
	CAPTURE_IMAGE_SIZE_4K_N,			///< 2048 * 2160ͨ��/1920*2160��˼
	CAPTURE_IMAGE_SIZE_EXT_V3_NR,
};

static ConfigPair s_videoResolutionMap[] = 
{
	{"D1", CAPTURE_IMAGE_SIZE_D1},
	{"HD1", CAPTURE_IMAGE_SIZE_HD1},
	{"BCIF", CAPTURE_IMAGE_SIZE_BCIF},
	{"CIF", CAPTURE_IMAGE_SIZE_CIF},
	{"QCIF", CAPTURE_IMAGE_SIZE_QCIF},
	{"VGA", CAPTURE_IMAGE_SIZE_VGA},
	{"QVGA", CAPTURE_IMAGE_SIZE_QVGA},
	{"SVCD", CAPTURE_IMAGE_SIZE_SVCD},
	{"QQVGA",CAPTURE_IMAGE_SIZE_QQVGA},
	{"ND1",CAPTURE_IMAGE_SIZE_ND1},
	{"650TVL",CAPTURE_IMAGE_SIZE_650TVL},
	{"720P",CAPTURE_IMAGE_SIZE_720P},
	{"1_3M",CAPTURE_IMAGE_SIZE_1_3M},
	{"UXGA",CAPTURE_IMAGE_SIZE_UXGA},
	{"1080P",CAPTURE_IMAGE_SIZE_1080P},
	{"WUXGA",CAPTURE_IMAGE_SIZE_WUXGA},
	{"2_5M",CAPTURE_IMAGE_SIZE_2_5M},
	{"3M",CAPTURE_IMAGE_SIZE_3M},
	{"5M",CAPTURE_IMAGE_SIZE_5M},
	{"1080N",CAPTURE_IMAGE_SIZE_1080N},
	{"4M",CAPTURE_IMAGE_SIZE_4M},
	{"6M",CAPTURE_IMAGE_SIZE_6M},
	{"8M",CAPTURE_IMAGE_SIZE_8M},
	{"12M",CAPTURE_IMAGE_SIZE_12M},
	{"4K",CAPTURE_IMAGE_SIZE_4K},
	{"720N",CAPTURE_IMAGE_SIZE_720N},
	{"WSVGA",CAPTURE_IMAGE_SIZE_WSVGA},
	{"NHD", CAPTURE_IMAGE_SIZE_NHD},
	{"3M_N",CAPTURE_IMAGE_SIZE_3M_N},
	{"4M_N",CAPTURE_IMAGE_SIZE_4M_N},
	{"5M_N",CAPTURE_IMAGE_SIZE_5M_N},
	{"4K_N",CAPTURE_IMAGE_SIZE_4K_N},
	{NULL, }
};

#define JK_EncodeCapability "EncodeCapability" 
class EncodeCapability : public JObject
{
public:
	JIntObj								ChannelMaxSetSync;				///< ÿ��ͨ���ֱ����Ƿ���Ҫͬ�� 0-��ͬ��, 1 -ͬ��
	JObjArray<CombEncodeInfo>			mCombEncodeInfo;				///< ��ϱ�����Ϣ,��ʱ����4������
	JIntHex								Compression;					///< ����ģʽ����
	JObjArray<EncodeInfo>				mEncodeInfo;					///< ������Ϣ,��ʱ����4������
	JObjArray<JIntHex>					ExImageSizePerChannel;			///< ÿ��ͨ��֧�ֵĸ�����ͼ��ֱ���
	JObjArray<JObjArray<JIntHex> >		ExImageSizePerChannelEx;		///< ÿ��ͨ��֧�ֵĸ�����ͼ��ֱ���
	JObjArray<JIntHex>					ImageSizePerChannel;			///< ÿ��ͨ��֧�ֵ�ͼ��ֱ���
	JIntObj								MaxBitrate;						///< �������Kbps
	JIntObj								MaxEncodePower;					///< ֧�ֵ�����������
	JObjArray<JIntHex>					MaxEncodePowerPerChannel;		///< ÿ��ͨ��֧�ֵ���߱�������
	JObjArray<JIntHex>					ThirdStreamImageSize;			///< CHL_3IRD_T����֧�ֵ�ͼ��ֱ���
	JObjArray<JIntHex>					FourthStreamImageSize;			///< CHL_4RTH_T����֧�ֵ�ͼ��ֱ���

public:
	EncodeCapability(JObject *pParent = NULL, const char *szName = JK_EncodeCapability):
	JObject(pParent,szName),
	ChannelMaxSetSync(this, "ChannelMaxSetSync"),
	mCombEncodeInfo(this, "CombEncodeInfo"),
	Compression(this, "Compression"),
	mEncodeInfo(this, "EncodeInfo"),
	ExImageSizePerChannel(this, "ExImageSizePerChannel"),
	ExImageSizePerChannelEx(this, "ExImageSizePerChannelEx"),
	ImageSizePerChannel(this, "ImageSizePerChannel"),
	MaxBitrate(this, "MaxBitrate"),
	MaxEncodePower(this, "MaxEncodePower"),
	ThirdStreamImageSize(this, "ThirdStreamImageSize"),
	FourthStreamImageSize(this, "FourthStreamImageSize"),
	MaxEncodePowerPerChannel(this, "MaxEncodePowerPerChannel"){
		this->Parse("{ \"EncodeCapability\" : { \"ChannelMaxSetSync\" : 0, \"CombEncodeInfo\" : [ { \"CompressionMask\" : \"0x00000000\", \"Enable\" : true, \"HaveAudio\" : true, \"ResolutionMask\" : \"0x00000000\", \"StreamType\" : \"MainStream\" }, { \"CompressionMask\" : \"0x00000000\", \"Enable\" : false, \"HaveAudio\" : false, \"ResolutionMask\" : \"0x00000000\", \"StreamType\" : \"ExtraStream2\" }, { \"CompressionMask\" : \"0x00000000\", \"Enable\" : false, \"HaveAudio\" : false, \"ResolutionMask\" : \"0x00000000\", \"StreamType\" : \"ExtraStream3\" }, { \"CompressionMask\" : \"0x00000000\", \"Enable\" : false, \"HaveAudio\" : false, \"ResolutionMask\" : \"0x00000000\", \"StreamType\" : \"ExtraStream4\" }, { \"CompressionMask\" : \"0x00000000\", \"Enable\" : false, \"HaveAudio\" : false, \"ResolutionMask\" : \"0x00000000\", \"StreamType\" : \"JPEGStream\" } ], \"Compression\" : \"0x00000000\", \"EncodeInfo\" : [ { \"CompressionMask\" : \"0x00000080\", \"Enable\" : true, \"HaveAudio\" : true, \"ResolutionMask\" : \"0xFFBFFFFF\", \"StreamType\" : \"MainStream\" }, { \"CompressionMask\" : \"0x00000080\", \"Enable\" : true, \"HaveAudio\" : true, \"ResolutionMask\" : \"0xFFFFFFFF\", \"StreamType\" : \"ExtraStream2\" }, { \"CompressionMask\" : \"0x00000000\", \"Enable\" : false, \"HaveAudio\" : false, \"ResolutionMask\" : \"0x00000000\", \"StreamType\" : \"ExtraStream3\" }, { \"CompressionMask\" : \"0x00000000\", \"Enable\" : false, \"HaveAudio\" : false, \"ResolutionMask\" : \"0x00000000\", \"StreamType\" : \"ExtraStream4\" }, { \"CompressionMask\" : \"0x00000080\", \"Enable\" : true, \"HaveAudio\" : true, \"ResolutionMask\" : \"0xFFFFFFFF\", \"StreamType\" : \"JPEGStream\" } ], \"ExImageSizePerChannel\" : [ \"0x00000009\" ], \"ExImageSizePerChannelEx\" : [ [ \"0x00000018\", \"0x00000000\", \"0x00000000\", \"0x00000018\", \"0x00000010\", \"0x00000078\", \"0x00000040\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000009\", \"0x00000009\", \"0x00000000\", \"0x00000009\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\", \"0x00000000\" ] ], \"FourthStreamImageSize\" : [ \"0x00000000\" ], \"ImageSizePerChannel\" : [ \"0x00000801\" ], \"MaxBitrate\" : 49152, \"MaxEncodePower\" : 38016000, \"MaxEncodePowerPerChannel\" : [ \"0x02441400\" ], \"ThirdStreamImageSize\" : [ \"0x00000000\" ] }, \"Name\" : \"EncodeCapability\", \"Ret\" : 100, \"SessionID\" : \"0x00000178\" }");
	};

	~EncodeCapability(void){};
};

NS_NETSDK_CFG_END