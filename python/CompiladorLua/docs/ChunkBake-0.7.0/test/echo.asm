; echo command line arguments

.function
.local i 0
.local limit 1
.local step 2
loadk i #0
getglobal 1 "table"
gettable limit 1 "getn"
getglobal 2 "arg"
call 1 2 2
loadk step #1
sub 0 0 2
jmp START
LOOP:
  getglobal 3 "print"
  move 4 i
  getglobal 5, "arg"
  gettable 5 5[i]
  call 3 3 1
START:
forloop 0 LOOP
return 0 1
.end
