# EBrainFuck

EBrainFuck - Extended BrainFuck Interpreter have two mods read code from file or interactive.<br>
<b>BrainFuck</b> <i><file|inter> [-m]</i><br>
<b>file</b> - BF wil read code from file<br>
<b>inter</b> - interactive mode you can exit intractive mod using <b><i>ex</i></b><br>
<b>-m</b> - optional flag for printing memory and stack<br>

| OP   | Action |
|-----:|-----------|
|     +| Increase the byte at the current memory cell |
|     -| Decrease the byte at the current memory cell |
|     >| Move ptr to right |
|     <| Move ptr to left |
|     [| If byte at the current mem cell is zero move to ] |
|     ]| If byte at the current mem cell is non zero move to [ |
|     .| Print current mem cell value as char |
|     ,| Input char |
|     :| Print current mem cell value as integer |
|     ;| Input value as Byte |
|     #| Copy value of current mem cell to top of the stack    |
|     $| Put value from top of the stack to current mem cell       |
|     !| Pop value from stack|
