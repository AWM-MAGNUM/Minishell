# ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
#include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

# define EXEC 1
# define PIPE 2
# define REDIR 3
# define HERDOC 4

typedef struct v_type
{
    int type;
}      t_type;

typedef struct v_exec
{
    int type;
    char *args[1024];
    int argc;
    t_type *cmd;
}           t_exec;

typedef struct v_pipe
{
    int type;
    struct  v_type *rightcmd;
    struct  v_type *leftcmd;
}       t_pipe;

typedef struct v_redir
{
    int type;
    char *filename;
    t_type  *cmd;
    int open_file;
    int fd;
    int flags;
}       t_redir;

typedef struct v_copy
{
    char *content;
    struct v_list *next;
}   t_copy;

/*lexer*/
int	get_token(char **str, char *str_end, char **previous, char **ep);
int	token(char **ptr, char *str_end, int tok);
/*lexer_func*/
char	*substring_copy(char *str, char *after_str);



/* parser_ */
t_type	*pipe_commands(char **str, char *str_end, t_copy *env);
t_type	*single_command(char **str, char *str_end, t_copy *env);
t_type *redirection_commands(t_type *cmd,char **str,char *str_end,t_copy *env);

/*annexe_func_parse*/
void    add_arg_to_list(char *str,char **args,int *argc);

/*allocation*/
t_type *create_data_exec(void);
t_type *create_data_pipe(t_type *right_cmd,t_type *left_cmd);

/*cheaker*/
int ft_check_chock(char *str,char *str_end,char *symbol);
int ft_spaces(char *str,char *str_end,char *symbol);

#endif