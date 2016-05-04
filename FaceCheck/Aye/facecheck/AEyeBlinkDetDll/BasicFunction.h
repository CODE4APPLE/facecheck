/* BasicFunction.h
  copyright: vimicro
  edition 1.0
  created by yafeng deng in 2005.11.7
  define data struct of common function
*/

#ifndef _BASIC_FUNCTION_H
#define _BASIC_FUNCTION_H

//#define LOG_FILE_PATH "d:\\alive_file.txt"

#include <STDIO.H>
#include <stdlib.h>

#define _DRIVER
//#define _HUANGYING

#define ROUND_int32(f) (f>0 ? ( (int)(f+0.5) ) : ( (int)(f-0.5) ))
#define ROUND_uint32(f) ((int)(f+0.5))
#define FREE( p ) if( NULL!=p ) { free( p ); p = NULL; }

//#define AVG_COORD( A, B ) ( A/B )
#define AVG_COORD( A, B ) ((int)( A/B+0.5 ))
#define MUL_INT_ROUND( a, b ) (int)( a*b+0.5 )

#define MAX_IMG_WIDTH 1024
#define MAX_IMG_HEIGHT 1024

#ifndef CLIP
#define CLIP(a) (a>255?255:(a<0?0:a))
#endif

#define INT_MAX0 2147483647
#define INT_MIN0 (-2147483647-1)

/* typedef.h */

//typedef int int;
typedef unsigned long dword;
//typedef double double;
typedef unsigned char byte;
//typedef char char;
//typedef long bool;
typedef byte BYTE;
typedef short int int16;
//typedef bool BOOL;
typedef void *HANDLE;
//#define true 1
//#define vifd_false 0
#define vifd_notinit 2
#define vifd_out_of_read_range 3
//#define TRUE true
//#define FALSE vifd_false

#define BETRUE(ret) (ret == true)

#define vifd_abs(a) ( (a<0)?(-a):a )

/* vifdmath.h */

//#ifndef max
#define max2(a,b)            (((a) > (b)) ? (a) : (b))
//#endif
//#ifndef min
#define min2(a,b)            (((a) < (b)) ? (a) : (b))
//#endif

//#define vifd_max(x, y) ( ((x)>=(y)) ? (x) : (y) )
//#define vifd_min(x, y) ( ((x)<=(y)) ? (x) : (y) )

#ifndef PI
#define PI 3.1415926536
#endif

#define sqrt2_2PI 2.506628
#define sqrt2_2PI_recip 0.3989423

#ifndef NEAR_ZERO
#define NEAR_ZERO (1e-20f)
#endif

#define COLOR_NUM 12

// 范数类型
typedef enum e_NormType { n1_norm, n2_norm, max_norm } e_NormType;

typedef struct s_Fraction
{
	int numerator;
	int denominator;
	int halfDenominator;
}
s_Fraction;

typedef struct s_VifdLongQn
{
	int value;
	int q; // shift bits
	bool sign; // if true, shift rightly, and if false, shift leftly
}
s_VifdLongQn;

void InitBasicFunction();

typedef enum data_type { type_int32, type_double, type_int16, type_byte, type_float };

//图像类型

int GetDataSize( data_type dataType );

dword Sqrt( dword sqVal );

typedef struct s_Double
{
	int times;
	int shift;
}
s_Double;

int Shift_32i( int val, int shift );
s_Double Neg_64f( s_Double src );
int GetBitsNum_u64i( long long val );
int GetIncBitsNum_u64i( long long val );
int GetBitsNum_32i( int val );
int GetIncBitsNum_32i( int val );

s_Double Add_32i_64f( int src1, s_Double src2 );
s_Double Sub_32i_64f( int src1, s_Double src2 );
s_Double Multi_64f_64f( s_Double src1, s_Double src2 );
s_Double Div_64f_64f( s_Double src1, s_Double src2, int shift );
s_Double Div_32i_64f( int src1, s_Double src2, int shift );
void Multi_DownBits( int & multi, int & downBits, int src0, int src1, int maxBitsNum );
s_Double Multi_32i_64f( int alpha, s_Double src );
s_Double Add_64f_64f( s_Double src1, s_Double src2 );
s_Double Sub_64f_64f( s_Double src1, s_Double src2 );
s_Double SetFraction_64f( int numrator, int denominator, int shift );
int Round_64f( s_Double src );

void LimitVal( int * pVal, int minVal, int maxVal );

void SetLesserDataZero_1D_32f( float * pData, float thresh, int dataSize );

void SetLesserDataZero_2D_32f( float ** ppData, float thresh, int width, int height );

void GetLargerFlag_2D_32f( byte ** ppFlagImg, float ** ppData, float thresh, int width, int height );

int GetSum_1D_32i( const int * pData, int dataNum );
float GetSum_1D_32f( const float * pData, int dataNum );
double GetSum_1D_64f( const double * pData, int dataNum );
int GetSum_1D_8u( const byte * pData, int dataNum );

float GetAvgVal_1D_32f( float * pData, int dataNum );
double GetAvgVal_1D_16s( int16 * pData, int dataNum );
double GetAvgVal_1D_64f( double * pData, int dataSize );
double GetAvgVal_1D_32i( int * pData, int dataNum );
double GetAvgVal_1D_8u( byte * pData, int dataNum );

float GetAvgVal_2D_32f( float ** ppData, int width, int height );
float GetAvgVal_2D_32f_Mask( float ** ppData, int width, int height, byte ** ppMask, byte maskVal );

double GetAvgVal_2D_64f( double ** ppData, int width, int height );
double GetAvgVal_2D_64f_Flag( double ** ppData, byte ** ppFlag, int width, int height );
double GetAvgVal_2D_64f_Inv_Flag( double ** ppData, byte ** ppFlag, int width, int height );
double GetAvgVal_2D_32i( int ** ppData, int width, int height );
double GetAvgVal_2D_32i_Flag( int ** ppData, byte ** ppFlag, int width, int height );
double GetAvgVal_2D_32i_Inv_Flag( int ** ppData, byte ** ppFlag, int width, int height );
double GetAvgVal_2D_8u( byte ** ppData, int width, int height );
double GetAvgVal_2D_8u_Mask( byte ** ppData, int width, int height, 
						   byte ** ppMask, byte maskVal );

double GetCovVal_1D_8u( byte * pData, int dataSize );
double GetCovVal_1D_32i( int * pData, int dataSize );
double GetCovVal_1D_32f( float * pData, int dataSize );
double GetCovVal_1D_64f( double * pData, int dataSize );

double GetCovVal_2D_64f( double ** ppData, int width, int height );
double GetCovVal_2D_32f( float ** ppData, int width, int height );
double GetCovVal_2D_32i( int ** ppData, int width, int height );
double GetCovVal_2D_8u( byte ** ppData, int width, int height );

double GetSqSum_1D_64f( double * pData, int num );
double GetSqSum_1D_32f( float * pData, int num );
double GetSqSum_1D_32i( int * pData, int num );
int GetSqSum_1D_8u( byte * pData, int num );

double GetAbsSum_1D_64f( double * pData, int num );
float GetAbsSum_1D_32f( float * pData, int num );

int MultiplyFraction( int temp, s_Fraction fraction );

s_Fraction GetFractionReciprocal( s_Fraction origFraction );

void ExchangeToSortData( int * pMin, int * pMax );

int GetFractionVal( int minVal, int maxVal, s_Fraction fraction );
int  GetFractionVal_SDouble( int minVal, int maxVal, s_Double fraction );

bool GetMinMaxVal_1D_16s_Energy( int16 * pMin, int16 * pMax, int16 * pData, int dataNum, double energy );
bool GetMinMaxVal_1D_32i_Energy( int *pMin, int * pMax, int * pData, int dataNum, double energy );
bool GetMinMaxVal_2D_32i_Energy( int * pMin, int * pMax, int ** ppData, int width, int height, double energy );
bool GetMinMaxVal_1D_64f_Energy( double * pMin, double * pMax, double * pData, int dataNum, double energy );
bool GetMinMaxVal_2D_64f_Energy( double * pMin, double * pMax, double ** ppData, int width, int height, double energy );
bool GetMinMaxVal_2D_32f_Energy( float * pMin, float * pMax, float ** ppData, int width, int height, float energy );

void GetMinMaxVal_1D_32i( int * pMin, int * pMax, int * pData, int dataNum );
void GetMinMaxVal_1D_16s( int16 * pMin, int16 * pMax, int16 * pData, int dataNum );
void GetMinMaxVal_1D_32f( float * pMin, float * pMax, float * pData, int dataSize );
void GetMinMaxVal_1D_64f( double * pMin, double * pMax, double * pData, int dataSize );

void GetMinMaxVal_2D_32f( float * pMin, float * pMax, float ** ppData, int width, int height );
void GetMinMaxVal_2D_16s( int16 * pMin, int16 * pMax, int16 ** ppData, int width, int height );
void GetMinMaxVal_2D_32i( int * pMin, int * pMax, int ** ppData, int width, int height );
void GetMinMaxVal_2D_64f( double * pMin, double * pMax, double ** ppData, int width, int height );

bool GetMaxDataOrder_2D_64f( int * pMaxWd, int * pMaxHt, double ** ppData, int width, int height );
bool GetMaxDataOrder_2D_32f( int * pMaxWd, int * pMaxHt, float ** ppData, int width, int height );

