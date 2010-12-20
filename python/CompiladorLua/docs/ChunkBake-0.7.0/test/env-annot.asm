; read environment variables as if they were global variables
.function
.local f, 0

  .function
  .param t
  .param i
  getglobal 2, "os"
  gettable 2, 2["getenv"]
  move 3, i
  tailcall 2, 2         ; os.getenv(i)
  return 2, 0
  .end

closure f, 0            ; instantiate the prototype
getglobal 1, "setmetatable"
getglobal 2, "getfenv"
call 2, 1, 2            ; getfenv()
newtable 3, #0, #2      ; create a new table
settable 3["__index"], f ; table[__index]=f
call 1, 3, 1            ; setmetatable()

; -- an example
getglobal 1, "print"
getglobal 2, "a"        ; parameters: a, USER, PATH
getglobal 3, "USER"
getglobal 4, "PATH"
call 1, 4, 1            ; call print()
return 0, 1
.end
