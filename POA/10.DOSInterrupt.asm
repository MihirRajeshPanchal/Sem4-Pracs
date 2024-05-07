data segment

MSG DB "Enter a character:$"

data ends

;Mihir

code segment

assume cs:code, ds:data

start:

mov ax,data

mov ds,ax

lea DX,MSG

MOV AH,09h

INT 21H

mov ah,01

int 21h

mov dl,al

mov ah,02

int 21h

mov ah,4ch

int 21h

code ends

end start