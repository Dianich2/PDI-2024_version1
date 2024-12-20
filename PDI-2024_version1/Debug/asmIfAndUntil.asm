.586
.MODEL FLAT, stdcall
includelib kernel32.lib
includelib user32.lib
includelib libucrt.lib
includelib msvcrtd.lib
includelib "..\Debug\MyLib.lib"
compnum PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
printss PROTO :DWORD, :DWORD
printssln PROTO :DWORD, :DWORD
readss PROTO : DWORD, : DWORD
compare PROTO : DWORD, : DWORD
len PROTO : DWORD
getmin PROTO : DWORD, : DWORD
getmax PROTO : DWORD, : DWORD
ExitProcess PROTO : DWORD
SetConsoleOutputCP PROTO : DWORD
SetConsoleCP PROTO : DWORD
waitPause PROTO

.STACK 4096

.CONST
	null_division BYTE 'ERROR: DIVISION BY ZERO', 0
	error_read BYTE 'ERROR: READING ERROR', 0
	TRUE BYTE 'true', 0
	FALSE BYTE 'false', 0
	L0 DWORD 1
	L1 DWORD 10
	L2 DWORD 2
	L3 DWORD 0
	L4 BYTE 'Число ', 0
	L5 BYTE ' четное', 0
	L6 BYTE 'Число ', 0
	L7 BYTE ' нечетное', 0
	L8 DWORD 1
	L9 DWORD 0

.DATA
	j DWORD 0
	k DWORD 0


.CODE
push 1251d
call SetConsoleOutputCP
push 1251d
call SetConsoleCP

theend:
	call waitPause
	push 0
	call ExitProcess
SOMETHINGWRONG:
	push OFFSET null_division
	push 4
	call printss
jmp THEENDER
ERRORREAD:
	push OFFSET error_read
	push 4
	call printss
THEENDER:
	call waitPause
	push -1
	call ExitProcess

main PROC
	push L0
	pop j

while0:
	mov al, 'o'
	push eax
	push OFFSET L1
	push 1
	push OFFSET j
	push 1
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 0
	je notwhile0
	push L2
	push j
	pop eax
	pop ebx
	cmp ebx, 0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push edx
	pop k

	mov al, 'c'
	push eax
	push OFFSET L3
	push 1
	push OFFSET k
	push 1
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 1
	je ifi0
	cmp eax, 0
	je elsei0
ifi0:

	INVOKE printss, 4, addr L4

	INVOKE printss, 1, addr j

	INVOKE printssln, 4, addr L5
	jmp ifEnd0
elsei0:

	INVOKE printss, 4, addr L6

	INVOKE printss, 1, addr j

	INVOKE printssln, 4, addr L7
ifEnd0:
	push L8
	push j
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop j

jmp while0
notwhile0:
	push L9
	jmp theend

main ENDP
end main