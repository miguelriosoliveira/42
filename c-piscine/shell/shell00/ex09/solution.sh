# create the magic file to detect "42 files" (files that has the string "42" at their 42nd byte, first position being 0)
printf "41\tstring 42 42 file" > ft_magic
# compile magic file (will generate other files such as "ft_magic.mgc" and "magic.mgc")
file -C -m ft_magic

# create a "42 file" filling the first 41 positions with random "=" character
printf %41s | tr " " "=" > 42file
# append the string "42" to the end of the file
printf 42 >> 42file

# create a common text file
echo potato > potato.txt

# list all the files in the current directory and their file descriptions (the 42file should have the "42 file" description, while the potato.txt should have the "ASCII text" descript)
file -m ft_magic.mgc *

