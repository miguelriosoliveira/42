./push_swap \
	> test/empty.received \
	&& diff -s test/empty.received test/empty.expected

./push_swap word \
	> test/error_single_non_int.received 2>&1 \
	; diff -s test/error_single_non_int.received test/error.expected

./push_swap 0 one 2 3 \
	> test/error_contains_non_int.received 2>&1 \
	; diff -s test/error_contains_non_int.received test/error.expected
