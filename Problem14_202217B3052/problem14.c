#include <stdio.h>

#define MAX_NODE 15

// Array representation of a binary tree
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 
               'V', '\0', 'J', 'L'};

// Function to get the index of the right child
int get_right_child(int index)
{
    // Right child index is 2 * index + 1
    int right_index = 2 * index + 1;
    if (right_index <= MAX_NODE && tree[right_index] != '\0')
        return right_index;
    return -1;
}

// Function to get the index of the left child
int get_left_child(int index)
{
    // Left child index is 2 * index
    int left_index = 2 * index;
    if (left_index <= MAX_NODE && tree[left_index] != '\0')
        return left_index;
    return -1;
}

// Preorder traversal (Root - Left - Right)
void preorder(int index)
{
    if (index > 0 && index <= MAX_NODE && tree[index] != '\0')
    {
        printf(" %c ", tree[index]);      // Visit root
        preorder(get_left_child(index)); // Traverse left subtree
        preorder(get_right_child(index));// Traverse right subtree
    }
}

// Postorder traversal (Left - Right - Root)
void postorder(int index)
{
    if (index > 0 && index <= MAX_NODE && tree[index] != '\0')
    {
        postorder(get_left_child(index)); // Traverse left subtree
        postorder(get_right_child(index));// Traverse right subtree
        printf(" %c ", tree[index]);      // Visit root
    }
}

// Inorder traversal (Left - Root - Right)
void inorder(int index)
{
    if (index > 0 && index <= MAX_NODE && tree[index] != '\0')
    {
        inorder(get_left_child(index)); // Traverse left subtree
        printf(" %c ", tree[index]);    // Visit root
        inorder(get_right_child(index));// Traverse right subtree
    }
}

int main()
{
    printf("Preorder:\n");
    preorder(1);
    printf("\nPostorder:\n");
    postorder(1);
    printf("\nInorder:\n");
    inorder(1);
    printf("\n");

    return 0;
}
