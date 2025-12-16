#pragma once

#ifdef VZ_PLATFORM_WINDOWS
	#ifdef VZ_BUILD_DLL
		#define VIZUAL_API __declspec(dllexport)
	#else
		#define VIZUAL_API __declspec(dllimport)
	#endif
#else
	#error The windows platform is only supported right now.
#endif