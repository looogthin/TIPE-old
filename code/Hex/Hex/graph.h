#ifndef GRAPH_H
#define GRAPH_H

typedef enum { NO, SEMI, VIRTUAL, REAL } LINK;

/*
* Structure d'un graph
*/
struct Graph {
	LINK** mat;
	int size;
};
typedef struct Graph Graph;

/*
* Structure d'une arete
*/
struct Edge {
	int a;
	int b;
	LINK link;
};
typedef struct Edge Edge;

/*
* Structure d'un tableau d'aretes
*/
struct ListEdges {
	Edge* list;
	int nb;
};
typedef struct ListEdges ListEdges;

/*
* Graph graph_create
* Parametre :
*	- int size : taille du graph a creer
* Return Graph : nouveau graph
* 
* Cree un nouveau graph
*/
Graph graph_create(int size);

/*
* void graph_modify
* Parametres :
*	- Graph g : graph a modifier
*	- int a : 1er sommet de l'arete a modifier
*	- int b : 2e sommet de l'arete a modifier
*	- LINK val : type de liens entre les sommets
* 
* Modifie une arete du graph
*/
void graph_modify(Graph g, int a, int b, LINK val);

/*
* ListEdges graph_touch
* Parametres :
*	- Graph g : graph qui contient le sommet
*	- int a : sommet dont on veut connaitre les voisins
* Return ListEdges : liste des aretes
* 
* Renvoie la liste des aretes qui conduisent a des sommets
*/
ListEdges graph_touch(Graph g, int a);

#endif