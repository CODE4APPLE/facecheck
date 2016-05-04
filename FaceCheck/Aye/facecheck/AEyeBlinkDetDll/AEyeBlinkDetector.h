#pragma once
#ifndef BLINKDETECTOR_H
#define BLINKDETECTOR_H
//#include "opencv2/opencv.hpp"
// ���庯�����÷�ʽ
#define STD_CALL __stdcall

//#pragma comment(lib,"opencv_imgproc243.lib")
//#pragma comment(lib,"opencv_core243.lib")
//#pragma comment(lib,"opencv_highgui243.lib")

// ���庯��������뷽ʽ

#include "BasicFunction.h"
#include "AEyeBaseFaceStruct.h" 
#include "AEyePoseDetector.h"
// ���庯�����ؽ��
#define  AEYE_SUCCESS 0
#define  AEYE_FAIL    -1
#define  IN


/*******************************************************************

�� �� �� : InitBlinkModel

�������� : ��ʼ��գ�ۼ��ģ�ͣ�����ֲ��˶�ģ�ͺͱ��ۼ��ģ�͵������ļ� 

�������� : [IN] : 
				  poseModelPath         pose���ģ���ļ�
				  landmarkModelPath     �ؼ�����ģ���ļ�
�������� : �ɹ�����HANDLE, ʧ��NULL
********************************************************************/
HANDLE InitBlinkModel(IN char* poseModelPath, IN char* landmarkPath);
/*******************************************************************

�� �� �� : DetectLocalMove

�������� : ����۾�����������֡ͼ��ľֲ��˶����õ��ֲ��˶������ŶȺ;����ж�

�������� : [IN] : hObject              dll�����ָ��
                  pGrayBuf             ��ǰ֡�Ҷ�����buffer
				  pGrayPreBuf          ǰһ֡�Ҷ�����buffer
                  width                ͼ���
				  height               ͼ���
				  LeftEyeRect          ��ǰ֡���۵ľ��ο�
				  RightEyeRect         ��ǰ֡���۵ľ��ο�

           [OUT] : relia               �ֲ��˶��������Ŷȣ����Ŷ�Խ�󣬾ֲ��˶��Ŀ�����ҲԽ��
		   		   bLocalMove          �ֲ��˶��ж������trueΪ��⵽�ֲ��˶���falseΪû�м�⵽

�������� : �ɹ�����AEYE_SUCCESS, ʧ�ܷ���AEYE_FAIL

********************************************************************/
//DLL_API long STD_CALL DetectLocalMove(IN HANDLE hObject, OUT bool& bLocalMove, IN BYTE* pGrayBuf, IN BYTE* pGrayPreBuf, IN int width, IN int height, IN s_Rect LeftEyeRect, IN s_Rect RightEyeRect, OUT double& relia);
/*******************************************************************

�� �� �� : DetectEyeStatus

�������� : ��ⵥ֡ͼ�����۾���������״̬���õ����۵����ŶȺ���������״̬�ľ���

�������� : [IN] : hObject              dll�����ָ��
                  pGrayBuf             ��ǰ֡�Ҷ�����buffer
                  width                ͼ���
				  height               ͼ���
				  LeftEyeRect          ��ǰ֡���۵ľ��ο�
				  RightEyeRect         ��ǰ֡���۵ľ��ο�

           [OUT] : relia               ��������״̬���Ŷȣ� reliaԽ��Խ���������ۣ�reliaԽСԽ�����Ǳ���
		   		   bEyeStatus          �۾�������״̬���������trueΪ���ۣ�falseΪ����

�������� : �ɹ�����AEYE_SUCCESS, ʧ�ܷ���AEYE_FAIL

********************************************************************/
//DLL_API long STD_CALL DetectEyeStatus(IN HANDLE hObject, OUT bool& bEyeStatus, IN BYTE* pGrayBuf, IN int width, IN int height, IN s_Rect LeftEyeRect, IN s_Rect RightEyeRect, OUT double& relia);
/*******************************************************************

�� �� �� : DetectImgStatus

�������� : ��ⵥ֡ͼ��״̬�ľ���

�������� : [IN] : hObject              dll�����ָ��
                  pNormImg             ������һ���Ҷ�ͼ������buffer
				  width                ͼ���
				  height               ͼ���

	       [OUT] : bImgStatus           ����ͼ��״̬��1Ϊ����ͼ��0Ϊ�ǻ���ͼ��
				  score                ͼ��״̬�÷�

�������� : �ɹ�����AEYE_SUCCESS, ʧ�ܷ���AEYE_FAIL

********************************************************************/
/*******************************************************************

�� �� �� : DetectLocalMove

�������� : ����۾�����������֡ͼ��ľֲ��˶����õ��ֲ��˶������ŶȺ;����ж�

�������� : [IN] : hObject              dll�����ָ��
				  currentFrameNum      ��ǰ֡���к� 
                  pGrayBuf             ��ǰ֡�Ҷ�����buffer
				  pGrayPreBuf          ǰһ֡�Ҷ�����buffer
                  width                ͼ���
				  height               ͼ���
				  eyeDet               ���۶�λ�ṹ��
				  faceDet              ������Ϣ�ṹ��
				  pNormImg             ��ǰ֡��һ��ͼ��
				  widthNor             ��һ��ͼ���
				  heightNor            ��һ��ͼ���
				  bIfFirst             �Ƿ��һ�ε��ô˺�����true����Ϊ��һ�Σ�false�����ǵ�һ��

           [OUT] : qulityMSG            ͼ����������    0 Ϊ������1 Ϊ���뾵ͷ̫���� 2Ϊ���뾵ͷ̫Զ�� 3��Ϊ�ֲ�����̫ǿ�� 4 Ϊ�ֲ�����̫����
		          bBlinkStatus         գ��״̬�� 0Ϊ���ۣ�1Ϊ����
		          bAliveStatus         ����������0Ϊ���壬1Ϊ�ǻ��壬2Ϊ��ʼ�ж���ȷ������Ҫ�û�����һ�Σ�-1Ϊ�жϻ���״̬���ڽ�����,-2 Ϊ�����ⳬʱ�ж�
				  aliveDetectLevel    ���������׵ȼ���1-4��������Խ�ߣ��Ѷ�Խ��Ĭ�ϼ���Ϊ3
				 


�������� : �ɹ�����AEYE_SUCCESS, ʧ�ܷ���AEYE_FAIL

********************************************************************/
//DLL_API long STD_CALL DetectImgStatus(IN HANDLE hObject, OUT bool& bImgStatus, IN BYTE* pNormImg,IN int width, IN int height,  OUT float& score);
long DetectAliveStatus(IN bool bIfFirst, OUT int *qulityMSG, OUT int *bAliveStatus, OUT double* unknown,
	IN BYTE* pGrayBuf, IN int width, IN int height, IN s_AEFace faceDet, IN int aliveDetectLevel);

#endif