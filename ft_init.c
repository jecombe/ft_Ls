/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 13:14:54 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/09 17:25:36 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			ft_init(t_dir *dir)
{
	dir->options = ft_memalloc(sizeof(int) * 8);
	dir->path = ft_strnew(PATH_MAX);
	dir->path_dir = ft_strnew(PATH_MAX);
	dir->file_p = NULL;
	dir->bad_param = NULL;
	dir->param = NULL;
	dir->first_result = 0;
}

void			ft_create_path(char *path, char *one, char *two)
{
	ft_strcpy(path, one);
	if (!ft_strequ(one, "/"))
		ft_strcpy(&path[ft_strlen(path)], "/");
	ft_strcpy(&path[ft_strlen(path)], two);
}

void			ft_free(t_tree *node)
{
	if (!node)
		return ;
	if (node->left)
		ft_free(node->left);
	if (node->right)
		ft_free(node->right);
	free(node->name);
	free(node);
}

t_tree			*tree_init(void)
{
	t_tree *node;

	node = ft_memalloc(sizeof(t_tree));
	node->left = NULL;
	node->right = NULL;
	node->reg = 0;
	node->dir = 0;
	node->fifo = 0;
	node->lnk = 0;
	return (node);
}

void			ft_putstr_color(char const *s, t_tree *tree)
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
