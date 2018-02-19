/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:07:03 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 15:31:21 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			captage(t_result *result,char *ch, int i, t_dir *dir, t_tree *tree)
{
	if (!ch)
		;
	if (i == 0)
		result->un = ch;
	else if (i == 1)
		result->deux = ch;
	else if (i == 2)
		result->trois = ch;
	else if (i == 3)
		result->quatre = ch;
	else if (i == 4)
		result->cinq = ch;
	else if (i == 5)
		result->six = ch;
	else if (i == 6)
		result->sept = ch;
	else if (i == 7)
	{
		result->huit = ch;
			if (result->sept && tree->lnk == 1)
			{
				if (dir->options[6] == 0)
					ft_strcat(result->sept, " -> ");
				if (dir->options[6] == 1)
					ft_strcat(result->sept, "@ -> ");
			}
	}
}

void			affiche(t_result *result, t_tree *tree)
{

	ft_putstr(result->un);
	ft_putstr(" ");
	ft_putstr(result->deux);
	ft_putstr(" ");
	ft_putstr(result->trois);
	ft_putstr(" ");
	ft_putstr(result->quatre);
	ft_putstr("\t");
	ft_putstr(result->cinq);
	ft_putstr("\t");
	ft_putstr(result->six);
	ft_putstr(" ");
	ft_putstr_color(result->sept, tree);
	ft_putstr("\033[0m");
	ft_putstr(result->huit);
	ft_putstr("\n");
}

void			ft_format(char **long_l, t_dir *dir, t_tree *tree)

{
	short int i;
	int j;

	i = 0;
	j = 0;
	static t_result *result;

	result = malloc(sizeof(t_result));
	result->un = NULL;
	result->deux = NULL;
	result->trois = NULL;
	result->quatre = NULL;
	result->cinq = NULL;
	result->six = NULL;
	result->sept = NULL;

	result->huit = NULL;
	while (i < 8)
	{
			captage(result, long_l[i], i, dir, tree);
		
		i++;
	}
	affiche(result, tree);

}


void			ft_padding(char **long_l, t_dir *dir, t_tree *tree)
{
	ft_format(long_l, dir, tree);
}

void			ft_putstr_color(char const *s, t_tree *tree)
{
	int i;

	i = 0;
	if (s)
	{

		if (tree->reg == 1)
		ft_putstr("\033[1;31m");
		if (tree->dir == 1)
			ft_putstr("\033[1;36m");
		if (tree->lnk == 1)
			ft_putstr("\033[1;35m");

		while (*s != '\0')
			ft_putchar(*s++);
	}
}

void			ft_print_tree(t_tree *tree, t_dir *dir)
{
	if (tree->left)
		ft_print_tree(tree->left, dir);
	if (dir->options[2] == 1 || (dir->options[2] == 0 && tree->name[0] != '.'))
	{
		if (dir->options[0] == 1)
		{
			ft_padding(tree->list_long, dir, tree);

			free(tree->linelist);
		}
		else
		{	
				ft_putstr_color(tree->name, tree);
				ft_putstr("\033[0m\n");
		}
		
	}
	if (tree->right)
		ft_print_tree(tree->right, dir);
}

void		ft_print_tree_rev(t_tree *tree, t_dir *dir)
{
	if (tree->right)
		ft_print_tree_rev(tree->right, dir);
	if (dir->options[2] == 1 || (dir->options[2] == 0 && tree->name[0] != '.'))
	{
		if (dir->options[0] == 1)
		{
			ft_padding(tree->list_long, dir, tree);

			free(tree->linelist);
		}
		else
		{
			ft_putstr_color(tree->name, tree);
			ft_putstr("\033[0m\n");
		}

	}
	if (tree->left)
		ft_print_tree_rev(tree->left, dir);
}

void			ft_print(t_dir *dir, char *current)
{
	int i;

	i = 0;
	if (dir->options[7] == 1 && dir->first_result == 0)
	{
		ft_putendl(current);
		return ;
	}
	if (dir->first_result == 1 || (dir->options[1] == 1 && dir->first_result == 1))
	{
		if (dir->options[7] == 1)
		{
			if (dir->options[0] == 0)
				ft_putstr(current);
			ft_putstr("\n");
			return ;
		}
		else if (dir->options[7] == 0)
		{
			if (!ft_strequ(current, dir->first))
				ft_putstr("\n");
			ft_putstr(current);
			ft_putstr(":\n");
		}
	}
	dir->first_result = 1;
	dir->first[0] = '\0';
	if (dir->options[0] == 1)
	{
		ft_putstr("total ");
		ft_putnbr(dir->sizeblock);
		ft_putstr("\n");
	}
	if (dir->options[3] == 0)
		ft_print_tree(dir->node, dir);
	else
		ft_print_tree_rev(dir->node, dir);
}
