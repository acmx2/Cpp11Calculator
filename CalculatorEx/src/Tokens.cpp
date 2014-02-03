#include <assert.h>
#include <ctype.h>

#include "Tokens.h"



void WhitespaceToken::read( std::istream& str )
{
	assert(canBeReadFrom(str));

	char c;
	while(canBeReadFrom(str))
	{
		str>>c;
	}
}

bool WhitespaceToken::canBeReadFrom( std::istream& str ) const
{
	if(!str) return false;

	char c;
	str >> c;
	str.putback(c);
	if ( c==' ' )
	{
		return true;
	}
	return false;
}

TokenBase* WhitespaceToken::clone() const
{
	return new WhitespaceToken(*this);
}

void IntegerToken::read( std::istream& str )
{
	assert(canBeReadFrom(str));

	str>>val;
}

bool IntegerToken::canBeReadFrom( std::istream& str ) const
{
	if(!str) return false;

	char c;
	str >> c;
	str.putback(c);
	if ( isdigit(c) )
	{
		return true;
	}
	return false;
}

TokenBase* IntegerToken::clone() const
{
	return new IntegerToken(*this);
}

void BracketToken::read( std::istream& str )
{
	assert(canBeReadFrom(str));

	char c;
	str >> c;
	kind = ( c=='(' ) ? Opening : Closing;
}

bool BracketToken::canBeReadFrom( std::istream& str ) const
{
	if(!str) return false;

	char c;
	str >> c;
	str.putback(c);
	if ( c=='(' || c==')' )
	{
		return true;
	}
	return false;
}

TokenBase* BracketToken::clone() const
{
	return new BracketToken(*this);
}

void SignToken::read( std::istream& str )
{
	assert(canBeReadFrom(str));

	char c;
	str >> c;
	kind = ( c=='+' ) ? Plus : Minus;
}

bool SignToken::canBeReadFrom( std::istream& str ) const
{
	if(!str) return false;

	char c;
	str >> c;
	str.putback(c);
	if ( c=='+' || c=='-' )
	{
		return true;
	}
	return false;
}

TokenBase* SignToken::clone() const
{
	return new SignToken(*this);
}

void InvertionToken::read( std::istream& str )
{
	assert(canBeReadFrom(str));
	char c1, c2;
	str >> c1 >> c2;
}

bool InvertionToken::canBeReadFrom( std::istream& str ) const
{
	if(!str) return false;

	char c1, c2;
	str >> c1;
	str.putback(c1);

	if(!str) return false;
	str >> c2;
	str.putback(c2);

	if ( c1=='-' && c2=='+' )
	{
		return true;
	}
	return false;
}

TokenBase* InvertionToken::clone() const
{
	return new InvertionToken(*this);
}

void PrintResultToken::read( std::istream& str )
{
	assert(canBeReadFrom(str));

	char c;
	str>>c;
}

bool PrintResultToken::canBeReadFrom( std::istream& str ) const
{
	if(!str) return false;

	char c;
	str >> c;
	str.putback(c);
	if ( c=='=' )
	{
		return true;
	}
	return false;
}

TokenBase* PrintResultToken::clone() const
{
	return new PrintResultToken(*this);
}
