include irvine32.inc

;Using the equation Z = (A+B) - (C-D)
;A and B are 543210 and 3210 respectively
;C and D are inputs that are taken from the users keyboard (note: it is assumed that valid inputs entered for each data type size)
;A = DWORD
;B = WORD
;C = DWORD
;D = BYTE
;Z = DWORD

;Z will be caluclated using the equation above, and the program will output the answer into 3 different forms
; binary, hexadecimal, and decimal form


.data
Avar DWORD 543210
Bvar WORD 3210
Cvar DWORD ?
Dvar BYTE ?
Zvar DWORD ?
s1 BYTE "What is the value of C?", 0
s2 BYTE "What is the value of D?", 0
s3 BYTE "Z = (A+B) - (C-D)", 0
sep BYTE "   ;   ", 0

.code
main proc
	;prompts user for input
     mov edx, offset s1
     Call WriteString
     
     ;user input into Cvar
     Call ReadDec
     mov Cvar, eax

     ;promts user for input 
     mov edx, offset s2
     Call WriteString

     ;user input stored into Dvar
     Call ReadDec
     mov Dvar, al

     ;Prints out the equation
     mov edx, offset s3
     Call WriteString

     Call Crlf

     ;Writes out contents in A B C and D with semi colons seperating
     mov eax, Avar
     Call WriteDec
     mov edx, offset sep
     Call WriteString
     movzx eax, Bvar
     Call WriteDec
     mov edx, offset sep
     Call WriteString
     mov eax, Cvar
     Call WriteDec
     mov edx, offset sep
     Call WriteString
     movzx eax, Dvar
     Call WriteDec
     
     ;new lines
     Call Crlf
     Call Crlf
     
     ;Caclulates Z variable with equation and store into Zvar
     movzx ax, Dvar
     add ax, Bvar
     movzx eax, ax
     add eax, Avar
     sub eax, Cvar

     ;writes out binary, decimal and hexadecimal in seperate lines
     call WriteBin
     Call Crlf
     call WriteDec
     Call Crlf
     call WriteHex
     Call Crlf

	
     exit
main endp
end main