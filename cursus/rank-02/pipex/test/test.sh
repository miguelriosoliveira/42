./pipex

./pipex infile

./pipex infile "ls -l"

./pipex infile "ls -l" "wc -l"

./pipex test/infile "lssss -l" "wc -l" test/outfile1

./pipex test/non-existent-file "ls -l" "wc -l" test/outfile1

touch test/invalid_permission_read_infile \
	&& chmod -r test/invalid_permission_read_infile \
	&& ./pipex test/invalid_permission_read_infile "ls -l" "wc -l" test/outfile1 \
	; rm test/invalid_permission_read_infile

./pipex test/infile "ls -l" "wc -l"  test/outfile1 \
   && < test/infile  ls -l | wc -l > test/outfile2 \
   && diff -s test/outfile1 test/outfile2

./pipex test/lorem "cat" "wc -m"  test/outfile1 \
   && < test/lorem  cat | wc -m > test/outfile2 \
   && diff -s test/outfile1 test/outfile2

./pipex test/pokemon "cat" "sort"  test/outfile1 \
   && < test/pokemon  cat | sort > test/outfile2 \
   && diff -s test/outfile1 test/outfile2
