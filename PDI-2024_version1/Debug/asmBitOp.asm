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
	L0 DWORD 5
	L1 DWORD 3
	L2 DWORD 8
	L3 BYTE 'Результат выполнения побитовых операций ИЛИ 5|3|8=', 0
	L4 DWORD 15
	L5 DWORD 5
	L6 DWORD 3
	L7 BYTE 'Результат выполнения побитовых операций И 15&5&3=', 0
	L8 DWORD 0

.DATA
	a DWORD 0
	b DWORD 0


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
	push L1
	push L0
	pop ebx
	pop eax
	or eax, ebx
	push eax
	push L2
	pop ebx
	pop eax
	or eax, ebx
	push eax
	pop a


	INVOKE printss, 4, addr L3

	INVOKE printssln, 1, addr a
	push L5
	push L4
	pop ebx
	pop eax
	and eax, ebx
	push eax
	push L6
	pop ebx
	pop eax
	and eax, ebx
	push eax
	pop b


	INVOKE printss, 4, addr L7

	INVOKE printssln, 1, addr b
	push L8
	jmp theend

main ENDP
end main