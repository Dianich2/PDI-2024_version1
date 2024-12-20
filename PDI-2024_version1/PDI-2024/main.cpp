#include <iostream>
#include <Windows.h>
#include "stdafx.h"
#include <locale>
#include <cwchar>
#include <TCHAR.h>
#include "asmGenerator.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Parm::PARm parm;
	Log::LOG log;
	Out::OUt out;
	try
	{
		parm = Parm::getparm(argc, argv);
		log = Log::INITLOG;
		out = Out::INITOUT;
		out = Out::getout(parm.out);
		log = Log::getlog(parm.log);
		In::iN in_result = In::getin(parm.in);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		//Out::WriteOut(in_result, out.outfile);
		Log::WriteIn(log, in_result);
		LexA::LEX LeX = LexA::LexA(parm, in_result);
		ofstream st("ST.txt");
		MFST_TRACE_START(st);
			MFST::Mfst mfst(LeX.lexTable, GRB::getGreibach());
		mfst.start(st);

		mfst.savededucation();

		mfst.printrules(st);
		SemA::checkSemantic(LeX.lexTable, LeX.idTable, LeX.functions);
		RPN::searchNextPosForCheck(LeX.lexTable, LeX.idTable);
		LT::WriteInFile(LeX.lexTable);
		ASMGenerator::asmGenerator(LeX, parm.out);
		Log::Close(log);
		Out::Close(out);
	}
	catch (Error::ERROr e)
	{
		cout << "Ошибка " << e.id << ':' << e.message << "\n\n";
		if (e.inext.line != -1 && e.inext.col != -1) {
			cout << "Строка " << e.inext.line << " позиция " << e.inext.col << '\n';
		}
		if (e.inext.line > 0)
		{
			Log::WriteError(log, e);
			Log::Close(log);
			Out::Close(out);
		}
	}

	return 0;
}