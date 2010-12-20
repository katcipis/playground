; the first program in every language

; - Constants can be inserted directly as operands, making code more
;   readable. The constant table is automatically generated.
.function
getglobal 0, "io"
gettable 0, 0, "write"          ; get function closure from "io.write"
loadk 1, "Hello world, from "
getglobal 2, "_VERSION"
loadk 3, "!\n"
call 0, 4, 1                    ; closure in 0, arguments in 1,2,3
return 0, 1
.end
