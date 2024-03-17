/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#include <stdio.h>
#include <stdlib.h>

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {
    *L = (DuLinkedList)malloc(sizeof(DuLNode));
    if (!(*L)) {
        return ERROR;
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) {
    DuLinkedList p = *L;
    while (p) {
        DuLinkedList tmp = p;
        p = p->next;
        free(tmp);
    }
    *L = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
    if (!p || !q) {
        return ERROR;
    }

    //这里没解决头结点前插不了的问题
    //if (!p->prior) {
        // 如果p为头节点，则将头节点的next指针指向q，q的prior指针指向NULL
        //q->next = p;
        //q->prior = NULL;
        //p->prior = q;
    //}
    //else {
        q->prior = p->prior;
        q->next = p;
        if (p->prior) {
            p->prior->next = q;
        }
        p->prior = q;
    //}
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
    //判断是否为空
    if (!p || !q) {
        return ERROR;
    }
    q->prior = p;
    q->next = p->next;
    if (p->next) {
        p->next->prior = q;
    }
    p->next = q;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
    if (!p || !p->next) {
        return ERROR;
    }
    // 在链表中查找指定值的节点
    DuLNode* q = p->next;
    *e = q->data;
    p->next = q->next;
    if (q->next) {
        q->next->prior = p;
    }
    free(q);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList p = L->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
}

/**
 *  @name        : Status InsertFirstList(DuLNode* p, DuLNode* q)
 *	@description : insert a first node
 *	@param		 : p,q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertFirstList(DuLNode* p, DuLNode* q) {
    if (!p || !q) {
        return ERROR;
    }
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
