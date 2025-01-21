# ----------------------------------------------------------
#  error test cases
# ----------------------------------------------------------

# missing all arguments
./pipex > test/output_stdout_pipex 2>test/output_stderr_pipex
diff -s test/output_stderr_pipex test/error_bad_arguments.txt

# missing cmd1 cmd2 outfile
./pipex test/input > test/output_stdout_pipex 2>test/output_stderr_pipex
diff -s test/output_stderr_pipex test/error_bad_arguments.txt

# missing cmd2 outfile
./pipex test/input "ls -l" > test/output_stdout_pipex 2>test/output_stderr_pipex
diff -s test/output_stderr_pipex test/error_bad_arguments.txt

# missing outfile
./pipex test/input "ls -l" "wc -l" > test/output_stdout_pipex 2>test/output_stderr_pipex
diff -s test/output_stderr_pipex test/error_bad_arguments.txt

# invalid infile
./pipex test/nonexistent "ls -l" "wc -l"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/nonexistent  ls -l | wc -l > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# infile missing read permission
chmod -r test/input
./pipex test/input "ls -l" "wc -l"  ""  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  ls -l | wc -l > "") > test/output_stdout_shell 2>test/output_stderr_shell
chmod +r test/input
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# outfile missing write permission
chmod -w test/lorem
./pipex test/input "ls -l" "wc -l"  test/lorem  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  ls -l | wc -l > test/lorem) > test/output_stdout_shell 2>test/output_stderr_shell
chmod +w test/lorem
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# invalid cmd1
./pipex test/input "lz -l" "wc -l"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  lz -l | wc -l > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# invalid cmd2
./pipex test/input "ls -l" "wz -l"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  ls -l | wz -l > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# invalid cmd1 and cmd2
./pipex test/input "lz -l" "wz -l"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  lz -l | wz -l > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# empty infile
./pipex "" "ls"  "cat"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      ""  ls |  cat > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# empty cmd1
./pipex test/input ""  "cat"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input "" | cat > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# empty cmd2
./pipex test/input "ls"  ""   test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  ls | "" > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# empty cmd1 and cmd2
./pipex test/input ""   ""   test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input "" | "" > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# empty outfile
./pipex test/input "ls"  "cat"  ""  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  ls |  cat > "") > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# empty infile and outfile
./pipex "" "ls"  "cat"  ""  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      ""  ls |  cat > "") > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# all arguments empty
./pipex "" ""   ""   ""  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      "" "" | "" > "") > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# cmd1 as nonexistent local command
./pipex test/input "./lz" "ls"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  ./lz | ls > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# cmd2 as nonexistent local command
./pipex test/input "ls" "./lz"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  ls | ./lz > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# cmd1 and cmd2 as nonexistent local commands
./pipex test/input "./lz" "./lz"  test/output  > test/output_stdout_pipex 2>test/output_stderr_pipex
(<      test/input  ./lz | ./lz > test/output) > test/output_stdout_shell 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# ----------------------------------------------------------
#  valid test cases
# ----------------------------------------------------------

# count lines in ls -l output
./pipex test/input "ls -l" "wc -l"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/input  ls -l | wc -l > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# count characters in lorem output
./pipex test/lorem "cat" "wc -m"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/lorem  cat | wc -m > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# sort letters in letters file
./pipex test/letters "cat" "sort"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/letters  cat | sort > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# sort pokemon names
./pipex test/pokemon "cat" "sort"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/pokemon  cat | sort > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# sort names case-insensitively
./pipex test/names "cat" "sort -f"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/names  cat | sort -f > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# sort letters in /dev/null
./pipex /dev/null "cat" "sort"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      /dev/null  cat | sort > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# sort pokemon names in reverse order
./pipex test/pokemon "rev" "sort"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/pokemon  rev | sort > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# sort lowercased names
./pipex test/names "tr '[:upper:]' '[:lower:]'" "sort"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/names  tr '[:upper:]' '[:lower:]' | sort > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# get 5th to 10th line of lorem
./pipex test/lorem "head -n 10" "tail -n 5"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/lorem  head -n 10 | tail -n 5 > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# count number of lines with 'a' in lorem
./pipex test/lorem "grep a" "wc -l"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/lorem  grep a | wc -l > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# cmd1 as local command
./pipex test/lorem "./ls" "ls"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/lorem  ./ls | ls > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# cmd2 as local command
./pipex test/lorem "ls" "./ls"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/lorem  ls | ./ls > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell

# cmd1 and cmd2 as local commands
./pipex test/lorem "./ls" "./ls"  test/output_stdout_pipex  2>test/output_stderr_pipex
(<      test/lorem  ./ls | ./ls > test/output_stdout_shell) 2>test/output_stderr_shell
diff -s test/output_stdout_pipex test/output_stdout_shell
diff -s test/output_stderr_pipex test/output_stderr_shell