void abs_1D_16s( int16 * pData, int dataNum );
void abs_1D_64f( double * pData, int dataNum );
void abs_2D_64f( double ** ppData, int width, int height );
void abs_1D_32f( float * pData, int dataNum );

s_Fraction SetFraction( int numerator, int denominator );

int GetAverageVal( int sum, int num );

void RescaleData_1D_8u_64f( byte * p8BitsDesImg, double * pSrcImg, int dataSize, double srcMin, 
						   double srcMax, byte desMin, byte desMax );
void RescaleData_2D_8u_32f( byte ** pp8BitsDesImg, float ** ppSrcImg, int width, int height, float srcMin, 
						  float srcMax, byte desMin, byte desMax );
void RescaleData_1D_8u_32f( byte * p8BitsDesImg, float * pSrcImg, int dataSize, float srcMin, float srcMax, 
						   byte desMin, byte desMax );
void RescaleData_1D_8u_16s( byte * p8BitsDesImg, int16 * pSrcImg, int imgSize, int16 srcMin, 
						  int16 srcMax, byte desMin, byte desMax );
void RescaleData_2D_8u_32i( byte ** pp8BitsDesImg, int ** ppSrcImg, int width, int height, 
						   int srcMin, int srcMax, byte desMin, byte desMax );
void RescaleData_1D_32f_32f( float * pDesImg, float * pSrcImg, int dataSize, float srcMin, float srcMax, 
						   float desMin, float desMax );
void RescaleData_1D_8u_32i( byte * p8BitsDesImg, int * pSrcImg, int imgSize, int srcMin, 
						  int srcMax, byte desMin, byte desMax );
void RescaleData_2D_8u_64f( byte ** pp8BitsDesImg, double ** ppSrcImg, int width, int height, double srcMin, 
						   double srcMax, byte desMin, byte desMax );
void RescaleData_2D_8u_16s( byte ** pp8BitsDesImg, int16 ** ppSrcImg, int width, int height, int16 srcMin, 
						   int16 srcMax, byte desMin, byte desMax );

void NegLog_Array_1D_64f( double * pData, int dataSize );

void Max_Array_1D_64f( double * pMaxData, double * pSrcData, int dataSize );
void Min_Array_1D_64f( double * pMinData, double * pSrcData, int dataSize );

void Max_Array_1D_32f( float * pMaxData, float * pSrcData, int dataSize );
void Min_Array_1D_32f( float * pMinData, float * pSrcData, int dataSize );

void Max_Array_1D_32i( int * pMaxData, int * pSrcData, int dataSize );
void Min_Array_1D_32i( int * pMinData, int * pSrcData, int dataSize );

void Max_Array_1D_16s( int16 * pMaxData, int16 * pSrcData, int dataSize );
void Min_Array_1D_16s( int16 * pMinData, int16 * pSrcData, int dataSize );

void Max_Array_1D_8u( byte * pMaxData, byte * pSrcData, int dataSize );
void Min_Array_1D_8u( byte * pMinData, byte * pSrcData, int dataSize );

void SubAvgArray_32f( float * pData, int dataNum );

void SubConstArray_32f( float * pData, int dataNum, int subVal );

void DivConstArray_32f( float * pData, int dataNum, float divVal );
void DivConstArray_64f( double * pData, int dataNum, double divVal );

void MulConstArray_1D_32f( float * pData, int dataNum, float mulVal );

void MulConstArray_2D_32f( float ** ppData, int width, int height, float mulVal );

// for matrix
bool MatrixMulti_64f( double *pDes, double *pSrc0, int row0, int col0, double *pSrc1, int row1, int col1 );

// 计算向量的范数
int CacuNorm_int32( int * pVector, int num, e_NormType normType );

int GetRand( int Min, int Max );

double GetRand_64f( double Min, double Max );

void StartRand();

double GetVectorDis_1D_64f_N2( double * pVector0, double * pVector1, int dataNum );
float GetVectorDis_1D_32f_N2( float * pVector0, float * pVector1, int dataNum );

double GetVectorDis_1D_64f_N1( double * pVector0, double * pVector1, int dataNum );
float GetVectorDis_1D_32f_N1( float * pVector0, float * pVector1, int dataNum );

void TransPosMatrix( float ** ppMatrix, int N );

void SmoothData_1D_32i( int * pData, int dataNum, int halfNeigbSize );
void SmoothData_1D_32f( float * pData, int dataNum, int halfNeigbSize );

void SortReal_Bub_64f( double * p, int n );
void SortReal_Bub_32f( float * p, int n );
	
int GetPercentSumIndex( float ratio, float * pHist, int binNum, int vldNum );

void GetEllipseFlag_2D_8u( byte ** ppFlag, int width, int height, int centerX, 
		int centerY, int radX, int radY, byte flag, byte negFlag );

void GetEllipseFlag_1D_8u( byte * pFlag, int width, int height, int centerX, 
		int centerY, int radX, int radY, byte flag, byte negFlag );

void CacuStepRecipFromMaxMin_64f( double * pFeatStepRecip, double * pMaxFeat, double * pMinFeata, 
								 int allFeatNum, int histNum );
void CacuStepRecipFromMaxMin_32f( double * pFeatStepRecip, float * pMaxFeat, float * pMinFeata, 
								 int allFeatNum, int histNum );
void CacuStepRecipFromMaxMin_32i( double * pFeatStepRecip, int * pMaxFeat, int * pMinFeata, 
								 int allFeatNum, int histNum );
void CacuStepRecipFromMaxMin_16s( double * pFeatStepRecip, int16 * pMaxFeat, int16 * pMinFeata, 
	int allFeatNum, int16 histNum );
void CacuStepRecipFromMaxMin_8u( double * pFeatStepRecip, byte * pMaxFeat, byte * pMinFeata, 
								 int allFeatNum, int histNum );

void CacuStepOrder_8u_64f( byte * pSmpStepOrder, double * pFeatRslt, double * pMinFeat, 
				   double * pFeatStepRecip, int featNum, byte stepOrderNum );
void CacuStepOrder_32i_64f( int * pSmpStepOrder, double * pFeatRslt, double * pMinFeat, 
				   double * pFeatStepRecip, int featNum, int stepOrderNum );
void CacuStepOrder_8u_32f( byte * pSmpStepOrder, float * pFeatRslt, float * pMinFeat, 
				   double * pFeatStepRecip, int featNum, byte stepOrderNum );
void CacuStepOrder_32i_32f( int * pSmpStepOrder, float * pFeatRslt, float * pMinFeat, 
				   double * pFeatStepRecip, int featNum, int stepOrderNum );
void CacuStepOrder_8u_32i( byte * pSmpStepOrder, int * pFeatRslt, int * pMinFeat, 
					   double * pFeatStepRecip, int featNum, byte stepOrderNum );
void CacuStepOrder_32i_32i( int * pSmpStepOrder, int * pFeatRslt, int * pMinFeat, 
						   double * pFeatStepRecip, int featNum, int stepOrderNum );
void CacuStepOrder_8u_16s( byte * pSmpStepOrder, int16 * pFeatRslt, int16 * pMinFeat, 
					   double * pFeatStepRecip, int featNum, byte stepOrderNum );
void CacuStepOrder_32i_16s( int * pSmpStepOrder, int16 * pFeatRslt, int16 * pMinFeat, 
						   double * pFeatStepRecip, int featNum, int stepOrderNum );
void CacuStepOrder_8u_8u( byte * pSmpStepOrder, byte * pFeatRslt, byte * pMinFeat, 
				   double * pFeatStepRecip, int featNum, byte stepOrderNum );

void CacuHist_Order( int16 ** ppHist, byte ** ppSmpFeatOrder, int smpNum, int featNum, int histNum );
void CacuHist_Region( int * pHist, byte *pImg, int left, int top, int right, int bottom, int width, int histNum );

/* vifdrect.h */

typedef struct s_Point
{
	int x;
	int y;
}
s_Point;

typedef struct s_PointArray
{
	int maxNum;
	int actNum;
	s_Point * pArray;
}
s_PointArray;

typedef struct s_Point_f64
{
	double x;
	double y;
}
s_Point_f64;

typedef struct s_RectSize
{
	int width;
	int height;
}
s_RectSize;

typedef struct s_Rect
{
	int left;
	int top;
	int right;
	int bottom;
}
s_Rect;

// data is sorted by ascending order
typedef struct s_RectArray
{
	s_Rect * pArray;
	int maxNum;
	int actNum;
}
s_RectArray;

typedef struct s_VifdRect_ltsize
{
	s_Point ltPt;
	s_RectSize rectSize;
}
s_VifdRect_ltsize;

typedef struct s_Rect_f64
{
	double left;
	double top;
	double right;
	double bottom;
}
s_Rect_f64;

typedef struct s_ReferScope
{
	s_Point referPoint;
	s_Rect scopeRect;
}
s_ReferScope;

typedef struct s_Ellipse
{
	s_Point centerPoint; //椭圆中心
	int rad_x; //横坐标方向椭圆的半径
	int rad_y; //纵坐标方向椭圆的半径
}
s_Ellipse;

typedef struct
{
	int width;
	int height;
	double whRatio; // width/height
}
s_RectSizeInfo;

