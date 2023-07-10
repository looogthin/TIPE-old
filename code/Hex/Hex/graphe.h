#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <stdbool.h>

enum CONNECTION { NONE, SEMI, VIRTUAL, REAL };

struct Point {
	int x;
	int y;
};
typedef struct Point Point;

struct Edge {
	Point a;
	Point b;
	enum CONNECTION connection;
};
typedef struct Edge Edge;

struct Graphe {
	Edge* list_edges;
	int nb_edges;
	int max_edges;
};
typedef struct Graphe Graphe;

/*
* Graphe *graphe_create
* Parametre :
* Return Graphe * : le nouveau graphe vide
* 
* Cree un nouveau graphe vide
*/
Graphe* graphe_create();

/*
* graphe_free
* Parametre :
*	- Graphe *g : graphe a supprimmer
* Return void
* 
* supprime le graphe
*/
void graphe_free(Graphe* g);

/*
* bool add_edge
* Parametres :
*	- Graphe *g : graphe dans lequel l'arete doit etre ajoute
*	- Edge e : arete a ajouter dans le graphe
* Return bool : true si l'arete a pu etre ajoute, false si il y a eu un probleme
* 
* Ajoute une arete dans le graphe
*/
bool add_edge(Graphe* g, Edge e);

/*
* 
*/
bool delete_edge(Graphe* g, Edge e);

#endif