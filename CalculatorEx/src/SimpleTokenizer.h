#pragma once

#include "TokenizerBase.h"

class SimpleTokenizer : public TokenizerBase
{
private:
	virtual bool shouldTokenBeFilteredOut(const TokenBase&) const;
public:
	explicit SimpleTokenizer(std::istream&);
};

