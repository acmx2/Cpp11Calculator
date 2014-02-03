#pragma once

#include <ostream>
#include "UException.h"

class TokenizerBase;


class CalculatorBase
{
protected:
	class CalcException : public Utils::UException
	{
	public:
		explicit CalcException(const char* s =0);
	};

	TokenizerBase& m_tokenizerRef;
	std::ostream& m_outputStreamRef;
	std::ostream& m_errorStreamRef;
	virtual void perform() =0;
public:
	CalculatorBase(TokenizerBase&,std::ostream&,std::ostream&);
	virtual ~CalculatorBase();;
	virtual bool calculate();
};

