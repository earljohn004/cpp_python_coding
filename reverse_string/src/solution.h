/**
 * Reverse string problem - version 1.00
 * --------------------------------------------------------
 * Created November 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 **/
#include <iostream>
#include <string>


class solution{
	public:
		solution() = default;
		~solution() = default;

		/**
		 * Description: 
		 *	 Reverses a string retaining the order of the words.
		 *	 Non-alphanumeric characters will not be reversed
		 **/
		std::string reverse_string(const std::string text);
};
