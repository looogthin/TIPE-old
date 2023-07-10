#include "graph.h"
#include "stack.h"
#include <stdlib.h>

Graph graph_create(int size) {
	Graph g;
	g.mat = malloc(size * sizeof(int*));
	if (g.mat == NULL)
		return g;
	for (int i = 0; i < size; i++) {
		int* x = malloc(size * sizeof(int));
		if (x == NULL) {
			free(g.mat);
			g.mat = NULL;
			return g;
		}
		for (int j = 0; j < size; j++)
			x[j] = 0;
		g.mat[i] = x;
	}
	return g;
}

void graph_modify(Graph g, int a, int b, LINK val) {
	g.mat[a][b] = val;
	g.mat[b][a] = val;
}

ListEdges graph_touch(Graph g, int a) {
	Stack* s = stack_create();
	for (int i = 0; i < g.size; i++) {
		if (g.mat[i] > 0)
			s = stack_push(s, i);
	}
	ListEdges l = { malloc(s->size * sizeof(Edge)), s->size };
	while (s != NULL) {
		Edge e = { a, stack_peek(s), REAL };
		l.list[s->size - 1] = e;
		s = stack_pop(s);
	}
	return l;
}