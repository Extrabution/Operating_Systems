echo "Hello my name is My name is Slim Vanya"> ~/week10/_ex3.txt
echo ""> ex3.txt
chmod -c 666 _ex3.txt > ~/week10/ex3.txt
chmod -c 767 _ex3.txt >> ~/week10/ex3.txt
chmod -c 777 _ex3.txt >> ~/week10/ex3.txt
echo "660 -read and write permissions only for owner and groups, no permissons for others">> ~/week10/ex3.txt
echo "775 - rwx for owner and groups, rx for others">> ~/week10/ex3.txt
echo "777 - rrwx permissions for all">> ~/week10/ex3.txt
