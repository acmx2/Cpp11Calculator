#pragma once

#include <ostream>

namespace Utils
{
	//ExceptionHelper class. 
	//Role: contains helper methods for exception handling
	class ExceptionHelper
	{
	private:
		// Description:	Deprecated ctor.
		ExceptionHelper();	
		// Description:	Deprecated dtor
		~ExceptionHelper();

	public:

		// Description:	Catches all risen exceptions and logs them to a stream
		static void catchAndLogAllTo(std::ostream&);
	};
}