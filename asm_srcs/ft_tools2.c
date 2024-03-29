/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:05:09 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 21:50:32 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_iscom(char c)
{
	if (c == COMMENT_CHAR)
		return (1);
	return (0);
}

char	*ft_erase_dc(char *str)
{
	char	*tmp;

	tmp = str + 1;
	tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

void	ft_col(t_champ *champ)
{
	int		i;

	i = 0;
	while (champ->line[i] != LABEL_CHAR)
		i++;
	champ->col = i - 1;
}

int		ft_space_bef(char *line)
{
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}
