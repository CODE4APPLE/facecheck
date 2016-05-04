#ifndef __AEMODULEFACTORY_H__
#define __AEMODULEFACTORY_H__

#include <map>
#include "AECommon.h"
#include "AEException.h"

template <class Type, typename Key, class Constructor= Type* (*)()>
class AEDLLExport AEModuleFactory
{
public:
	static AEModuleFactory& Instance()
	{
		static AEModuleFactory instance;
		return instance;
	}

	bool RegisterModule( const Key& module_info, Constructor ptr )
	{
		if( module_rep_.find( module_info ) != module_rep_.end() )
		{
			throw AEException( "already register have this module, rename it" );
		}

		module_rep_[module_info] = ptr;
		return true;
	}

	Type* CreateModule( const Key& module_info ) const
	{
		Type* module = NULL;
		auto iter = module_rep_.find( module_info );

		if( module_rep_.end() != iter )
		{
			module = (iter->second)();
		}

		return module;
	}

	void DestroyModule( Type*& module )
	{
		delete module;
		module = NULL;
	}
private:
	std::map< Key, Constructor > module_rep_;
private:
	DISALLOW_CONSTRUCTOR(AEModuleFactory);
};

#define REGISTER_AEMODULES( Type, Key, key_value, constructor  ) \
static bool XXRegister##key_value = AEModuleFactory<Type, Key>::Instance().RegisterModule( #key_value, constructor )

#define EXPORT_AEFACTORY( Type, Key ) \
template AEDLLExport class AEModuleFactory< Type, Key >

#endif //__AEMODULEFACTORY_H__
