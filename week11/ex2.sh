echo "Ivan" > lofsdisk/file1.txt

echo "Inchin" > lofsdisk/file2.txt

disk=lofsdisk

mkdir -p $disk/{bin,lib64,lib}

mkdir -p $disk/lib/x86_64-linux-gnu

cp /bin/{bash,cat,echo,ls} $disk/bin

libs="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $libs; do sudo cp "$i" "${disk}${i}"; done

libs="$(ldd /bin/cat | egrep -o '/lib.*\.[0-9]')"
for i in $libs; do sudo cp "$i" "${disk}${i}"; done

libs="$(ldd /bin/echo | egrep -o '/lib.*\.[0-9]')"
for i in $libs; do sudo cp "$i" "${disk}${i}"; done

libs="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"
for i in $libs; do sudo cp "$i" "${disk}${i}"; done

gcc -o ex2.out ex2.c

chmod 777 ex2.out

cp ./ex2.out $disk/

chmod 777 $disk/ex2.out

sudo chmod -R 777 $disk

sudo chroot $disk ./ex2.out > ex2.txt

echo '________________________________________' >> ex2.txt

./ex2.out >> ex2.txt


