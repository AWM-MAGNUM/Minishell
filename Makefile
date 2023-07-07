NAMES = minishell 
 
CFILES = parser.c

CC = CC -g

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -lreadline

all :  $(NAMES)

$(NAMES) : $(CFILES)
			$(CC) $(CFLAGS) $(CFILES) -o minishell

clean : 
		$(RM) $(NAMES)

fclean : clean 

re : fclean all 
