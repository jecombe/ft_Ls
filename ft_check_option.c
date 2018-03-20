/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_options.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:40:33 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 13:53:40 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"

void			ft_no_param(t_dir *dir, char *argv)
{
	if (!dir->info.st_mode)
	{
		ft_check_g_a(dir);
		ft_sort_name(&dir->bad_param, dir, argv);
	}
}

void			ft_sort_option_next(t_dir *dir, char **argv, int i)
{
	while (argv[i])
	{
		if (!argv[i][0])
		{
			ft_putstr("ls: fts_open: No such file or directory\n");
			exit(1);
		}
		lstat(argv[i], &dir->info);
		if (S_ISLNK(dir->info.st_mode) || S_ISREG(dir->info.st_mode))
		{
			ft_check_g_a(dir);
			dir->options[4] == 1 ? ft_sort_date(&dir->file_p, dir, argv[i]) : 0;
			dir->options[4] == 0 ? ft_sort_name(&dir->file_p, dir, argv[i]) : 0;
		}
		ft_no_param(dir, argv[i]);
		if (S_ISDIR(dir->info.st_mode))
		{
			g_a++;
			dir->name2 = argv[i];
			dir->options[4] == 1 ? ft_sort_date(&dir->param, dir, argv[i]) : 0;
			dir->options[4] == 0 ? ft_sort_name(&dir->param, dir, argv[i]) : 0;
		}
		dir->info.st_mode = 0;
		i++;
	}
}

void			ft_sort_options(t_dir *dir, char **argv, int i)
{
	if (g_o == 1)
	{
		lstat(argv[i], &dir->info);
		if (S_ISDIR(dir->info.st_mode))
		{
			dir->name2 = argv[i];
			dir->options[4] == 1 ? ft_sort_date(&dir->param, dir, ".") : 0;
			dir->options[4] == 0 ? ft_sort_name(&dir->param, dir, ".") : 0;
		}
		dir->name2 = NULL;
	}
	if (g_o != 1)
		ft_sort_option_next(dir, argv, i);
}

void			ft_check_options_next(t_dir *dir, int argc, char **argv, int i)
{
	int o;

	o = 0;
	if (i == argc)
	{
		if (dir->options[1] == 1 && dir->options[0] == 1)
		{
			g_o = 1;
			while (argv[o])
				o++;
			argv[o] = ".";
			ft_sort_options(dir, argv, i);
			g_o = 0;
			return ;
		}
		ft_sort_name(&dir->param, dir, ".");
	}
	(i < argc - 1) ? dir->first_result = 1 : 0;
	ft_sort_options(dir, argv, i);
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
		i++;
	}
	if (ft_strequ(argv[i], "--"))
		i++;
	ft_check_options_next(dir, argc, argv, i);
	dir->name2 = NULL;
}
