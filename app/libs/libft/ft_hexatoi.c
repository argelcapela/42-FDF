/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:41:09 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/11 13:12:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	extract_number(char hexa_letter)
{
	int		n;
	char	*l_base_16;

	l_base_16 = ft_strdup("0123456789ABCDEF");
	n = 0;
	while (l_base_16[n] != ft_toupper(hexa_letter))
		n++;
	return (n);
}

static void	convert_base(int len, char *hexa, int **integer)
{
	int	sum;
	int	exp;
	int	n;

	exp = 0;
	sum = 0;
	while (--len >= 0)
	{
		n = extract_number(hexa[len]);
		sum += n * (pow(16, exp));
		exp++;
	}
	*(*integer) = sum;
}

int	*ft_hexatoi(char *hexa)
{
	int		*integer;
	int		len;

	len = ft_strlen(hexa);
	integer = (int *) malloc(sizeof(int));
	if (integer == NULL)
		return (0);
	convert_base(len - 2, ft_substr(hexa, 2, len), &integer);
	return (integer);
}