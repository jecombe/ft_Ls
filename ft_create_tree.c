/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_tree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 14:07:21 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 13:23:18 by jecombe     ###    #+. /#+    ###.fr     */
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

char				**ft_listgood(void)
{
	char			**opt_l;

	opt_l = ft_memalloc(sizeof(char *) * 8);
	if (aa > 1)
	{
		free(opt_l[0]);
		free(opt_l[1]);
		free(opt_l[2]);
		free(opt_l[3]);
		free(opt_l[4]);
		free(opt_l[5]);
		free(opt_l[6]);
		free(opt_l[7]);
		free(opt_l);
	}
	return (opt_l);
}

void			ft_check_option_node(t_dir *dir, t_tree *node, char *param)
{
	char *temp;
	char	**temp2;
	if (dir->options[0] == 1)
	{
		if (dir->options[6] == 1)
		{
			temp2 = ft_list_long(dir, node->name);
			node->tab_list = temp2;
		}
		else if ((dir->options[6] == 0 && dir->options[2] == 0))
		{
			if (dir->name2 != NULL)
			node->tab_list = ft_listgood();
			if (dir->name2 == NULL)
			{
				node->tab_list = ft_list_long(dir, param);
				if (dir->options[3] == 1 && ft_strequ(node->name, ".."))
				{
					free(node->tab_list[0]);
					free(node->tab_list[1]);
					free(node->tab_list[2]);
					free(node->tab_list[3]);
					free(node->tab_list[4]);
					free(node->tab_list[5]);
					free(node->tab_list[6]);
					free(node->tab_list[7]);
					free(node->tab_list);
				}

				if (dir->options[1] == 1 && ft_strequ(node->name, "."))
				{
					free(node->tab_list[0]);
					free(node->tab_list[1]);
					free(node->tab_list[2]);
					free(node->tab_list[3]);
					free(node->tab_list[4]);
					free(node->tab_list[5]);
					free(node->tab_list[6]);
					free(node->tab_list[7]);
					free(node->tab_list);
				}
			}

		}
		else if (dir->options[6] == 0 && dir->options[2] == 1)
		{
			if (dir->name2 != NULL)
				node->tab_list = ft_listgood();
			if (dir->name2 == NULL)
				node->tab_list = ft_list_long(dir, param);
		}
	}
	if (dir->options[4] == 1)
	{
		node->time = dir->info.st_mtime;
		node->nanosec = dir->info.st_mtimespec.tv_nsec;
	}
	if (!dir->info.st_mode)
	{
		temp = ft_strnew(ft_strlen(param) + 60);
		node->print = temp;
		ft_strcpy(node->print, "ls: ");
		ft_strcpy(&node->print[ft_strlen(node->print)], param);
		ft_strcpy(&node->print[ft_strlen(node->print)],
				": No such file or directory \n");
		free(temp);
	}	

}


t_tree			*ft_create_node(t_dir *dir, char *param)
{
	t_tree		*node;
	char		*temp;

	node = tree_init();
	node->name = ft_strdup(param);
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
		node->lnk = 1;
	//ft_check_s(dir, node);
	ft_check_option_node(dir, node, param);
	return (node);
}
