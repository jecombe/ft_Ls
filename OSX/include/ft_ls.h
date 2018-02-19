/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 13:09:25 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 14:46:11 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/sysmacros.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>

typedef struct		s_tree
{
	struct	s_tree	*left;
	struct	s_tree	*right;

	char			*name;
	char			**list_long;
	int				isdir;
	unsigned int	time;
	long			nanosec;
	char			*print;
	char			*linelist;
	char			*optDD;
	int				reg;
	int				dir;
	int				lnk;
	int				symbol;
	int				fifo;



}					t_tree;

typedef struct		s_result
{
	char *un;
	char *deux;
	char *trois;
	char *quatre;
	char *cinq;
	char *six;
	char *sept;
	char *huit;


}					t_result;

typedef struct		s_dir
{
	int				*options;
	int				multiple_dir;
	char			*path;
	char			**name_dir;
	char			**wrong_dir;
	char			**no_dir;
	char			*path_dir;
	char			*first;
	int				first_result;
	char			*optD;
	struct	dirent	*file;
	struct	stat	info;
	struct group	*group;
	struct	passwd	*user;
	int				*max_len;
	DIR			*dir;
	DIR			*dir2;

	t_tree			*node;
	t_tree			*param;
	t_tree			*file_param;
	t_tree			*bad_param;

	blkcnt_t		sizeblock;

}					t_dir;

void		ft_init(t_dir *dir);
void		ft_check_options(t_dir *dir, int argc, char **argv);
void		ft_sort_name(t_tree **tree_ftname, t_dir *dir, char *name);
char		**ft_list_long(t_dir *dir, char *param);
void		ft_sort_date(t_tree **tree_fdate, t_dir *dir, char *name);
void		ft_print_tree(t_tree *tree, t_dir *dir);
int			ft_list(t_dir *dir, char *name);
void		ft_print_tree_rev(t_tree *tree, t_dir *dir);
void		ft_print(t_dir *dir, char *name);
void		ft_print_error(t_dir *dir, char *current, char *name);
void		ft_create_path(char *path, char *current, char *name);
void		ft_free_dir(t_dir *dir);
void		ft_check_first(t_tree *tree, t_dir *dir);
void		ft_print_param(t_dir *dir, t_tree *tree);
void		ft_sort_name(t_tree **tree_ftname, t_dir *dir, char *name);
void		ft_sort_date(t_tree **tree_ftname, t_dir *dir, char *name);
t_tree		*ft_create_node(t_dir *dir, char *param);
void		ft_free(t_tree *tree);
void		ft_recurs(t_tree *tree, t_dir *dir, char *current);
void		ft_recurs_rev(t_tree *tree, t_dir *dir, char *current);
int			ft_create_tree(char *current, t_dir *dir);
void		ft_init_node(t_tree *node);
t_tree		*tree_init(void);
#endif
