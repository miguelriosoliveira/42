printf %40s | tr " " "=" > testShell00
touch -t 202206012342 testShell00
chmod 455 testShell00
ls -l
tar -cf testShell00.tar testShell00
ls -l
