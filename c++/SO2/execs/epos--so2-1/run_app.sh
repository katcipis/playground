export EPOS=/home/katcipis/.workspace/SO2/epos--so2-1
export PATH=$PATH:$EPOS/bin

rm img/epos.img
make veryclean
make
qemu -fda img/epos.img -serial stdio
