/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:51:59 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:52:00 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *oct1;
	unsigned char *oct2;

	oct1 = (unsigned char*)dst;
	oct2 = (unsigned char*)src;
	while (n--)
	{
		*oct1 = *oct2;
		if (*oct1 == (unsigned char)c)
			return (oct1 + 1);
		oct1++;
		oct2++;
	}
	return (NULL);
}
