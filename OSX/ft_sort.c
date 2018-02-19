/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 12:54:49 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 14:27:44 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			ft_sort_name(t_tree **tree_ftname, t_dir *dir, char *name)
{
	if (*tree_ftname == NULL)
	{
		*tree_ftname = ft_create_node(dir, name);
		return;
	}
	if (ft_strcmp(name, (*tree_ftname)->name) < 0)
		ft_sort_name(&(*tree_ftname)->left, dir, name);
	else
		ft_sort_name(&(*tree_ftname)->right, dir, name);

}

void		ft_sort_date(t_tree **tree_ftdate, t_dir *dir, char *name)
{
	if (*tree_ftdate == NULL)
	{
		*tree_ftdate = ft_create_node(dir, name);
		return;
	}
	if (dir->info.st_mtime > (*tree_ftdate)->time)
		ft_sort_date(&(*tree_ftdate)->left, dir, name);
	else if (dir->info.st_mtime < (*tree_ftdate)->time)
		ft_sort_date(&(*tree_ftdate)->right, dir, name);
	else
	{
		if (dir->info.st_mtim.tv_nsec > (*tree_ftdate)->nanosec)
			ft_sort_date(&(*tree_ftdate)->left, dir, name);
		else if (dir->info.st_mtim.tv_nsec < (*tree_ftdate)->nanosec)
			ft_sort_date(&(*tree_ftdate)->right, dir, name);
		else
		{
			if (ft_strcmp(name, (*tree_ftdate)->name) <= 0)
				ft_sort_date(&(*tree_ftdate)->left, dir, name);
			else
				ft_sort_date(&(*tree_ftdate)->right, dir,name);
		}
	}
}

void			ft_recurs(t_tree *tree, t_dir *dir, char *current)
{
	char *tmp;

	tmp = ft_strdup(current);
	if (tree->left)
		ft_recurs(tree->left, dir, tmp);
	if (tree->isdir == 1)
	{
		ft_create_path(dir->path_dir, tmp, tree->name);
		if (ft_list(dir, dir->path_dir) == -1)
			ft_print_error(dir, tmp, tree->name);
	}
	if (tree->right)
		ft_recurs(tree->right, dir, tmp);
	free(tmp);
	free(tree->name);
	free(tree);
}

void			ft_recurs_rev(t_tree *tree, t_dir *dir, char *current)
{
	char *tmp;

	tmp = ft_strdup(current);
	if (tree->right)
		ft_recurs_rev(tree->right, dir, tmp);
	if (tree->isdir == 1)
	{
		ft_create_path(dir->path_dir, tmp, tree->name);
		if (ft_list(dir, dir->path_dir) == -1)
			ft_print_error(dir, tmp, tree->name);
	}
	if (tree->left)
		ft_recurs_rev(tree->left, dir, tmp);
	free(tmp);
	free(tree->name);
	free(tree);
}

