/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**************************************************************
 *    Struct Define Section
 **************************************************************/
//链式队列结构
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;					
char datatype[30];			

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
    Q->front = Q->rear = (Node*)malloc(sizeof(Node));
    if (!Q->front) {
        exit(EXIT_FAILURE);
    }
    Q->front->next = NULL;
    Q->length = 0; // 初始化队列长度为0
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
        Q->length = 0; // 队列长度置零
    }
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
    return Q->front == Q->rear ? TRUE : FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
    if (Q->front == Q->rear) {
        return FALSE;
    }
    Node* p = Q->front->next;
    e = p->data; // 将队头元素的数据赋值给e
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data, size_t dataSize) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return FALSE;
    }

    // 为数据分配独立的内存空间，并将数据复制到这个空间中
    newNode->data = malloc(dataSize);
    if (!newNode->data) {
        free(newNode);
        return FALSE;
    }
    memcpy(newNode->data, data, dataSize);

    newNode->next = NULL;
    Q->rear->next = newNode;
    Q->rear = newNode;
    Q->length++; // 队列长度加1
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
    if (Q->front == Q->rear) {
        return FALSE;
    }
    Node* p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);
    Q->length--; // 队列长度减1
    return TRUE;
}


/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
    Node* p = Q->front->next;
    while (p) {
        Q->front->next = p->next;
        free(p);
        p = Q->front->next;
    }
    Q->rear = Q->front;
    Q->length = 0; // 队列长度置零
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    Node* p = Q->front->next;
    while (p) {
        foo(p->data);
        p = p->next;
    }
    return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void* q) {
    printf("%p\n", q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


