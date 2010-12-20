; an implementation of printf

.function

  PRINTF .function is_vararg=1
  getglobal $1 "io"
  gettable $1 $1["write"]
  getglobal $2 "string"
  gettable $2 $2["format"]
  getglobal $3 "unpack"
  move $4 $0
  call $3 2 0
  call $2 0 0
  call $1 0 1
  return 0 1
  .end

closure $0 PRINTF
setglobal $0 "printf"

getglobal $0 "printf"
loadk $1 "Hello %s from %s on %s\n"
getglobal $2 "os"
gettable $2 $2["getenv"]
loadk $3 "USER"
call $2 2 2
test $2 $2 1 ; skip next inst if false
jmp SKIP
loadk $2 "there"
SKIP:
getglobal $3 "_VERSION"
getglobal $4 "os"
gettable $4 $4["date"]
call $4 1 0
call $0 0 1
return 0 1
.end
