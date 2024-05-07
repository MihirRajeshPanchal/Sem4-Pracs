; Mihir Panchal Factorial

data segment
    fact dw ?
    num dw 05h
data ends

code segment
    start:mov ax, data
    mov ds, ax
    mov ax, 01h
    mov cx, num
    l1:
        mul cx
        dec cx
        jnz l1
    mov fact, ax
code ends
end start