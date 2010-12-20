; read environment variables as if they were global variables
.function
.local f, 0

  .function
  .param t
  .param i
  getglobal 2, "os"
  gettable 2, 2["getenv"]
  move 3, i
  tailcall 2, 2
  return 2, 0
  .end

closure f, 0
getglobal 1, "setmetatable"
getglobal 2, "getfenv"
call 2, 1, 2
newtable 3, #0, #2
settable 3["__index"], f
call 1, 3, 1

; -- an example
getglobal 1, "print"
getglobal 2, "a"
getglobal 3, "USER"
getglobal 4, "PATH"
call 1, 4, 1
return 0, 1
.end
