/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:58:00 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:58:01 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
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
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
