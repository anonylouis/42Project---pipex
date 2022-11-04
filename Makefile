CC = gcc

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = pipex

SOURCES = commands1.c commands2.c error.c exec.c ft_memcmp.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c get_next_line.c get_next_line_utils.c main.c pipex.c print.c read_stdin.c utils.c
SRCS = $(addprefix ./srcs/, $(SOURCES))

OBJECTS = ${SOURCES:.c=.o}
OBJS = $(addprefix ./objs/, $(OBJECTS))

DEPENDENCIES = ${SOURCES:.c=.d}
DPDC = $(addprefix ./objs/, $(DEPENDENCIES))

HEADER = ./includes
HEADER_FILES=$(HEADER)/pipex.h $(HEADER)/command.h 

all : $(NAME)

$(NAME) :	$(OBJS)
		gcc $(FLAGS) -o $(NAME) $(OBJS)

clean : 
		rm -f $(OBJS) $(DPDC)

fclean : clean 
		rm -f $(NAME) 

re :	fclean all

./objs/%.o :	./srcs/%.c $(HEADER_FILES)
		mkdir -p objs
		$(CC) $(FLAGS) -MMD -I $(HEADER) -o $@ -c $<

.PHONY : all re clean fclean bonus

