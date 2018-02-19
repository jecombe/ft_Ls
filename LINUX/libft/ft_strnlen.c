/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:58:53 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:58:54 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strnlen(const char *s, size_t maxlen)
{
	size_t len;

	len = 0;
	while (len < maxlen)
	{
		if (!*s)
			return (0);
		len++;
		s++;
	}
	return (len);
}
