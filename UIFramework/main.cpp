#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>

#include "Button.h"
#include "Frame.h"

void Display(Widget* pWidget) {
	if (auto pFrame = pWidget->GetFrame(); pFrame != nullptr) {
		pWidget->AddChild(new Button{});
	}
	else {
		std::cout << "Not a frame so cannot add a child\n";
	}

	if (auto parent = pWidget->GetParent(); parent != nullptr) {
		parent->Paint();  // Calls recursively paint on all the children
	}
	else {
		std::cout << "No parent\n";
	}
}

//#define ENABLE_REMOVE_BTNOK

int main() {
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(223); // número de bloque que aparece en el informe de fuga
#endif

	Frame * mainWindow = new Frame{};
	Button* btnOk = new Button{};
	mainWindow->AddChild(btnOk);

#ifdef ENABLE_REMOVE_BTNOK
	mainWindow->RemoveChild(btnOk);
#endif

	Frame * childWindow = new Frame{};  
	Button * btnFind = new Button{};
	childWindow->AddChild(btnFind);

	mainWindow->AddChild(childWindow);

	std::cout << "Operating on button\n";
	Display(btnOk);
	std::cout << "Operating on frame\n";
	Display(mainWindow);

#ifdef ENABLE_REMOVE_BTNOK
	delete btnOk;
#endif

	delete mainWindow;

	//int* ptr = new int[10]; // <-- fuga, no se libera
}


