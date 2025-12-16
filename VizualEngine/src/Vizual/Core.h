#pragma once

#ifdef VZ_PLATFORM_WINDOWS
	#ifdef VZ_BUILD_DLL
		#define VZ_API __declspec(dllexport)
	#elif VZ_IMPORT_DLL
		#define VZ_API __declspec(dllimport)
	#else
		#define VZ_API __declspec(dllimport)
	#endif
#else
	#error The windows platform is only supported right now.
#endif