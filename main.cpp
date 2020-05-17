#include "Dijkstra.h"

int main() {
	Heap heap;
	HeapInit(heap);

	int adjencyMatrix[VERTEX_AMOUNT][VERTEX_AMOUNT];
	int minPath[VERTEX_AMOUNT];
	bool visitedVertexStatus[VERTEX_AMOUNT];
	int beginIndex = 0;
	int minIndex = 0;
	int minVertexPath = 0;
	int path = 0;

	adjencyMatrixInit(adjencyMatrix, path);
	adjencyMatrixOutput(adjencyMatrix);
	PathAndVertexInit(heap, visitedVertexStatus);
	showMinimalWays(adjencyMatrix, heap, visitedVertexStatus, minIndex, minVertexPath, path, beginIndex);
	return 0;
}