typedef struct s_RealData
{
	double real_data;
	double img_data;
}
s_RealData;

typedef struct s_VldData
{
	int bVld;
	double data;
}
s_VldData;

typedef struct s_VldRealData
{
	s_VldData real;
	s_VldData img;
}
s_VldRealData;

s_Point SetPoint( int x, int y );

s_Point ShiftPoint( s_Point srcPoint, int shiftx, int shifty );

s_Point_f64 ShiftPoint_f64( s_Point_f64 srcPoint, int shiftx, int shifty );

int GetPointDis( s_Point point1, s_Point point2 );

double GetPointDis_f64( s_Point point1, s_Point point2 );

s_Point GetCenterPoint( s_Point point1, s_Point point2 );

void InitializePointArray( s_PointArray * pArray, int maxdataSize );
void RemovePointArray( s_PointArray * pArray );

int GetRectArea( s_RectSize rectSize );
int GetRectArea_Rect( s_Rect rect );

bool LimitRect( s_Rect * pRect, int leftLimit, int topLimit, int rightLimit, int bottomLimit );

s_RectSize GetRectSize( s_Rect rect );
void GetRectSize_WH( int * pWd, int * pHt, s_Rect rect );

s_Rect GetVerFlipRect( s_Rect srcRect, int width );

s_Point GetRectCenterPoint( s_Rect rect );

s_Point ZoomPoint_64f( s_Point * pPoint, double zoomRatio );

s_Rect EnlargeRect( s_Rect rect, s_Fraction fraction );
s_Rect EnlargeRect_64f( s_Rect * pRect, double widthZoomRatio, double heightZoomRatio );
s_Rect ZoomRect( s_Rect rect, s_Fraction zoomFranction );
s_Rect ZoomRect_64f( s_Rect rect, double zoomRatio );

void ResizeRect( s_Rect * pDesRect, s_Rect srcRect, double sizeRatio );

s_RectSize EnlargeRectSize( s_RectSize rectSize, s_Fraction fraction );

s_RectSize GetAverageRectSize( s_RectSize tempRectSize1, s_RectSize tempRectSize2 );

s_Rect SetVifdRect( int left, int top, int right, int bottom );

s_Rect SetRect_CenterSize( int centerX, int centerY, int width, int height );

s_Rect NormRect( s_Rect rect );

s_RectSize SetVifdRectSize( int width, int height );

bool GetRandRect_FixedRatio( s_Rect * pRandRect, s_Rect * pRegion, int minWd, double fixedRatio );

s_Rect ShiftRect( s_Rect srcRect, int shiftx, int shifty );

s_ReferScope ShiftScope( s_ReferScope srcScope, int shiftx, int shifty );

void GetScopeFromRectSize( s_ReferScope * pDesImgScope, s_RectSize desRectSize );

s_ReferScope SetVifdScope( s_Point centerPoint, int halfWd, int halfHt );

bool IsPointInRect( s_Point point, s_Rect rect );

s_Rect GetRectSameCenter( s_Rect srcRect, int desWd, int desHt );

s_Rect GetValidRect(  int centerX, int centerY, int rectWd, int rectHt, int leftLimit, int topLimit, 
			 int rightLimit, int bottomLimit );

bool IsValidRect(  s_Rect * pRect, int leftLimit, int topLimit, int rightLimit, int bottomLimit );

bool GetIntersectRect( s_Rect * pInterSectRect, s_Rect * pRect1, s_Rect * pRect2 );

int GetIntersectRectArea( s_Rect * pRect1, s_Rect * pRect2 );

double GetSizeSimRatio( s_Rect * pRect1, s_Rect * pRect2 );

bool DoesSimRectExist( s_Rect * pRectArray, int rectNum, s_Rect * pRandRect, double disRatioThresh, double sizeSimRatioThresh );

bool DoesSimRect( s_Rect * pRect0, s_Rect * pRect1, double disRatioThresh, double sizeSimRatioThresh );
bool DoesSimRectInArray( s_Rect * pRectArray, int rectNum, s_Rect * pRect1, double disRatioThresh, double sizeSimRatioThresh );

void GetRectSizeInfo( s_RectSizeInfo * pRectSizeInfo, s_Rect * pRect );

bool IsSameObject( s_Rect tempObject1, s_Rect tempObject2 );
bool IsCoverObject( s_Rect tempObject1, s_Rect tempObject2 );

double GetRectCoverRatio( s_Rect tempObject1, s_Rect tempObject2 );

int DeleteSmallRect( s_Rect * pRectArray, int rectNum, int minSize );
int MergeNeighborRect( s_Rect * pRectArray, int rectNum );

int GetRectSum_2DInteg( int ** ppIntegImg, int left, int top, int right, int bottom );
double GetRectDelta_2DInteg( int ** ppIntegImg, int ** ppIntegSqImg, int left, int top, int right, int bottom );
int GetRectSum_32i_1DInteg( int * pIntegImg, int width, int left, int top, int right, int bottom );
double GetRectDelta_1DInteg( int * pIntegImg, int * pIntegSqImg, int width, int left, int top, int right, int bottom );
double GetRectSum_64f_1DInteg( double * pIntegImg, int width, int left, int top, int right, int bottom );

void InitializeRectArray( s_RectArray * pArray, int maxdataSize );
void RemoveRectArray( s_RectArray * pArray );

// float

typedef struct s_Point_32f
{
	float x;
	float y;
}
s_Point_32f;

/* imageProcess.h */

#ifndef WIDTHBYTES
	#define WIDTHBYTES(bits) ((DWORD)(((bits)+31) & (~31)) / 8)
#endif

typedef enum ImgType
{
	it_gray, it_flipgray, it_RGB24, it_flipRGB24, it_BGR24, it_flipBGR24, it_YUV444, it_YUV422,
}
ImgType;

void FilterImg_8u_1R_SetVal( byte *pDesImg, void *pSrcImg, int imgWd, int imgHt, s_Rect vldRegion, 
			data_type srcDataType, byte (*func_proc)(void *, int, int, int, int), byte setVal );
void FilterImg_8u_1R_Boundary( byte *pDesImg, void *pSrcImg, int imgWd, int imgHt, s_Rect vldRegion, 
			data_type srcDataType, byte (*func_proc)(void *, int, int, int, int), 
			byte (*func_proc_boundary)(void *, int, int, int, int) );
void CacuIndexImg_8u( byte * pImg, byte * pIndex, int width, int height );

void ConvFilter( double * pDesImg, byte * pSrcImg, s_VldRealData * pFilter, int imgWd, int imgHt, int filterHalfWd, int filterHalfHt );

void SetImgVal_64f_2D_1R_ROI( double ** ppImg, s_Rect * pRegion, double val );

void SetImgVal_64f_2D_3R_ROI( double ** ppImg, s_Rect * pRegion, double * pVal );

void SetImgVal_32i_2D_3R_ROI( int ** ppImg, s_Rect * pRegion, int * pVal );

void SetImgVal_32i_2D_1R_ROI( int ** ppImg, s_Rect * pRegion, int val );

void SetImgVal_8u_2D_3R_ROI( byte ** ppImg, s_Rect * pRegion, byte * pVal );

void SetImgVal_8u_2D_1R_ROI( byte ** ppImg, s_Rect * pRegion, byte val );

void GetFlagByThresh_8u_2D( byte ** ppFlag, int ** ppDif, int width, int height, int thresh );

void GetImgByFlag_8u_2D_3R( byte ** ppDesImg, byte ** ppFlag, byte ** ppSrcImg, int width, int height );

void GetImgByFlag_8u_2D_1R( byte ** ppDesImg, byte ** ppFlag, byte ** ppSrcImg, int width, int height );

void ZoomOutGrayImg( byte ** ppDesImg, s_Rect desImgRect, byte ** ppSrcImg, s_Rect srcImgRect );

bool Trans3RImgTo1R_2D_8u( byte ** ppDesImg, byte ** ppSrcImg, s_Rect clipRegionRange );

bool Trans1RImgTo3R_2D_8u( byte ** ppDesImg, byte ** ppSrcImg, s_Rect clipRegionRange );

// clip and resize
bool ClipResizeImg_1D_1D_8u( byte * pDesImg, int desWd, int desHt, byte * pSrcImg, int srcWd, int srcHt, 
		s_Rect clipRegionRange, int srcGradNum, int desGradNum );

bool ClipImg_2D_2D_8u( byte ** ppDesImg, byte ** ppSrcImg, s_Rect clipRegionRange, int srcBytesNum, int desBytesNum );
bool ClipImg_1D_2D_8u( byte ** ppDesImg, byte * pSrcImg, int srcWd, int srcHt, s_Rect clipRegionRange, int srcGradNum, int desGradNum );
bool ClipImg_2D_1D_8u( byte * pDesImg, int desWd, int desHt, 
			byte ** ppSrcImg, s_Rect clipRegionRange, int srcGradNum, int desGradNum );
bool ClipImg_1D_1D_8u( byte * pDesImg, int desWd, int desHt, byte * pSrcImg, int srcWd, int srcHt, s_Rect clipRegionRange, int srcGradNum, int desGradNum );
bool ClipImg_2D_2D_16s( int16 ** ppDesImg, int16 ** ppSrcImg, s_Rect clipRegionRange, int srcGradNum, int desGradNum );
bool ClipImg_2D_2D_32i( int ** ppDesImg, int ** ppSrcImg, s_Rect clipRegionRange, int srcGradNum, int desGradNum );

