
rmmod memory
rm /dev/memory 
make
mknod /dev/memory c 100 1
insmod memory.ko

