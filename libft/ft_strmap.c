/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:57:51 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:57:52 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ptr = ft_strnew(ft_strlen(s))))
		return (NULL);
	if (s && f)
	{
		while (s[i] != '\0')
		{
			ptr[i] = f(s[i]);
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
