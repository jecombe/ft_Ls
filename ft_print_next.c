/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_next.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 14:30:43 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 16:18:50 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			affiche_next_next(t_tree *tree, t_dir *dir, char **result,
		int len)
{
	if (dir->options[6] == 0 && tree->lnk == 1)
	{
		len = readlink(result[6], result[7], 1024);
		result[7][len] = '\0';
		ft_putstr(" -> ");
	}
	if (tree->lnk == 1)
		ft_putstr(result[7]);
	ft_putstr("\n");
}

void			affiche_next(t_tree *tree, t_dir *dir, char **result)
{
	int len;

	if (tree->reg == 1 && dir->options[6] == 1)
		ft_putstr("*");
	if (tree->dir == 1 && dir->options[6] == 1)
		ft_putstr("/");
	if (tree->fifo == 1 && dir->options[6] == 1)
		ft_putstr("|");
	if (dir->file_p)
	{
		len = readlink(result[6], result[7], 1024);
		result[7][len] = '\0';
	}
	if (dir->options[6] == 1 && tree->lnk == 1)
	{
		len = readlink(result[6], result[7], 1024);
		result[7][len] = '\0';
		ft_putstr("@ -> ");
	}
	affiche_next_next(tree, dir, result, len);
}

void			affiche(char **result, t_tree *tree, t_dir *dir)
{
	ft_putstr(result[0]);
	ft_putstr(" ");
	ft_putstr(result[1]);
	ft_putstr("\t");
	ft_putstr(result[2]);
	ft_putstr("\t");
	ft_putstr(result[3]);
	ft_putstr("\t");
	ft_putstr(result[4]);
	ft_putstr("\t");
	ft_putstr(result[5]);
	ft_putstr(" ");
	ft_putstr_color(result[6], tree);
	ft_putstr("\033[0m");
	affiche_next(tree, dir, result);
	free(result[0]);
	free(result[1]);
	free(result[2]);
	free(result[3]);
	free(result[4]);
	free(result[5]);
	free(result[6]);
	free(result[7]);
	free(result);
}
