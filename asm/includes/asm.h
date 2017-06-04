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
				int fd;
				int size;
				char *file;
				char *name;
				char *comment;
				char *instr;
				char *content;
				char header[PROG_NAME_LENGTH + COMMENT_LENGTH];
				char **champ;
}					t_asm;

typedef struct		s_op
{
					char *instr;
					int nbargs;
					int *arg;
					int opcode;
					int cycle;
					char *name;
					int o;
					int sef;
}					t_op;

int				ft_launcher(char *file);
int				ft_head(t_asm *sfile);
int				ft_set_header(t_asm *sfile);
int				ft_asm(t_asm *sfile);
int				ft_write(t_asm *sfile);
int				ft_trt_instr(t_asm *sfile, char **tab);

#endif
