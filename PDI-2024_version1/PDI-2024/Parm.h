#pragma once
#include <tchar.h>
#define PARM_IN  L"-in:" // ���� ��� ����� ��������� ����
#define PARM_OUT L"-out:" // ���� ��� ����� ���������� ����
#define PARM_LOG L"-log:" // ���� ��� ����� �������
#define PARM_MAX_SIZE 300 // ������������ ����� ������ ���������
#define PARM_OUT_DEFAULT_EXT L".asm" //���������� ���������� ���� �� ���������
#define PARM_LOG_DEFAULT_EXT L".log" //���������� ����� ������� �� ���������

namespace Parm {
	struct PARm { // ������� ���������
		wchar_t in[PARM_MAX_SIZE]; // ��� ����� ��������� ����
		wchar_t out[PARM_MAX_SIZE]; // ��� ����� ���������� ����
		wchar_t log[PARM_MAX_SIZE]; // ��� log �����
	};
	PARm getparm(int argc, _TCHAR* argv[]); // ������� ��� ��������� ����������
}