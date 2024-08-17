#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is full, 0 otherwise
 * Description: A binary tree is full if every node has either 0 or 2 children.
 * A single node with no children is considered a full tree.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* A leaf node (node with no children) is a full tree */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* A node with both children must also be full for the tree to be full */
    if (tree->left != NULL && tree->right != NULL)
    {
        return (binary_tree_is_full(tree->left) &&
                binary_tree_is_full(tree->right));
    }

    /* If a node has one child only, it's not a full tree */
    return (0);
}
