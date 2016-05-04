//
//  MyAddtions.h
//  MyLaoLai
//
//  Created by eye on 14-12-25.
//  Copyright (c) 2014年 ___A-EYE___. All rights reserved.
//

#ifndef MyLaoLai_MyAddtions_h
#define MyLaoLai_MyAddtions_h


#endif

#define DataBasePath(v) [[(NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask,YES)) lastObject]stringByAppendingPathComponent:v]
//获取屏幕的高度
#define winsizeH [[UIScreen mainScreen] bounds].size.height
#define winsizeW  [[UIScreen mainScreen] bounds].size.width
#define  DATAPHOTO @"photofilename"
#define  DATAFEATURE @"featuresfilename"
#define  MBRINITDATA  @"mbrinitdata.plist"
#define  CHECKPARAMETERS @"checkParameter"

#define NUMBER_TEXTFIELD_FILE @"numbertextfield"
#define SYSTEM_TEXTFIELD_FILE @"systemstextfield"

#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhone6pluse ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(2208, 1242), [[UIScreen mainScreen] currentMode].size): NO)

#define iOS7 (([[[UIDevice currentDevice]systemVersion] floatValue] >= 7.0)?YES:NO)
#define iOS8 (([[[UIDevice currentDevice]systemVersion] floatValue] >= 8.0)?YES:NO)

#define ISNOTNULL(v) !((NSNull*)v == [NSNull null])
#define WEB_BASIE_URL  @"http://10.176.118.231:8080"//@"http://218.76.43.103:8613"@"http://114.141.165.123"

