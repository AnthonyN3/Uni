include Irvine32.inc

;We will take the value in BIGENDIAN of form 89ABCDEF (basically imitating how BIGENDIAN is in memory storage)
;we then will then convert it into littleEndian (EFCDAB89)
;We are basically taking a value that is supposely how bigendian is and showings its littleEndian version

;OUTPUT:
;LittleEndian: EFCDAB89
;BigEndian: 89ABCDEF

.data
bigEndian Byte 089h, 0ABh, 0CDh, 0EFh
littleEndian   DWORD ?
s1 BYTE "LittleEndian: ",0
s2 BYTE "BigEndian: ",0

.code
main proc
   
   ;---------Assigns the reverse order to each byte part of the DWORD in "littleEndian"
     mov al, [bigEndian+3]
     mov  BYTE PTR [littleEndian+3], al

     mov al,[bigEndian+2]
     mov BYTE PTR [littleEndian+2], al

     mov al,[bigEndian+1]
     mov BYTE PTR [littleEndian+1], al

     mov al, [bigEndian]
     mov BYTE PTR [littleEndian], al
  
  ;-------Prints out contents in littleEndian (reverse of the array of bigEndian)-----------------------
     
     mov edx, offset s1
     Call WriteString

     mov eax, littleEndian
     Call WriteHex

     Call Crlf
   ;--------------Prints contents in bigEndian in order of position in array and excludes the leading zeros-----------------------------------  
     mov edx, offset s2
     Call WriteString

     ;Uses WiretHexb in order to get rid of leading zeros
     movzx eax, bigEndian
     mov ebx, TYPE bigEndian
     Call WriteHexB
     movzx eax, [bigEndian+1]
     Call WriteHexB
     movzx eax, [bigEndian+2]
     Call WriteHexB
     movzx eax, [bigEndian+3]
     Call WriteHexB

     Call Crlf

     exit
main endp
end main