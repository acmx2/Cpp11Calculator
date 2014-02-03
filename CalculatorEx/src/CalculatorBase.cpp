#include "CalculatorBase.h"
#include "TokenizerBase.h"


CalculatorBase::CalcException::CalcException( const char* s /*=0*/ )
	: Utils::UException(std::string( s ? s : "calculation error."))
{
}

CalculatorBase::CalculatorBase( TokenizerBase& tz ,std::ostream& sto ,std::ostream& ste )
	: m_tokenizerRef(tz)
	, m_outputStreamRef(sto)
	, m_errorStreamRef(ste)
{
}

CalculatorBase::~CalculatorBase()
{
}

bool CalculatorBase::calculate()
{
	try
	{
		m_tokenizerRef.clearTokenHistory();
		perform();
	}
	catch(const CalcException& e)
	{
		m_errorStreamRef<<e.getMessage();
		return true;
	}
	return true;
}
