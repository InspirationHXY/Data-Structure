/* list.h -- simple linked list type header*/
#ifndef LIST_H_
#define LIST_H_
#include<stdbool.h>	/* C99 property*/

/*specific program statement*/

#define TSIZE	45	/*film name*/
struct film
{
	char title[TSIZE];
	int rating;
};

/*general type define*/

typedef struct film Item;

typedef struct node{
	Item item;
	struct node *next;
}Node;

typedef Node * List;

/*function prototype*/

/*func:			initialize a list			*/
/*precondition:		plist point to a list			*/
/*postcondition:	linked list will be initialize		*/
void InitializeList(List * plist);

/*func:			verify if list is empty, plist point to a initialized list */
/*postcondition:	if list is empty, return true, else return false*/
bool ListIsEmpty(const List *plist);

/*func:			verify if list is full, plist point to a initialized list*/
/*postcondition:	if list is full, return true, else return false*/
bool ListIsFull(const List *plist);

/*func:			verify the item number in the list, plist point to a initialized list*/
/*postcondition:	return the item number in the list*/
unsigned int ListItemCount(const List *plist);

/*func:			add item in the ending of list*/
/*precondition:		item is a element to be added, plist point to initialized list*/
/*postcondition:	if list allow to add, so add a item in the end of the list and return true, else return false*/
bool AddItem(Item item, List *plist);

/*func:			use func to process all item in the list*/
/*			plist point to a initialized list	*/
/*			pfun point to a func, the func receive a Item parameter and non_return_value*/
/*postcondition:	func pfun pointing to process all item onece*/
void Traverse(const List *plist, void (*pfun)(Item item));

/*func:			free allocated memory(if has)*/
/*			plist point to a initialized list*/
/*postcondition:	free all memory allocated to list, list sets to empty */
void EmptyTheList(List *plist);

#endif
