#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
void binary_tree_print(const binary_tree_t *tree);
static size_t _height(const binary_tree_t *tree);
static int _print_t(const binary_tree_t *tree, int is_left, int offset, int depth, char **s);

static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);
	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

static int _print_t(const binary_tree_t *tree, int is_left, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, i;

	if (!tree)
		return (0);
	sprintf(b, "(%03d)", tree->n);
	width = strlen(b);

	left = _print_t(tree->left, 1, offset, depth + 1, s);
	right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;

	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], ' ', 255);
	}

	_print_t(tree, 0, 0, 0, s);

	for (i = 0; i < height + 1; i++)
	{
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}

