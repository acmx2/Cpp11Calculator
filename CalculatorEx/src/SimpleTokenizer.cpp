#include "SimpleTokenizer.h"
#include "Tokens.h"


SimpleTokenizer::SimpleTokenizer(std::istream& istr)
	: TokenizerBase(istr)
{
	appendToPrototypes(WhitespaceToken());
	appendToPrototypes(IntegerToken());
	appendToPrototypes(BracketToken());
	appendToPrototypes(SignToken());
	appendToPrototypes(InvertionToken());
	appendToPrototypes(PrintResultToken());
}

bool SimpleTokenizer::shouldTokenBeFilteredOut( const TokenBase& x ) const
{
	if (x.castTo<WhitespaceToken>())
	{
		return true;
	}
	return false;
}
