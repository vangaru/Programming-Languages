#include "Dijkstra.h"

void adjencyMatrixInit(int adjencyMatrix[][VERTEX_AMOUNT], int path) {
	for (int i = 0; i < VERTEX_AMOUNT; i++) {
		adjencyMatrix[i][i] = 0;
		for (int k = i + 1; k < VERTEX_AMOUNT; k++) {
			cout << "Enter way " << i + 1 << " - " << k + 1 << " >>> ";
			cin >> path;
			adjencyMatrix[i][k] = adjencyMatrix[k][i] = path;
		}
	}
}

void adjencyMatrixOutput(int adjencyMatrix[][VERTEX_AMOUNT]) {
	cout << endl << "Adjency matrix:" << endl;
	for (int i = 0; i < VERTEX_AMOUNT; i++) {
		for (int k = 0; k < VERTEX_AMOUNT; k++)
			cout << setw(3) << left << adjencyMatrix[i][k] << " ";
		cout << endl;
	}
}

void PathAndVertexInit(Heap& Heap, bool visitedVertexStatus[]) {
	for (int i = 0; i < VERTEX_AMOUNT; i++) {
		AddHeapElement(Heap, 10000);
		visitedVertexStatus[i] = 1;
	}
}

void showMinimalWays(int adjencyMatrix[][VERTEX_AMOUNT], Heap& Heap, bool visitedVertexStatus[], int minIndex, int minVertexPath, int path, int beginIndex) {
	cout << endl << "Enter vertex to find minimal pathes >>> ";
	cin >> beginIndex;
	beginIndex--;
	Heap.minPath[beginIndex] = 0;
	do {
		minVertexPath = minIndex = 10000; 
		for (int i = 0; i < VERTEX_AMOUNT; i++) {
			if (visitedVertexStatus[i] && Heap.minPath[i] < minVertexPath) { 
				minVertexPath = Heap.minPath[i]; 
				minIndex = i; 
			}
		}

		if (minIndex != 10000) {
			for (int i = 0; i < VERTEX_AMOUNT; i++) {
				if (adjencyMatrix[minIndex][i] > 0) { 
					path = minVertexPath + adjencyMatrix[minIndex][i]; 
					if (path < Heap.minPath[i]) Heap.minPath[i] = path; 
				}
			}
			visitedVertexStatus[minIndex] = 0; 
		}
	} while (minIndex < 10000);

	cout << endl << "Minimal Ways:" << endl;
	for (int i = 0; i < VERTEX_AMOUNT; i++)
		cout << beginIndex + 1 << " - " << i + 1 << ": " << Heap.minPath[i] << endl;
}
