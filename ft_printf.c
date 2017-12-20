#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	flag_type	flag;
	wii			wiit;
	char		*cur_arg = (char *)format;
	int			ret;
	spe_c		spec;
	
	ret = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	wiit = ft_watinit(format, ft_size_tab(format));
//	printf("test de watinit\n");
	va_start(ap, format);
	while(wiit.tab[i])
	{
		if (wiit.pos_conv[i] == 0)
		{
			ret = ret + ft_strlen(wiit.tab[i]);
			ft_putstr(wiit.tab[i]);
			free(wiit.tab[i]);
		}
		else if (wiit.pos_conv[i] == 1)
		{
//			printf("wiit.tab[i] est [%s]", wiit.tab[i]);
			flag = ft_arg_conv(wiit.tab[i]); 
//			printf("test des valeurs des flags\ncn : [%d] | wi : [%d] | pr : [%d] | - : [%d] | + : [%d] | # : [%d] | 0 : [%d] | sp : [%d] | . : [%d] |\n", flag.conv_num, flag.width, flag.preci, flag.minus, flag.plus, flag.dies, flag.zero, flag.space, flag.point);
			cur_arg = ft_what_type(flag.conv_num, ap);
//			printf("wiit.tab[i] est [%s]", wiit.tab[i]);
//			printf("cur_arg est [%c%c]", cur_arg[0], cur_arg[1]);
//			printf("str est [%s]\n", cur_arg);
			if(flag.conv_num == -1)
			{
//				printf("1 l'argument est [%s]\n", cur_arg);
				if (flag.tab == NULL)
					cur_arg = ft_strdup(wiit.tab[i]);
				else
					cur_arg = ft_strdup(flag.tab);
				ret = ret + ft_strlen(cur_arg) ;
				ft_putstr(cur_arg);
//				free(cur_arg);
			}
			else if (flag.conv_num == 6 || flag.conv_num == 14)
			{
//				printf("2 l'argument est [%s]\n", cur_arg);
				spec = ft_special_c(cur_arg, flag);
				if(!(spec.tab))
					return (-1);
				ft_nputstr(spec.tab, spec.len);
				ret = ret + spec.len;
				if(flag.width > 1)
					free(spec.tab);
//				free(cur_arg);
			}
			else
			{
	//		printf("3 l'argument est [%s]\n", cur_arg);
				cur_arg = ft_flag_use(cur_arg, flag);
	//			printf("3.1 l'argument est [%s]\n", cur_arg);
				ret = ret + ft_strlen(cur_arg) ;
				ft_putstr(cur_arg);
//				free(cur_arg);
			}
/*			if (flag.conv_num == 6 || 14)
			{
				ft_nputstr(spec.tab, spec.len);
				ret = ret + spec.len;
				free(spec.tab);
			}
			else 
			{
				ret = ret + ft_strlen(cur_arg) ;
				ft_putstr(cur_arg);
				free(cur_arg);
			}
*/	//		printf("4 l'argument est [%s]\n", cur_arg);
			free(cur_arg);
			free(wiit.tab[i]);
		}
		i++;
	}
	va_end(ap);
	free(wiit.pos_conv);
	free(wiit.tab);
	return (ret);
}
