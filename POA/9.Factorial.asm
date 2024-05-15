DATA SEGMENT
    fact dw ?
    num dw 05h
DATA ENDS

CODE SEGMENT
   START:
        MOV AX,DATA
        MOV DS,AX
        MOV AX,01H
        MOV CX,NUM
        li:
            MUL CX
            DEC CX
            JNZ li
        MOV fact,ax
    
CODE ENDS          
END START