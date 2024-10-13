
.model flat, stdcall
.stack 4096

.data
    promptLower BYTE "Please enter the lower bound: ", 0
    promptUpper BYTE "Please enter the upper bound: ", 0
    newLine BYTE 0Dh, 0Ah, 0  ; New line characters (Carriage return + Line feed)
    numPrompt BYTE 30 DUP(?)

.code
extern RandomRange : proc
extern WriteString : proc
extern ReadInt : proc
extern WriteInt : proc
extern Crlf : proc

BetterRandomRange PROC
    ; Input: EBX = M (lower bound), EAX = N (upper bound)
    ; Output: EAX contains the random number between M and N-1

    sub eax, ebx             ; Calculate the range (N - M)
    call RandomRange         ; Generate random number between 0 and (N-M-1)
    add eax, ebx             ; Shift the random number by M

    ret
BetterRandomRange ENDP

main PROC
    mov ecx, 3               ; Loop 3 times for three different ranges

mainLoop:
    ; Prompt user for lower bound
    mov edx, OFFSET promptLower
    call WriteString
    call ReadInt          ; User inputs lower bound
    mov ebx, eax          ; Store lower bound in EBX

    ; Prompt user for upper bound
    mov edx, OFFSET promptUpper
    call WriteString
    call ReadInt          ; User inputs upper bound (already in EAX)

    ; Generate 30 random numbers between M and N
    mov esi, 30           ; Loop counter for 30 random numbers
randomLoop:
    call BetterRandomRange   ; Generate a random number
    call WriteInt            ; Display the random number
    call Crlf                ; New line
    dec esi
    jnz randomLoop

    dec ecx
    jnz mainLoop

    ret
main ENDP

end main
