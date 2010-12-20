; catch "undefined" global variables

.function

  ; this is the function set for __index in the metatable
  .function
  .param t
  .param i
  getglobal R2, "error"
  loadk R3, "undefined global variable `"
  move R4, i
  loadk R5, "'"
  concat R3, R3...R5            ; builds the error message string
  loadk R4, #2
  call R2, 3, 1                 ; reports the error
  return 0 1
  .end

; sets the metatable
closure R0, 0
getglobal R1, "setmetatable"
getglobal R2 "getfenv"
call R2, 1, 2
newtable R3, #0, #2             ; create new table for metatable
settable R3["__index"], R0      ; populate table
call R1, 3, 1                   ; actually set the metatable

; an example
loadk R1, #1
setglobal R1, "a"
loadk R1, #3
setglobal R1, "c"

getglobal R1, "print"
getglobal R2, "a"
getglobal R3, "b"       ; `b' is undefined, __index is called to handle this,
getglobal R4, "c"       ; and error() is called
call R1, 4, 1
return R0, 1
.end
