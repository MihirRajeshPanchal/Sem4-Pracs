DATA SEGMENT
    fact dw ?
    num dw 05h
DATA ENDS

MACRO factorial n
    MOV CX, n
    l1: 
        MUL CX
        DEC CX
        JNZ l1
ENDM

CODE SEGMENT
    START:
        MOV AX,DATA
        MOV DS,AX
        MOV AX,01H
        factorial num
        MOV fact,ax
CODE ENDS
END START