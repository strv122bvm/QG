#define _CRT_SECURE_NO_WARNINGS
#include <LQueue.h>
typedef int ElementType;

// 打印队列元素的操作函数
void PrintElement(void* q) {
    printf("%d ", *((ElementType*)q));
}

int main() {
    int a;
    LQueue Q;
    ElementType element;

    while (1) {
        printf("1.初始化队列\n");
        printf("2.销毁队列\n");
        printf("3.检查队列是否为空\n");
        printf("4.查看队头元素\n");
        printf("5.确定队列长度\n");
        printf("6.入队操作\n");
        printf("7.出队操作\n");
        printf("8.清空队列\n");
        printf("9.遍历队列元素\n");
        printf("0.退出\n");
        printf("Enter your choice: ");
        scanf("%d", &a);

        switch (a) {
        case 1:
            InitLQueue(&Q);
            printf("队列已初始化\n");
            break;
        case 2:
            DestoryLQueue(&Q);
            printf("队列已销毁\n");
            break;
        case 3:
            printf(IsEmptyLQueue(&Q) ? "队列为空\n" : "队列非空\n");
            break;
        case 4:
            if (!IsEmptyLQueue(&Q)) {
                if (GetHeadLQueue(&Q, &element)) {
                    printf("队头元素为：%d\n", element);
                }
                else {
                    printf("获取队头元素失败\n");
                }
            }
            else {
                printf("队列为空\n");
            }
            break;
        case 5:
            printf("队列长度为：%d\n", LengthLQueue(&Q));
            break;
        case 6:
            printf("请输入要入队的元素值：");
            scanf("%d", &element);
            if (EnLQueue(&Q, &element, sizeof(int))) {
                printf("元素 %d 入队成功\n", element);
            }
            else {
                printf("入队失败\n");
            }
            break;
        case 7:
            if (DeLQueue(&Q)) {
                printf("出队成功\n");
            }
            else {
                printf("队列为空，无法出队\n");
            }
            break;
        case 8:
            ClearLQueue(&Q);
            printf("队列已清空\n");
            break;
        case 9:
            printf("队列元素为：");
            TraverseLQueue(&Q, PrintElement);
            printf("\n");
            break;
        case 0:
            printf("程序退出\n");
            exit(0);
        default:
            printf("无效选择，请重新输入\n");
            break;
        }
    }

    return 0;
}