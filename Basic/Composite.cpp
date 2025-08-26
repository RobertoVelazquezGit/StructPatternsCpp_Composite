#include "Composite.h"
#include <iostream>

int depth{};

void Composite::Add(Component* pComponent) {
	m_Components.push_back(pComponent);
}

Component* Composite::GetChild(int index) {
	return m_Components[index];
}

void Composite::Operation() {
	std::cout << "[Composite] Operation" << std::endl;
	++depth;
	for (auto pComp : m_Components) {
		for (int i = 0; i < depth; ++i) {
			std::cout << ' ';
		}
		std::cout << "|-";
		pComp->Operation();  // If a Composite again and ++depth
	}
	--depth;

}

void Composite::Remove(Component* pComponent) {
	//auto newend = std::remove(begin(m_Components), end(m_Components), pComponent) ;
	//m_Components.erase(newend, end(m_Components)) ;

	// Erase remove idiom
	m_Components.erase(std::remove(m_Components.begin(), m_Components.end(), pComponent), m_Components.end());
}
