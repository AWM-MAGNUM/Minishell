#include "minishell.h"

t_type	*pipe_commands(char **str, char *str_end, t_copy *env)
{
   t_type *cmd;

   cmd = single_command(str,str_end,env);
   if(ft_check_chock(*str,*str_end,"|"))
   {
        if (!*((t_exec *)cmd)->args && !((t_exec *)cmd)->cmd)
			return (NULL);// si la commande est vide apres le pipe
        get_token(*str,str_end,0,0);
        cmd = create_data_pipe(cmd,pars_pipe(str,str_end,env));
   }
        return (cmd);
}

t_type	*single_command(char **str, char *str_end, t_copy *env)
{
    t_exec *exec_cmd;
    t_type *cmd;
    char *ptr;
    char *ptr_end;

    exec_cmd = (t_exec*)create_data_exec();
    exec_cmd->argc = 0;
    cmd = (t_type*)exec_cmd; //polymorphisme
    cmd = redirection_commands(cmd,str,str_end,env);
    while (!ft_check_chock(str,str_end,"|"))
    {
        if(get_token(*str,str_end,ptr,ptr_end) == 0)
            break;
        else
            add_arg_to_list(substring_copy(ptr,ptr_end), &exec_cmd->args[exec_cmd->argc],&exec_cmd->argc);
        cmd = redirection_commands(cmd,str,str_end,env);
    }
    exec_cmd->args[exec_cmd->argc] = 0; // P,NULL
    return((t_type*)cmd);
}

t_type *redirection_commands(t_type *cmd,char **str,char *str_end,t_copy *env)
{
    char *ptr;
    char *ptr_end;
    int token;
    t_redir *redir_cmd;

    while (ft_check_chock(str,str_end,"<>"))
    {
        token = get_token(str,str_end,&ptr,&ptr_end)
        
    }
    
}