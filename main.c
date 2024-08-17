#include "binary_trees.h"
#include <stdio.h>

/**
 * main - Entry point for testing binary_tree_node function
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    if (root == NULL)
    {
        printf("Failed to create node\n");
        return (1);
    }

    printf("Node created: %d\n", root->n);
    printf("Parent: %p\n", (void *)root->parent);
    printf("Left child: %p\n", (void *)root->left);
    printf("Right child: %p\n", (void *)root->right);

    return (0);
}

