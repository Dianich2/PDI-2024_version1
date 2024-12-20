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
	L0 DWORD 4294967295
	L1 real8 10.7
	L2 BYTE 'Проверка работы функции', 0
	L3 real8 100.5
	L4 real8 12.7
	L5 real8 7.25
	L6 BYTE 'h(100.5,k)-12.7-7.25=', 0
	L7 DWORD 10
	L8 DWORD 10
	L9 DWORD 2
	L10 DWORD 5
	L11 BYTE 'b=', 0
	L12 BYTE 'Введенное число больше b', 0
	L13 BYTE 'Введенное число меньше или равно b', 0
	L14 BYTE 'Проверка работы цикла. Вывод цифр от 0 до 3', 0
	L15 DWORD 0
	L16 DWORD 4
	L17 DWORD 1
	L18 BYTE 'Конец', 0
	L19 DWORD 0

.DATA
	n DWORD 0
	k real8 0.0
	s BYTE 128 dup(0)
	t real8 0.0
	a DWORD 0
	b DWORD 0
	r DWORD 0
	j DWORD 0


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

h PROC b_ : real8, a_ : real8
	fld b_
	fld a_
	fadd
	fstp a_

	fld a_
	jmp local0
local0:
	
	ret
h ENDP

main PROC
	push L0
	pop n


	INVOKE printssln, 1, addr n
	fld L1
	fstp k

	lea esi, [L2]
	lea edi, [s]
	mov ecx, lengthof L2
	rep movsb

	INVOKE printssln, 4, addr s
	INVOKE h, L3, k
	fld L4
	fsub
	fld L5
	fsub
	fstp t


	INVOKE printss, 4, addr L6

	INVOKE printssln, 2, addr t
	push L7
	pop a

	push a
	push L8
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push L9
	pop eax
	pop ebx
	cmp ebx, 0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push eax
	push L10
	pop eax
	pop ebx
	sub eax, ebx
	push eax
	pop b


	INVOKE printss, 4, addr L11

	INVOKE printssln, 1, addr b

	INVOKE readss, 1, addr r
	cmp eax, -1
	jz THEENDER
	mov al, '>'
	push eax
	push OFFSET b
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

	INVOKE printssln, 4, addr L12
	jmp ifEnd0
elsei0:

	INVOKE printssln, 4, addr L13
ifEnd0:

	INVOKE printssln, 4, addr L14
	push L15
	pop j

while0:
	mov al, '<'
	push eax
	push OFFSET L16
	push 1
	push OFFSET j
	push 1
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 0
	je notwhile0

	INVOKE printssln, 1, addr j
	push L17
	push j
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop j

jmp while0
notwhile0:

	INVOKE printssln, 4, addr L18
	push L19
	jmp theend

main ENDP
end main