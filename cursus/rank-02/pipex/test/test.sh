./pipex > test/output_stdout_pipex 2>test/output_stderr_pipex
diff -s test/output_stderr_pipex test/error_bad_arguments.txt

./pipex test/input > test/output_stdout_pipex 2>test/output_stderr_pipex
diff -s test/output_stderr_pipex test/error_bad_arguments.txt

./pipex test/input "ls -l" > test/output_stdout_pipex 2>test/output_stderr_pipex
diff -s test/output_stderr_pipex test/error_bad_arguments.txt

./pipex test/input "ls -l" "wc -l" > test/output_stdout_pipex 2>test/output_stderr_pipex
diff -s test/output_stderr_pipex test/error_bad_arguments.txt

./pipex test/input "lz -l" "wc -l"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  lz -l | wc -l > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# ./pipex test/input "" "cat" test/output_pipex \
# 	> test/error_empty_cmd1_output 2>&1 \
# 	; diff -s test/error_empty_cmd1_output test/error_unknown_cmd.txt

# ./pipex test/input "ls -l" "" test/output_pipex \
# 	> test/error_empty_cmd2_output 2>&1 \
# 	; diff -s test/error_empty_cmd2_output test/error_unknown_cmd.txt

# ./pipex "" "ls -l" "wc -l" test/output_pipex \
# 	> test/error_empty_infile_arg_output 2>&1 \
# 	; diff -s test/error_empty_infile_arg_output test/error_empty_file_arg_file.txt

# ./pipex test/input "ls -l" "wc -l" "" \
# 	> test/error_empty_outfile_arg_output 2>&1 \
# 	; diff -s test/error_empty_outfile_arg_output test/error_empty_file_arg_file.txt

# ./pipex "" "ls -l" "wc -l" "" \
# 	> test/error_empty_both_files_arg_output 2>&1 \
# 	; diff -s test/error_empty_both_files_arg_output test/error_empty_both_files_arg_file.txt

# ./pipex test/non-existent-file "ls -l" "wc -l" test/output_pipex \
# 	> test/error_invalid_file_output 2>&1 \
# 	; diff -s test/error_invalid_file_output test/error_invalid_file.txt

# chmod -r test/input
# ./pipex test/input "ls -l" "wc -l"  ""  > test/output_stdout_pipex 2>test/output_stderr_pipex
# (<      test/input  ls -l | wc -l > "") > test/output_stdout_shell 2>test/output_stderr_shell
# chmod +r test/input
# diff -s test/output_stdout_pipex test/output_stdout_shell
# diff -s test/output_stderr_pipex test/output_stderr_shell

# ./pipex test/input "ls -l" "wc -l"  test/input_output_pipex \
# 	&& <  test/input  ls -l | wc -l > test/input_output_shell \
# 	&& diff -s test/input_output_pipex test/input_output_shell

# ./pipex test/lorem "cat" "wc -m"  test/lorem_output_pipex \
# 	&& <  test/lorem  cat | wc -m > test/lorem_output_shell \
# 	&& diff -s test/lorem_output_pipex test/lorem_output_shell

# ./pipex test/letters "cat" "sort"  test/letters_output_pipex \
# 	&& <  test/letters  cat | sort > test/letters_output_shell \
# 	&& diff -s test/letters_output_pipex test/letters_output_shell

# ./pipex test/pokemon "cat" "sort"  test/pokemon_output_pipex \
# 	&& <  test/pokemon  cat | sort > test/pokemon_output_shell \
# 	&& diff -s test/pokemon_output_pipex test/pokemon_output_shell

# ./pipex test/names "cat" "sort -f"  test/names_output_pipex \
# 	&& <  test/names  cat | sort -f > test/names_output_shell \
# 	&& diff -s test/names_output_pipex test/names_output_shell

# ./pipex /dev/null "cat" "sort"  test/null_output_pipex \
# 	&& <  /dev/null  cat | sort > test/null_output_shell \
# 	&& diff -s test/null_output_pipex test/null_output_shell

# ./pipex test/pokemon "rev" "sort"  test/pokemon_rev_output_pipex \
# 	&& <  test/pokemon  rev | sort > test/pokemon_rev_output_shell \
# 	&& diff -s test/pokemon_rev_output_pipex test/pokemon_rev_output_shell

# ./pipex test/names "tr '[:upper:]' '[:lower:]'" "sort"  test/names_lowercase_output_pipex \
# 	&& <  test/names  tr '[:upper:]' '[:lower:]' | sort > test/names_lowercase_output_shell \
# 	&& diff -s test/names_lowercase_output_pipex test/names_lowercase_output_shell

# ./pipex test/lorem "head -n 10" "tail -n 5"  test/lorem_head_tail_output_pipex \
# 	&& <  test/lorem  head -n 10 | tail -n 5 > test/lorem_head_tail_output_shell \
# 	&& diff -s test/lorem_head_tail_output_pipex test/lorem_head_tail_output_shell

# ./pipex test/lorem "grep a" "wc -l"  test/lorem_count_a_output_pipex \
# 	&& <  test/lorem  grep a | wc -l > test/lorem_count_a_output_shell \
# 	&& diff -s test/lorem_count_a_output_pipex test/lorem_count_a_output_shell
