rm -rf test* exo2*

mkdir test0
chmod 715 test0
touch -d "2022-06-01T20:47:00" test0

printf 1234 > test1
chmod 714 test1
touch -d "2022-06-01T21:46:00" test1

mkdir test2
chmod 504 test2
touch -d "2022-06-01T22:45:00" test2

printf 1 > test3
chmod 404 test3
touch -d "2022-06-01T23:44:00" test3

printf 12 > test4
chmod 641 test4
touch -d "2022-06-01T23:43:00" test4

ln test3 test5

ln -s test0 test6
touch -hd "2022-06-01T22:20:00" test6
chmod -h 777 test6

ls -l

tar -cf exo2.tar test*

ls -l

