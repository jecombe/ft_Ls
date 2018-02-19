/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:56:11 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:56:12 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;
	char	*p;

	len = 0;
	while (s1[len])
		len++;
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	p = copy;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (copy);
}
