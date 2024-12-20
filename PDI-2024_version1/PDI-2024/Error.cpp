#include"stdafx.h"
#include"Error.h"
namespace Error
{
		ERROr errors[ERROR_MAX_ENTRY] = {
		ERROR_ENTRY(0,"������������ ��� ������"),
		ERROR_ENTRY(1,"��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"�������� -in ������ ���� �����"),
		ERROR_ENTRY(101, "��������� ����� �������� ���������"), 
		ERROR_ENTRY(102, "��� ������� ������ ���� ��������� �� main"),
		ERROR_ENTRY(103, "������� main �� ���������"),
		ERROR_ENTRY(104, "�������� ����� �� ����� ���� ���������������"),
		ERROR_ENTRY(105,"������������ ��������������"),
		ERROR_ENTRY(106,"������������� �� ��������"),
		ERROR_ENTRY(107, "������� ��� ����������"),
		ERROR_ENTRY(108, "��������� ����������� ��������� ����� ���������� � �������"),
		ERROR_ENTRY(109, "��������� ���������� main"),
		ERROR_ENTRY(110,"������ ��� �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111,"������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(112,"������ ��� �������� ����� � ���������� (-log)"),
		ERROR_ENTRY(113,"������ ��� �������� ��������� ����� � ����������� .out"),
		ERROR_ENTRY(114,"������������ ������ ������� ������"),
		ERROR_ENTRY(115,"�������� ������ ������� ������"),
		ERROR_ENTRY(117,"������������ ������ ������� ���������������"),
		ERROR_ENTRY(118,"�������� ������ ������� ���������������"),
		ERROR_ENTRY(119,"��������� ����� �������"),
		ERROR_ENTRY(120, "������������� �������� �� ������������� ���� ����������"),
		ERROR_ENTRY(121, "������������ �������� � ������� �� ������������� �� ����"),
		ERROR_ENTRY(122, "����������� � ���������� ��������� �� ������������� �� ���� ��� ����������"),
		ERROR_ENTRY(123, "��� ������������, ����� ������ ���� ���������� ��� ������ ���� ��������"),
		ERROR_ENTRY(124, "����������� ������� �� ����"),
		ERROR_ENTRY(125, "������ � ��������� ��������"),
		ERROR_ENTRY(126, "������� �� ����� ���� ���������� ����"),
		ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),ERROR_ENTRY_NODEF10(160),
		ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),ERROR_ENTRY_NODEF100(200),ERROR_ENTRY_NODEF100(300),
		ERROR_ENTRY_NODEF100(400),ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "�������� ��������� ���������"),
		ERROR_ENTRY(601, "��������� ��������"),
		ERROR_ENTRY(602, "������ � ���������"),
		ERROR_ENTRY(603, "������ � ���������� �������"),
		ERROR_ENTRY(604, "������ � ���������� ���������� �������"),
		ERROR_ENTRY(605, "������ � ������������"),
		ERROR_ENTRY(606, "������ � ���������� ���������"),
		ERROR_ENTRY(607, "������ � ���������� ������������"),
		ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),
		ERROR_ENTRY_NODEF100(900)
	};
	ERROr geterror(int id)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			for (int i = 0; i < 1000; i++) {
				if (id == errors[i].id) {
					return errors[i];
				}
			}
			return errors[0];
		}
		else
		{
			return errors[0];
		}
	}
	ERROr geterrorin(int id, int line = -1, int col = -1)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			for (int i = 0; i < 1000; i++) {
				if (id == errors[i].id) {
					errors[i].inext.col = col;
					errors[i].inext.line = line;
					return errors[i];
				}
			}
		}
		else
		{
			return errors[0];
		}
	}
};