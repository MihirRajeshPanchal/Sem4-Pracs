DATA SEGMENT
    S1 DB 10,1,2,3,4,5,6,7,8,9,10
    S2 DB 10 DUP(0)
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    START:
        MOV AX,DATA
        MOV DS,AX
        MOV ES,AX
        LEA SI, S1
        LEA DI, S2
        MOV CL, [SI]
        MOV CH, 00H
        INC SI
        CLD
        REP MOVSB
        MOV AX,4C00H
        INT 21H
CODE ENDS
END START