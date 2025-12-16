workspace "Vizual"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "VizualEngine"
	location "VizualEngine"
	kind "sharedlib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
	}

	includedirs 
	{
		"%{prj.name}/vendor/"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"VZ_PLATFORM_WINDOWS",
			"VZ_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{MKDIR} ../bin/" .. outputdir .. "/VizualEditor"),
			("{MKDIR} ../bin/" .. outputdir .. "/VizualEngine"),

			-- Copy engine lib to editor bin
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/VizualEditor")
		}

	filter "configurations:Debug"
		defines "VZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VZ_DIST"
		optimize "On"

project "VizualEditor"
	location "VizualEditor"
	kind "ConsoleApp"
		language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/",
		"VizualEngine/src"
	}

	links 
	{
		"VizualEngine"
	}

    dependson
    {
        "VizualEngine"
    }
	
	postbuildcommands 
	{
		"{COPY} ../bin/" .. outputdir .. "/VizualEngine/VizualEngine.dll \"../bin/" .. outputdir .. "/VizualEditor/\""
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"VZ_PLATFORM_WINDOWS",
			"VZ_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "VZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VZ_DIST"
		optimize "On"