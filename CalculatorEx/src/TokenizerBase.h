#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "UException.h"


class TokenizerBase;

class TokenBase
{
	friend class TokenizerBase;
protected:
	virtual void read(std::istream&) =0;
	virtual bool canBeReadFrom(std::istream&) const =0;
	virtual TokenBase* clone() const =0;
public:
	virtual ~TokenBase();
	template <typename T> const T* castTo() const {return dynamic_cast<const T*>(this);}
};

class TokenizerBase
{
public:
	class InterruptException : public Utils::UException
	{
	};
private:
	std::istream& m_inputStreamRef;
	std::vector<std::unique_ptr<TokenBase>> m_tokenPrototypes; 
	std::vector<std::unique_ptr<TokenBase>> m_readTokens;
protected:
	void appendToPrototypes(const TokenBase& x);
	virtual bool shouldTokenBeFilteredOut(const TokenBase&) const =0;
public:
	explicit TokenizerBase(std::istream&);
	virtual ~TokenizerBase();
	void clearTokenHistory();
	const TokenBase* getCurrentToken() const;
	template <typename T> const T* getCurrentTokenCast() const { return dynamic_cast<const T*>(getCurrentToken()); }
	const TokenBase* readNextToken();
};
