#include "minishell.h"

char *find_end_of_var(char *str)
{
    while (*str && *str != '\'' && *str != '\"')
        str++;
    return (str);
}

char *func_double_qoutes_expand(char *str)
{
    char *key = strchr(str, '$');
    if (key != NULL)
    {
        if (key != NULL)
        {
            if ((key > str && *(key - 1) == '\'') || *(key + 1) == '\'') 
            {
            printf("syntax error: %s: command not found \n", key);
            return NULL;
            }
        }
        else if ((key > str && *(key - 1) == '\"')) 
        {
            char *quote = strchr(key, '\"');
            if (quote != NULL) 
            {
                key++;
                char *end = find_end_of_var(key);
                if (end != NULL && *end == '\"') 
                {
                    *end = '\0';
                    char *value = getenv(key);
                    if (value != NULL)
                        return value;
                }
            }
        }
        else if ((key == str || *(key - 1) != '\"') && *(key+1) != '\0' && *(key+1) != '\'')
        {
            key++;
            char *end = find_end_of_var(key);
            if (end != NULL && *end != '\"') 
            {
                *end = '\0';
                char *value = getenv(key);
                if (value != NULL)
                    return value;
            }
        }
            printf("syntax error: unexpected end of file \n");
    }
    return 0;
}
