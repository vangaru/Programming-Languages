#pragma once

#include <iostream>
#include <iomanip>
#define VERTEX_AMOUNT 10 
using namespace std;

struct Heap {
	const int MaxSize = VERTEX_AMOUNT; 
	int CurrentSize; 
	int* minPath; 
};

void HeapInit(Heap&); 
void AddHeapElement(Heap&, int); 

