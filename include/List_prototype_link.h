#ifndef _List_Prototype_LINK_H
#define _List_Prototype_LINK_H
#include<const.h>

/*
 * define the data tyep Here **
 */
typedef int ElemType; 

typedef struct LNode{	    //Node type
    ElemType	    data;
    struct LNode    *next;
}LNode, *Link, *Position;

typedef struct{		    //List type
    Link head, tail;	    //point to the head node and the last node
    int	 len;		    //the length of linked list
}LinkList;

//allocate node pointed to by p and initialize data with e
Status MakeNode(Link *p, const ElemType e);

//free node pointed to by p
void FreeNode(Link p);

//Initialize a linked list
Status InitList(LinkList *);

//Clear a list
Status ClearList(LinkList *);

//insert a node pointed to by s before the first node
Status InsFirst(LinkList *, Link s);

//Delete the first node and save it in q
Status DelFirst(LinkList *, Link *q);

//Append s to the end of L and change the L'tail pointer
Status Append(LinkList *, const Link s);

//Delete the last node in List and return it by q, update the tail pointer in List
Status Remove(LinkList *, Link *q);

//p point to a node in List, insert s before q, update q to point to the new node.
Status InsBefore(LinkList *, Link *p, Link s);

//p point to a node in List, insert s after q, update q to point to the new node.
Status InsAfter(LinkList *, Link *p, Link s);

//Update the data field of the node pointed to by p with e
Status SetCurElem(Link p, const ElemType e);

//Get the elem of the node pointed to by p
ElemType GetCurElem(const Link p);

//if List empty return TRUE, if not return FALSE
Status ListEmpty(const LinkList *);

//Get the length of List
int ListLength(const LinkList *);

//Get the position of the head node
Position GetHead(const LinkList *);

//Get the position fo the last node
Position GetLast(const LinkList *);

//p point to a node in the List, return the previous node position of the node pointed to by p
//if not return NULL
Position PriorPos(const LinkList *, const Link p);

//p point to a node in the List , return the next node position of the node pointed to by p
//if not return NULL
Position NextPos(const LinkList *, const Link p);

//return the postion of i_th with p
Status LocatePos(const LinkList *, int i, Link *p);

//return the first position of elem satisfied with e in the compare()
//if not return NULL
Position LocateElem(const LinkList *, const ElemType e, int (*compare)(ElemType, ElemType));

//Call visit() func for each elem in order, if order fails, return ERROR
Status ListTraverse(const LinkList *, Status (*visit)(ElemType e));


/*
 * Orderly List prototype
 */

/* 
 * if orderly list exists a element that satisfies the result that is 0 
 * when executing compare() func with e, q indicates the postion of the elem,
 * and return TRUE. else, q indicates the position where the elem is the last one
 * that satisfies the result that is less than 0 when executing compare() func, return FALSE.
 */
Status OrderLocateElem(const LinkList *Lp, ElemType e, Position *q, 
			int (*compare)(ElemType, ElemType));

/*
 * In terms of tested result of compare() func, Inserting e into proper position 
 * of orderly list.
 */
Status OrderInsert(LinkList *Lp, ElemType e, int (*compare)(ElemType, ElemType));



/*
 * ** General Application **
 * 
 * Inserting element e before the i_th elem in the linklist with head node
 */
Status ListInsert(LinkList *Lp, int i, ElemType e);

/*
 * Deleting the i_the elem in the linklist with head node
 * and save it in q
 */
Status ListDelete(LinkList *Lp, int i, Link *q);
#endif
