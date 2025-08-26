
#include "Composite.h"
#include "Leaf.h"

#define ENABLE_MORE_THAN_EXAMPLE

int main() {
	Leaf leaf1, leaf2, leaf3;
	Composite root;
	root.Add(&leaf1);
	root.Add(&leaf2);

	Composite subRoot1{}, subRoot2{};
	subRoot1.Add(&leaf1);
	subRoot2.Add(&leaf2);

	root.Add(&subRoot1);

#ifdef ENABLE_MORE_THAN_EXAMPLE
	root.Add(&subRoot2) ;
	Composite subRoot3{};
	subRoot3.Add(&leaf3);
	subRoot1.Add(&subRoot3);
#endif

	root.Operation();
}

