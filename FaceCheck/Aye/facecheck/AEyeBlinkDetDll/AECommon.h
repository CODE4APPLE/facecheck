#ifndef __AECOMMON_H__
#define __AECOMMON_H__

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName( const TypeName& ); \
void operator=(const TypeName&);

#define DISALLOW_CONSTRUCTOR(TypeName) \
TypeName(){}; \
DISALLOW_COPY_AND_ASSIGN(TypeName)

#ifdef WIN32
#define AEDLLExport __declspec( dllexport )
#define AEDLLImport __declspec( dllimport )
#else
#define AEDLLExport
#define AEDLLImport
#endif

typedef unsigned char BYTE;
typedef int INT;

#endif //__AECOMMON_H__
