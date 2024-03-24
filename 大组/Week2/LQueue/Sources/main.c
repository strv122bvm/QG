#define _CRT_SECURE_NO_WARNINGS
#include <LQueue.h>
typedef int ElementType;

// ��ӡ����Ԫ�صĲ�������
void PrintElement(void* q) {
    printf("%d ", *((ElementType*)q));
}

int main() {
    int a;
    LQueue Q;
    ElementType element;

    while (1) {
        printf("1.��ʼ������\n");
        printf("2.���ٶ���\n");
        printf("3.�������Ƿ�Ϊ��\n");
        printf("4.�鿴��ͷԪ��\n");
        printf("5.ȷ�����г���\n");
        printf("6.��Ӳ���\n");
        printf("7.���Ӳ���\n");
        printf("8.��ն���\n");
        printf("9.��������Ԫ��\n");
        printf("0.�˳�\n");
        printf("Enter your choice: ");
        scanf("%d", &a);

        switch (a) {
        case 1:
            InitLQueue(&Q);
            printf("�����ѳ�ʼ��\n");
            break;
        case 2:
            DestoryLQueue(&Q);
            printf("����������\n");
            break;
        case 3:
            printf(IsEmptyLQueue(&Q) ? "����Ϊ��\n" : "���зǿ�\n");
            break;
        case 4:
            if (!IsEmptyLQueue(&Q)) {
                if (GetHeadLQueue(&Q, &element)) {
                    printf("��ͷԪ��Ϊ��%d\n", element);
                }
                else {
                    printf("��ȡ��ͷԪ��ʧ��\n");
                }
            }
            else {
                printf("����Ϊ��\n");
            }
            break;
        case 5:
            printf("���г���Ϊ��%d\n", LengthLQueue(&Q));
            break;
        case 6:
            printf("������Ҫ��ӵ�Ԫ��ֵ��");
            scanf("%d", &element);
            if (EnLQueue(&Q, &element, sizeof(int))) {
                printf("Ԫ�� %d ��ӳɹ�\n", element);
            }
            else {
                printf("���ʧ��\n");
            }
            break;
        case 7:
            if (DeLQueue(&Q)) {
                printf("���ӳɹ�\n");
            }
            else {
                printf("����Ϊ�գ��޷�����\n");
            }
            break;
        case 8:
            ClearLQueue(&Q);
            printf("���������\n");
            break;
        case 9:
            printf("����Ԫ��Ϊ��");
            TraverseLQueue(&Q, PrintElement);
            printf("\n");
            break;
        case 0:
            printf("�����˳�\n");
            exit(0);
        default:
            printf("��Чѡ������������\n");
            break;
        }
    }

    return 0;
}