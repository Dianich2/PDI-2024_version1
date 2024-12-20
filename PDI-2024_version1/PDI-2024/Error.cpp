#include"stdafx.h"
#include"Error.h"
namespace Error
{
		ERROr errors[ERROR_MAX_ENTRY] = {
		ERROR_ENTRY(0,"Íåäîïóñòèìûé êîä îøèáêè"),
		ERROR_ENTRY(1,"Ñèñòåìíûé ñáîé"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"Ïàğàìåòğ -in äîëæåí áûòü çàäàí"),
		ERROR_ENTRY(101, "Ïğåâûøåíà äëèíà âõîäíîãî ïàğàìåòğà"), 
		ERROR_ENTRY(102, "Âñå ôóíêöèè äîëæíû áûòü îáúÿâëåíû äî main"),
		ERROR_ENTRY(103, "Ôóíêöèÿ main íå îáúÿâëåíà"),
		ERROR_ENTRY(104, "Êëş÷åâîå ñëîâî íå ìîæåò áûòü èäåíòèôèêàòîğîì"),
		ERROR_ENTRY(105,"Äóáëèğîâàíèå èäåíòèôèêàòîğà"),
		ERROR_ENTRY(106,"Èäåíòèôèêàòîğ íå îïğåäåë¸í"),
		ERROR_ENTRY(107, "Ôóíêöèÿ óæå îïğåäåëåíà"),
		ERROR_ENTRY(108, "Ïğåâûøåíî ìàêñèìàëüíî âîçìîæíîå ÷èñëî ïàğàìåòğîâ â ôóíêöèè"),
		ERROR_ENTRY(109, "Ïîâòîğíîå îáúÿâëåíèå main"),
		ERROR_ENTRY(110,"Îøèáêà ïğè îòêğûòèè ôàéëà ñ èñõîäíûì êîäîì (-in)"),
		ERROR_ENTRY(111,"Íåäîïóñòèìûé ñèìâîë â èñõîäíîì ôàéëå (-in)"),
		ERROR_ENTRY(112,"Îøèáêà ïğè ñîçäàíèè ôàéëà ñ ïğîòîêîëîì (-log)"),
		ERROR_ENTRY(113,"Îøèáêà ïğè ñîçäàíèè âûõîäíîãî ôàéëà ñ ğàñøèğåíèåì .out"),
		ERROR_ENTRY(114,"Íåäîïóñòèìûé ğàçìåğ òàáëèöû ëåêñåì"),
		ERROR_ENTRY(115,"Ïğåâûøåí ğàçìåğ òàáëèöû ëåêñåì"),
		ERROR_ENTRY(117,"Íåäîïóñòèìûé ğàçìåğ òàáëèöû èäåíòèôèêàòîğîâ"),
		ERROR_ENTRY(118,"Ïğåâûøåí ğàçìåğ òàáëèöû èäåíòèôèêàòîğîâ"),
		ERROR_ENTRY(119,"Ïğåâûøåíà äëèíà ëåêñåìû"),
		ERROR_ENTRY(120, "Ïğèñâàèâàåìîå çíà÷åíèå íå ñîîòâåòñòâóåò òèïó ïåğåìåííîé"),
		ERROR_ENTRY(121, "Âîçâğàùàåìîå çíà÷åíèå â ôóíêöèè íå ñîîòâåòñòâóåò åå òèïó"),
		ERROR_ENTRY(122, "Ôàêòè÷åñêèå è ôîğìàëüíûå ïàğàìåòğû íå ñîîòâåòñòâóşò ïî òèïó èëè êîëè÷åñòâó"),
		ERROR_ENTRY(123, "Ïğè ïğèñâàèâàíèè, ñëåâà äîëæíà áûòü ïåğåìåííàÿ èëè äîëæåí áûòü ïàğàìåòğ"),
		ERROR_ENTRY(124, "Íåäîïóñòèìî äåëåíèå íà íîëü"),
		ERROR_ENTRY(125, "Îøèáêà â ñòğîêîâîì ëèòåğàëå"),
		ERROR_ENTRY(126, "Ôóíêöèÿ íå ìîæåò áûòü ñòğîêîâîãî òèïà"),
		ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),ERROR_ENTRY_NODEF10(160),
		ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),ERROR_ENTRY_NODEF100(200),ERROR_ENTRY_NODEF100(300),
		ERROR_ENTRY_NODEF100(400),ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "Íåâåğíàÿ ñòğóêòóğà ïğîãğàììû"),
		ERROR_ENTRY(601, "Îøèáî÷íûé îïåğàòîğ"),
		ERROR_ENTRY(602, "Îøèáêà â âûğàæåíèè"),
		ERROR_ENTRY(603, "Îøèáêà â ïàğàìåòğàõ ôóíêöèè"),
		ERROR_ENTRY(604, "Îøèáêà â ïàğàìåòğàõ âûçûâàåìîé ôóíêöèè"),
		ERROR_ENTRY(605, "Îøèáêà â ïîäâûğàæåíèè"),
		ERROR_ENTRY(606, "Îøèáêà â ëîãè÷åñêîì âûğàæåíèè"),
		ERROR_ENTRY(607, "Îøèáêà â ëîãè÷åñêîì ïîäâûğàæåíèè"),
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