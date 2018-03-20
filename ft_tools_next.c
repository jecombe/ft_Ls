/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tools_next.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:08:45 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 16:03:09 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

char			*ft_strrev(char *str)
{
	int			i;
	int			l;
	char		t;

	l = 0;
	while (str[l] != '\0')
		l++;
	i = -1;
	while (++i < --l)
	{
		t = str[i];
		str[i] = str[l];
		str[l] = t;
	}
	return (str);
}

char			*ft_print_erro_next(char *name)
{
	int		i;
	int		co;
	int		transfer;
	int		o;
	char	*tmp;

	i = 0;
	o = 0;
	co = 0;
	transfer = 0;
	while (name[i + 1] != '\0')
		i++;
	transfer = i;
	while (name[i--] != '/')
		co++;
	i = 0;
	tmp = malloc(sizeof(char) * co + 1);
	while (name[transfer] != '/')
	{
		tmp[o] = name[transfer--];
		o++;
	}
	tmp[o] = '\0';
	ft_strrev(tmp);
	return (tmp);
}

void			ft_display_dir(t_tree *tree, t_dir *dir)
{
	if (tree->left)
		ft_display_dir(tree->left, dir);
	if (ft_list(dir, tree->name) == -1)
	{
		ft_print_error(dir, tree->name);
		if (dir->options[0] == 1 && dir->perm_denied != 1)
		{
			free(tree->tab_list[0]);
			free(tree->tab_list[1]);
			free(tree->tab_list[2]);
			free(tree->tab_list[3]);
			free(tree->tab_list[4]);
			free(tree->tab_list[5]);
			free(tree->tab_list[6]);
			free(tree->tab_list[7]);
			free(tree->tab_list);
		}
	}
	if (tree->right)
		ft_display_dir(tree->right, dir);
}
