/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:07:03 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 13:54:25 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			ft_print_tree(t_tree *tree, t_dir *dir)
{
	if (tree->left)
		ft_print_tree(tree->left, dir);
	if (ft_strequ(tree->name, "..") && dir->options[2] == 0 &&
			dir->options[0] == 1)
		ft_free_tab(tree->tab_list);
	if (dir->options[2] == 1 || (dir->options[2] == 0 && tree->name[0] != '.'))
	{
		if (dir->options[0] == 1)
			affiche(tree->tab_list, tree, dir);
		else
		{
			ft_putstr_color(tree->name, tree);
			ft_putstr("\033[0m");
			if (dir->options[6] == 1)
				ft_check_special(tree);
			ft_putstr("\n");
		}
	}
	if (tree->right)
		ft_print_tree(tree->right, dir);
}

void			ft_check_special(t_tree *tree)
{
	if (tree->reg == 1)
		ft_putstr("*");
	if (tree->dir == 1)
		ft_putstr("/");
	if (tree->lnk == 1)
		ft_putstr("@");
	if (tree->fifo)
		ft_putstr("|");
}

void			ft_print_tree_rev(t_tree *tree, t_dir *dir)
{
	if (tree->right)
		ft_print_tree_rev(tree->right, dir);
	if (dir->options[2] == 1 || (dir->options[2] == 0 && tree->name[0] != '.'))
	{
		if (dir->options[0] == 1)
			affiche(tree->tab_list, tree, dir);
		else
		{
			ft_putstr_color(tree->name, tree);
			ft_putstr("\033[0m");
			if (dir->options[6] == 1)
				ft_check_special(tree);
			ft_putstr("\n");
		}
	}
	if (tree->left)
		ft_print_tree_rev(tree->left, dir);
}

void			ft_print_next(t_dir *dir)
{
	dir->first_result = 1;
	if (dir->options[0] == 1)
	{
		ft_putstr("total ");
		ft_putnbr(dir->sizeblock);
		ft_putstr("\n");
	}
	if (dir->options[3] == 0)
		ft_print_tree(dir->node, dir);
	if (dir->options[3] == 1)
		ft_print_tree_rev(dir->node, dir);
}

void			ft_print(t_dir *dir, char *current)
{
	if (dir->first_result == 1 || (dir->options[1] == 1
				&& dir->first_result == 1))
	{
		if (!ft_strequ(current, dir->first))
		{
			ft_putstr("\n");
		}
		ft_putstr(current);
		ft_putstr(":\n");
	}
	ft_print_next(dir);
}
