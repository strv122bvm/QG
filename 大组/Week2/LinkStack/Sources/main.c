#define _CRT_SECURE_NO_WARNINGS
#include <LinkStack.h>

int main() {
    int a;
    ElemType data;
    LinkStack Q;
    Status status;
    initLStack(&Q);

    while (1) {
        printf("1.初始化栈\n");
        printf("2.判断栈是否为空\n");
        printf("3.得到栈顶元素\n");
        printf("4.清空栈\n");
        printf("5.销毁栈\n");
        printf("6.检测栈长度\n");
        printf("7.入栈\n");
        printf("8.出栈\n");
        printf("0.退出\n");
        printf("Enter your choice: ");
        scanf("%d", &a);

        switch (a) {
        case 1:
            status = initLStack(&Q);
            if (status == SUCCESS)
                printf("栈已初始化\n");
            else
                printf("初始化栈失败\n");
            break;
        case 2:
            status = isEmptyLStack(&Q);
            if (status == SUCCESS)
                printf("栈为空\n");
            else
                printf("栈不为空\n");
            break;
        case 3:
            status = getTopLStack(&Q, &data);
            if (status == SUCCESS)
                printf("栈顶元素为: %d\n", data);
            else
                printf("获取栈顶元素失败，栈为空\n");
            break;
        case 4:
            status = clearLStack(&Q);
            if (status == SUCCESS)
                printf("栈已清空\n");
            else
                printf("清空栈失败\n");
            break;
        case 5:
            status = destroyLStack(&Q);
            if (status == SUCCESS)
                printf("栈已销毁\n");
            else
                printf("销毁栈失败\n");
            break;
        case 6:
            status = LStackLength(&Q, &data);
            if (status == SUCCESS)
                printf("栈长度为: %d\n", data);
            else
                printf("获取栈长度失败\n");
            break;
        case 7:
            printf("请输入要入栈的元素: ");
            scanf("%d", &data);
            status = pushLStack(&Q, data);
            if (status == SUCCESS)
                printf("元素 %d 入栈成功\n", data);
            else
                printf("入栈失败\n");
            break;
        case 8:
            status = popLStack(&Q, &data);
            if (status == SUCCESS)
                printf("元素 %d 出栈成功\n", data);
            else
                printf("出栈失败，栈为空\n");
            break;
        case 0:
            printf("程序退出\n");
            return 0;
        default:
            printf("请输入有效的选项\n");
            break;
        }
    }

    return 0;
}