/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 17:36:17 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 16:23:24 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			ft_display_dir(t_tree *tree, t_dir *dir)
{
	if (tree->left)
		ft_display_dir(tree->left, dir);
	if (ft_list(dir, tree->name) == -1)
		ft_print_error(dir, tree->name, tree->name);
	if (tree->right)
		ft_display_dir(tree->right, dir);
}

void			ft_print_error(t_dir *d, char *current, char *name)
{
	char		*tmp;

	tmp = ft_strnew(ft_strlen(name) + 5);
	ft_strcpy(tmp, "ls: ");
	ft_strcpy(&tmp[ft_strlen(tmp)], name);
	(errno == 2) ? perror(tmp) : 0;
	if (errno == 13)
	{
		if (d->first_result == 1)
		{
			ft_putstr("\n");
			ft_create_path(d->path, current, name);
			ft_putstr(d->path);
			ft_putstr(":\n");
		}
		perror(tmp);
	}
	if (d->first_result == 1)
	{
		ft_putstr("\n");
		ft_create_path(d->path, current, name);
		ft_putstr(d->path);
		ft_putstr(":\n");
	}
	free(tmp);
}

void			ft_is_param(t_dir *dir)
{
	if (dir->param)
	{
		if (dir->file_p)
		{
			ft_putstr("\n");
		}
		ft_check_first(dir->param, dir);
		ft_display_dir(dir->param, dir);
		ft_free(dir->param);
	}
	if (dir->options[0] == 1 && dir->param)
	{
		free(dir->param->tab_list[0]);
		free(dir->param->tab_list[1]);
		free(dir->param->tab_list[2]);
		free(dir->param->tab_list[3]);
		free(dir->param->tab_list[4]);
		free(dir->param->tab_list[5]);
		free(dir->param->tab_list[6]);
		free(dir->param->tab_list[7]);
		free(dir->param->tab_list);
	}
	ft_free_dir(dir);
}

int				ft_main_next(t_dir *dir)
{
	if (dir->file_p && dir->options[3] == 0)
	{
		ft_print_tree(dir->file_p, dir);
		ft_free(dir->file_p);
	}
	if (dir->file_p && dir->options[3] == 1)
	{
		ft_print_tree_rev(dir->file_p, dir);
		ft_free(dir->file_p);
	}
	if (dir->options[7] == 1 && dir->param && dir->options[3] == 0)
	{
		ft_print_tree(dir->param, dir);
		return (0);
	}
	if (dir->options[7] == 1 && dir->param && dir->options[3] == 1)
	{
		ft_print_tree_rev(dir->param, dir);
		return (0);
	}
	ft_is_param(dir);
	return (0);
}

int				main(int argc, char **argv)
{
	t_dir		*dir;

	dir = NULL;
	dir = ft_memalloc(sizeof(t_dir));
	ft_init(dir);
	ft_check_options(dir, argc, argv);
	if (dir->bad_param)
	{
		ft_print_param(dir, dir->bad_param);
		if (dir->options[0] == 1)
		{
			free(dir->bad_param->tab_list[0]);
			free(dir->bad_param->tab_list[1]);
			free(dir->bad_param->tab_list[2]);
			free(dir->bad_param->tab_list[3]);
			free(dir->bad_param->tab_list[4]);
			free(dir->bad_param->tab_list[5]);
			free(dir->bad_param->tab_list[6]);
			free(dir->bad_param->tab_list[7]);
			free(dir->bad_param->tab_list);
			ft_free(dir->bad_param);
		}
	}
	ft_main_next(dir);
}
