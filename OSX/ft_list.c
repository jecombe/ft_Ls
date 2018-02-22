/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 15:42:57 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 17:36:49 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/ft_ls.h"
char        *ft_permissions(t_dir *dir)
{
	char    *perm;
	perm = ft_strnew(11);

	S_ISLNK(dir->info.st_mode) ? perm[0] = 'l' : 0;
	S_ISREG(dir->info.st_mode) ? perm[0] = '-' : 0;
	S_ISDIR(dir->info.st_mode) ? perm[0] = 'd' : 0;
	S_ISCHR(dir->info.st_mode) ? perm[0] = 'c' : 0;
	S_ISBLK(dir->info.st_mode) ? perm[0] = 'b' : 0;
	S_ISFIFO(dir->info.st_mode) ? perm[0] = 'p' : '-';
	perm[1] = dir->info.st_mode & S_IRUSR ? 'r' : '-';
	perm[2] = dir->info.st_mode & S_IWUSR ? 'w' : '-';
	perm[3] = dir->info.st_mode & S_IXUSR ? 'x' : '-';
	if (dir->info.st_mode & S_ISUID)
		perm[3] = dir->info.st_mode & S_IXUSR ? 's' : 'S';
	perm[4] = dir->info.st_mode & S_IRGRP ? 'r' : '-';
	perm[5] = dir->info.st_mode & S_IWGRP ? 'w' : '-';
	perm[6] = dir->info.st_mode & S_IXGRP ? 'x' : '-';
	if (dir->info.st_mode & S_ISUID)
		perm[6] = dir->info.st_mode & S_IXUSR ? 's' : 'S';
	perm[7] = dir->info.st_mode & S_IROTH ? 'r' : '-';
	perm[8] = dir->info.st_mode & S_IWOTH ? 'w' : '-';
	perm[9] = dir->info.st_mode & S_IXOTH ? 'x' : '-';
	if (dir->info.st_mode & S_ISUID)
		perm[9] = dir->info.st_mode & S_IXUSR ? 't' : 'T';;
	return (perm);

}

char		*ft_device(t_dir *dir)
{
	char *device;
	char *temp;

	if (S_ISCHR(dir->info.st_mode) || S_ISBLK(dir->info.st_mode))
	{
		device = ft_strnew(12);
		temp = ft_itoa(major(dir->info.st_rdev));
		ft_strcpy(device, temp);
		free(temp);
		ft_strcpy(&device[ft_strlen(device)], ",  ");
		temp = ft_itoa(minor(dir->info.st_rdev));
		ft_strcpy(&device[ft_strlen(device) - 1 - ft_strlen(temp)], temp);
		free(temp);
	}
	else 
		device = ft_itoa(dir->info.st_size);
return (device);

}

char				*ft_modif_date(t_dir *dir)
{
	time_t			actual;
	char			*tmp;
	char			*modif;

	actual = 0;
	time(&actual);
	tmp = ft_strdup(ctime(&dir->info.st_mtime));
	modif = ft_strnew(ft_strlen(tmp));
	 if (dir->info.st_mtime < (actual - 15778800) ||
			dir->info.st_mtime > (actual + 15778800))
	{
		ft_strncpy(modif, &tmp[4], 7);
		ft_strncpy(&modif[ft_strlen(modif)], &tmp[19], 5);
	}
	else
		ft_strncpy(modif, &tmp[4], 12);
	free(tmp);
	return (modif);
}

char				**ft_list_long(t_dir *dir, char *param)
{
	char			**tab;
	int				len;
	tab = ft_memalloc(sizeof(char *) * 8);
	dir->user = getpwuid(dir->info.st_uid);
	dir->sizeblock = dir->sizeblock + dir->info.st_blocks;
	dir->group = getgrgid(dir->info.st_gid);
	tab[0] = ft_permissions(dir);
	tab[1] = ft_itoa(dir->info.st_nlink);
	tab[2] = (dir->user ? ft_strdup(dir->user->pw_name) :
			ft_itoa(dir->info.st_uid));
	tab[3] = (dir->group ? ft_strdup(dir->group->gr_name) : ft_itoa(dir->info.st_gid));
	tab[4] = ft_device(dir);
	tab[5] = ft_modif_date(dir);
	tab[6] = param ? ft_strdup(param) : ft_strdup(dir->file->d_name);
	tab[7] = ft_strnew(PATH_MAX);
	if (S_ISLNK(dir->info.st_mode))
	{
		len = readlink(dir->path, tab[7], 1024);
		tab[7][len] = '\0';
	}

	return (tab);
}

int				ft_list(t_dir *dir, char *name)
{
	short int i;

	i = 0;
	dir->sizeblock = 0;
	dir->node = NULL;
	if (ft_create_tree(name, dir) == -1)
		return (-1);
	ft_print(dir, name);
	if (dir->options[1] == 0)
		ft_free(dir->node);
	else
	{
		if (dir->options[3] == 1)
			ft_recurs_rev(dir->node, dir, name);
		else
			ft_recurs(dir->node, dir, name);
	}
	return (0);
}
