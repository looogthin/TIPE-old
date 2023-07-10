#include "graphe.h"

Graphe* graphe_create() {
	Graphe* g = malloc(sizeof(Graphe));
	if (g == NULL)
		return NULL;
	g->nb_edges = 0;
	g->max_edges = 100;
	g->list_edges = malloc(g->max_edges * sizeof(Edge));
	if (g->list_edges == NULL) {
		free(g);
		return NULL;
	}
	return g;
}

void graphe_free(Graphe* g) {
	if (g == NULL)
		return;
	free(g->list_edges);
	free(g);
}

bool add_edge(Graphe* g, Edge e) {
	if (g == NULL)
		return;
	g->nb_edges++;
	if (g->nb_edges > g->max_edges) {
		g->max_edges += 100;
		Edge *tmp = realloc(g->list_edges, g->max_edges * sizeof(Edge));
		if (tmp == NULL)
			return false;
		g->list_edges = tmp;
	}
	g->list_edges[g->nb_edges - 1] = e;
	return true;
}


