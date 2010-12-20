; temperature conversion table (celsius to farenheit)
.function

; * important constants can be given appropriate names
; * note that some instructions can be saved if io.write and
;   string.format were put in a local variable first

.const TEMP_START, #-20
.const TEMP_END, #50
.const TEMP_STEP, #10
loadk 0, TEMP_START             ; set up outer loop
sub 1, TEMP_END, #1
loadk 2, TEMP_STEP
sub 0, 0, 2
jmp START_LOOP

LOOP:
  getglobal 3, "io"
  gettable 3, 3["write"]
  loadk 4, "C "
  call 3, 2, 1                  ; write leading "C"

  .const COLUMNS, #10
  .const COLSTEP, #1
  move 3, 0                     ; loop for celsius row
  add 4, 0, COLUMNS
  sub 4, 4, COLSTEP
  loadk 5, COLSTEP
  sub 3, 3, 5
  jmp START_LOOPC
  LOOPC:
    getglobal 6, "io"
    gettable 6, 6["write"]
    getglobal 7, "string"
    gettable 7, 7["format"]
    loadk 8, "%3.0f "
    move 9, 3
    call 7, 3, 0                ; string.format
    call 6, 0, 1                ; io.write
  START_LOOPC:
  forloop 3, LOOPC

  getglobal 3, "io"
  gettable 3, 3["write"]
  loadk 4, "\n"
  call 3, 2, 1                  ; write trailing newline
  getglobal 3, "io"
  gettable 3, 3["write"]
  loadk 4, "F "
  call 3, 2, 1                  ; write leading "F"

  move 3, 0                     ; loop for fahrenheit row
  add 4, 0, COLUMNS
  sub 4, 4, COLSTEP
  loadk 5, COLSTEP
  sub 3, 3, 5
  jmp START_LOOPF
  LOOPF:
    div 6, #9, #5               ; celsius to fahrenheit calculation
    mul 6, 6, 3                 ; note that no optimization is done
    add 6, 6, #32
    setglobal 6, "f"

    getglobal 6, "io"
    gettable 6, 6["write"]
    getglobal 7, "string"
    gettable 7, 7["format"]
    loadk 8, "%3.0f "
    getglobal 9, "f"
    call 7, 3, 0                ; string.format
    call 6, 0, 1                ; io.write
  START_LOOPF:
  forloop 3, LOOPF

  getglobal 3, "io"
  gettable 3, 3["write"]
  loadk 4, "\n\n"
  call 3, 2, 1                  ; write trailing newlines
START_LOOP:
forloop 0, LOOP
return 0, 1
.end
