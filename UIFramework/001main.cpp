#include <iostream>

#include "Button.h"
#include "Frame.h"

// Only one of them
//#define ENABLE_ORIGINAL_EXAMPLE
#define ENABLE_MORE_EXAMPLE

// Display function usage
#define ENABLE_DISPLAY_FUNC_USAGE

void Display(Widget* pWidget) {
	pWidget->Paint();
}

int main() {
#ifdef ENABLE_ORIGINAL_EXAMPLE
	Frame mainWindow{};
	Button btnOk;
	mainWindow.AddChild(&btnOk);
	mainWindow.Paint();

	//auto p = mainWindow.GetFrame() ;
	//if(p) {
	//	p->AddChild(&btnOk) ;
	//}
	//mainWindow.Paint() ;
	auto parent = btnOk.GetParent();
	parent->Paint();
#endif

#ifdef ENABLE_MORE_EXAMPLE
	Frame mainWindow{};
	Button btnOk;
	mainWindow.AddChild(&btnOk);
	mainWindow.Paint();

	Frame childWindow{};  
	// Frame childWindow = Frame(); // explicit, Most Vexing Parse
	Button btnFind{};
	childWindow.AddChild(&btnFind);

	mainWindow.AddChild(&childWindow);

#ifndef ENABLE_DISPLAY_FUNC_USAGE
	mainWindow.Paint();

	std::cout << "Changing visibility\n";
	mainWindow.SetVisibility(false);
	mainWindow.Paint();
#else
	Display(&btnOk);
#endif
#endif  // ENABLE_MORE_EXAMPLE
}


