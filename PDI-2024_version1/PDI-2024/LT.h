#pragma once
#define LEXEMA_FIXSIZE 1 // ������������� ������ �������
#define LT_MAXSIZE 4096 // ������������ ����� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff // ��� �������� ������� ���������������
#define LEX_UINTEGER 't' // ������� ��� integer
#define LEX_STRING 't' // ������� ��� string
#define LEX_BOOL 't'
#define LEX_DOUBLE 't'
#define LEX_ID 'i' // ������� ��� ��������������
#define LEX_MAIN 'm' // ������� ��� main
#define LEX_LITERAL 'l' // ������� ��� ��������
#define LEX_FUNCTION 'f' // ������� ��� function
#define LEX_RETURN 'r' // ������� ��� return
#define LEX_PRINT 'p' // ������� ��� print
#define LEX_PRINTLN 'x'
#define LEX_READ 'h'
#define LEX_SEMICOLON ';' // ������� ��� ;
#define LEX_COMMA ',' // ������� ��� ,
#define LEX_LEFTBRACE '{' // ������� ��� {
#define LEX_BRACELET '}' // ������� ��� }
#define LEX_LEFTTHESIS '(' // ������� ��� (
#define LEX_RIGHTTHESIS ')' // ������� ��� )
#define LEX_PLUS '+' // ������� ��� +
#define LEX_MINUS '-' // ������� ��� -
#define LEX_STAR '*' // ������� ��� *
#define LEX_DIRSLASH '/' // ������� ��� /
#define LEX_EQUAL '=' // ������� ��� =
#define LEX_ISEQUAL 'c' // ������� ��� ==
#define LEX_MORE '>'
#define LEX_LESS '<'
#define LEX_NOT '!'
#define LEX_OST '%'
#define LEX_NOT_EQUAL 'n'
#define LEX_MORE_OR_EQUAL 'e'
#define LEX_LESS_OR_EQUAL 'o'
#define LEX_IF 'y' // ������� ��� if
#define LEX_ELSE 'd'
#define LEX_WHILE 'w' // ������� ��� while
#define LEX_LEN 'a'
#define LEX_COMP 'b'
#define LEX_AND '&'
#define LEX_OR '|'

namespace LT { // ������� ������
	struct Entry { // ������ ������� ������
		char lexema[LEXEMA_FIXSIZE]; // �������
		int sn; // ����� ������ � �������� ������
		int idxTI; // ������ � ������� ��������������� ��� LT_TI_NULLIDX
	};

	struct LexTable { // ��������� ������� ������
		int maxsize = 0; // ������� ������� ������ < LT_MAXSIZE
		int size = 0; // ������� ������ ������� ������ < maxsize
		Entry* table; // ������ ����� ������� ������
	};

	LexTable Create(int size); // ������� �������
	void Add(LexTable& lextable, Entry entry); // �������� ������ � ������� ������
	Entry GetEntry(LexTable& lextable, int n); // �������� ������ �� ������� ������
	void Delete(LexTable& lextable); // ������� ������� ������
	void WriteInFile(LexTable& lextable);
}