#pragma once

#include "AEyeBaseFaceStruct.h"
// ���庯�����÷�ʽ
#define STD_CALL __stdcall

#if defined(__cplusplus)
extern "C"
{
#endif

#ifdef EXPORT_FRONTAL_FACE_DETECT
#define FRONTAL_FACE_DETECT_0_DLL_API __declspec(dllexport)
#else
#define FRONTAL_FACE_DETECT_0_DLL_API __declspec(dllimport)
#endif

	// ���庯�����ؽ��
#define  AEYE_SUCCESS 0
#define  AEYE_FAIL    -1

	// ����facedetection��ز���
	// pPara����Ҫ���õĲ����б���0����ʾrectNum��ֵ���˰�ɼ���ľ���ֵrectNumΪ3
	//������棨���0��ģ��û�г�ʼ����ȷ,�򷵻�ֵresultΪ1,
	//������[-45,-20]�ȣ����1��û�г�ʼ����ȷ,�򷵻�ֵresultΪ2,
	//����Ҳ�[20,45]�ȣ����2��û�г�ʼ����ȷ,�򷵻�ֵresultΪ3,
	//�����ͷ[-45,-20]�ȣ����3��û�г�ʼ����ȷ,�򷵻�ֵresultΪ4,
	//���ƽ������ת[-75,-46]�����5��ģ��û�г�ʼ����ȷ,�򷵻�ֵresultΪ5,
	//���ƽ������ת[-45,-16]�����6��ģ��û�г�ʼ����ȷ,�򷵻�ֵresultΪ6,
	//���ƽ������ת[16,45]�����7��ģ��û�г�ʼ����ȷ,�򷵻�ֵresultΪ7,
	//���ƽ������ת[46,75]�����8��ģ��û�г�ʼ����ȷ,�򷵻�ֵresultΪ8,
	//���ÿ��ģ�Ͷ�������ȷ,�򷵻�ֵresultΪ9
	FRONTAL_FACE_DETECT_0_DLL_API HANDLE STD_CALL CreateFaceDetector(int &result, int *pPara);
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL DestroyFaceDetector(HANDLE hObject);

	//PositionFace������⴦����
	/****************************************************************************/
	/* �������ܣ�����������⣬���ڴ��ж�ȡ���ģ��                             */
	/* ������                                                                   */ 
	/* 	   unsigned char * pImg������һά�Ҷ�ͼ��buffer��ָ��                   */
	/* 	   int imgWidth��        ͼ����                                       */
	/* 	   int imgHeight��       ͼ��߶�                                       */
	/*     int minWidth��        �����������С�߶�                             */
	/*     int maxWidth��        ������������߶�                             */
	/*     s_AERect searchROI��  ȷ������������ͼ���е�����λ�÷�Χ           */
	/*     ����ֵΪ0������ȷ������ֵΪ����ֵ�������                            */
	/*	   PositionFace(pProcImg, srcImg.Width(), srcImg.Height(), (faceRect.bottom - faceRect.top)/2, (faceRect.bottom - faceRect.top)*2, searchROI);*/
	/*     int *pPara����Ҫ���õĲ����б���0����ʾrectNum��ֵ���˰�ɼ���ľ���ֵrectNumΪ3*/
	/****************************************************************************/
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL PositionFace(HANDLE hObject, unsigned char * pImg, int imgWidth, int imgHeight,int minWidth, int maxWidth, s_AERect searchROI, int *pPara);

	//PositionFace����̬������⴦����
	/****************************************************************************/
	/* �������ܣ����ж���̬������⣬��ֱ�Ӵ��ڴ��ж�ȡ���ģ�ͣ����������ó�ʼ������*/
	/* ������                                                                   */ 
	/* 	   unsigned char * pImg������һά�Ҷ�ͼ��buffer��ָ��                   */
	/* 	   int imgWidth��        ͼ����                                       */
	/* 	   int imgHeight��       ͼ��߶�                                       */
	/*     int minWidth��        �����������С�߶�                             */
	/*     int maxWidth��        ������������߶�                             */
	/*     s_AERect searchROI��  ȷ������������ͼ���е�����λ�÷�Χ           */
	/*     int *pViewControl    ����̬����������                              */
	/*     ����̬������⣬���ڹ�֧�����棨���0�������[-45,-20]�ȣ����1�����Ҳ�[20,45]�ȣ����2����
	/*     ��ͷ[-45,-20]�ȣ����3������ͷ[20,45]�ȣ����4����ƽ������ת[-75,-46]�����5����
	/*     ƽ������ת[-45,-16]�����6����ƽ������ת[16,45]�����7����ƽ������ת[46,75]�����8�����Ÿ���̬
	/*     int *pViewControlΪָ�룬�䳤�ȵ���֧�ֵ���̬��Ŀ������Ϊ9��˳�������������и�������ţ�
	/*     ��ÿ��ֵ�����Ϊ1����ʾ���и���Ŷ�Ӧ��̬�ļ�⣬���򲻽��м��
	/*     ���pViewControlΪNULL�������������̬���������
	/*     ����ֵΪ0������ȷ������ֵΪ����ֵ�������                            */
	/* PositionMultiViewFace(pProcImg, srcImg.Width(), srcImg.Height(), (faceRect.bottom - faceRect.top)/2, (faceRect.bottom - faceRect.top)*2, searchROI, NULL);*/
	/*     int *pPara����Ҫ���õĲ����б���0����ʾrectNum��ֵ���˰�ɼ���ľ���ֵrectNumΪ3*/
	/****************************************************************************/
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL PositionMultiViewFace(HANDLE hObject,unsigned char * pImg, int imgWidth, int imgHeight,int minWidth, int maxWidth, s_AERect searchROI, int *pViewControl, int *pPara);

	/****************************************************************************/
	/* �������ܣ��������������ü�⵽��������Ŀ                             */
	/* ������                                                                   */ 
	/* 	   ֱ�ӵõ����������������Ŀ                                           */
	/****************************************************************************/
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL GetFaceNum(int &faceNum, HANDLE hObject);

	/****************************************************************************/
	/* �������ܣ����������������Ŀ�õ������ľ���λ��                           */
	/* ������                                                                   */ 
	/*           	s_Rect faceDetRect;                                         */
	/* 	            faceNum = GetFaceNum();                                     */
	/* 	 	for (i = 0; i < faceNum; i ++)                                    */
	/*		{                                                                   */
	/*                  faceDetRect = GetFaceRect(i);                           */
	/*      }                                                                   */ 
	/****************************************************************************/
	FRONTAL_FACE_DETECT_0_DLL_API long STD_CALL GetFaceRect(s_AEFace &faceDetRect, HANDLE hObject,int faceOrder);

#if defined(__cplusplus)
}
#endif
