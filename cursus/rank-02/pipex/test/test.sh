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
   && < test/input  ls -l | wc -l > test/input_output_shell \
   && diff -s test/input_output_pipex test/input_output_shell

./pipex test/lorem "cat" "wc -m"  test/lorem_output_pipex \
   && < test/lorem  cat | wc -m > test/lorem_output_shell \
   && diff -s test/lorem_output_pipex test/lorem_output_shell

./pipex test/pokemon "cat" "sort"  test/pokemon_output_pipex \
   && < test/pokemon  cat | sort > test/pokemon_output_shell \
   && diff -s test/pokemon_output_pipex test/pokemon_output_shell

./pipex test/names "cat" "sort -f"  test/names_output_pipex \
   && < test/names  cat | sort -f > test/names_output_shell \
   && diff -s test/names_output_pipex test/names_output_shell
