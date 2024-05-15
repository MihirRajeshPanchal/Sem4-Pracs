DATA SEGMENT
    ARR DB 5,3,7,1,0,6,2,8,9
    LEN DW $-ARR
    MIN DB ?
    MAX DB ?
DATA ENDS

CODE SEGMENT
    ASSUME DS:DATA CS:CODE
    START:
        MOV AX,DATA
        MOV DS,AX
        
        LEA SI,ARR
        MOV AL,ARR[SI]
        MOV MIN,AL
        MOV MAX,AL
        
        MOV CX,LEN
        REPEAT:
            MOV AL,ARR[SI]
            CMP MIN,AL
            JL CHECKMAX
            MOV MIN,AL
            
        CHECKMAX:
            CMP MAX,AL
            JG DONE
            MOV MAX,AL
        
        DONE:
            INC SI
            LOOP REPEAT
            MOV AH,4CH
            INT 21H   
CODE ENDS
END START