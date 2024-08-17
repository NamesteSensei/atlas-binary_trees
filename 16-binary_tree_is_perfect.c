#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    /* Calculate the height of left and right subtrees */
    left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
    right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;

    /* Return the greater height */
    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If it's a leaf node, it's perfect */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* If it has two children, check if both subtrees are perfect and of equal height */
    if (tree->left != NULL && tree->right != NULL)
    {
        int left_perfect = binary_tree_is_perfect(tree->left);
        int right_perfect = binary_tree_is_perfect(tree->right);
        int left_height = binary_tree_height(tree->left);
        int right_height = binary_tree_height(tree->right);

        return (left_perfect && right_perfect && left_height == right_height);
    }

    /* If a node has only one child, it's not perfect */
    return (0);
}

