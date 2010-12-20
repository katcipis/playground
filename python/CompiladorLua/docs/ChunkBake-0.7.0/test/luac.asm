; bare-bones luac in Lua
; usage: lua luac.lua file.lua
.function

getglobal 0, "assert"
getglobal 1, "arg"
gettable 1, 1[#1]
eq 1, 1, nil
jmp SKIP1
getglobal 1, "arg"
gettable 1, 1[#2]
eq 1, 1, nil
jmp SKIP2
SKIP1:
loadbool 1, false, 1
SKIP2:
loadbool 1, true, 0
loadk 2, "usage: lua luac.lua file.lua"
call 0, 3, 1

getglobal 0, "assert"
getglobal 1, "io"
gettable 1, 1["open"]
loadk 2, "luac.out"
loadk 3, "wb"
call 1, 3, 0
call 0, 0, 2
setglobal 0, "f"

getglobal 0, "f"
self 0, 0["write"]
getglobal 2, "string"
gettable 2, 2["dump"]
getglobal 3, "assert"
getglobal 4, "loadfile"
getglobal 5, "arg"
gettable 5, 5[#1]
call 4, 2, 0
call 3, 0, 0
call 2, 0, 0
call 0, 0, 1

getglobal 0, "io"
gettable 0, 0["close"]
getglobal 1, "f"
call 0, 2, 1
return 0, 1

.end
