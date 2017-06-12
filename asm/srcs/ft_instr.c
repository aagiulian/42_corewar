#include "asm.h"

extern t_op op_tab[17];

int		ft_split_instr(char c)
{
	if (ft_isspace(c) || c == SEPARATOR_CHAR)
		return (1);
	return (0);
}

int		ft_set_codage(char *str, t_asm *sfile)
{
	int i;
	unsigned char desc;
	char **tab;
	char *tmp;
	int		size;

	i = 0;
	desc = 0;
	size = 1;
	tab = ft_strsplitnbif(str, ft_split_instr, 2);
	while (tab[i] && i < 4)
	{
		desc <<= 2;
		if (tab[i][0] == 'r')
		{
			size += T_REG;
			desc |= REG_CODE;
			tmp = tab[i] + 1;
			ft_printf("tmp:%s sisze:%d\n",tmp,size);
			sfile->instr[size] = ft_atoi(tmp);
		}
		else if (tab[i][0] == DIRECT_CHAR)
		{
			size += DIR_SIZE;
			desc |= DIR_CODE;
			tmp = tab[i] + 1;
			ft_printf("tmpatiu:%d size:%d\n",ft_atoi(tmp),size);
			sfile->instr[size] = ft_atoi(tmp);
		}
		else if (ft_isstrdigit(tab[i]))
		{
			size += IND_SIZE;
			desc |= IND_CODE;
			sfile->instr[size] = ft_atoi(tab[i]);
		}
		i++;
	}
	while (i < 4)
	{
		desc <<= 2;
		i++;
	}
	sfile->instr[1] = desc;
	ft_free_strtab(tab);
	return (0);
}

int		ft_size_instr(char *str, t_asm *sfile)
{
	char **tab;
	int size;
	int i;

	i = 0;
	size = 2;
	tab = ft_strsplitnbif(str, ft_split_instr, 2);
	while (tab[i])
	{
		if (tab[i][0] == 'r')
			size += T_REG;
		else if (tab[i][0] == DIRECT_CHAR)
			size += DIR_SIZE;
		else if (ft_isstrdigit(tab[i]))
			size += IND_SIZE;
		i++;
	}
	sfile->instr = ft_strnew(size);
	ft_free_strtab(tab);
	return (size);
}

int		ft_start_instr(char *instr, t_asm *sfile)
{
	int i;

	i = 0;
	while (op_tab[i].instr && ft_strcmp(op_tab[i].instr, instr))
		i++;
	if (op_tab[i].instr)
		sfile->instr[0]= op_tab[i].opcode;
	return (0);
}

int		ft_trt_instr(t_asm *sfile, char **tab)
{
	int size;

	size = ft_size_instr(tab[1], sfile);
	ft_start_instr(tab[0], sfile);
	ft_set_codage(tab[1], sfile);
	sfile->content = ft_strljoin(sfile->content, sfile->instr, sfile->size, size);
	sfile->size += size;
	free(sfile->instr);
	return (0);
}
