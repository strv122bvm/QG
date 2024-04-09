#define _CRT_SECURE_NO_WARNINGS
#include <binary_sort_tree.h>

int main() {
    BinarySortTree tree;
    int choice, value;
    Status status;
    tree.root = NULL;
    // 初始化二叉树
    BST_init(&tree);

    while (1) {
        printf("\n1. 初始化二叉树\n");
        printf("2. 插入结点\n");
        printf("3. 删除结点\n");
        printf("4. 查找结点\n");
        printf("5. 非递归先序遍历\n");
        printf("6. 递归先序遍历\n");
        printf("7. 非递归中序遍历\n");
        printf("8. 递归中序遍历\n");
        printf("9. 非递归后序遍历\n");
        printf("10. 递归后序遍历\n");
        printf("11. 层序遍历\n");
        printf("0. 退出\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // 初始化二叉树
            status = BST_init(&tree);
            if (status == succeed)
                printf("二叉树初始化成功\n");
            else
                printf("二叉树初始化失败\n");
            break;
        case 2:
            // 插入结点
            printf("请输入要插入的结点值: ");
            scanf("%d", &value);
            status = BST_insert(&tree.root, value);
            if (status == succeed)
                printf("结点插入成功\n");
            else
                printf("结点插入失败\n");
            break;
        case 3:
            // 删除结点
            printf("请输入要删除的结点值: ");
            scanf("%d", &value);
            status = BST_delete(&tree.root, value);
            if (status == succeed)
                printf("结点删除成功\n");
            else
                printf("结点删除失败\n");
            break;
        case 4:
            // 查找结点
            printf("请输入要查找的结点值: ");
            scanf("%d", &value);
            if (BST_search(tree.root, value))
                printf("结点值 %d 存在于二叉树中\n", value);
            else
                printf("结点值 %d 不存在于二叉树中\n", value);
            break;
        case 5:
            // 非递归先序遍历
            printf("非递归先序遍历结果: ");
            BST_preorderI(&tree, visitNode);
            printf("\n");
            break;
        case 6:
            // 递归先序遍历
            printf("递归先序遍历结果: ");
            BST_preorderR(&tree, visitNode);
            printf("\n");
            break;
        case 7:
            // 非递归中序遍历
            printf("非递归中序遍历结果: ");
            BST_inorderI(&tree, visitNode);
            printf("\n");
            break;
        case 8:
            // 递归中序遍历
            printf("递归中序遍历结果: ");
            BST_inorderR(&tree, visitNode);
            printf("\n");
            break;
        case 9:
            // 非递归后序遍历
            printf("非递归后序遍历结果: ");
            BST_postorderI(&tree, visitNode);
            printf("\n");
            break;
        case 10:
            // 递归后序遍历
            printf("递归后序遍历结果: ");
            BST_postorderR(&tree, visitNode);
            printf("\n");
            break;
        case 11:
            // 层序遍历
            printf("层序遍历结果: ");
            BST_levelOrder(&tree, visitNode);
            printf("\n");
            break;
        case 0:
            // 退出程序
            printf("程序已退出\n");
            exit(EXIT_SUCCESS);
        default:
            printf("无效的选项，请重新输入\n");
        }
    }

    return 0;
}