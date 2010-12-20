export EPOS=/home/katz/workspace/SO2/proj/trunk
export PATH=$PATH:$EPOS/bin

rm img/epos.img
make veryclean
make all
eposcc -D __ia32 -D __pc -c -ansi -O2 app/secure_segment_test.cc -o app/secure_segment_test.o
eposcc --library -o app/secure_segment_test app/secure_segment_test.o
make APPLICATION=secure_segment_test
qemu -fda img/secure_segment_test.img -serial stdio
