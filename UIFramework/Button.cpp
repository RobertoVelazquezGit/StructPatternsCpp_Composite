#include "Button.h"

#include <iostream>

void Button::AddChild(Widget* pWidget) {
	throw std::runtime_error{ "Not implemented" };
}

void Button::Paint() {
	if (m_IsVisible)
		std::cout << "[Button] Painting\n";
}

void Button::RemoveChild(Widget* pWidget) {
	throw std::runtime_error{ "Not implemented" };
}

void Button::SetVisibility(bool visibility) {
	std::cout << std::boolalpha;  // stream manipulator
	std::cout << "[Button] Visibility:" << visibility << std::endl;
	m_IsVisible = visibility;
}
