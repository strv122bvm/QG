#define _CRT_SECURE_NO_WARNINGS
#include <binary_sort_tree.h>

int main() {
    BinarySortTree tree;
    int choice, value;
    Status status;
    tree.root = NULL;
    // ��ʼ��������
    BST_init(&tree);

    while (1) {
        printf("\n1. ��ʼ��������\n");
        printf("2. ������\n");
        printf("3. ɾ�����\n");
        printf("4. ���ҽ��\n");
        printf("5. �ǵݹ��������\n");
        printf("6. �ݹ��������\n");
        printf("7. �ǵݹ��������\n");
        printf("8. �ݹ��������\n");
        printf("9. �ǵݹ�������\n");
        printf("10. �ݹ�������\n");
        printf("11. �������\n");
        printf("0. �˳�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // ��ʼ��������
            status = BST_init(&tree);
            if (status == succeed)
                printf("��������ʼ���ɹ�\n");
            else
                printf("��������ʼ��ʧ��\n");
            break;
        case 2:
            // ������
            printf("������Ҫ����Ľ��ֵ: ");
            scanf("%d", &value);
            status = BST_insert(&tree.root, value);
            if (status == succeed)
                printf("������ɹ�\n");
            else
                printf("������ʧ��\n");
            break;
        case 3:
            // ɾ�����
            printf("������Ҫɾ���Ľ��ֵ: ");
            scanf("%d", &value);
            status = BST_delete(&tree.root, value);
            if (status == succeed)
                printf("���ɾ���ɹ�\n");
            else
                printf("���ɾ��ʧ��\n");
            break;
        case 4:
            // ���ҽ��
            printf("������Ҫ���ҵĽ��ֵ: ");
            scanf("%d", &value);
            if (BST_search(tree.root, value))
                printf("���ֵ %d �����ڶ�������\n", value);
            else
                printf("���ֵ %d �������ڶ�������\n", value);
            break;
        case 5:
            // �ǵݹ��������
            printf("�ǵݹ�����������: ");
            BST_preorderI(&tree, visitNode);
            printf("\n");
            break;
        case 6:
            // �ݹ��������
            printf("�ݹ�����������: ");
            BST_preorderR(&tree, visitNode);
            printf("\n");
            break;
        case 7:
            // �ǵݹ��������
            printf("�ǵݹ�����������: ");
            BST_inorderI(&tree, visitNode);
            printf("\n");
            break;
        case 8:
            // �ݹ��������
            printf("�ݹ�����������: ");
            BST_inorderR(&tree, visitNode);
            printf("\n");
            break;
        case 9:
            // �ǵݹ�������
            printf("�ǵݹ����������: ");
            BST_postorderI(&tree, visitNode);
            printf("\n");
            break;
        case 10:
            // �ݹ�������
            printf("�ݹ����������: ");
            BST_postorderR(&tree, visitNode);
            printf("\n");
            break;
        case 11:
            // �������
            printf("����������: ");
            BST_levelOrder(&tree, visitNode);
            printf("\n");
            break;
        case 0:
            // �˳�����
            printf("�������˳�\n");
            exit(EXIT_SUCCESS);
        default:
            printf("��Ч��ѡ�����������\n");
        }
    }

    return 0;
}