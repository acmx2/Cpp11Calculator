#pragma once

#include <string>

namespace Utils
{
	class UException
	{
	private:
		static const char* s_defaultMessage;
		std::string m_message;

	public:
		explicit UException(std::string&& msg =std::string(s_defaultMessage));
		explicit UException(const std::string&);
		virtual ~UException(void);

		const std::string& getMessage() const;
	};
}