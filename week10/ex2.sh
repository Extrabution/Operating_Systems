mkdir ~/week01

echo "Ivan Inchin as an exmaple OmegaLUL"> ~/week01/file.txt

ln ~/week01/file.txt ~/week10/_ex2.txt

find . -inum $(ls -i ~/week10/_ex2.txt | awk '{print $1}') > ~/week10/ex2.txt

find . -inum $(ls -i ~/week10/_ex2.txt | awk '{print $1}') -exec rm {} \; >> ~/week10/ex2.txt
