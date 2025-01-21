./push_swap > test/empty.received
diff -s test/empty.expected test/empty.received

./push_swap word > test/error_single_non_int.received 2>&1
diff -s test/error.expected test/error_single_non_int.received

./push_swap 0 one 2 3 > test/error_contains_non_int.received 2>&1
diff -s test/error.expected test/error_contains_non_int.received

# INT_MAX = 2147483647
./push_swap 2147483648 > test/error_greater_than_INT_MAX.received 2>&1
diff -s test/error.expected test/error_greater_than_INT_MAX.received

# INT_MIN = -2147483648
./push_swap -2147483649 > test/error_lower_than_INT_MIN.received 2>&1
diff -s test/error.expected test/error_lower_than_INT_MIN.received

./push_swap 0 1 2 3 2 > test/error_contains_duplicates.received 2>&1
diff -s test/error.expected test/error_contains_duplicates.received

./push_swap 0 1 2 3 > test/ok_numbers.received
diff -s test/ok.expected test/ok_numbers.received

./push_swap "0 1 2 3" > test/ok_string.received
diff -s test/ok.expected test/ok_string.received

./push_swap "0 1 2       3" > test/ok_string_with_spaces.received
diff -s test/ok.expected test/ok_string_with_spaces.received
