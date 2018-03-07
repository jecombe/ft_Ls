/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:59:35 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:59:37 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	while (s[start] != '\0' && len--)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
