/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:56:49 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:56:51 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	if (!(ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ptr = ft_strcpy(ptr, s1);
	ptr = ft_strcat(ptr, s2);
	return (ptr);
}
