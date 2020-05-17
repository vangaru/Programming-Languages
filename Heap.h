#pragma once

#include <iostream>
#include <iomanip>
#define VERTEX_AMOUNT 10 // количество вершин графа
using namespace std;

struct Heap {
	const int MaxSize = VERTEX_AMOUNT; // максимально возможный размер массива
	int CurrentSize; // текущий размер массива
	int* minPath; // массив, содержащий минимальные пути
};

void HeapInit(Heap&); // Инициализация кучи
void AddHeapElement(Heap&, int); // Добавление в кучу

