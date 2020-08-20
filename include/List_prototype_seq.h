#ifndef _List_Proto_SEQ_H
#define _List_Proto_SEQ_H

/* List ADT function prototype */
#include<const.h>
#include<stdbool.h> 

#define LIST_INIT_SIZE	100 //initial allocation
#define LISTINCREAMENT	10  //increased allocation

/*
 * define Element type HERE
 */
typedef int ElemType;

typedef struct{
    ElemType  *elem;	//basic address in memory space
    int	    length;	//current length
    int	    listsize;	//allocated storage capacity
}SqList;

typedef SqList List;

/* Function's Prototype */

//postcond: Creat an empty List
Status InistList(List *);

/*
 * precond: List already exists
 * postcond: destroy List
 */
Status DestroyList(List *);

/*
 * precond: List already exists
 * postcond: reset List to empty
 */
void ClearList(List *);

/*
 * precond: List already exists
 * postcond: if L is empty return true, else return false
 */
bool ListEmpty(List *);

/*
 * precond: List already exists
 * postcond: return elem quantity in list
 */
int ListLength(List *);

/*
 * precond: List already exists, 1<=i<=ListLength(L)
 * postcond: return i_th value in the space of e
 */
Status GetElem(List *, int i, ElemType *);

/*
 * precond: List already exists, compare() is used to judge
 * postcond: return the first elem position satisfied  in compare() func, if not return 0
 */
Status LocateElem(List *, ElemType, int (*compare)(ElemType, ElemType));

/*
 * precond: List already exists, 1<=i<=ListLength(L)+1
 * postcond: insert i before the i_th elem position in List, Length adds 1
 */
Status ListInsert(List *, int i, ElemType);

/*
 * precond: List already exists and not empty, 1<=i<=Length(L)
 * postcond: delete the i_th elem in List, return the elem value, Length substracts 1
 */
Status ListDelete(List *, int i, ElemType *);

/*
 * precond: List already exsits 
 * postcond: call visit() func for each elem in the List, if error, return 0
 */
Status ListTraverse(List *, int(*visit)(ElemType));

#endif
