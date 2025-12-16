#pragma once
#include "Core.h"

namespace Vizual {
	class VZ_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in the client
	Application* CreateApplication();
}