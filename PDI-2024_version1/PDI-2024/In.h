#pragma once
#pragma once
#define IN_MAX_LEN_TEXT 1024*1024 // ������������ ������ ��������� ����
#define IN_CODE_ENDL '\n' // ������ ����� ������

// ������� �������� ������� ����������, ������ - ���(Windows-1251) �������
// �������� iN::F - ����������� ������, iN::T -����������� ������, iN::I - ������������(�� ��������)
// ���� 0 <= �������� < 256 - �� ��������� ������ ��������
namespace In {
	struct iN { // �������� ������
		enum { T = 1024, F = 2048, I = 4096, S = 8192, Z = 512}; // T - ���������� ������, F - ������������ ������, i - ������������, ����� ��������
		int size = 0; // ������ ��������� ����
		int lines = 0; // ���������� �����
		int ignore = 0; // ���������� ����������������� ��������
		unsigned char* text; // �������� ���(Windows-1251)
		int code[256] = { // ����� ������� ��������
T, T, T, T, T, T, T, T, T, S, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
S, T, T, T, T, Z, Z, T, Z, Z, Z, Z, Z, Z, T, Z, \
T, T, T, T, T, T, T, T, T, T, T, Z, Z, Z, Z, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T,	T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, Z, Z, Z, T, T, \
																																																								\
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, T, \
		};
	};
	iN getin(wchar_t infile[]); // ������ � ��������� ������� �����
}