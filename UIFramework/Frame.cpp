#include "Frame.h"
#include <algorithm>
#include <iostream>
int depth{};
void Frame::AddChild(Widget* pWidget) {
	pWidget->SetParent(this);
	m_Children.push_back(pWidget);
}

void Frame::Paint() {
	if (!m_IsVisible)
		return;
	++depth;
	std::cout << "[Frame] Painting\n";
	for (auto pChild : m_Children) {
		for (int i = 0; i < depth; ++i) {
			std::cout << '\t';
		}
		pChild->Paint();
	}
	--depth;
}

void Frame::RemoveChild(Widget* pWidget) {
	pWidget->SetParent(nullptr);
	m_Children.erase(remove(begin(m_Children), end(m_Children), pWidget), end(m_Children));
}

void Frame::SetVisibility(bool visibility) {
	++depth;
	m_IsVisible = visibility;
	std::cout << "[Frame] Changing visiblity\n";
	for (auto pChild : m_Children) {
		for (int i = 0; i < depth; ++i) {
			std::cout << '\t';
		}
		pChild->SetVisibility(visibility);
	}
	--depth;
}

Frame* Frame::GetFrame() {
	return this;
}

Frame::~Frame(){
	for (auto pChild : m_Children) {
		delete pChild;
		counterDelete++;
		std::cout << "[Frame] counterDelete = " << counterDelete << "\n";
	}
}

int Frame::counterDelete = 0;
