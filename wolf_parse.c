#include "minishell.h"

int	check_append(char **ptr)
{
	int	tok;

	(*ptr)++;
	tok = '>';
	if (**ptr == '>')
	{
		(*ptr)++;
		tok = '+';
	}
	return (tok);
}

int	check_herdoc(char **ptr)
{
	int	tok;

	(*ptr)++;
	tok = '<';
	if (**ptr == '<')
	{
		(*ptr)++;
		tok = '*';
	}
	return (tok);
}

int ft_check_chock(char *str,char *str_end,char *symbol)
{
    if(!str)
        return(0);
    char *ptr = str;
    while(ptr < str_end)
    {
            if(strchr(symbol,*ptr))
                return (1);
            ptr++;
    }
        return(0);
}
int ft_spaces(char *str,char *str_end,char *symbol)
{
    char *whitespaces;
    whitespaces = " \t\r\n\f\v";

    char *ptr = str;
    while (ptr < str_end && strchr(whitespaces,*ptr))
        ptr++;
    if(*ptr && strchr(symbol,*ptr))
        return(1); // Vérifier le premier caractère non-espace
    return(0);   
}
