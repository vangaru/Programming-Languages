#pragma once

#include "Heap.h"

void adjencyMatrixInit(int[][VERTEX_AMOUNT], int); 
void adjencyMatrixOutput(int[][VERTEX_AMOUNT]); 
void PathAndVertexInit(Heap&, bool[]); 
void showMinimalWays(int[][VERTEX_AMOUNT], Heap&, bool[], int, int, int, int); 
