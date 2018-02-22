/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:07:03 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 15:42:45 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"
void		ft_putstr_color(char const *si, t_tree *tree);

void		affiche(char **result, t_tree *tree, t_dir *dir)
{

	ft_putstr(result[0]);
	ft_putstr(" ");
	ft_putstr(result[1]);
	ft_putstr("\t");
	ft_putstr(result[2]);
	ft_putstr("\t");
	ft_putstr(result[3]);
	ft_putstr("\t");
	ft_putstr(result[4]);
	ft_putstr("\t");
	ft_putstr(result[5]);
	ft_putstr(" ");
	ft_putstr_color(result[6], tree);
	ft_putstr("\033[0m");
	if (dir->options[6] == 1 && tree->lnk == 1)
		ft_putstr("@ -> ");
	if (dir->options[6] == 0 && tree->lnk == 1)
		ft_putstr(" -> ");
	ft_putstr(result[7]);
	ft_putstr("\n");
}

void ft_format(char **tab, t_tree *tree,t_dir  *dir)
{
	affiche(tab, tree, dir);
	free(tab);

}

void		ft_putstr_color(char const *s, t_tree *tree)
{
	if (s)
	{

		if (tree->reg == 1)
		ft_putstr("\033[0;31m");
		if (tree->dir == 1)
			ft_putstr("\033[1;36m");
		if (tree->lnk == 1)
			ft_putstr("\033[0;35m");

		while (*s != '\0')
		{

			ft_putchar(*s);
			s++;
		}
	}
}
void		ft_print_tree(t_tree *tree, t_dir *dir)
{
	if (tree->left)
		ft_print_tree(tree->left, dir);
	if (dir->options[2] == 1 || (dir->options[2] == 0 && tree->name[0] != '.'))
	{
		if (dir->options[0] == 1)
			ft_format(tree->tab_list, tree ,dir);
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
			ft_format(tree->tab_list, tree, dir);
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
				ft_putendl(current);
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
	if (dir->options[0] == 1)
	{
		ft_putstr("total ");
		ft_putnbr(dir->sizeblock);
		ft_putstr("\n");
	}
	(dir->options[3] == 0) ? ft_print_tree(dir->node, dir) :
		ft_print_tree_rev(dir->node, dir);
}
