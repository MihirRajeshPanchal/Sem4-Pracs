; multi-segment executable file template.
;Ascending
data segment
    ; add your data here!
    string1 db 99h,12h,56h,45h,36h
ends

stack segment
    dw   128  dup(0)
ends

code segment
 assume cs :code,ds:data
    start: mov ax,data
    mov ds,ax
    
    mov ch,04h
    
    up2:mov cl,04h
    lea si,string1
    
    up1: mov al,[si]
    mov bl,[si+1]
    cmp al,bl
    jc down
    mov dl,[si+1]
    xchg [si],dl
    mov [si+1],dl
    
    down: inc si
    dec cl
    jnz up1
    dec ch
    jnz up2
    
   
ends

end start ; set entry point and stop the assembler.
