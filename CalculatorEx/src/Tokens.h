#pragma once

#include "TokenizerBase.h"



class WhitespaceToken : public TokenBase
{
protected:
	virtual void read(std::istream&);
	virtual bool canBeReadFrom(std::istream&) const;
	virtual TokenBase* clone() const;
};

class NumericToken : public TokenBase
{
};

class IntegerToken : public NumericToken
{
protected:
	virtual void read(std::istream&);
	virtual bool canBeReadFrom(std::istream&) const;
	virtual TokenBase* clone() const;
public:
	int val;
};

class BracketToken : public TokenBase
{
protected:
	virtual void read(std::istream&);
	virtual bool canBeReadFrom(std::istream&) const;
	virtual TokenBase* clone() const;

public:
	enum Kind
	{
		Opening,
		Closing
	};
	Kind kind;
};

class OperationToken : public TokenBase
{
};

class SignToken : public OperationToken
{
protected:
	virtual void read(std::istream&);
	virtual bool canBeReadFrom(std::istream&) const;
	virtual TokenBase* clone() const;
public:
	enum Kind
	{
		Plus,
		Minus
	};
	Kind kind;
};

class InvertionToken : public OperationToken
{
protected:
	virtual void read(std::istream&);
	virtual bool canBeReadFrom(std::istream&) const;
	virtual TokenBase* clone() const;
};

class PrintResultToken : public OperationToken
{
protected:
	virtual void read(std::istream&);
	virtual bool canBeReadFrom(std::istream&) const;
	virtual TokenBase* clone() const;
};