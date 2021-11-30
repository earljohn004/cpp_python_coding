/**
 * Reverse string problem - version 1.00
 * --------------------------------------------------------
 * Created November 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains the solution to the main problem
 *
 **/
#include <algorithm>
#include <ctype.h>
#include <sstream>
#include "solution.h"
#include "common_debug.h"

std::string solution::reverse_string(const std::string text){

	std::stringstream al_numstream {};
	std::stringstream output {};

	std::for_each( text.begin(), text.end(), [&](auto ch){
		if( std::isalnum(ch) ){
			// When current character is alphanumeric, push to al_numstream
			al_numstream << ch;
		}else{

			auto temp_str = al_numstream.str();
			std::reverse( temp_str.begin(), temp_str.end() );
			output << temp_str << ch;
			al_numstream.str("");  //Clear the contents of stringstream
		}
	});

	// Additional checking, else statement block above is not performed when 
	// the input is all valid alphanumeric only
	if( output.str().empty() || !al_numstream.str().empty() ){
		auto temp_str = al_numstream.str();
		std::reverse( temp_str.begin(), temp_str.end() );
		output << temp_str;
	}else{ /* Do nothing */ }
	
	return output.str();
}
