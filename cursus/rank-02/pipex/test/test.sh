SEPARATOR="\n----------------------------------------\n"

INVALIDS=(
	"./pipex"
	"./pipex infile"
	"./pipex infile \"ls -l\""
	"./pipex infile \"ls -l\" \"wc -l\""
	"./pipex test/infile \"lssss -l\" \"wc -l\" test/outfile1"
	"./pipex test/non-existent-file \"ls -l\" \"wc -l\" test/outfile1"
	"./pipex test/invalid_permission_read_infile \"ls -l\" \"wc -l\" test/outfile1"
)

echo $SEPARATOR
for (( i=0; i < ${#INVALIDS[@]}; i++ ));
do
  echo "[$(expr $i + 1)] ${INVALIDS[$i]}"
  ${INVALIDS[$i]}
	echo $SEPARATOR
done

VALIDS=(
	("test/infile" "ls -l" "wc -l" "test/outfile1")
	("test/infile_cat" "cat" "wc -l" "test/outfile1")
)

echo $SEPARATOR
for (( i=0; i < ${#VALIDS[@]}; i++ ));
do
  echo "[$(expr $i + 1)] ${VALIDS[$i]}"
  ./pipex ${VALIDS[$i]}
	echo $SEPARATOR
done

# ./pipex
# echo $SEPARATOR
# ./pipex infile
# echo $SEPARATOR
# ./pipex infile "ls -l"
# echo $SEPARATOR
# ./pipex infile "ls -l" "wc -l"
# echo $SEPARATOR
# ./pipex test/infile "lssss -l" "wc -l" test/outfile1
# echo $SEPARATOR
# ./pipex test/non-existent-file "ls -l" "wc -l" test/outfile1
# echo $SEPARATOR
# ./pipex test/invalid_permission_read_infile "ls -l" "wc -l" test/outfile1
# echo $SEPARATOR
# ./pipex test/infile "ls -l" "wc -l"  test/outfile1 \
#    && < test/infile  ls -l | wc -l > test/outfile2 \
#    && diff -s test/outfile1 test/outfile2
# echo $SEPARATOR
# ./pipex test/infile_cat "cat" "wc -l"  test/outfile1 \
#    && < test/infile_cat  cat | wc -l > test/outfile2 \
#    && diff -s test/outfile1 test/outfile2
