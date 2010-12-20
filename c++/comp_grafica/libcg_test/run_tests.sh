echo
echo "--------------------------------------------------------------------------------------------------------------------------"
echo "The libcg dir must be on the same dir where is the libcg_test !!"
echo "--------------------------------------------------------------------------------------------------------------------------"
echo

cd ../libcg
make clean
make

cd ../libcg_test
make clean
rm ./cg_test
make

export LD_LIBRARY_PATH=../libcg:$LD_LIBRARY_PATH
./cg_test

