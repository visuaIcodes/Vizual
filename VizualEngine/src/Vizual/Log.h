#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Vizual {
	class VZ_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};
}

#ifndef VZ_DIST

#define VZ_CORE_ERROR(...)	::Vizual::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VZ_CORE_WARN(...)	::Vizual::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VZ_CORE_INFO(...)	::Vizual::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VZ_CORE_TRACE(...)	::Vizual::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VZ_CORE_FATAL(...)	::Vizual::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define VZ_ERROR(...)	::Vizual::Log::GetClientLogger()->error(__VA_ARGS__)
#define VZ_WARN(...)	::Vizual::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VZ_INFO(...)	::Vizual::Log::GetClientLogger()->info(__VA_ARGS__)
#define VZ_TRACE(...)	::Vizual::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VZ_FATAL(...)	::Vizual::Log::GetClientLogger()->fatal(__VA_ARGS__)

#else

#define VZ_CORE_ERROR(...)
#define VZ_CORE_WARN(...)
#define VZ_CORE_INFO(...)
#define VZ_CORE_TRACE(...)
#define VZ_CORE_FATAL(...)

#define VZ_ERROR(...)
#define VZ_WARN(...)
#define VZ_INFO(...)
#define VZ_TRACE(...)
#define VZ_FATAL(...)

#endif