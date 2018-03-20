/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 16:21:52 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/09 15:13:28 by jecombe     ###    #+. /#+    ###.fr     */
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

void			ft_is_false(t_dir *dir, char *options)
{
	int i;
	int co;

	i = 0;
	co = 0;
	while (options[i])
	{
		options[i] == '-' ? co++ : 0;
		if (options[i] != '-' || co >= 2)
		{
			if (options[i] != 'l' && options[i] != 'R' && options[i] != 'a'
					&& options[i] != 'r' && options[i] != 't'
					&& options[i] != '1'
					&& options[i] != 'F')
			{
				ft_putstr("ls: illegal option -- ");
				ft_putchar_fd(co >= 2 ? '-' : options[i], 2);
				ft_putstr_fd("\nusage: ls [lRart] [file ...]\n", 2);
				ft_free_dir(dir);
				exit(1);
			}
		}
		i++;
	}
}

void			ft_check_g_a(t_dir *dir)
{
	if (g_a > 0)
		dir->name2 = NULL;
}
