/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 17:36:17 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 15:59:13 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			ft_print_error_next(t_dir *d, char *tmp, char *tmp2)
{
	if (errno == 13)
	{
		d->perm_denied = 1;
		if (d->first_result == 1)
		{
			ft_putstr("\n");
			ft_putstr(tmp);
			ft_putstr(":\n");
		}
		ft_putstr("ls: ");
		perror(tmp2);
	}
}

void			ft_print_error(t_dir *d, char *name)
{
	char		*tmp;
	char		*tmp2;

	d->perm_denied = 0;
	tmp2 = ft_print_erro_next(name);
	tmp = ft_strnew(ft_strlen(name) + 5);
	ft_strcpy(&tmp[ft_strlen(tmp)], name);
	if (errno == 2)
	{
		ft_putstr("ls: ");
		perror(tmp);
	}
	ft_print_error_next(d, tmp, tmp2);
	if (errno == 3)
	{
		ft_putstr("\n");
		perror(tmp);
	}
	free(tmp);
	free(tmp2);
}

void			ft_is_param(t_dir *dir)
{
	if (dir->param)
	{
		if (dir->file_p)
			ft_putstr("\n");
		ft_check_first(dir->param, dir);
		ft_display_dir(dir->param, dir);
		if (dir->options[0] == 1)
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
		ft_free(dir->param);
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
	g_a = 0;
	if (dir->bad_param)
	{
		ft_display_dir(dir->bad_param, dir);
		ft_free(dir->bad_param);
	}
	ft_main_next(dir);
}
