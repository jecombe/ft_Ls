/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 16:21:52 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 16:23:16 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			ft_free_tab(char **tab_list)
{
	free(tab_list[0]);
	free(tab_list[1]);
	free(tab_list[2]);
	free(tab_list[3]);
	free(tab_list[4]);
	free(tab_list[5]);
	free(tab_list[6]);
	free(tab_list[7]);
	free(tab_list);
}

void			ft_print_param(t_dir *dir, t_tree *tree)
{
	if (tree->left)
		ft_print_param(dir, tree->left);
	ft_putstr_fd(tree->print, 2);
	if (tree->right)
		ft_print_param(dir, tree->right);
}

void			ft_check_first(t_tree *tree, t_dir *dir)
{
	if (tree->left)
		ft_check_first(tree->left, dir);
	else
		dir->first = ft_strdup(tree->name);
}

void			ft_free_dir(t_dir *dir)
{
	free(dir->first);
	free(dir->name_dir);
	free(dir->wrong_dir);
	free(dir->no_dir);
	free(dir->path);
	free(dir->path_dir);
	free(dir->file);
	free(dir->options);
	free(dir);
}
