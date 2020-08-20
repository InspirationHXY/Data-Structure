/* List ADT function prototype */

#ifndef _List_H
#define _List_H
#include"const.h"
#include<stdbool.h> 

#define LIST_INIT_SIZE	100 //initial allocation
#define LISTINCREAMENT	10  //increased allocation

/*
 * define Element type HERE
 */

typedef struct{
    ElemType  *elem;	//basic address in memory space
    int	    length;	//current length
    int	    listsize;	//allocated storage capacity
}SqList;

#endif
