#define _CRT_SECURE_NO_WARNINGS

#include <linkedList.h>

void printElement(ElemType e) {
    printf("%d ", e); 
}

int main() {
    ElemType a=0;
    LinkedList L=NULL;
    while (1) {
    printf("������ADT\n\n");
    printf("1.����������\n");
    printf("2.��������\n");
    printf("3.��������\n");
    printf("4.ɾ�����\n");
    printf("5.��������\n");
    printf("6.��������\n");
    printf("7.��ת����\n");
    printf("8.�ж������Ƿ�ɻ�\n");
    printf("9.��ת����ż�����\n");
    printf("10.�����м���\n");
    printf("11.����\n");
    scanf("%d", &a);
    switch (a) {
        case 1:
            InitList(&L);
            printf("�����ɹ�\n\n");
            break;
        case 2:
            DestroyList(&L);
            printf("������\n\n");
            break;
        case 3:
            ElemType data;
            printf("������Ҫ���������: ");
            scanf("%d", &data);
            LNode* newNode = (LNode*)malloc(sizeof(LNode));
            newNode->data = data;
            newNode->next = NULL;
            InsertList(L, newNode);
            printf("����ɹ�\n\n");
            break;
        case 4:
        {
            ElemType delData;
            printf("������Ҫɾ��������: ");
            scanf("%d", &delData);
            Status delStatus = DeleteList(L, &delData);
            if (delStatus == SUCCESS) {
                printf("ɾ���ɹ���ɾ��������Ϊ: %d\n\n", delData);
            }
            else {
                printf("ɾ��ʧ�ܣ�δ�ҵ�����: %d\n\n", delData);
            }
            break;
        }
        case 5:
            printf("����Ԫ��Ϊ: ");
            TraverseList(L, &printElement); 
            printf("\n\n");
            break;
        case 6:
        {
            ElemType searchData;
            printf("������Ҫ���ҵ�����: ");
            scanf("%d", &searchData);
            Status searchStatus = SearchList(L, searchData);//�Ƿ��ҵ�
            if (searchStatus == SUCCESS) {
                printf("�ҵ�����: %d\n\n", searchData);
            }
            else {
                printf("δ�ҵ�����: %d\n\n", searchData);
            }
            break;
        }
        case 7:
        {
            Status reverseStatus = ReverseList(&L);//��ת�Ƿ�ɹ�
            if (reverseStatus == SUCCESS) {
                printf("�����ѷ�ת\n\n");
            }
            else {
                printf("����תʧ��\n\n");
            }
            break;
        }
        case 8:
        {
            Status loopStatus = IsLoopList(L);//�Ƿ�ɻ�
            if (loopStatus == SUCCESS) {
                printf("����ɻ�\n\n");
            }
            else {
                printf("�����ɻ�\n\n");
            }
            break;
        }
        case 9:
        {
            LNode* newHead = ReverseEvenList(&L);
            printf("ż���ڵ��ѷ�ת\n\n");
            break;
        }
        case 10:
        {
            LNode* midNode = FindMidNode(&L);
            printf("�м�ڵ��ֵΪ: %d\n\n", midNode->data);
            break;
        }
        case 11:
            printf("����\n");
            exit(0);
        }
    }

    
    return 0;
}