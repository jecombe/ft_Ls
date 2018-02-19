/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 17:36:17 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 12:50:39 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void		ft_display_dir(t_tree *tree, t_dir *dir)
{
	if (tree->left)
		ft_display_dir(tree->left, dir);
	if (ft_list(dir, tree->name) == -1)
		ft_print_error(dir, tree->name, tree->name);
	if (tree->right)
		ft_display_dir(tree->right, dir);

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
	free(dir->max_len);
	free(dir->options);
	free(dir);
}

void ft_print_error(t_dir *d, char *current, char *name)

{

	char *tmp;

	tmp = ft_strnew(ft_strlen(name) + 5);
	ft_strcpy(tmp, "ls: ");
	ft_strcpy(&tmp[ft_strlen(tmp)], name);
	if (errno == 2)
		perror(tmp);
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

int main(int argc, char **argv)
{
	t_dir		*dir;
	int			i;

	dir = NULL;
	dir = ft_memalloc(sizeof(t_dir));

	ft_init(dir);
	ft_check_options(dir, argc, argv);
	if (dir->bad_param)
		ft_print_param(dir, dir->bad_param);
	if (dir->file_param && dir->options[3] == 0)
		ft_print_tree(dir->file_param, dir);
	if (dir->file_param && dir->options[3] == 1)
		ft_print_tree_rev(dir->file_param, dir);
	if (dir->options[7] == 1 && dir->param && dir->options[3] == 0)
	{
		ft_print_tree(dir->param, dir);
		return(0);
	}
		if (dir->options[7] == 1 && dir->param && dir->options[3] == 1)
	{
		ft_print_tree_rev(dir->param, dir);
		return(0);
	}

	if (dir->param)
	{
		if (dir->file_param)
			ft_putstr("\n");
		ft_check_first(dir->param, dir);
		ft_display_dir(dir->param, dir);
	}
	ft_free_dir(dir);
	return (0);
}
