/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:00:27 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/17 16:50:08 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_wchardup_null()
{
	char	*tab;

	if(!(tab = malloc(sizeof(char)* 7)))
		return (NULL);
	tab[0] = '(';
	tab[1] = 'n';
	tab[2] = 'u';
	tab[3] = 'l';
	tab[4] = 'l';
	tab[5] = ')';
	tab[6] = '\0';
	return (NULL);
}

char	*ft_wchardup(wchar_t *s)
{
	int		i;
	int		j;
	char	*moc;

	if (s == NULL)
		return (ft_wchardup_null());
	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	moc = (char*)malloc(sizeof(wchar_t) * (i));
	if (!moc)
		return (NULL);
	while (j < i)
	{
		moc[j] = s[j];
		j++;
	}
	moc[j] = '\0';
	return (moc);
}
