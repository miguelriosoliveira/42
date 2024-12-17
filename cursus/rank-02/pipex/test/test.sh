./pipex

./pipex test/input

./pipex test/input "ls -l"

./pipex test/input "ls -l" "wc -l"

./pipex test/input "lssss -l" "wc -l" test/output_pipex

./pipex test/non-existent-file "ls -l" "wc -l" test/output_pipex

touch test/invalid_permission_read_input \
	&& chmod -r test/invalid_permission_read_input \
	&& ./pipex test/invalid_permission_read_input "ls -l" "wc -l" test/output_pipex \
	; rm test/invalid_permission_read_input

./pipex test/input "ls -l" "wc -l"  test/input_output_pipex \
	&& <  test/input  ls -l | wc -l > test/input_output_shell \
	&& diff -s test/input_output_pipex test/input_output_shell

./pipex test/lorem "cat" "wc -m"  test/lorem_output_pipex \
	&& <  test/lorem  cat | wc -m > test/lorem_output_shell \
	&& diff -s test/lorem_output_pipex test/lorem_output_shell

./pipex test/letters "cat" "sort"  test/letters_output_pipex \
	&& <  test/letters  cat | sort > test/letters_output_shell \
	&& diff -s test/letters_output_pipex test/letters_output_shell

./pipex test/pokemon "cat" "sort"  test/pokemon_output_pipex \
	&& <  test/pokemon  cat | sort > test/pokemon_output_shell \
	&& diff -s test/pokemon_output_pipex test/pokemon_output_shell

./pipex test/names "cat" "sort -f"  test/names_output_pipex \
	&& <  test/names  cat | sort -f > test/names_output_shell \
	&& diff -s test/names_output_pipex test/names_output_shell

./pipex /dev/null "cat" "sort"  test/null_output_pipex \
	&& <  /dev/null  cat | sort > test/null_output_shell \
	&& diff -s test/null_output_pipex test/null_output_shell

./pipex test/pokemon "rev" "sort"  test/pokemon_rev_output_pipex \
	&& <  test/pokemon  rev | sort > test/pokemon_rev_output_shell \
	&& diff -s test/pokemon_rev_output_pipex test/pokemon_rev_output_shell

./pipex test/names "tr '[:upper:]' '[:lower:]'" "sort"  test/names_lowercase_output_pipex \
	&& <  test/names  tr '[:upper:]' '[:lower:]' | sort > test/names_lowercase_output_shell \
	&& diff -s test/names_lowercase_output_pipex test/names_lowercase_output_shell

./pipex test/lorem "head -n 10" "tail -n 5"  test/lorem_head_tail_output_pipex \
	&& <  test/lorem  head -n 10 | tail -n 5 > test/lorem_head_tail_output_shell \
	&& diff -s test/lorem_head_tail_output_pipex test/lorem_head_tail_output_shell

./pipex test/lorem "grep a" "wc -l"  test/lorem_count_a_output_pipex \
	&& <  test/lorem  grep a | wc -l > test/lorem_count_a_output_shell \
	&& diff -s test/lorem_count_a_output_pipex test/lorem_count_a_output_shell
