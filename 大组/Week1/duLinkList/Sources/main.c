#define _CRT_SECURE_NO_WARNINGS

#include <duLinkedList.h>

void printElement(ElemType e) {
    printf("%d ", e);
}

int main() {
    ElemType a = 0;
    DuLinkedList L = NULL;
    while (1) {
        printf("双链表ADT\n\n");
        printf("1.创建空链表\n");
        printf("2.销毁链表\n");
        printf("3.插入第一个结点\n");
        printf("4.向前插入链表\n");
        printf("5.向后插入链表\n");
        printf("6.删除结点\n");
        printf("7.遍历链表\n");
        printf("8.结束\n");
        scanf("%d", &a);
        switch (a) {
        case 1:
            InitList_DuL(&L);
            printf("创建成功\n\n");
            break;
        case 2:
            DestroyList_DuL(&L);
            printf("已销毁\n\n");
            break;
        case 3:
        {
            ElemType first_data;
            printf("请输入要插入的数据: ");
            scanf("%d", &first_data);
            //插入第一个数据
            DuLNode* newNode = (DuLNode*)malloc(sizeof(DuLNode));
            newNode->data = first_data;
            newNode->next = NULL;
            InsertFirstList(L, newNode);
            printf("插入成功\n");
            break;
        }
        case 4:
            ElemType before_data;
            printf("请输入要在哪个节点之前插入数据: ");//*不能往头结点之前插入，会卡死*
            scanf("%d", &before_data);

            // 在链表中查找指定值的节点
            DuLinkedList p = L->next;
            while (p && p->data != before_data) {
                p = p->next;
            }

            if (p) {
                printf("请输入要插入的数据: ");
                scanf("%d", &before_data);
                DuLNode* before_newNode = (DuLNode*)malloc(sizeof(DuLNode));
                before_newNode->data = before_data;
                before_newNode->next = NULL;
                InsertBeforeList_DuL(p, before_newNode); // 插入指定节点之前
                printf("向前插入成功\n\n");
            }
            else {
                printf("未找到指定节点\n\n");
            }
            break;

        case 5:
            ElemType after_data;
            printf("请输入要在哪个节点之后插入数据: ");
            scanf("%d", &after_data);

            // 在链表中查找指定值的节点
            DuLinkedList q = L->next;
            while (q && q->data != after_data) {
                q = q->next;
            }

            if (q) {
                printf("请输入要插入的数据: ");
                scanf("%d", &after_data);
                DuLNode* after_newNode = (DuLNode*)malloc(sizeof(DuLNode));
                after_newNode->data = after_data;
                after_newNode->next = NULL;
                InsertAfterList_DuL(q, after_newNode); // 插入指定节点之前
                printf("向后插入成功\n\n");
            }
            else {
                printf("未找到指定节点\n\n");
            }
            break;

        case 6:
        {
            ElemType delData;
            printf("请输入要删除的数据: ");
            scanf("%d", &delData);
            Status delStatus = DeleteList_DuL(L, &delData);
            if (delStatus == SUCCESS) {
                printf("删除成功，删除的数据为: %d\n\n", delData);
            }
            else {
                printf("删除失败，未找到数据: %d\n\n", delData);
            }
            break;
        }
        case 7:
            printf("链表元素为: ");
            TraverseList_DuL(L, &printElement);
            printf("\n\n");
            break;
        case 8:
            printf("结束\n");
            exit(0);
        }
    }


    return 0;
}