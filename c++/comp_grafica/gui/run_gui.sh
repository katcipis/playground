echo
echo "--------------------------------------------------------------------------------------------------------------------------"
echo "The libcg dir must be on the same dir where is the gui !!"
echo "--------------------------------------------------------------------------------------------------------------------------"
echo

cd ../libcg
make clean
make

cd ../gui
make clean
rm ./gui
make

export LD_LIBRARY_PATH=../libcg:$LD_LIBRARY_PATH
./gui

