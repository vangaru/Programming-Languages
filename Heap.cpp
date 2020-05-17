#include "Heap.h"

void HeapInit(Heap& Heap) {
	Heap.minPath = new int[Heap.MaxSize];
	Heap.CurrentSize = 0;
}

void AddHeapElement(Heap& Heap, int element) {
	int elementPosition, parentPosition, temp;
	elementPosition = Heap.CurrentSize; 
	parentPosition = (elementPosition - 1) / 2; 
	Heap.minPath[elementPosition] = element; 
	while (parentPosition >= 0 && elementPosition > 0) {
		if (Heap.minPath[elementPosition] < Heap.minPath[parentPosition]) { 
			temp = Heap.minPath[elementPosition];
			Heap.minPath[elementPosition] = Heap.minPath[parentPosition];
			Heap.minPath[parentPosition] = temp;
		}
		elementPosition = parentPosition; 
		parentPosition = (elementPosition - 1) / 2; 
	}
	Heap.CurrentSize++; 
}