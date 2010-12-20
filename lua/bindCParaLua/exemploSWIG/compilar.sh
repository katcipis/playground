rm *wrap.c
rm *.so

swig -lua exemplo.i
gcc -Wall -shared exemplo.c -o libexemplo.so
gcc -Wall -shared -I/usr/include/lua5.1 -L./ -lexemplo exemplo_wrap.c -o exemplo.so


