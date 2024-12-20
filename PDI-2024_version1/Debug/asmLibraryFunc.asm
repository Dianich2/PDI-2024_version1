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
	L0 BYTE 'Первая строка', 0
	L1 BYTE 'Вторая строка', 0
	L2 DWORD 0
	L3 BYTE 'Первая строка лексикографически меньше второй', 0
	L4 DWORD 2
	L5 BYTE 'Вторая строка лексикографически меньше первой', 0
	L6 DWORD 1
	L7 BYTE 'Строки равны', 0
	L8 BYTE 'Длина первой строки=', 0
	L9 DWORD 2
	L10 DWORD 5
	L11 BYTE 'Наибольшее число из 2 и 5 это ', 0
	L12 BYTE 'Наименьшее число из 2 и 5 это ', 0
	L13 DWORD 0

.DATA
	a BYTE 128 dup(0)
	b BYTE 128 dup(0)
	r DWORD 0
	n DWORD 0
	t DWORD 0
	e DWORD 0
	max DWORD 0
	min DWORD 0


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
	lea esi, [L0]
	lea edi, [a]
	mov ecx, lengthof L0
	rep movsb
	lea esi, [L1]
	lea edi, [b]
	mov ecx, lengthof L1
	rep movsb
	INVOKE compare, addr a, addr b
	push eax
	pop r

	mov al, 'c'
	push eax
	push OFFSET L2
	push 1
	push OFFSET r
	push 1
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 1
	je ifi0
	cmp eax, 0
	je elsei0
ifi0:

	INVOKE printssln, 4, addr L3
elsei0:
	mov al, 'c'
	push eax
	push OFFSET L4
	push 1
	push OFFSET r
	push 1
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 1
	je ifi1
	cmp eax, 0
	je elsei1
ifi1:

	INVOKE printssln, 4, addr L5
elsei1:
	mov al, 'c'
	push eax
	push OFFSET L6
	push 1
	push OFFSET r
	push 1
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 1
	je ifi2
	cmp eax, 0
	je elsei2
ifi2:

	INVOKE printssln, 4, addr L7
elsei2:
	INVOKE len, addr a
	push eax
	pop n


	INVOKE printss, 4, addr L8

	INVOKE printssln, 1, addr n
	push L9
	pop t

	push L10
	pop e


	INVOKE printss, 4, addr L11
	INVOKE getmax, t, e
	push eax
	pop max


	INVOKE printssln, 1, addr max

	INVOKE printss, 4, addr L12
	INVOKE getmin, t, e
	push eax
	pop min


	INVOKE printssln, 1, addr min
	push L13
	jmp theend

main ENDP
end main