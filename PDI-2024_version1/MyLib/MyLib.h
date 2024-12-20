#pragma once
#ifndef MYLIB_H
#define MYLIB_H

#ifdef __cplusplus
extern "C" {
#endif

	__declspec(dllexport) int __stdcall getmin(int f, int s);
	__declspec(dllexport) int __stdcall getmax(int f, int s);
	__declspec(dllexport) int __stdcall printss(int type, char* str);
	__declspec(dllexport) int __stdcall printssln(int type, char* str);
	__declspec(dllexport) int __stdcall readss(int type, char* value);
	__declspec(dllexport) int __stdcall compare(char* f, char* s);
	__declspec(dllexport) int __stdcall len(char* f);
	__declspec(dllexport) int __stdcall waitPause();
	__declspec(dllexport) int __stdcall compnum(int type1, char* f, int type2, char* s, char op);

#ifdef __cplusplus
}
#endif

#endif