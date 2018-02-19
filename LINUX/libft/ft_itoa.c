/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <jecombe@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/15 15:50:41 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/15 15:50:43 by jecombe     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(int n)
{
	int i;

	i = 0;
	if (i < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		count;
	int		i;

	count = ft_count(n);
	i = 0;
	if (n < 0 || count == 0)
		count++;
	if (!(dest = ft_strnew(count)))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		dest[0] = '-';
		i++;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (count > i)
	{
		count--;
		dest[count] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}
