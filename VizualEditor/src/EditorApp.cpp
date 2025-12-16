#include "pch.h"
#include <Vizual.h>

class EditorApp : public Vizual::Application {
public:
	EditorApp() {

	}

	~EditorApp() {

	}
};

Vizual::Application* Vizual::CreateApplication() {
	return new EditorApp();
}