; an implementation of printf

.function

  ; this is a function with a variable number of arguments
  ; there is an implicit parameter at register location 0,
  ; but DO NOT declare this as a parameter
  PRINTF .function is_vararg=1
  getglobal $1 "io"
  gettable $1 $1["write"]       ; io.write
  getglobal $2 "string"
  gettable $2 $2["format"]      ; string.format
  getglobal $3 "unpack"
  move $4 $0
  call $3 2 0                   ; unpack(arg)
  call $2 0 0
  call $1 0 1
  return 0 1
  .end

; continue with top-level function
closure $0 PRINTF
setglobal $0 "printf"           ; instantiate and set function printf

; print some stuff here
getglobal $0 "printf"
loadk $1 "Hello %s from %s on %s\n"
getglobal $2 "os"
gettable $2 $2["getenv"]        ; os.getenv
loadk $3 "USER"
call $2 2 2
test $2 $2 1 ; skip next inst if false; this does the "A or B" logic
jmp SKIP
loadk $2 "there"                ; this is the "or B" part
SKIP:
getglobal $3 "_VERSION"
getglobal $4 "os"
gettable $4 $4["date"]          ; os.date
call $4 1 0
call $0 0 1                     ; call printf with variable number of arguments
return 0 1
.end
