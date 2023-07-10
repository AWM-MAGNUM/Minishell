#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    (void)envp;
    t_copy *envt = env(NULL,envp);
    (void)envt;
    (void)argc,(void)argv;
    t_exec *exec_command = NULL;
    t_pipe *pipe_command = NULL;
    t_redir *redirection_command = NULL;

    while(1)
    {
       char *str = readline("\033[1;31me1r5p5 :: \033[0m\033[1;32m~/Desktop/minishell » \033[0m");
        if (!str)
            exit(1);
        add_history(str);
        // if(!strcmp(str,"env"))
            // print_env(envt);
        char *expanded_value = func_double_qoutes_expand(str);
        if (expanded_value != NULL)
            printf("%s\n", expanded_value);
        int end = strlen(str);
        t_type *cmd = pipe_commands(&str , str + end, NULL);
        if (cmd == NULL)
            exit(1);
        while(cmd)
        {
            if(cmd->type == 1)
            {
                exec_command = (t_exec *)cmd;

                // printf("type de la commande execution : %d\n",exec_command->type);
                // printf("%s\n",exec_command->args[0]);
                cmd = exec_command->cmd;
            }
            else if(cmd->type == 2)
            {
                pipe_command = (t_pipe*)cmd;
                // printf("type de la commande pipe : %d\n",pipe_command->type);
                cmd = pipe_command->leftcmd;
                // cmd = pipe_command->rightcmd;
            }
            else if(cmd->type == 3)
            {
                redirection_command = (t_redir *)cmd;
                printf("type de la commande redirection : %d\n",redirection_command->type);
                printf("%s\n",redirection_command->filename);
                cmd = redirection_command->cmd;
            }
            else
                break;
        }
    }
    return(0);
}
