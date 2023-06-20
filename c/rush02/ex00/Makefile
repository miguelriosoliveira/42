NAME	= rush-02
FILES	= *.c
OBJS	= ${FILES:.c=.o}
HEADER	= ftlib.h
CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

${NAME}:	${FILES}
					${CC} -c ${FLAGS} ${FILES}
					${CC} ${FLAGS} -o ${NAME} ${OBJS} -I ${HEADER}

all:		${NAME}

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:					fclean ${NAME}

.PHONY:		clean
					fclean
					all
					re
