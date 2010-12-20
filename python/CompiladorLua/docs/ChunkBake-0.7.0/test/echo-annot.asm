; echo command line arguments

.function
.local i 0              ; for clarity, the 3 locals needed for a for
.local limit 1          ; loop is declared as named locals
.local step 2
loadk i #0
getglobal 1 "table"
gettable limit 1 "getn"
getglobal 2 "arg"
call 1 2 2              ; table.getn(arg)
loadk step #1
sub 0 0 2               ; for loop starts here
jmp START
LOOP:
  getglobal 3 "print"
  move 4 i
  getglobal 5, "arg"
  gettable 5 5[i]       ; arg[i]
  call 3 3 1            ; print...
START:
forloop 0 LOOP          ; loops back to beginning of loop body
return 0 1
.end
