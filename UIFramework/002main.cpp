#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>

#include "Button.h"
#include "Frame.h"

void Display(Widget* pWidget) {
	pWidget->Paint();
	auto pFrame = pWidget->GetFrame();
	if (pFrame) {
		pWidget->AddChild(new Button{});
	}
	else {
		std::cout << "Cannot add a child\n";
	}
}

#define ENABLE_DISPLAY_FUNCTION_USAGE

int main() {
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(223); // número de bloque que aparece en el informe de fuga
#endif

	Frame * mainWindow = new Frame{};
	Button* btnOk = new Button{};
	mainWindow->AddChild(btnOk);
	mainWindow->Paint();

	Frame * childWindow = new Frame{};  
	Button * btnFind = new Button{};
	childWindow->AddChild(btnFind);

	mainWindow->AddChild(childWindow);

#ifndef ENABLE_DISPLAY_FUNCTION_USAGE
	mainWindow->Paint();

	std::cout << "Changing visibility\n";
	mainWindow->SetVisibility(false);
	mainWindow->Paint();
#else
	Display(btnOk);
	Display(mainWindow);
#endif

	delete mainWindow;

	//int* ptr = new int[10]; // <-- fuga, no se libera
}


