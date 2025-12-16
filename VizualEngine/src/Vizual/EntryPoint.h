#pragma once
#include "Application.h"
#include "Vizual/Log.h"

#ifdef VZ_PLATFORM_WINDOWS
extern Vizual::Application* Vizual::CreateApplication();

int main(int argc, char** argv) {
	Vizual::Log::Init();

	VZ_CORE_WARN("Yo wasgud");
	VZ_WARN("yo wasgud! Var={0}", 5);

	auto app = Vizual::CreateApplication();
	app->Run();
	delete app;
}
#endif