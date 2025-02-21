rm -rf test* exo2*

mkdir test0
chmod 715 test0
touch -t 202206012047 test0

printf 1234 > test1
chmod 714 test1
touch -t 202206012146 test1

mkdir test2
chmod 504 test2
touch -t 202206012245 test2

printf 1 > test3
chmod 404 test3
touch -t 202206012344 test3

printf 12 > test4
chmod 641 test4
touch -t 202206012343 test4

ln test3 test5

ln -s test0 test6
touch -ht 202206012220 test6
chmod -h 777 test6

ls -l

tar -cf exo2.tar test*

ls -l
