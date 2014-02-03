#include <utility>

#include "UException.h"


using namespace Utils;


const char* Utils::UException::s_defaultMessage ="Application exception.";

Utils::UException::UException( std::string&& msg /*=std::string(s_defaultMessage)*/ )
	: m_message(std::forward<std::string>(msg))
{
}

Utils::UException::UException( const std::string& msg )
	: m_message(msg)
{
}

Utils::UException::~UException()
{
}

const std::string& Utils::UException::getMessage() const
{
	return m_message;
}
