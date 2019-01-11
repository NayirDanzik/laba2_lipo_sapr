#include <cstdlib>
#include <iostream>
#include "stdio.h"
#include <string>
#include <pcrecpp.h>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

class HeaderCount
{
	public:
		HeaderCount();
		int getHeadersCount();
		char* main_regular_expression;
};