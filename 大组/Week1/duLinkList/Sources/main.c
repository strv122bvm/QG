#define _CRT_SECURE_NO_WARNINGS

#include <duLinkedList.h>

void printElement(ElemType e) {
    printf("%d ", e);
}

int main() {
    ElemType a = 0;
    DuLinkedList L = NULL;
    while (1) {
        printf("˫����ADT\n\n");
        printf("1.����������\n");
        printf("2.��������\n");
        printf("3.�����һ�����\n");
        printf("4.��ǰ��������\n");
        printf("5.����������\n");
        printf("6.ɾ�����\n");
        printf("7.��������\n");
        printf("8.����\n");
        scanf("%d", &a);
        switch (a) {
        case 1:
            InitList_DuL(&L);
            printf("�����ɹ�\n\n");
            break;
        case 2:
            DestroyList_DuL(&L);
            printf("������\n\n");
            break;
        case 3:
        {
            ElemType first_data;
            printf("������Ҫ���������: ");
            scanf("%d", &first_data);
            //�����һ������
            DuLNode* newNode = (DuLNode*)malloc(sizeof(DuLNode));
            newNode->data = first_data;
            newNode->next = NULL;
            InsertFirstList(L, newNode);
            printf("����ɹ�\n");
            break;
        }
        case 4:
            ElemType before_data;
            printf("������Ҫ���ĸ��ڵ�֮ǰ��������: ");//*������ͷ���֮ǰ���룬�Ῠ��*
            scanf("%d", &before_data);

            // �������в���ָ��ֵ�Ľڵ�
            DuLinkedList p = L->next;
            while (p && p->data != before_data) {
                p = p->next;
            }

            if (p) {
                printf("������Ҫ���������: ");
                scanf("%d", &before_data);
                DuLNode* before_newNode = (DuLNode*)malloc(sizeof(DuLNode));
                before_newNode->data = before_data;
                before_newNode->next = NULL;
                InsertBeforeList_DuL(p, before_newNode); // ����ָ���ڵ�֮ǰ
                printf("��ǰ����ɹ�\n\n");
            }
            else {
                printf("δ�ҵ�ָ���ڵ�\n\n");
            }
            break;

        case 5:
            ElemType after_data;
            printf("������Ҫ���ĸ��ڵ�֮���������: ");
            scanf("%d", &after_data);

            // �������в���ָ��ֵ�Ľڵ�
            DuLinkedList q = L->next;
            while (q && q->data != after_data) {
                q = q->next;
            }

            if (q) {
                printf("������Ҫ���������: ");
                scanf("%d", &after_data);
                DuLNode* after_newNode = (DuLNode*)malloc(sizeof(DuLNode));
                after_newNode->data = after_data;
                after_newNode->next = NULL;
                InsertAfterList_DuL(q, after_newNode); // ����ָ���ڵ�֮ǰ
                printf("������ɹ�\n\n");
            }
            else {
                printf("δ�ҵ�ָ���ڵ�\n\n");
            }
            break;

        case 6:
        {
            ElemType delData;
            printf("������Ҫɾ��������: ");
            scanf("%d", &delData);
            Status delStatus = DeleteList_DuL(L, &delData);
            if (delStatus == SUCCESS) {
                printf("ɾ���ɹ���ɾ��������Ϊ: %d\n\n", delData);
            }
            else {
                printf("ɾ��ʧ�ܣ�δ�ҵ�����: %d\n\n", delData);
            }
            break;
        }
        case 7:
            printf("����Ԫ��Ϊ: ");
            TraverseList_DuL(L, &printElement);
            printf("\n\n");
            break;
        case 8:
            printf("����\n");
            exit(0);
        }
    }


    return 0;
}