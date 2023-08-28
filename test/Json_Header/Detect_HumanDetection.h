#pragma once
#include "JObject_NetSDK.h"
#include "PedRule.h"

NS_NETSDK_CFG_BEGIN

#define JK_Detect_HumanDetection "Detect.HumanDetection" 
class Detect_HumanDetection : public JObject
{
public:
	JBoolObj		Enable;				/// �Ƿ���
	JIntObj			ObjectType;			/// ������0:��  0xFF:�������� 
	JIntObj			Sensitivity;		/// ���μ��������
	JIntObj			ShowRule;			/// �Ƿ���ʾ����
	JIntObj			ShowTrack;			/// �Ƿ���ʾ�켣
	JObjArray<PedRule>	m_PedRule;

public:
	Detect_HumanDetection(JObject *pParent = NULL, const char *szName = JK_Detect_HumanDetection):
	JObject(pParent,szName),
	Enable(this, "Enable"),
	ObjectType(this, "ObjectType"),
	Sensitivity(this, "Sensitivity"),
	ShowRule(this, "ShowRule"),
	ShowTrack(this, "ShowTrack"),
	m_PedRule(this, "PedRule"){
	};

    ~Detect_HumanDetection(void){};
};

NS_NETSDK_CFG_END