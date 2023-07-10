#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/*
* Structure d'une pile
*/
struct Stack {
	int val;
	int size;
	struct Stack* prev;
};
typedef struct Stack Stack;

/*
* Stack *stack_create
* Parametre :
* Return Stack * : nouvelle pile vide
* 
* Cree une nouvelle pile vide
*/
Stack* stack_create();

/*
* bool stack_empty
* Parametre :
*	- Stack *s : pile dont on veut savoir si elle est vide
* Return bool : True si la pile est vide, false sinon
* 
* Teste si la pile est vide
*/
bool stack_empty(Stack* s);

/*
* Stack *stack_add
* Parametres :
*	- Stack *s : Pile ou il faut ajouter l'element
*	- int val : valeur a ajouter
* Return Stack *s : nouvelle pile
* 
* Ajoute un element dans la pile
*/
Stack* stack_add(Stack* s, int val);

/*
* Stack *stack_pop
* Parametre :
*	- Stack *s : pile ou il faut enlever l'element
* Return Stack * : Nouvelle pile
* 
* Supprime l'element au dessus de la pile
*/
Stack* stack_pop(Stack* s);

/*
* int stack_peek
* Parametre :
*	- Stack *s : pile dont on veut connaitre l'element
* Return int : element en au de la pile
* 
* Renvoie l'element en haut de la pile sans le supprimer
*/
int stack_peek(Stack* s);

#endif