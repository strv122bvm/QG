//
// Created by eke_l on 2021/4/21.
//
#include<stdio.h>
#include<stdlib.h>

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int
#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr tree) {
    if (tree == NULL)
        return failed;

    tree->root = NULL;
    return succeed;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(NodePtr* root, ElemType value) {
    if (*root == NULL) {
        *root = (NodePtr)malloc(sizeof(Node));
        if (*root == NULL)
            return failed;
        (*root)->value = value;
        (*root)->left = (*root)->right = NULL;
        return succeed;
    }

    if (value < (*root)->value)
        return BST_insert(&(*root)->left, value);
    else if (value > (*root)->value)
        return BST_insert(&(*root)->right, value);
    else
        return failed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
NodePtr findMin(NodePtr node) {
    NodePtr current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Status BST_delete(NodePtr* root, ElemType value) {
    if (*root == NULL)
        return failed; 

    if (value < (*root)->value)
        return BST_delete(&((*root)->left), value);
    else if (value > (*root)->value)
        return BST_delete(&((*root)->right), value);
    else {
        if ((*root)->left == NULL) {
            NodePtr temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL) {
            NodePtr temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else {
            NodePtr temp = findMin((*root)->right);
            (*root)->value = temp->value;
            BST_delete(&((*root)->right), temp->value);
        }
        return succeed;
    }
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr root, ElemType value) {
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (value < root->value)
        return BST_search(root->left, value);
    else
        return BST_search(root->right, value);
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr tree, void (*visit)(NodePtr)) {
    if (tree == NULL || tree->root == NULL)
        return failed;

    NodePtr stack[MAX_STACK_SIZE];
    int top = -1;
    stack[++top] = tree->root;

    while (top != -1) {
        NodePtr current = stack[top--];
        visit(current);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }

    return succeed;
}


/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status preorderRecursive(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return succeed;

    visit(root);
    preorderRecursive(root->left, visit);
    preorderRecursive(root->right, visit);

    return succeed;
}

Status BST_preorderR(BinarySortTreePtr tree, void (*visit)(NodePtr)) {
    if (tree == NULL || tree->root == NULL)
        return failed;

    return preorderRecursive(tree->root, visit);
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr tree, void (*visit)(NodePtr)) {
    if (tree == NULL || tree->root == NULL)
        return failed;

    NodePtr stack[MAX_STACK_SIZE];
    int top = -1;
    NodePtr current = tree->root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        visit(current);

        current = current->right;
    }

    return succeed;
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status inorderRecursive(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return succeed;

    inorderRecursive(root->left, visit);
    visit(root);
    inorderRecursive(root->right, visit);

    return succeed;
}

Status BST_inorderR(BinarySortTreePtr tree, void (*visit)(NodePtr)) {
    if (tree == NULL || tree->root == NULL)
        return failed;

    return inorderRecursive(tree->root, visit);
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
typedef struct StackFrame {
    NodePtr node;
    int processed;
} StackFrame;

Status BST_postorderI(BinarySortTreePtr tree, void (*visit)(NodePtr)) {
    if (tree == NULL || tree->root == NULL)
        return failed;

    StackFrame stack[MAX_STACK_SIZE];
    int top = -1;
    NodePtr current = tree->root;

    do {
        while (current != NULL) {
            // Create a new stack frame for the current node
            stack[++top].node = current;
            stack[top].processed = 0;
            current = current->left;
        }

        while (top != -1 && stack[top].processed == 1) {
            // If the current node has been processed, visit it
            visit(stack[top--].node);
        }

        if (top != -1) {
            current = stack[top].node->right;
            stack[top].processed = 1;
        }
    } while (top != -1);

    return succeed;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status postorderRecursive(NodePtr root, void (*visit)(NodePtr)) {
    if (root == NULL)
        return succeed;

    postorderRecursive(root->left, visit);
    postorderRecursive(root->right, visit);
    visit(root);

    return succeed;
}

Status BST_postorderR(BinarySortTreePtr tree, void (*visit)(NodePtr)) {
    if (tree == NULL || tree->root == NULL)
        return failed;

    return postorderRecursive(tree->root, visit);
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr tree, void (*visit)(NodePtr)) {
    if (tree == NULL || tree->root == NULL)
        return failed;

    NodePtr queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = tree->root;

    while (front < rear) {
        NodePtr current = queue[front++];

        visit(current);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    return succeed;
}

void visitNode(NodePtr node) {
    printf("%d ", node->value); // 访问结点值并打印
}

#endif
