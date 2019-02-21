include irvine32.inc

;This program will take a string from the user
;and it will reverse the string and  the letter caps.
;Ex: Hello! --> !OLLEh
;it will also display number of characters and the number of uppercase letters in the newly converted string

;Author: Anthony Nguyen
;Date: 2019-02-20

.data
     ;Arrays
     user BYTE 128 dup(?),0        ;Used to take the users input and changes every uppercase to a lower case and vice versa

     ;Variables (NOTE: we know that the string entered will be 0<n<128, therefore its safe to use size BYTE for character counter)
     upperCounter BYTE 0
     characterCounter BYTE 0

     ;Strings used for displaying
     prompt BYTE "Enter a string of at most 128 characters: ",0
     promptRev BYTE "Here it is, with all lowercases and uppercases flipped, and in reverse order: ",0
     displayOne BYTE "There are ",0
     displayTwo BYTE " upper-case letters after conversion",0
     displayThree BYTE " characters in the string",0
.code
main proc
     

     ;prompt user for a string input
     mov edx, OFFSET prompt
     Call WriteString

     mov ecx, 128   ;Used to loop 128 times (note: if the string is less than 128 characters we will implement a break so it stops on the \r)
     mov ebx, 0     ;We will use this register to count the number of characters while reading the characters

     READ:
          Call ReadChar  ;Reading each char 
          Call WriteChar ;writing each char as we read (this way is so we can see the characters written onto screen)
          cmp al, 0dh    ;ReadChar actually stores the character(ascii) in al (1 byte)...We compare this with "0dh" which is the Character CR also known as \r which is basically the enter key
          je DONE   ;if the character == Enter (end of string) we jump out off this loop            

          ;Check if its a letter and in if its upper case then change it to lowercase and vice versa
          cmp al, 60h
          ja LOWERCASE
          cmp al, 40h
          ja UPPERCASE

          BACK:
               mov [user + ebx], al
               inc ebx   ;counter to keep track of number of characters

          loop READ
     
     LOWERCASE:
          cmp al, 7Ah
          ja BACK        ;if its not in this range, then it is not a lower case letter... therefore you cannot convert its case
          
          inc upperCounter
          sub al, 20h    ;this converts it into a uppercase (there is a 20 hexadecimal difference between upper and lower in ascii table)
          
          jmp BACK

     UPPERCASE:
          cmp al, 5Ah
          ja BACK   ;if its above this range, then it is not a uppercaes letter...cannot convert

          add al, 20h    ;converts uppercase to lowercase

          jmp BACK  

     DONE:

          Call Crlf
          Call Crlf

          mov edx, OFFSET promptRev
          Call WriteString
          Call Crlf

          mov characterCounter, bl      ;bl is lower bit of ebx
          mov ecx, ebx   

          dec ebx   ;We are going to use ebx for indexing the array (in reverse) therefore we must decriment ebx by one since it orginally was a counter for # of characters

          REVERSE:
               mov al, [user + ebx]
               Call WriteChar
               dec ebx
               loop REVERSE
     
          Call Crlf
          Call Crlf

          ;Clear eax for use of al when WritingDec
          mov eax, 0

          ;displays: "There are n upper-case letters after conversion" (where n = # )
          mov edx, OFFSET displayOne
          Call WriteString
          mov al, upperCounter
          Call WriteDec
          mov edx, OFFSET displayTwo
          Call WriteString
     
          Call Crlf

          ;displays: "There are n characters in the string" (where n = # )
          mov edx, OFFSET displayOne
          Call WriteString
          mov al, characterCounter
          Call WriteDec
          mov edx, OFFSET displayThree
          Call WriteString

          Call Crlf

     exit
main endp
end main