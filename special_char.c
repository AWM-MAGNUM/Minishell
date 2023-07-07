#include "minishell.h"
char    check_special(char *str,t_copy *env)
{
    char *end = str + strlen(str);

    if (check_for_symbol(str, end, "\"'$"))
    {
        char *processed_str = handle_quotes_and_dollar(str, env_list);
        free(str);
        return processed_str;
    }
    return str;
}

char    handle_quotes_and_dollar(str,env_list)
{
    
}