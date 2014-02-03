#include "TokenizerBase.h"
#include <assert.h>



TokenBase::~TokenBase()
{
}

TokenizerBase::TokenizerBase( std::istream& sti )
	: m_inputStreamRef(sti)
{
}

TokenizerBase::~TokenizerBase()
{
}

void TokenizerBase::appendToPrototypes( const TokenBase& x )
{
	m_tokenPrototypes.emplace_back(x.clone());
}

const TokenBase* TokenizerBase::getCurrentToken() const
{
	if (m_readTokens.empty())
	{
		return 0;
	}
	return m_readTokens.back().get();
}

const TokenBase* TokenizerBase::readNextToken()
{
	if (!m_inputStreamRef.good())
	{
		throw InterruptException();
	}

	m_inputStreamRef.exceptions( 	std::ios_base::eofbit | 
									std::ios_base::failbit |
									std::ios_base::badbit );

	try
	{
		for (auto i =m_tokenPrototypes.begin(); i !=m_tokenPrototypes.end(); i++)
		{
			if ( (*i)->canBeReadFrom(m_inputStreamRef) )
			{
				std::unique_ptr<TokenBase> newToken((*i)->clone());
				assert(newToken.get());
				newToken->read(m_inputStreamRef);
				if ( shouldTokenBeFilteredOut(*newToken) )
				{
					return readNextToken();
				}
				else
				{
					m_readTokens.push_back( std::move(newToken) );
				}
				return getCurrentToken();
			}
		}
	}
	catch(const std::ios_base::failure&)
	{
		throw InterruptException();
	}
	return 0;
}

void TokenizerBase::clearTokenHistory()
{
	m_readTokens.clear();
}

