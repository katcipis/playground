; the first program in every language

.function
getglobal 0, "io"
gettable 0, 0, "write"
loadk 1, "Hello world, from "
getglobal 2, "_VERSION"
loadk 3, "!\n"
call 0, 4, 1
return 0, 1
.end
