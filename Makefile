# This is the macro used to identify the libft directory 
# to be used to cal the makefile of libft and retrieve the archive file

LIB_DIR := libft

# This is the $(CC) Macro that indicates 
# the compiler that we are using which is cc

CC = cc

# This is the $(CFLAGS) Macro that indicates 
# which flags we use in combination with $(CC) macros

CFLAGS = -Wall -Werror -Wextra

# This is the $(SRCS) Macro that indicates 
# which files we want to compile in this makefile

SRCS = libftprintf.c ft_printchar.c ft_printstr.c \
	ft_printint.c ft_printuint.c ft_printamp.c ft_printhex.c \
	ft_hexconvert.c ft_printptr.c ft_hexconvertptr.c 

# These objects are dependent on the sources macro
# This syntax means that it replaces all the .c to .o
# when the $(OBJS) macro is called.

OBJS = $(SRCS:.c=.o)

# This is the $(NAME) macro that is equivalent to the 
# libftprint.a file.

NAME = libftprintf.a

# This rule makes sure that the makefile will
# not accidently confuse the rules in this file for 
# physical files which could be called the same as the rules
# for example if there is a file called all, then this prevents
# the makefile from trying to do anything with that file called all

.PHONY: all clean fclean re

# This all is a rule that is dependent on $(NAME) rule
# because it is the first command in the makefile, it will be 
# triggered when we call "make" in the terminal

all: $(NAME) 

# This is a rule that is called $(NAME), which is dependent on
# $(LIB_DIR)/libft.a rule, which first goes into the libft directory 
# to call it's makefile that then copies to libft.a into the local directory
# and names it libftprintf.a. It is also dependent on 
# $(OBJS), which once it's updates, fires the ar command to 
# (r)eplace files in archive that been changed, (c) create new 
# files if they did not exist yet, and reindex(s) the archive
# to make it easier to locate files

$(NAME): $(LIB_DIR)/libft.a $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIB_DIR)/libft.a: 
	@$(MAKE) -C $(LIB_DIR) all
	cp libft/libft.a libftprintf.a
	

# all command is dependent on .o files existing, so this rule
# will make sure to (re)create them if neccessary. This rule is a 
# a pattern rule ‘%.o : %.c’ that says how to make any file stem.o 
# from another file stem.c. It uses the automatic variable $@ for 
# source file which is %.o and $< for each target file which is %.c
# and it will apply this rule for each case. -c is to make object files
# and -o to then name those .o files.

 %.o: %.c
	$(CC) $(CFLAGS) -c $<  -o $@

# This rule has a phony target. This rule will first call
# the clean command in the makefile of libft. Then the command 
# will forcefully remove all elements that are in 
# $(OBJS) macro.

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	rm -f $(OBJS)

# This rule has a target which is clean
# This will make sure clean is up to date and 
# execute it's commands before, it then calles the fclean of 
# the libft makefile and then it cleans the 
# $(NAME) macro

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

# This rule has a target which is fclean
# This will make sure fclean is up to date and 
# execute it's commands before. Then it will do the
# same with all.

re: fclean all
