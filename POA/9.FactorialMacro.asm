; Mihir Panchal Factorial using Macro

data segment
    fact dw ?
    num dw 05h
data ends

macro factorial n
    mov cx, n
    l1:
        mul cx
        dec cx
        jnz l1
endm

code segment
    start:mov ax, data
    mov ds, ax
    mov ax, 01h
    factorial num
    mov fact, ax
code ends
end start
