#include <new>
#include <typeinfo>

#include "ExceptionHelper.h"
#include "UException.h"

// Method:    	Utils::ExceptionHelper::catchAndReportAllTo
// Access:    	public static 
// Returns:   	void
// Parameter: 	std::ostream& - a stream to output messages to 
void Utils::ExceptionHelper::catchAndLogAllTo( std::ostream& outStream )
{
	try
	{															//catch and re-throw risen exception, if is,
		throw;												//to catch it again in the blocks right below
	}
	catch (const Utils::UException& ue)			//catching application exception
	{
		outStream << "Utils::UException caught: " << ue.getMessage() << std::endl;
	}
	catch (const std::bad_alloc& ba)			//catching std low memory exception
	{
		outStream << "std::bad_alloc caught: " << ba.what() << std::endl;
	}
	catch (const std::bad_cast& bc)			//catching std bad cast exception
	{
		outStream << "std::bad_cast caught: " << bc.what() << std::endl;
	}
	catch (std::exception& e)						//catching all others std exceptions
	{
		outStream << "std::exception caught: " << e.what() << std::endl;
	}
	catch (...)												//catching non-std exceptions
	{															
		outStream << "unexpected exception caught" << std::endl;
	}
}
