/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_tree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 14:07:21 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 18:17:13 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

int				ft_create_tree(char *current, t_dir *dir)
{
	if (!(dir->dir = opendir(current)))
		return (-1);
	while ((dir->file = readdir(dir->dir)) != NULL)
	{
		ft_create_path(dir->path, current, dir->file->d_name);
		lstat(dir->path, &dir->info);
		if (ft_strequ(dir->file->d_name, ".") ||
				ft_strequ(dir->file->d_name, "..")
				|| dir->file->d_name[0] != '.'
				|| (dir->file->d_name[0] == '.' && dir->options[2] == 1))
			dir->options[4] == 1 ?
				ft_sort_date(&dir->node, dir, dir->file->d_name)
				: ft_sort_name(&dir->node, dir, dir->file->d_name);
	}
	if (closedir(dir->dir) == -1 || !dir->node)
		return (-1);
	return (0);
}

void			ft_check_option_node(t_dir *dir, t_tree *node, char *param)
{
	if (dir->options[0] == 1)
	{
		/*if (dir->options[6] == 1)
			node->tab_list = ft_list_long(dir, node->name);
		else if (dir->options[6] == 0)*/
			node->tab_list = ft_list_long(dir, param);
	}
	if (dir->options[4] == 1)
	{
		node->time = dir->info.st_mtime;
		node->nanosec = dir->info.st_mtimespec.tv_nsec;
	}
	if (!dir->info.st_mode)
	{
		node->print = ft_strnew(ft_strlen(param));
		ft_strcpy(node->print, "ls: ");
		ft_strcpy(&node->print[ft_strlen(node->print)], param);
		ft_strcpy(&node->print[ft_strlen(node->print)], "No such directory \n");
	}
}

void			ft_check_s(t_dir *dir, t_tree *node)
{
	if (dir->options[6] == 1)
	{
		if (node->reg == 1)
			node->print = ft_strcat(node->name, "*");
		if (node->dir == 1)
			node->print = ft_strcat(node->name, "/");
		if (node->fifo == 1)
			node->print = ft_strcat(node->name, "|");
		if (node->lnk == 1)
			if (dir->options[0] == 0)
			node->print = ft_strcat(node->name, "@");
	}
	else
		node->print = ft_strdup(node->name);
}

t_tree			*ft_create_node(t_dir *dir, char *param)
{
	t_tree *node;
	node = NULL;
	node = ft_memalloc(sizeof(t_tree));
	init_node(node, param);
	if (S_ISDIR(dir->info.st_mode) && !ft_strequ(node->name, ".")
			&& !ft_strequ(node->name, ".."))
		node->isdir = 1;
	else
		node->isdir = 0;
	if (S_ISREG(dir->info.st_mode))
		if (dir->info.st_mode & S_IXUSR)
			node->reg = 1;
	if (S_ISFIFO(dir->info.st_mode))
		node->fifo = 1;
	if (S_ISDIR(dir->info.st_mode))
		node->dir = 1;
	else if (S_ISLNK(dir->info.st_mode))
		node->lnk  = 1;
	ft_check_s(dir, node);
	ft_check_option_node(dir, node, param);
	return (node);
}
