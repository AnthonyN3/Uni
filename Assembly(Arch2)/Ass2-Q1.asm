include irvine32.inc

;Program that takes users input to display the fibonacci sequence of that number
;Ex: User input = 5.... Outpout = 0 1 1 2 3 5

;Author: Anthony Nguyen
;Date: 2019-02-20

.data
     space BYTE " ",0
     header BYTE "Fibonacci Number Sequence Program",0
     promptOne BYTE "Enter a positive integer: ",0
     promptTwo BYTE "Fibonacci sequence of N = ",0
     temp dword ?

.code
main proc
     
     ;prompts the program title
     mov edx, offset header
     Call WriteString
     Call Crlf
     Call Crlf

     ;prompt for user input
     mov edx, offset promptOne
     Call WriteString
     Call ReadDec
     Call Crlf

     ;prompt what fib sequence you are calculating
     mov edx, offset PromptTwo
     Call WriteString
     Call WriteDec
     Call Crlf

     ;saving a space into the edx for futute calls
     mov edx, offset space

     ; There are 3 different cases
     ; either the user inputs a value of 0,1 or something greater than 1... if n = 0 then output is just 0 and if n = 1 then output = 0 1
     ; the last case, is more complex where we will use a loop to display all sequence
     cmp eax, 1
     jb CASE1
     je CASE2
     ja CASE3

     ;Prints "0" and exits
     CASE1:
          Call WriteDec
          jmp done
     ;prints "0 1" and exits
     CASE2:
          mov eax, 0
          Call WriteDec
          
          Call WriteString
          
          mov eax, 1
          Call WriteDec
          jmp done
     
     ;in this case we use a loop to loop through the fib sequence
     CASE3:
          mov ecx, eax
          inc ecx        ;Since when finding for example fib(2) there is actually 3 values and not 2. Therefore if input = N it will give you N+1 sequence of numbers and not just N 

          ;First 2 fib numbers
          mov eax,0
          mov ebx,1

          ;We loop n+1 times (user input + 1 times)
          fib:
               Call WriteDec
               Call WriteString    ;create a space between each number
               mov temp, eax       ;make use of temp to hold the value of the next fib number in sequence
               add temp, ebx
               mov eax, ebx
               mov ebx, temp

               loop fib

     done:
    
     exit
main endp
end main