#pragma once
#include "Application.h"

#ifdef VZ_PLATFORM_WINDOWS
extern Vizual::Application* Vizual::CreateApplication();

int main(int argc, char** argv) {
	auto app = Vizual::CreateApplication();
	app->Run();
	delete app;
}
#endif