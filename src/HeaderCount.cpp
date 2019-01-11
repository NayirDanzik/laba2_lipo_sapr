#include "HeaderCount.h"

using namespace std;

// Class constructor
HeaderCount::HeaderCount()
{
	main_regular_expression = "^(.*#include\\s[<\"](\\w+\\/?)+(\\.h(pp)?)?[>\"])$";
}

// Function for count headers on file
int HeaderCount::getHeadersCount()
{
	string std_input;
	string error_part_string;
	string null_pointer;
	pcrecpp::RE main_pattern( main_regular_expression );
	
	vector<string>input_array;
	
	while ( !cin.eof() )
	{
		std_input += cin.get();
		if ( std_input.find("\n") != -1 )
		{
			pcrecpp::StringPiece pcrecpp_piece(std_input);
				
			if ( main_pattern.Consume(&pcrecpp_piece, &error_part_string, &null_pointer, &null_pointer) )
			{
				if ( std::find(input_array.begin(), input_array.end(), std_input) == input_array.end() ) 
				{
					input_array.push_back(std_input);
				}
			}
			std_input = "";
			error_part_string = "";
			std::cin.clear();
		}
	}
	
	return input_array.size();
}