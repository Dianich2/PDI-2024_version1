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
	L0 DWORD 0
	L1 BYTE 'Введите значение первого числа', 0
	L2 BYTE 'Введите значение второго числа', 0
	L3 BYTE 'Наибольший общий делитель введенных чисел=', 0
	L4 DWORD 0

.DATA
	k DWORD 0
	a DWORD 0
	b DWORD 0
	t DWORD 0


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

gcd PROC b_ : DWORD, a_ : DWORD
	push b_
	push a_
	pop eax
	pop ebx
	mul ebx
	push eax
	pop k

while0:
	mov al, 'n'
	push eax
	push OFFSET L0
	push 1
	push OFFSET k
	push 1
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 0
	je notwhile0
	mov al, '>'
	push eax
	lea eax, b_
	push eax
	push 1
	lea eax, a_
	push eax
	push 1
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 1
	je ifi0
	cmp eax, 0
	je elsei0
ifi0:
	push b_
	push a_
	pop eax
	pop ebx
	cmp ebx, 0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push edx
	pop a_

	jmp ifEnd0
elsei0:
	push a_
	push b_
	pop eax
	pop ebx
	cmp ebx, 0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push edx
	pop b_

ifEnd0:
	push b_
	push a_
	pop eax
	pop ebx
	mul ebx
	push eax
	pop k

jmp while0
notwhile0:
	push b_
	push a_
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop k

	push k
	jmp local0
local0:
	pop eax
	ret
gcd ENDP

main PROC

	INVOKE printssln, 4, addr L1

	INVOKE readss, 1, addr a
	cmp eax, -1
	jz THEENDER

	INVOKE printssln, 4, addr L2

	INVOKE readss, 1, addr b
	cmp eax, -1
	jz THEENDER
	INVOKE gcd, a, b
	push eax
	pop t


	INVOKE printss, 4, addr L3

	INVOKE printssln, 1, addr t
	push L4
	jmp theend

main ENDP
end main