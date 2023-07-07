#include "minishell.h"

int			main(int ac, char **av, char **env)
{
     while(1)
    {
        char *str = readline("minishell: ");
        if (!str)
            exit(1);
        int end = strlen(str);
        t_type *cmd = pipe_commands(&str , str + end, NULL);
        {
            if (cmd == NULL)
                exit(1);
        }
        
    }
}