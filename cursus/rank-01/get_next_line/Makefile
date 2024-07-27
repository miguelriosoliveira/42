SRC = get_next_line.c get_next_line_utils.c
CC = gcc -Wall -Werror -Wextra
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

test: no_size size_1 size_10 size_9999 #size_10000000

# ====================================== BONUS ======================================

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

bonus_run:
	./test/a.out test/empty.txt test/file.txt test/hp1.txt

bonus_no_size:
	$(CC) $(SRC_BONUS) test/main_bonus.c -o test/a.out
	make bonus_run

bonus_size_%:
	$(CC) $(SRC_BONUS) test/main_bonus.c -o test/a.out $(BUFFER_FLAG)=$(@:bonus_size_%=%)
	make bonus_run

bonus_test: bonus_no_size bonus_size_1 bonus_size_10 bonus_size_9999 #bonus_size_10000000
