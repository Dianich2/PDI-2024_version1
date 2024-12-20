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
	L1 BYTE 'yes', 0
	L2 BYTE 'no', 0
	L3 DWORD 0

.DATA
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

main PROC

	INVOKE readss, 3, addr t
	cmp eax, -1
	jz THEENDER

	INVOKE printssln, 3, addr t
	mov al, 'c'
	push eax
	push OFFSET L0
	push 3
	push OFFSET t
	push 3
	call compnum
	cmp eax, -1
	je THEENDER
	cmp eax, 1
	je ifi0
	cmp eax, 0
	je elsei0
ifi0:

	INVOKE printssln, 3, addr t

	INVOKE printssln, 4, addr L1
	jmp ifEnd0
elsei0:

	INVOKE printssln, 3, addr t

	INVOKE printssln, 4, addr L2
ifEnd0:
	push L3
	jmp theend

main ENDP
end main