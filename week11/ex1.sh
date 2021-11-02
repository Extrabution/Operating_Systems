sudo fallocate -l 50M lofs.img
sudo losetup -f ~/week11/lofs.img
loopLast=$(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)
sudo mkfs.ext4 $loopLast
mkdir lofsdisk 
sudo mount $loopLast ./lofsdisk
sudo chmod 777 ~/week11/lofsdisk

