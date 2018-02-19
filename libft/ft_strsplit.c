/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:59:18 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:59:19 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		i;
	int		nbword;
	size_t	length;

	if (!s)
		return (NULL);
	i = 0;
	nbword = ft_count_word(s, c);
	if (!(dest = ((char **)malloc(sizeof(*dest) * (nbword + 1)))))
		return (NULL);
	while (nbword--)
	{
		while (*s != '\0' && *s == c)
			s++;
		length = ft_strlen_split(s, c);
		dest[i] = ft_strsub(s, 0, length);
		if (dest[i] == '\0')
			return (NULL);
		s = s + ft_strlen_split(s, c);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
