printf %40s | tr " " "=" > testShell00
touch -d "2022-06-01T23:42:00" testShell00
chmod 455 testShell00
ls -l
tar -cf testShell00.tar testShell00
ls -l
