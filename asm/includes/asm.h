/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*      asm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:29:11 by fmaury            #+#    #+#             */
/*   Updated: 2017/05/13 13:41:58 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op.h"
# include "../Libft/printf/printf.h"
# include "../Libft/srclib/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct		s_asm
{
					int		fd;
					char	*file;
					char	*name;
					char	*comment;
					char	*content;
					char	header[PROG_NAME_LENGTH + COMMENT_LENGTH];
}					t_asm;

int				ft_launcher(char *file);
int				ft_head(t_asm *sfile);
int				ft_set_header(t_asm *sfile);
int				ft_write(t_asm *sfile);

#endif
