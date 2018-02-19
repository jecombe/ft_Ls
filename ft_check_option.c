/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_option.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 17:23:00 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 16:00:11 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:40:33 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 17:21:07 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

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
					&& options[i] != 'r' && options[i] != 't' && options[i] != '1'
					&& options[i] != 'F' && options[i] != 'd')
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

void			ft_sort_options(t_dir *dir, char **argv, int i)
{
	//printf("passe dans sort optiins:\n");
	while (argv[i])
	{
		if (!argv[i][0])
		{
			ft_putstr("ls: fts_open: No such file or directory\n");
			exit(1);
		}
		if (lstat(argv[i], &dir->info) == 0)
			stat(argv[i], &dir->info);
		if (S_ISLNK(dir->info.st_mode) || S_ISREG(dir->info.st_mode))
		{
			//printf("passe la\n");
			//printf("%s -> file\n ", argv[i]);
			dir->options[4] == 1 ? ft_sort_date(&dir->file_param, dir, argv[i]) : 0;
			dir->options[4] == 0 ? ft_sort_name(&dir->file_param, dir, argv[i]) : 0;
		}	
		if (!dir->info.st_mode)
		{
			//printf("%s -> bad\n", argv[i]);
			ft_sort_name(&dir->bad_param, dir, argv[i]);
		}
		if (S_ISDIR(dir->info.st_mode))
		{
			//if (dir->options[7] == 1)
				//dir->param->optDD = ft_strdup(argv[i]);
			//printf("surprise:%s\n", dir->param->optDD);
			//printf("%s -> param\n ", argv[i]);

			dir->options[4] == 1 ? ft_sort_date(&dir->param, dir, argv[i]) : 0;
			dir->options[4] == 0 ? ft_sort_name(&dir->param, dir, argv[i]) : 0;
		}
		dir->info.st_mode = 0;
		i++;
	}
	//printf("fini sort options\n");

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
	//printf("Est dans check_first");
	if (tree->left)
	{
		//printf("left\n");
		ft_check_first(tree->left, dir);
	}
	else
		dir->first = ft_strdup(tree->name);
		//printf("checkfirst %s\n", tree->name);
}
void			ft_check_options(t_dir *dir, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc && (!ft_strequ("--", argv[i])) && (argv[i][0] == '-' 
				&& !ft_strequ("-", argv[i])))
	{
		ft_is_false(dir, argv[i]);
		ft_strchr(argv[i], 'l') ? (dir->options[0] = 1) : 0;
		ft_strchr(argv[i], 'R') ? (dir->options[1] = 1) : 0;
		ft_strchr(argv[i], 'a') ? (dir->options[2] = 1) : 0;
		ft_strchr(argv[i], 'r') ? (dir->options[3] = 1) : 0;
		ft_strchr(argv[i], 't') ? (dir->options[4] = 1) : 0;
		ft_strchr(argv[i], '1') ? (dir->options[5] = 1) : 0;
		ft_strchr(argv[i], 'F') ? (dir->options[6] = 1) : 0;
		ft_strchr(argv[i], 'd') ? (dir->options[7] = 1) : 0;

		i++;
	}
	if (ft_strequ(argv[i], "--"))
		i++;
	if (i == argc)
	{
		//printf("egale\n");
		ft_sort_name(&dir->param, dir, ".");
	}
	if (i < argc - 1)
		dir->first_result = 1;
	else
		dir->first_result = 0;
	ft_sort_options(dir, argv, i);
}
