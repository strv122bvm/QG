#define _CRT_SECURE_NO_WARNINGS
#include <LinkStack.h>

int main() {
    int a;
    ElemType data;
    LinkStack Q;
    Status status;
    initLStack(&Q);

    while (1) {
        printf("1.��ʼ��ջ\n");
        printf("2.�ж�ջ�Ƿ�Ϊ��\n");
        printf("3.�õ�ջ��Ԫ��\n");
        printf("4.���ջ\n");
        printf("5.����ջ\n");
        printf("6.���ջ����\n");
        printf("7.��ջ\n");
        printf("8.��ջ\n");
        printf("0.�˳�\n");
        printf("Enter your choice: ");
        scanf("%d", &a);

        switch (a) {
        case 1:
            status = initLStack(&Q);
            if (status == SUCCESS)
                printf("ջ�ѳ�ʼ��\n");
            else
                printf("��ʼ��ջʧ��\n");
            break;
        case 2:
            status = isEmptyLStack(&Q);
            if (status == SUCCESS)
                printf("ջΪ��\n");
            else
                printf("ջ��Ϊ��\n");
            break;
        case 3:
            status = getTopLStack(&Q, &data);
            if (status == SUCCESS)
                printf("ջ��Ԫ��Ϊ: %d\n", data);
            else
                printf("��ȡջ��Ԫ��ʧ�ܣ�ջΪ��\n");
            break;
        case 4:
            status = clearLStack(&Q);
            if (status == SUCCESS)
                printf("ջ�����\n");
            else
                printf("���ջʧ��\n");
            break;
        case 5:
            status = destroyLStack(&Q);
            if (status == SUCCESS)
                printf("ջ������\n");
            else
                printf("����ջʧ��\n");
            break;
        case 6:
            status = LStackLength(&Q, &data);
            if (status == SUCCESS)
                printf("ջ����Ϊ: %d\n", data);
            else
                printf("��ȡջ����ʧ��\n");
            break;
        case 7:
            printf("������Ҫ��ջ��Ԫ��: ");
            scanf("%d", &data);
            status = pushLStack(&Q, data);
            if (status == SUCCESS)
                printf("Ԫ�� %d ��ջ�ɹ�\n", data);
            else
                printf("��ջʧ��\n");
            break;
        case 8:
            status = popLStack(&Q, &data);
            if (status == SUCCESS)
                printf("Ԫ�� %d ��ջ�ɹ�\n", data);
            else
                printf("��ջʧ�ܣ�ջΪ��\n");
            break;
        case 0:
            printf("�����˳�\n");
            return 0;
        default:
            printf("��������Ч��ѡ��\n");
            break;
        }
    }

    return 0;
}