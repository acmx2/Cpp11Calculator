#include "SimpleCalculator.h"
#include "TokenizerBase.h"
#include "Tokens.h"



SimpleCalculator::SimpleCalculator( TokenizerBase& tz, std::ostream& sto, std::ostream& ste )
	: CalculatorBase(tz, sto, ste)
{
}

void SimpleCalculator::perform()
{
	try
	{
		while( true )
		{
			int nResult =evaluateExpression();
			if (m_tokenizerRef.getCurrentTokenCast<PrintResultToken>())
			{
				m_outputStreamRef<< nResult << std::endl;
			}
			else
			{
				throw CalcException("expression= expected.");
			}
		}
	}
	catch(const TokenizerBase::InterruptException&)
	{
	}
}

int SimpleCalculator::evaluateExpression() const
{
	int leftValue = evaluateNode();

	while(const SignToken* pSum= m_tokenizerRef.getCurrentTokenCast<SignToken>())
	{
		if (pSum->kind ==SignToken::Plus)
		{
			leftValue +=evaluateNode();
		}
		else
		{
			leftValue -=evaluateNode();
		}
	}

	return leftValue;
}

int SimpleCalculator::evaluateNode() const
{
	m_tokenizerRef.readNextToken();

	if (const IntegerToken* pInt= m_tokenizerRef.getCurrentTokenCast<IntegerToken>())
	{
		m_tokenizerRef.readNextToken();
		return pInt->val;
	}

	if (const SignToken* pSum= m_tokenizerRef.getCurrentTokenCast<SignToken>())
	if (pSum->kind==SignToken::Minus	)
	{
		return -evaluateNode();
	}

	if (const BracketToken* pBracket= m_tokenizerRef.getCurrentTokenCast<BracketToken>())
	if (pBracket->kind==BracketToken::Opening)
	{
		int exprVal =evaluateExpression();
		
		pBracket= m_tokenizerRef.getCurrentTokenCast<BracketToken>();
		if ( !pBracket || pBracket->kind !=BracketToken::Closing )
		{
			throw CalcException("bracket error.");
		}
		m_tokenizerRef.readNextToken();
		return exprVal;
	}

	throw CalcException("token error.");
	return 0;
}