void CopyImg_8u_2DTo1D( byte * pDesImg, byte ** ppSrcImg, int width, int height, int imageBytesNum );

void CopyImg_1D_8u( byte * pDesImg, byte * pSrcImg, int srcWd, s_Rect clipRegionRange, int gradNum );
bool CopyImg_2D_8u( byte ** ppDesImg, byte ** ppSrcImg, s_Rect clipRegionRange, int gradNum );
void CopyData_2D_32i_32i_SROI_DROI( int ** ppDesData, int ** ppSrcData, s_Rect * pROI, int gradNum );
void CopyData_2D_8u_32i_SROI_DROI( int ** ppDesData, byte ** ppSrcData, s_Rect * pROI, int gradNum );
void CopyData_2D_8u_8u_SROI_DROI( byte ** ppDesData, byte ** ppSrcData, s_Rect * pROI, int gradNum );
void CopyData_2D_8u_32f_SROI_DROI( float ** ppDesData, byte ** ppSrcData, s_Rect * pROI, int gradNum );

void CopyImg_2DTo1D( byte * pDesImg, byte ** ppSrcImg, int width, int height, int imageBytesNum );

void CopyImg_1DTo2D( byte ** ppDesImg, byte * pSrcImg, int width, int heigth, int imageBytesNum );

void AddData_2D_32i_8u_SROI_DROI( int ** ppDesData, byte ** ppSrcData, s_Rect * pROI, int gradNum );

bool MirrorImg_8u_2D_Inp( byte ** ppImg, int width, int height, int gradNum );

void MirrorImg_8u_2D( byte ** ppMirrorImg, byte ** ppSrcImg, int width, int height );

void MirrorImg_8u_1D( byte * pMirrorImg, byte * pSrcImg, int width, int height );

void MirrorImg_16s_2D( int16 ** ppMirrorImg, int16 ** ppSrcImg, int width, int height );

void MirrorImg_16s_1D( int16 * pMirrorImg, int16 * pSrcImg, int width, int height );

void FlipImg_8u_2D( byte ** ppImg, int width, int height, int gradNum );
void FlipImg_8u_1D( byte * pImg, int width, int height, int gradNum );

bool TransImgType( byte ** ppDesImg, byte ** ppSrcImg, int width, int height, ImgType srcImgType, ImgType desImgType );

bool SaveData_8u_1D( char * fileName, byte * pSrcImg, int width, int height );
bool ReadData_8u_1D( char * fileName, byte * pSrcImg, int width, int height );

