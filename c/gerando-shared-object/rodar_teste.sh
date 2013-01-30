make clean
make
cd teste
make clean
make
echo "--------------- Compilacao bem sucedida, executando teste agora --------------"
export LD_LIBRARY_PATH=../ & ./teste
echo "--------------- Fim da execucao --------------"

