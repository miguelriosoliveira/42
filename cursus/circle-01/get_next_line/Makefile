SRC = get_next_line.c get_next_line_utils.c
CC = cc -Wall -Werror -Wextra
BUFFER_FLAG = -D BUFFER_SIZE
RM = rm -rf

run:
	./test/a.out test/empty.txt
	./test/a.out test/file.txt
	./test/a.out test/hp1.txt

no_size:
	$(CC) $(SRC) test/main.c -o test/a.out
	make run

size_%:
	$(CC) $(BUFFER_FLAG)=$(@:size_%=%) $(SRC) test/main.c -o test/a.out
	make run

test: no_size #size_1 size_10 size_9999 size_10000000