bool SaveRawImg_2D_8u( char * fileName, byte ** ppSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_1D_8u( char * fileName, byte * pSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_1D_32f_Para( char * fileName, float * pSrcImg, int width, int height, 
								   float srcMin, float srcMax, ImgType imageType );

bool SaveRawImg_1D_32f( char * fileName, float * pSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_2D_32f( char * fileName, float ** ppSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_2D_32f_Para( char * fileName, float ** ppSrcImg, int width, int height, 
								   float minVal, float maxVal, ImgType imageType );

bool SaveRawImg_1D_16s( char * fileName, int16 * pSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_1D_32i_Para( char * fileName, int * pSrcImg, int width, int height, 
			int minSrcVal, int maxSrcVal, byte minDesVal, byte maxDesVal, ImgType imageType );

bool SaveRawImg_1D_32i( char * fileName, int * pSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_1D_16s_Para( char * fileName, int16 * pSrcImg, int width, int height, int16 srcMinVal, 
								   int16 srcMaxVal, byte desMinVal, byte desMaxVal, ImgType imageType );

bool SaveRawImg_1D_16s_Lmt( char * fileName, int16 * pSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_1D_64f( char * fileName, double * pSrcImg, int width, int height, ImgType imageType );

bool SaveIndexImg_1D_16s( char * fileName, int16 * pSrcImg, int width, int height, 
											ImgType imageType, int N );

bool SaveRawImg_2D_16s( char * fileName, int16 ** ppSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_2D_64f( char * fileName, double ** ppSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_1D_64f_Para( char * fileName, double * pSrcImg, int width, int height, 
								   double srcMinVal, double srcMaxVal, byte desMinVal, int desMaxVal, ImgType imageType );

bool SaveRawImg_2D_64f_Energy( char * fileName, double ** ppSrcImg, int width, int height, 
									   int desMinVal, int desMaxVal, double energy, ImgType imageType );

bool SaveRawImg_2D_64f_Para( char * fileName, double ** ppSrcImg, int width, 
								   int height, double srcMin, double srcMax, 
								   int desMinVal, int desMaxVal, ImgType imageType );

bool SaveRawImg_2D_32i( char * fileName, int ** ppSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_2D_32i_Energy( char * fileName, int ** ppSrcImg, int width, int height, 
							  byte desMinVal, byte desMaxVal, double energy, ImgType imageType );

bool SaveRawImg_2D_32i_Para( char * fileName, int ** ppSrcImg, int width, int height, 
							  byte desMinVal, byte desMaxVal, int srcMinVal, int srcMaxVal, ImgType imageType );

bool SaveRawImg_2D_32i_Clip( char * fileName, int ** ppSrcImg, int width, int height, 
								   int minVal, int maxVal, ImgType imageType );

bool SaveRawImg_2D_32i_Sqrt( char * fileName, int ** ppSrcImg, int width, int height, ImgType imageType );

bool SaveRawImg_2D_64f_Sqrt( char * fileName, double ** ppSrcImg, int width, int height, ImgType imageType );

bool DrawPointOnImg_2D_8u( byte ** ppSrcColorImg, int width, int height, s_Point point, int pointWd, ImgType imageType );

bool DrawPointOnImg_1D_8u( byte * pSrcColorImg, int width, int height, s_Point point, int pointWd, ImgType imageType );

bool DrawRectOnImg_2D_8u( byte ** ppSrcColorImg, int width, int height, s_Rect rect, byte * pColor, 
						  ImgType imageType );

bool DrawRectOnImg_2D_16s( int16 ** ppSrcImg, int width, int height, 
								 s_Rect rect, int16 * pColor, ImgType imageType );

bool DrawRectOnImg_1D_8u( byte * pSrcColorImg, int width, int height, s_Rect rect, byte * pColor, ImgType imageType );

void NormTo8BitsImg( byte ** pp8BitsDesImg, float ** ppSrcImg, int width, int height );

void ResizeImg_8u_1D_1R_Mem( byte * pSrcImg, byte * pDesImg, int srcWd, int srcHt, 
		int desWd, int desHt, byte * pBuf, int bufSize );

int GetFilterSize( int src, int des, int maxTimes );
void ResizeImg_8u_2D_1R( byte **ppInput, byte **ppOutput, int srcWd, int srcHt, int nDstWd, int nDstHt );
void ResizeImg_8u_1D_1R( byte *pInput, byte *pOutput, int srcWd, int srcHt, int nDstWd, int nDstHt );
void ResizeImg_8u_2D_3R( byte **ppInput, byte **ppOutput, int srcWd, int srcHt, int nDstWd, int nDstHt );
void ResizeImg_8u_1D_3R( byte *pInput, byte *pOutput, int srcWd, int srcHt, int nDstWd, int nDstHt );

void BilinearResize_8u_1D_3RTo1R( byte *pInput, byte *pOutput, int srcWd, int srcHt, int nDstWd, int nDstHt );

void BilinearResize_8u_2D_1R( byte **ppInput, byte **ppOutput, int srcWd, int srcHt, int nDstWd, int nDstHt );

void BilinearResize_8u_2D_3R( byte **ppInput, byte ** ppOutput, int srcWd, int srcHt, int nDstWd, int nDstHt );

void BilinearResize_8u_1D_1R(byte *pInput, byte *pOutput, int srcWd, int srcHt, int nDstWd, int nDstHt);

void BilinearResize_8u_1D_3R(byte *pInput, byte *pOutput, int srcWd, int srcHt, int nDstWd, int nDstHt);

bool ResizeImg_8u_2D_2D_3R_ADP( byte ** ppDesImgBuf, byte ** ppSrcImgBuf, int srcImgWd, 
					  int srcImgHt, int desImgWd, int desImgHt );
bool ResizeImg_8u_2D_2D_1R_ADP( byte ** ppDesImgBuf, byte ** ppSrcImgBuf, int srcImgWd, 
					  int srcImgHt, int desImgWd, int desImgHt );

bool ResizeImg_8u_1D_1D_3R( byte * pDesImgBuf, byte * pSrcImgBuf, s_Rect vrSrcROI, int srcImgWd, 
					  int srcImgHt, int desImgWd, int desImgHt );

bool ResizeImg_8u_1D_1D_1R( byte * pDesImgBuf, byte * pSrcImgBuf, s_Rect vrSrcROI, int srcImgWd, 
					  int srcImgHt, int desImgWd, int desImgHt );

bool ResizeImg_8u_2D_2D_3R( byte ** ppDesImgBuf, byte ** ppSrcImgBuf, s_Rect vrSrcROI, int srcImgWd, int srcImgHt, 
					  int desImgWd, int desImgHt );

bool ResizeImg_8u_2D_2D_3R_fast( byte ** ppDesImgBuf, byte ** ppSrcImgBuf, s_Rect vrSrcROI, int srcImgWd, 
					  int srcImgHt, int desImgWd, int desImgHt );

bool ResizeImg_8u_2D_2D_1R( byte ** ppDesImgBuf, byte ** ppSrcImgBuf, s_Rect vrSrcROI, int srcImgWd, 
					  int srcImgHt, int desImgWd, int desImgHt );

bool ResizeImg_8u_2D_2D_1R_fast( byte ** ppDesImgBuf, byte ** ppSrcImgBuf, s_Rect vrSrcROI, int srcImgWd, 
					  int srcImgHt, int desImgWd, int desImgHt );

bool DownSampleImg_8u_1R_2D_2D_Mem_4Times( byte ** ppDesImg, byte ** ppSrcImg, int desWd, int desHt );

bool DownSampleImg_8u_3R_2D_2D_Mem_4Times( byte ** ppDesImg, byte ** ppSrcImg, int desWd, int desHt );

bool DownSampleImg_8u_1R_2D_2D_Mem_2Times( byte ** ppDesImg, byte ** ppSrcImg, int desWd, int desHt );

bool DownSampleImg_8u_3R_2D_2D_Mem_2Times( byte ** ppDesImg, byte ** ppSrcImg, int desWd, int desHt );

void DownSampleImg_8u_3R_2D_2D_Times( byte ** ppDesImg, byte ** ppSrcImg, int desWd, int desHt, 
											 int times );

void DownSampleImg_8u_1R_2D_2D_Times( byte ** ppDesImg, byte ** ppSrcImg, int desWd, int desHt, 
											 int times );

bool ZoomOutImg_8u_3R_2D_2D_Mem_2Times( byte ** ppDesImg, byte ** ppSrcImg, 
											  int desWd, int desHt );

bool ZoomOutImg_8u_1R_2D_2D_Mem_2Times( byte ** ppDesImg, byte ** ppSrcImg, 
											  int desWd, int desHt );

bool ZoomOutImg_8u_1R_2D_2D_Mem_4Times( byte ** ppDesImg, byte ** ppSrcImg, 
											  int desWd, int desHt );

bool ZoomOutImg_8u_3R_2D_2D_Mem_4Times( byte ** ppDesImg, byte ** ppSrcImg, 
											  int desWd, int desHt );

bool ZoomOutImg_8u_2D_3R_Times( byte ** ppDesImg, int desWd, int desHt, 
					byte ** ppSrcImg, int srcWd, int srcHt, int downSampleTimes );

bool ZoomOutImg_8u_2D_1R_Times( byte ** ppDesImg, int desWd, int desHt, 
					byte ** ppSrcImg, int srcWd, int srcHt, int downSampleTimes );

void SmoothImg_8u_2D_3R_Avg_Inp_Integ( byte ** ppImg, int width, int height, int halfNeibSize );
void SmoothImg_8u_2D_1R_Avg_Inp_Integ( byte ** ppImg, int width, int height, int halfNeibSize );

void SmoothImg_16s_1D_1R_Avg_Inp_Integ( int16 * pImg, int width, int height, int halfNeibSize );
void SmoothImg_16s_2D_1R_Avg_Inp_Integ( int16 ** ppImg, int width, int height, int halfNeibSize );

void SmoothImg_8u_1D_1R_Avg_Inp_Integ( byte * pImg, int width, int height, int halfNeibSize );
void SmoothImg_8u_1D_3R_Avg_Inp_Integ( byte * pImg, int width, int height, int halfNeibSize );

void SmoothImg_8u_2D_3R_Avg_Inp( byte ** ppImg, int width, int height, int halfNeibSize );

void SmoothImg_8u_2D_3R_Avg( byte ** ppSmoothImg, byte ** ppImg, int width, int height, int halfNeibSize );

void SmoothImg_8u_2D_1R_Avg_Inp( byte ** ppImg, int width, int height, int halfNeibSize );

void SmoothImg_64f_2D_1R_Avg_Inp( double ** ppImg, int width, int height, int halfNeibSize );

void SmoothImg_32i_2D_1R_Avg_Inp( int ** ppImg, int width, int height, int halfNeibSize );

void SmoothImg_32i_2D_1R_Avg( int ** ppSmoothImg, int ** ppImg, int width, int height, int halfNeibSize );

void SmoothImg_16s_1D_1R_Avg_Inp( int16 * pImg, int width, int height, int halfNeibSize );

bool SmoothImg_8u_1D_Median_Inp( byte * pImg, int width, int height, int cn );
bool SmoothImg_8u_1D_Median( byte * pDesImg, byte * pSrcImg, int width, int height, int cn );

void ErodeRegion_P1( byte ** ppDesImg, byte ** ppSrcImg, int width, int height );

void ErodeRegion_P1_Inp( byte ** ppSrcDesImg, int width, int height );

void DilateErodeRegion_2D_8u_Inp( byte ** ppSrcDesImg, int width, int height, 
				int halfNeigborSize, byte valDilate, byte valErode );

void DilateErodeRegion_2D_8u( byte ** ppDesImg, byte ** ppSrcImg, int width, 
		int height, int halfNeigborSize, byte valDilate, byte valErode );

bool InsertX( int * pSortX0, int * pSortX1, int x0, int x1, int * pInsertNum, int maxNum );
bool GetInnerRegionMask( int * pNum, byte * pMask, int width, int height, int * pX, int * pY, 
				int pointNum, int maxCrossNum, byte flag, bool bInner );

// 得到矩形区域内，从左下开始的第一个区域的外边缘
bool TraceBottomBoundary_1D_8u( s_Point * pBoundary, int * pCurPointNum, int maxPointNum, byte * pMaskImg, int maskWd, int maskHt, 
		byte color_object, byte color_background, s_Rect region );
// 得到矩形区域内，从左下开始的第一个区域的外边缘
bool TraceBottomBoundary_2D_8u( s_Point * pBoundary, int * pCurPointNum, int maxPointNum, byte ** ppInputImg, int imgWd, int imgHt, 
		byte color_object, byte color_background, s_Rect region );
// 将记录数组的最后一个点删除，并更新记录数目
bool PopPoint( s_Point * pPoint, s_Point * pBoundary, int maxPointNum, int * pCurNum );
// 将点添加到记录数组中的最后一个位置，并更新记录数目
bool PushPoint( s_Point point, s_Point * pBoundary, int maxPointNum, int * pCurNum );

// 计算曲线长度
double GetPerimeter( s_Point * pBoundary, int pointNum );

// 获取标志为flag的区域矩形范围，有效范围包含right和bottom
void GetFlagRect( int * pLeft, int * pTop, int * pRight, int * pBottom, byte * pMask, int width, int height, byte flag );

void ReplaceBackground( byte ** ppDesImg, byte ** ppSrcImg, byte ** ppBkImg, byte ** ppFlagImg, 
					   int width, int height );

void ReplaceBackground_Blending( byte ** ppDesImg, byte ** ppSrcImg, byte ** ppBkImg, byte ** ppFlagImg, 
								int width, int height, int erodeSize, int dilateSize );

//void GetGrayImgFromRGB24( byte * pGrayImg, byte * pSrcImg, int width, int height );

void OrFlagImg_8u_Inp( byte ** ppSrcDesFlag, byte ** ppSrcFlag, int width, int height );

void AndFlagImg_8u_Inp( byte ** ppSrcDesFlag, byte ** ppSrcFlag, int width, int height );

void OrFlagImg_bool_Inp( bool ** ppSrcDesFlag, bool ** ppSrcFlag, int width, int height );

void AndFlagImg_bool_Inp( bool ** ppSrcDesFlag, bool ** ppSrcFlag, int width, int height );

void OrFlagImg_8u( byte ** ppDesFlag, byte ** ppSrcFlag0, byte ** ppSrcFlag1, 
				  int width, int height );

void AndFlagImg_8u( byte ** ppDesFlag, byte ** ppSrcFlag0, byte ** ppSrcFlag1, 
				   int width, int height );

void SetDataValFlag_1D_32f( float * pImg, byte * pFlag, int dataSize, byte flag, float val );
void SetDataValFlag_2D_32f( float ** ppImg, byte ** ppFlag, int width, int height, 
						   byte flag, float val );
void SetDataValFlag_2D_8u( byte ** ppImg, byte ** ppFlag, int width, int height, 
						   byte flag, byte val );

void AddVector_2D_32f_Inp( float ** ppVector0, float ** ppVector1, int width, int height );
void SubVector_2D_32f_Inp( float ** ppVector0, float ** ppVector1, int width, int height );
void SubVector_1D_32f_Inp( float * pVector0, float * pVector1, int vectLength );;

void FabsVector_2D_32f( float ** ppVector0, int width, int height );
void FabsVector_1D_32f( float * pVector0, int vectLength );

void HistEqualize_1D_8u( byte * pImg, int imgSize );

void HistEqualize_1D_8u_Mask( byte * pImg, int imgSize, byte * pMask );

void HistEqualize_2D_8u( byte ** ppImg, int width, int height );

void HistEqualize_2D_8u_Mask( byte ** ppImg, int width, int height, byte ** ppMask );
void GetFlagRectPara( int * pCenterX, int * pCenterY, int * pVldRectWd, int * pVldRectHt, int ** ppIntegFlag, int width, 
									   int height, s_Rect ROI );

// Color Space Transformation
void TransRGBToNormRGB( byte & pL, float & fb, float & fg, float & fr, byte b, byte g, byte r );
void TransRGBTo8uNormRGB( byte & pL, byte & fb, byte & fg, byte & fr, byte b, byte g, byte r );
void ClipImg_8u_1D_1D( byte * pDesImg, byte * pSrcImg, int srcWd, 
			s_Rect clipRegionRange, int bytesNum );
void TransFlipRGB24_1DImgToGray1D( byte * pDesImg, byte * pSrcImg, int width, int height );
bool TransYUV42221DImgToGray1D( byte * pDesImg, byte * pSrcImg, int width, int height );
void GetHSVValue( float & h, float & s, float & v, byte b, byte g, byte r );

/* MallocMemory.h */

typedef struct s_Data_2D_8u
{
	int width;
	int height;
	byte ** ppData;
}
s_Data_2D_8u;

typedef struct s_Data_2D_32i
{
	int width;
	int height;
	int ** ppData;
}
s_Data_2D_32i;

typedef struct s_Data_2D_64f
{
	int width;
	int height;
	double ** ppData;
}
s_Data_2D_64f;

typedef struct s_Data_1D_8u
{
	int width;
	int height;
	byte * pData;
}
s_Data_1D_8u;

typedef struct s_Data_1D_32i
{
	int width;
	int height;
	int * pData;
}
s_Data_1D_32i;

typedef struct s_Data_1D_64f
{
	int width;
	int height;
	double * pData;
}
s_Data_1D_64f;

void Create2DMem_2D_8u( s_Data_2D_8u * pMem, int width, int height );
void Create2DMem_2D_32i( s_Data_2D_32i * pMem, int width, int height );
void Create2DMem_2D_64f( s_Data_2D_64f * pMem, int width, int height );
void Release2DMem_2D_8u( s_Data_2D_8u * pMem );
void Release2DMem_2D_32i( s_Data_2D_32i * pMem );
void Release2DMem_2D_64f( s_Data_2D_64f * pMem );
void Set2DMemNull_2D_8u( s_Data_2D_8u * pMem );
void Set2DMemNull_2D_32i( s_Data_2D_32i * pMem );
void Set2DMemNull_2D_64f( s_Data_2D_64f * pMem );

void Create1DMem_1D_8u( s_Data_1D_8u * pMem, int width, int height );
void Create1DMem_1D_32i( s_Data_1D_32i * pMem, int width, int height );
void Create1DMem_1D_64f( s_Data_1D_64f * pMem, int width, int height );
void Release1DMem_1D_8u( s_Data_1D_8u * pMem );
void Release1DMem_1D_32i( s_Data_1D_32i * pMem );
void Release1DMem_1D_64f( s_Data_1D_64f * pMem );

typedef struct s_CommonMem
{
	byte * pBuf;
	int bufSize;
}
s_CommonMem;

#ifdef _HUANGYING
struct MYCOLOR
{
	BYTE b,g,r;
};
MYCOLOR **f2m (int nr, int nc);
void FreeArray_COLOR(MYCOLOR **array, int height, int col);
#endif

bool ** CreateMemory_1b_2D( int rowNum, int colNum );
void ReleaseMemory_1b_2D( bool ** ppMem, int rowNum, int colNum );

double ** CreateMemory_64f_2D( int rowNum, int colNum );
void ReleaseMemory_64f_2D( double ** ppMem, int rowNum, int colNum );

int ** CreateMemory_32i_2D( int rowNum, int colNum );
void ReleaseMemory_32i_2D( int ** ppMem, int rowNum, int colNum );

int16 ** CreateMemory_16s_2D( int rowNum, int colNum );
void ReleaseMemory_16s_2D( int16 ** ppMem, int rowNum, int colNum );

byte ** CreateMemory_8u_2D( int rowNum, int colNum );
void ReleaseMemory_8u_2D( byte ** ppMem, int rowNum, int colNum );

float ** CreateMemory_32f_2D( int rowNum, int colNum );
void ReleaseMemory_32f_2D( float ** ppMem, int rowNum, int colNum );

char ** CreateMemory_char_2D( int rowNum, int colNum );
void ReleaseMemory_char_2D( char ** ppMem, int rowNum, int colNum );

int ** CreateMemory_32i_2D_simmem( byte ** ppBuf, int * pBufSize, int rowNum, int colNum );
byte ** CreateMemory_8u_2D_simmem( byte ** ppBuf, int * pBufSize, int rowNum, int colNum );
float ** CreateMemory_32f_2D_simmem( byte ** ppBuf, int * pBufSize, int rowNum, int colNum );

void Get2DIndex_8u( byte ** ppData, byte * pData, int width, int height, int gradNum );
void Get2DIndex_16s( int16 ** ppData, int16 * pData, int width, int height, int gradNum );
void Get2DIndex_32i( int ** ppData, int * pData, int width, int height, int gradNum );
void Get2DIndex_32f( float ** ppData, float * pData, int width, int height, int gradNum );
void Get2DIndex_64f( double ** ppData, double * pData, int width, int height, int gradNum );

typedef struct s_Img_8u
{
	int width;
	int height;
	byte * pImgData;
	byte ** ppImgIndex;
	int grad;
}
s_Img_8u;

typedef struct s_Img_16s
{
	int width;
	int height;
	int16 * pImgData;
	int16 ** ppImgIndex;
}
s_Img_16s;

typedef struct s_Img_32i
{
	int width;
	int height;
	int * pImgData;
	int ** ppImgIndex;
}
s_Img_32i;

typedef struct s_IntegImg_32i
{
	int caseNum;
	int ** ppIntegImg;
	int width;
	int height;
}
s_IntegImg_32i;

byte * CreateImgBuffer( int width, int height, ImgType imgType );
int GetImgBufferSize( int width, int height, ImgType imgType );

void SetNullImg_8u( s_Img_8u * pImg );
void CrtImg_8u( s_Img_8u * pCurImg, int grad );
void ReleaseImg_8u( s_Img_8u * pImg );

void SetNullImg_16s( s_Img_16s * pImg );
void CrtImg_16s( s_Img_16s * pCurImg );
void ReleaseImg_16s( s_Img_16s * pImg );

void SetNullImg_32i( s_Img_32i * pImg );
void CrtImg_32i( s_Img_32i * pCurImg );
void ReleaseImg_32i( s_Img_32i * pImg );

void CreateIntegImg( void* pIntegImg, int imgWd, int imgHt, int caseNum );
void ReleaseIntegImg( void* pIntegImg );

int16 GetScaleNum( double minScale, double maxScale, double scaleStep );

/* IntegImg.h */

void Cacu1DIntegImg_1D_32i( int * pIntegImg, int * pImg, int length );

void CacuIntegImgWH_8u_32i_2D_2D( int ** ppIntegImg, byte ** ppImg, int srcWd, int srcHt );
void CacuIntegImgWH_8u_32i_1D_2D( int ** ppIntegImg, byte * pImg, int srcWd, int srcHt );

void CacuIntegImgRect( int ** ppIntegImg, byte ** ppImg, s_Rect rangeRect );

void CacuIntegIntenImg_8u_32i_1D_1D( int * pIntegImg, byte * pImg, int imgWd, int imgHt );
void CacuIntegIntenImg_32i_32i_1D_1D( int * pIntegImg, int * pImg, int imgWd, int imgHt );

void CacuIntegIntenImg_8u_64f_1D_1D( double * pIntegImg, byte * pImg, int imgWd, int imgHt );
void CacuIntegIntenImg_32i_64f_1D_1D( double * pIntegImg, int * pImg, int imgWd, int imgHt );
void CacuIntegIntenImg_64f_64f_1D_1D( double * pIntegImg, double * pImg, int imgWd, int imgHt );

void CacuIntegSqIntenImg_8u_32i_1D_1D( int * pIntegImg, byte * pImg, int imgWd, int imgHt );
void CacuIntegSquareImgWH( int ** ppIntegSquareImg, byte ** ppImg, int srcWd, int srcHt );
void CacuIntegSquareImgWH_8u_1D( int ** ppIntegSquareImg, byte * pImg, int srcWd, int srcHt );
void CacuIntegSquareImgRect( int ** ppIntegSquareImg, byte ** ppImg, s_Rect rangeRect );
void CacuIntegSqIntenImg_8u_64f_1D_1D( double * pIntegImg, byte * pImg, int imgWd, int imgHt );

void CacuIntegImgWH_16s_1D( int ** ppIntegImg, int16 * pImg, int srcWd, int srcHt );
void CacuIntegImgWH_16s_2D( int ** ppIntegImg, int16 ** ppImg, int srcWd, int srcHt );

void CacuIntegImgWH_16s_1D_3D( int *** pppIntegImg, int16 * pImg, int16 * pImgCase, int imgCaseNum, 
							 int srcWd, int srcHt );
void CacuIntegImgWH_32i_1D_3D( int *** pppIntegImg, int * pImg, int * pImgCase, 
			int imgCaseNum, int srcWd, int srcHt );

void CacuIntegImgRect_32i_2D_3D_Range( int *** pppIntegImg, int ** ppImg, byte ** ppImgCase, 
							byte imgCaseNum, s_Rect rangeRect );

void GetHOG_2D_IntegImgArray( int * pHOG, int *** pppIntegImg, int width, int height, 
							 int left, int top, int right, int bottom, int16 binNum );

void GetCM_2D_IntegImgArray( double * pCM, int *** pppIntegImg, int *** pppIntegSquareImg, int width, 
							int height, int left, int top, int right, int bottom, int16 binNum );

void CacuIntegImgRect_32i_2D_3D_Serial_Range( int *** pppIntegImg, byte ** ppImg, byte imgCaseNum, s_Rect rangeRect );
void CacuIntegSquareImgRect_32i_2D_3D_Serial_Range( int *** pppIntegImg, byte ** ppImg, byte imgCaseNum, s_Rect rangeRect );
void CacuMultiCaseIntegImg_8u_32i( int ** ppIntegImg, byte * pCaseImg, int imgWd, int imgHt, byte imgCaseNum );
void CacuMultiCaseIntegImg_8u_1D_32i_1D( int * pIntegImg, byte * pCaseImg, int imgWd, int imgHt, byte imgCaseNum );
void CacuMultiCaseIntenIntegImg_8u_32i( int ** ppIntegImg, byte * pCaseImg, int * pIntenImg, int imgWd, int imgHt, byte imgCaseNum );
void CacuMultiCaseIntenIntegImg_8u_1D_32i_1D( int * pIntegImg, byte * pCaseImg, int * pIntenImg, int imgWd, int imgHt, byte imgCaseNum );

void CacuColorMomentum_2_R3( double * pCM, byte ** ppImg, int width, int height, s_Rect * pRegion );

void CacuIntegSquareImgWH_32i_2D( int ** ppIntegImg, int ** ppImg, int srcWd, int srcHt );
void CacuIntegSquareImgWH_64f_2D( double ** ppIntegImg, double ** ppImg, int srcWd, int srcHt );

void CacuIntegImgWH_32i_2D( int ** ppIntegImg, int ** ppImg, int srcWd, int srcHt );
void CacuIntegImgWH_64f_2D( double ** ppIntegImg, double ** ppImg, int srcWd, int srcHt );

/* RotateImg.h */

typedef struct s_Angle
{
	s_Double cosAngle;
	s_Double sinAngle;
}
s_Angle;

s_Angle GetReverseAngle( s_Angle angle );

void GetAffinePara( s_Double & rot_s_x, s_Double & rot_s_y, s_Double & move_x, s_Double & move_y, 
		s_Point srcReferPoint, s_Point desReferPoint, s_Double srcToDesScale, s_Angle srcToDesAngle );

bool RotateImg_8u_1D_1R( byte * pDesImg, int desWd, int desHt, s_Point desReferPoint, 
		 byte * pSrcImg, int srcWd, int srcHt, 
		 s_Point srcReferPoint, s_Double desToSrcScale, s_Angle desToSrcAngle );
bool RotateImg_8u_1D_1R_Mem( byte * pDesImg, int desWd, int desHt, 
			 s_Point desReferPoint, 
			 byte * pSrcImg, int srcWd, int srcHt, 
			 s_Point srcReferPoint, s_Double desToSrcScale, 
			 s_Angle desToSrcAngle, byte * pMemBuf, int bufSize );
bool TransImg_Affine_1D_8u_Mem( s_Double rot_s_x, s_Double rot_s_y, 
							  s_Double move_x,  s_Double move_y, 
				byte * pDesImg, int desWd, int desHt, byte * pSrcImg, int srcWd, int srcHt, 
				int leftShift, int topShift, byte * pMemBuf, int bufSize );

s_Point TransPoint_Affine( s_Double rot_s_x, s_Double rot_s_y, s_Double move_x,  s_Double move_y, s_Point srcPoint );

bool TransImg_Affine_1D_8u( s_Double rot_s_x, s_Double rot_s_y, s_Double move_x,  s_Double move_y, 
				byte * pDesImg, int desWd, int desHt, byte * pSrcImg, int srcWd, int srcHt, 
				int leftShift, int topShift );

typedef struct s_RotateAngle
{
	int x;
	int y;
	int r;
	int halfr;
}
s_RotateAngle;

s_RotateAngle AddAngle( s_RotateAngle angle1, s_RotateAngle angle2 );

s_RotateAngle GetReverseAngle( s_RotateAngle angle );

s_RotateAngle GetRectifyAngle( s_Point srcOriginPoint, s_Point srcPoint2 );

s_RotateAngle GetRotAngle( s_Point srcOriginPoint, s_Point srcPoint2, s_Point desOriginPoint, s_Point desPoint2 );

void GetRectifyAngle_64f( double * pSinAngle, double * pCosAngle, s_Point point0, s_Point point1 );
void AddAngle_64f( double * pDesSinAngle, double * pDesCosAngle, double sinAngle0, double cosAngle0, double sinAngle1, double cosAngle1 );

double GetRotAngle_f64( s_Point srcOriginPoint, s_Point srcPoint2, s_Point desOriginPoint, s_Point desPoint2 );

s_RotateAngle GetEnlRotAngle( s_Point srcOriginPoint, s_Point srcPoint2, s_Point desOriginPoint, s_Point desPoint2 );

s_Fraction GetEnlargeRatio( s_Point srcOriginPoint, s_Point srcPoint2, s_Point desOriginPoint, s_Point desPoint2 );

s_Point GetReferRotatePoint( s_Point srcPoint, s_Point referPoint, s_RotateAngle * pRotAngle );

s_Point_f64 GetReferRotatePoint_f64( s_Point srcPoint, s_Point referPoint, double rotAngle );

s_Point RotatePoint( s_Point srcPoint, s_Point srcReferPoint, s_Point desReferPoint, s_RotateAngle * pRotAngle );

s_Point_f64 RotatePoint_f64( s_Point srcPoint, s_Point srcReferPoint, s_Point desReferPoint, double rotAngle );

s_Rect RotateRectRange( s_Rect srcRect, s_Point srcOriginPoint, s_Point desOriginPoint, s_RotateAngle * pRotAngle );

s_Rect RotateRectRange_f64( s_Rect srcRect, s_Point srcOriginPoint, s_Point desOriginPoint, double rotAngle );

bool RotateImg_2D_To_2D_1R_ReferPoint( byte ** ppRotImg, s_ReferScope desImgScope, byte ** ppSrcImg, 
		s_Rect srcImgRect, s_Point srcReferPoint, s_RotateAngle * pRotAngle, bool bGrayImg );

bool RotateImg_2D_1R_To_2D_1R_ReferPoint( byte ** ppRotImg, s_ReferScope desImgScope, byte ** ppSrcImg, 
		s_Rect srcImgRect, s_Point srcReferPoint, s_RotateAngle * pRotAngle );

bool RotateImg_2D_3R_To_2D_1R_ReferPoint( byte ** ppRotImg, s_ReferScope desImgScope, byte ** ppSrcImg, s_Rect srcImgRect, 
							 s_Point srcReferPoint, s_RotateAngle * pRotAngle );

bool RotateImg_2D_To_2D_ReferPoint_R64f( byte ** ppRotImg, s_ReferScope desImgScope, byte ** ppSrcImg, s_Rect srcImgRect, 
							 s_Point srcReferPoint, double sinAngle, double cosAngle, int gradNum );

void GetRotateImgScope_ReferPoint( s_ReferScope * pDesImgScope, s_RectSize srcImgSize, s_Point referPoint, 
									s_RotateAngle * pRotAngle );

bool ClipRotateImg_8u_2D_3R( byte ** ppDesImg, int desImgWd, int desImgHt, 
							byte ** ppSrcImg, int srcImgWd, int srcImgHt, 
							double srcToDesRotAngle, s_Point centerPoint );

s_Point RotatePoint_cossin( s_Point srcPoint, s_Point srcReferPoint, s_Point desReferPoint, 
							   double cosRotAngle, double sinRotAngle );

s_RotateAngle EnlargeAngleSinCosValue( s_RotateAngle origAngle, s_Fraction enlargeRatio );

s_Ellipse GetFaceEllipseFromFaceRect( s_Rect faceRect );

s_Ellipse GetFaceEllipseFromEyesPos( s_Point leftEyePos, s_Point rightEyePos );

//s_Ellipse GetFaceEllipseFromEllipse( ELLIP_TRACKING_DATA ellip_Tracking_Data );

s_Point GetCenterPointFromRegularTriangleApexes( s_Point leftTopApex, s_Point rightTopApex );

s_Point GetThirdApexFromRegularTriangleApexes( s_Point leftTopApex, s_Point rightTopApex );

s_Rect GetEllipseRect( s_Ellipse ellipse );

// 得到向量{x, y}的有符号离散化方向
int GetNormCase_16s_Nd_Uniform( int x, int y, int directNum );

// 得到向量{x, y}的无符号离散化方向
int GetNormCase_16s_uNd_Uniform( int x, int y, int directNum );

// cacu the left-right pos of face by organ Points
double GetFacePos( s_Point leftEye, s_Point rightEye, s_Point mouthPos );

/* FaceInfoStruct.h */

typedef enum e_PositionOrganStage
{
	op_exception, op_smaller, op_start, op_detectface, op_detectlefteye, op_detectrighteye, op_mergeeyes, 
		op_detectmouth, op_mergemouth
}
e_PositionOrganStage;

typedef struct s_OrganPointSet
{
	s_Point leftEye;
	s_Point rightEye;
	s_Point mouth;
	int	relia;
	e_PositionOrganStage processStage;
}
s_OrganPointSet;

typedef struct s_ObjectRect
{
	bool bValid;

	s_Rect rect;

	int relia;

	s_Angle rotAngle;

	s_OrganPointSet	organPointSet;

	dword rectNum;

	int fSumLeft;
	int fSumTop;
	int fSumRight;
	int fSumBottom;
//	double fSumLeft;
//	double fSumTop;
//	double fSumRight;
//	double fSumBottom;

	int reserveNum;
	double reserveDouble;

	double reliaSum;
//	double reserveSum;
//	double trackRelia;
}
s_ObjectRect;

//#define MIN_OPTIM_RATIO (-32768*30) // -163840
#define MIN_OPTIM_RATIO -163840 // (-30.0) // 

// data is sorted by ascending order
typedef struct s_OptimObjectArray
{
	s_ObjectRect * pObjectRectArray;
	int pCurObjectOrder;

 	int objectRatioThresh;
//	double objectRatioThresh;
	int maxDataSize;
	int dataSize;
}
s_OptimObjectArray;

void InitializeOptimObjectArray( s_OptimObjectArray * pOptimArray, int maxdataSize );
void RemoveAllOptimObject( s_OptimObjectArray * pOptimArray );

void DeleteAllObject( s_OptimObjectArray * pOptimArray );

void InitializeOptimObjectArray_simmem( byte ** ppBuf, int * pBufSize, s_OptimObjectArray * pOptimArray, int maxdataSize );

void SetOptimObjectArrayThresh( s_OptimObjectArray * pOptimArray, int thresh );

bool InsertOptimObject( s_OptimObjectArray * pOptimArray, s_ObjectRect * pObjectRect );

bool InsertObjectRect( s_OptimObjectArray * pOptimArray, s_Rect * pRect );

int GetMaxOptimObjectArraySize( s_OptimObjectArray * pOptimArray );
int	 GetOptimObjectArraySize( s_OptimObjectArray * pOptimArray );
s_ObjectRect GetOptimObject( s_OptimObjectArray * pOptimArray, int i );// i is in the range from 0 to (pOptimArray->dataSize - 1)
void SetOptimObject( s_OptimObjectArray * pOptimArray, s_ObjectRect * pObjectRec, int i ); // i is in the range from 0 to (pOptimArray->dataSize - 1)

bool IsSameObject( s_Rect tempObject1, s_Rect tempObject2 );
bool IsCoverObject( s_Rect tempObject1, s_Rect tempObject2, double coverRatioThresh );

bool IsHorNeighborRect( s_Rect tempObject1, s_Rect tempObject2, float sizeRatioThresh, float coverRatioThresh, float disRatioThresh );
bool IsVerNeighborRect( s_Rect tempObject1, s_Rect tempObject2, float sizeRatioThresh, float coverRatioThresh, float disRatioThresh );

void RemoveInvalidOptimObject( s_OptimObjectArray * pOptimArrayResult );
void CopyValidOptimObject( s_OptimObjectArray * pDesOptimObjectArray, s_OptimObjectArray * pSrcOptimObjectArray );

bool InitOptimObjectArray_Mem( s_OptimObjectArray * pOptimArray, int maxdataSize, byte ** ppBuf, int * pBufSize );
void RemoveAllOptimObject_Mem( s_OptimObjectArray * pOptimArray, byte ** ppBuf, int * pBufSize );
bool RemoveInvalidOptimObject_Mem( s_OptimObjectArray * pOptimArrayResult, byte ** ppBuf, int * pBufSize );
bool MergeObject_Mem( s_OptimObjectArray * pOptimArrayResult, byte * pBuf, int bufSize );
void CopyValidObjectRect( s_OptimObjectArray * pDesOptimArrayResult, s_OptimObjectArray * pSrcOptimArrayResult, bool bDetPre );
bool AppendObjectRectToArrayInOrder( s_OptimObjectArray * pDesOptimArrayResult, s_OptimObjectArray * pSrcOptimArrayResult, 
		int (*pCacuVal)( s_ObjectRect * ), int flag );
int CacuRectWd( s_ObjectRect * pObjectRect );

void GetActualObject( s_OptimObjectArray * pOptimArrayResult );

void EnlargeOptimObject( s_OptimObjectArray * pOptimArrayResult, double enlargeRatio );

// 将物体框进行扩大或者缩小，但原始图像尺寸不变
void ZoomObjectArrayOnly( s_OptimObjectArray * pOptimArrayResult, double widthZoomRatio, double heightZoomRatio, s_Rect limitRange );

void ZoomObjectOnly( s_ObjectRect * pObjectRect, double widthZoomRatio, double heightZoomRatio, s_Rect limitRange );

s_Rect GetActualRect( s_ObjectRect * pObjectRect );

void MergeObject( s_OptimObjectArray * pOptimArrayResult );
void MergeObject_Poten( s_OptimObjectArray * pOptimArrayResult, int reliaThresh );

void RemoveSameObject( s_OptimObjectArray * pOptimArrayResult, s_Rect rect );
void RemoveSameCoverObject( s_OptimObjectArray * pOptimArrayResult, s_Rect rect );

void ShiftObjectRect( s_ObjectRect * pObjectRect, int shiftX, int shiftY );

void DrawObjectRect( byte ** ppSrcImg, int width, int height, s_OptimObjectArray * pOptimArrayResult, 
								byte * pColor, ImgType imgType, double enlargeRatio );

void SetNullOptimObjectArray( s_OptimObjectArray * pOptimArrayResult );

double GetReliability_64f( int retStageOrder, int stageNum, double sumOfFeat, double thresh );
int GetReliability_32i( int retStageOrder, int stageNum, int sumOfFeat, int thresh, int enlargeRatio );

s_Rect * GetRectOnLabel( int * pRectNum, byte** image, int wd, int ht );
int PixelLabeling8_twopass(int** image, int ht, int wd);

/* AverageQuene.h */

#define AVG_THRESH_ENLARGE_BITS 12

typedef struct s_AverageQuene
{
	int actualArrayNum;
	int maxArrayNum;
	int numPerArray;

	int header;

	int ** ppData;
	int * pData;

	int * pSumData;

	int difThresh;
}
s_AverageQuene;

void AQ_Initialize( s_AverageQuene * pAverageQuene, int arrayNum, int numPerArray );

void AQ_ReleaseMemory( s_AverageQuene * pAverageQuene );

void AQ_AddElem( s_AverageQuene * pAverageQuene, int * pData );

void AQ_RemoveAllData( s_AverageQuene * pAverageQuene );

int AQ_GetAvgData( s_AverageQuene * pAverageQuene, int dataOrder );

/* fileOperation */

bool WriteTxtToFile( char * pTxt, char * filePath );

bool AppendTxtToFile( char * pTxt, char * filePath );

void ShowData_8u( byte bData );

bool ShowData_8u_1D( byte * pData, int width, int height, char * filePath );
bool ShowData_8u_2D( byte ** ppData, int width, int height, char * filePath );

bool ShowData_16s_2D( int16 ** ppData, int width, int height, char * filePath );
bool ShowData_16s_1D( int16 * pData, int width, int height, char * filePath );

bool ShowData_32i_1D( int * pData, int width, int height, char * filePath );
bool ShowData_32i_2D( int ** ppData, int width, int height, char * filePath );

bool ShowData_32f_1D( float * pData, int width, int height, char * filePath );
bool ShowData_32f_2D( float ** ppData, int width, int height, char * filePath );

bool ShowData_64f_1D( double * pData, int width, int height, char * filePath );
bool ShowData_64f_2D( double ** ppData, int width, int height, char * filePath );

bool AppendDataToFile_8u( byte bData, char * filePath );
bool AppendDataToFile_16s( int16 data, char * filePath );
bool AppendDataToFile_32i( int data, char * filePath );
bool AppendDataToFile_32f( float data, char * filePath );
bool AppendDataToFile_64f( double data, char * filePath );

bool SaveData_8u( char * pFeatPath, byte * pFeat, int allFeatNum );
bool SaveData_32i( char * pFeatPath, int * pFeat, int allFeatNum );
bool SaveData_32f( char * pFeatPath, float * pFeat, int allFeatNum );
bool SaveData_64f( char * pFeatPath, double * pFeat, int allFeatNum );

bool ReadDataNum( char * pFeatPath, int * pAllFeatNum );

bool ReadData_8u( char * pFeatPath, byte * pFeat, int allFeatNum );
bool ReadData_32i( char * pFeatPath, int * pFeat, int allFeatNum );
bool ReadData_32f( char * pFeatPath, float * pFeat, int allFeatNum );
bool ReadData_64f( char * pFeatPath, double * pFeat, int allFeatNum );

int FRead_Buf( void * pDesImg, int byteSize, int num, byte * & pBuf, int & fileLength );

void * MallocMem( byte ** ppBuf, int * pBufSize, int mallocSize );
void FreeMem( byte ** ppBuf, int * pBufSize, int mallocSize );

void CrtImg_32i( s_Img_32i* pCurImg, int width,  int height );
void CrtImg_8u( s_Img_8u* pCurImg, int width, int height );
int GetImgBufferSize( int width, int height,ImgType imgType );


#endif