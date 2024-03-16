#define _CRT_SECURE_NO_WARNINGS

#include <linkedList.h>

void printElement(ElemType e) {
    printf("%d ", e); 
}

int main() {
    ElemType a=0;
    LinkedList L=NULL;
    while (1) {
    printf("单链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.插入链表\n");
    printf("4.删除结点\n");
    printf("5.遍历链表\n");
    printf("6.查找数据\n");
    printf("7.反转链表\n");
    printf("8.判断链表是否成环\n");
    printf("9.反转链表偶数结点\n");
    printf("10.查找中间结点\n");
    printf("11.结束\n");
    scanf("%d", &a);
    switch (a) {
        case 1:
            InitList(&L);
            printf("创建成功\n\n");
            break;
        case 2:
            DestroyList(&L);
            printf("已销毁\n\n");
            break;
        case 3:
            ElemType data;
            printf("请输入要插入的数据: ");
            scanf("%d", &data);
            LNode* newNode = (LNode*)malloc(sizeof(LNode));
            newNode->data = data;
            newNode->next = NULL;
            InsertList(L, newNode);
            printf("插入成功\n\n");
            break;
        case 4:
        {
            ElemType delData;
            printf("请输入要删除的数据: ");
            scanf("%d", &delData);
            Status delStatus = DeleteList(L, &delData);
            if (delStatus == SUCCESS) {
                printf("删除成功，删除的数据为: %d\n\n", delData);
            }
            else {
                printf("删除失败，未找到数据: %d\n\n", delData);
            }
            break;
        }
        case 5:
            printf("链表元素为: ");
            TraverseList(L, &printElement); 
            printf("\n\n");
            break;
        case 6:
        {
            ElemType searchData;
            printf("请输入要查找的数据: ");
            scanf("%d", &searchData);
            Status searchStatus = SearchList(L, searchData);//是否找到
            if (searchStatus == SUCCESS) {
                printf("找到数据: %d\n\n", searchData);
            }
            else {
                printf("未找到数据: %d\n\n", searchData);
            }
            break;
        }
        case 7:
        {
            Status reverseStatus = ReverseList(&L);//反转是否成功
            if (reverseStatus == SUCCESS) {
                printf("链表已反转\n\n");
            }
            else {
                printf("链表反转失败\n\n");
            }
            break;
        }
        case 8:
        {
            Status loopStatus = IsLoopList(L);//是否成环
            if (loopStatus == SUCCESS) {
                printf("链表成环\n\n");
            }
            else {
                printf("链表不成环\n\n");
            }
            break;
        }
        case 9:
        {
            LNode* newHead = ReverseEvenList(&L);
            printf("偶数节点已反转\n\n");
            break;
        }
        case 10:
        {
            LNode* midNode = FindMidNode(&L);
            printf("中间节点的值为: %d\n\n", midNode->data);
            break;
        }
        case 11:
            printf("结束\n");
            exit(0);
        }
    }

    
    return 0;
}