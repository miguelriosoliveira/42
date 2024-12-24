./push_swap \
	> test/empty.received \
	&& diff -s test/empty.received test/empty.expected

./push_swap word \
	> test/error_single_non_int.received 2>&1 \
	; diff -s test/error_single_non_int.received test/error.expected

./push_swap 0 one 2 3 \
	> test/error_contains_non_int.received 2>&1 \
	; diff -s test/error_contains_non_int.received test/error.expected

# INT_MAX = 2147483647
./push_swap 2147483648 \
	> test/error_greater_than_INT_MAX.received 2>&1 \
	; diff -s test/error_greater_than_INT_MAX.received test/error.expected

# INT_MIN = -2147483648
./push_swap -2147483649 \
	> test/error_lower_than_INT_MIN.received 2>&1 \
	; diff -s test/error_lower_than_INT_MIN.received test/error.expected
