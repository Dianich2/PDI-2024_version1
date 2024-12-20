#pragma once
#include "GRB.h"
#include "Error.h"
#include "LT.h"
#include "LexA.h"
#define NS(n) GRB::Rule::Chain::N(n)
#define TS(n) GRB::Rule::Chain::T(n)
#define ISNS(n)	GRB::Rule::Chain::isN(n)
#define GRB_ERROR_SERIES 600

namespace GRB {
	Greibach greibach(NS('S'), TS('$'),
		8,
		Rule(NS('S'), GRB_ERROR_SERIES + 0,
			12,
			Rule::Chain(9, TS(LEX_MAIN), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_RETURN), TS(LEX_ID), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('S')),
			Rule::Chain(8, TS(LEX_MAIN), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_RETURN), TS(LEX_ID), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON)),
			Rule::Chain(9, TS(LEX_MAIN), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_RETURN), TS(LEX_LITERAL), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('S')),
			Rule::Chain(8, TS(LEX_MAIN), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_RETURN), TS(LEX_LITERAL), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON)),

			Rule::Chain(14, TS(LEX_FUNCTION), TS(TYPE), TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('F'), TS(LEX_RIGHTTHESIS), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_RETURN), TS(LEX_ID), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('S')),
			Rule::Chain(13, TS(LEX_FUNCTION), TS(TYPE), TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('F'), TS(LEX_RIGHTTHESIS), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_RETURN), TS(LEX_ID), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON)),
			Rule::Chain(14, TS(LEX_FUNCTION), TS(TYPE), TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('F'), TS(LEX_RIGHTTHESIS), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_RETURN), TS(LEX_LITERAL), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('S')),
			Rule::Chain(13, TS(LEX_FUNCTION), TS(TYPE), TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('F'), TS(LEX_RIGHTTHESIS), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_RETURN), TS(LEX_LITERAL), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON)),

			Rule::Chain(13, TS(LEX_FUNCTION), TS(TYPE), TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('F'), TS(LEX_RIGHTTHESIS), TS(LEX_LEFTBRACE), TS(LEX_RETURN), TS(LEX_ID), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('S')),
			Rule::Chain(12, TS(LEX_FUNCTION), TS(TYPE), TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('F'), TS(LEX_RIGHTTHESIS), TS(LEX_LEFTBRACE), TS(LEX_RETURN), TS(LEX_ID), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON)),
			Rule::Chain(13, TS(LEX_FUNCTION), TS(TYPE), TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('F'), TS(LEX_RIGHTTHESIS), TS(LEX_LEFTBRACE), TS(LEX_RETURN), TS(LEX_LITERAL), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('S')),
			Rule::Chain(12, TS(LEX_FUNCTION), TS(TYPE), TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('F'), TS(LEX_RIGHTTHESIS), TS(LEX_LEFTBRACE), TS(LEX_RETURN), TS(LEX_LITERAL), TS(LEX_SEMICOLON), TS(LEX_BRACELET), TS(LEX_SEMICOLON))
		),
		Rule(NS('N'), GRB_ERROR_SERIES + 1,
			22,
			Rule::Chain(4, TS(TYPE), TS(LEX_ID), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(3, TS(TYPE), TS(LEX_ID), TS(LEX_SEMICOLON)),

			Rule::Chain(6, TS(TYPE), TS(LEX_ID), TS(LEX_EQUAL), NS('E'), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(5, TS(TYPE), TS(LEX_ID), TS(LEX_EQUAL), NS('E'), TS(LEX_SEMICOLON)),

			Rule::Chain(5, TS(LEX_ID), TS(LEX_EQUAL), NS('E'), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(4, TS(LEX_ID), TS(LEX_EQUAL), NS('E'), TS(LEX_SEMICOLON)),

			Rule::Chain(4, TS(LEX_PRINT), TS(LEX_ID), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(3, TS(LEX_PRINT), TS(LEX_ID), TS(LEX_SEMICOLON)),

			Rule::Chain(4, TS(LEX_PRINT), TS(LEX_LITERAL), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(3, TS(LEX_PRINT), TS(LEX_LITERAL), TS(LEX_SEMICOLON)),

			Rule::Chain(4, TS(LEX_PRINTLN), TS(LEX_ID), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(3, TS(LEX_PRINTLN), TS(LEX_ID), TS(LEX_SEMICOLON)),

			Rule::Chain(4, TS(LEX_PRINTLN), TS(LEX_LITERAL), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(3, TS(LEX_PRINTLN), TS(LEX_LITERAL), TS(LEX_SEMICOLON)),

			Rule::Chain(4, TS(LEX_READ), TS(LEX_ID), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(3, TS(LEX_READ), TS(LEX_ID), TS(LEX_SEMICOLON)),

			Rule::Chain(7, TS(LEX_WHILE), NS('U'), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(6, TS(LEX_WHILE), NS('U'), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_BRACELET), TS(LEX_SEMICOLON)),

			Rule::Chain(7, TS(LEX_IF), NS('U'), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('N')), 
			Rule::Chain(6, TS(LEX_IF), NS('U'), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_BRACELET), TS(LEX_SEMICOLON)),

			Rule::Chain(12, TS(LEX_IF), NS('U'), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_BRACELET), TS(LEX_SEMICOLON), TS(LEX_ELSE), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_BRACELET), TS(LEX_SEMICOLON), NS('N')),
			Rule::Chain(11, TS(LEX_IF), NS('U'), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_BRACELET), TS(LEX_SEMICOLON), TS(LEX_ELSE), TS(LEX_LEFTBRACE), NS('N'), TS(LEX_BRACELET), TS(LEX_SEMICOLON))

		),
		Rule(NS('E'), GRB_ERROR_SERIES + 2, 
			8,
			Rule::Chain(1, TS(LEX_ID)),
			Rule::Chain(2, TS(LEX_ID), NS('M')),
			Rule::Chain(1, TS(LEX_LITERAL)),
			Rule::Chain(2, TS(LEX_LITERAL), NS('M')),
			Rule::Chain(3, TS(LEX_LEFTTHESIS), NS('E'), TS(LEX_RIGHTTHESIS)),
			Rule::Chain(4, TS(LEX_LEFTTHESIS), NS('E'), TS(LEX_RIGHTTHESIS), NS('M')),
			Rule::Chain(4, TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('W'), TS(LEX_RIGHTTHESIS)),
			Rule::Chain(5, TS(LEX_ID), TS(LEX_LEFTTHESIS), NS('W'), TS(LEX_RIGHTTHESIS), NS('M'))
		),
		Rule(NS('F'), GRB_ERROR_SERIES + 3, 
			2,
			Rule::Chain(2, TS(TYPE), TS(LEX_ID)),
			Rule::Chain(4, TS(TYPE), TS(LEX_ID), TS(LEX_COMMA), NS('F'))
		),
		Rule(NS('W'), GRB_ERROR_SERIES + 4,
			4,
			Rule::Chain(1, TS(LEX_ID)),
			Rule::Chain(3, TS(LEX_ID), TS(LEX_COMMA), NS('W')),
			Rule::Chain(1, TS(LEX_LITERAL)),
			Rule::Chain(3, TS(LEX_LITERAL), TS(LEX_COMMA), NS('W'))
		),
		Rule(NS('M'), GRB_ERROR_SERIES + 5,
			13,
			Rule::Chain(2, TS(LEX_PLUS), NS('E')),
			Rule::Chain(2, TS(LEX_MINUS), NS('E')),
			Rule::Chain(2, TS(LEX_STAR), NS('E')),
			Rule::Chain(2, TS(LEX_DIRSLASH), NS('E')),
			Rule::Chain(2, TS(LEX_MORE), NS('E')),
			Rule::Chain(2, TS(LEX_LESS), NS('E')),
			Rule::Chain(2, TS(LEX_ISEQUAL), NS('E')),
			Rule::Chain(2, TS(LEX_NOT_EQUAL), NS('E')),
			Rule::Chain(2, TS(LEX_MORE_OR_EQUAL), NS('E')),
			Rule::Chain(2, TS(LEX_LESS_OR_EQUAL), NS('E')),
			Rule::Chain(2, TS(LEX_OST), NS('E')),
			Rule::Chain(2, TS(LEX_AND), NS('E')),
			Rule::Chain(2, TS(LEX_OR), NS('E'))
		),
		Rule(NS('U'), GRB_ERROR_SERIES + 6,
			6,
			Rule::Chain(5, TS(LEX_LEFTTHESIS), NS('L'), TS(LEX_MORE), NS('L'), TS(LEX_RIGHTTHESIS)),
			Rule::Chain(5, TS(LEX_LEFTTHESIS), NS('L'), TS(LEX_LESS), NS('L'), TS(LEX_RIGHTTHESIS)),
			Rule::Chain(5, TS(LEX_LEFTTHESIS), NS('L'), TS(LEX_ISEQUAL), NS('L'), TS(LEX_RIGHTTHESIS)),
			Rule::Chain(5, TS(LEX_LEFTTHESIS), NS('L'), TS(LEX_NOT_EQUAL), NS('L'), TS(LEX_RIGHTTHESIS)),
			Rule::Chain(5, TS(LEX_LEFTTHESIS), NS('L'), TS(LEX_MORE_OR_EQUAL), NS('L'), TS(LEX_RIGHTTHESIS)),
			Rule::Chain(5, TS(LEX_LEFTTHESIS), NS('L'), TS(LEX_LESS_OR_EQUAL), NS('L'), TS(LEX_RIGHTTHESIS))
		),
		Rule(NS('L'), GRB_ERROR_SERIES + 7,
			2,
			Rule::Chain(1, TS(LEX_ID)),
			Rule::Chain(1, TS(LEX_LITERAL))
		)
	);
}