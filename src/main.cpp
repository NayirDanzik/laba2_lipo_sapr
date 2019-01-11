#include <cstdlib>
#include <iostream>	
#include "stdio.h"
#include <cstring>
#include <ctype.h>
#include "HeaderCount.h"

using namespace std;

int main(int argc, char* argv[]) 
{
	HeaderCount header_count;
	
	std::cout << header_count.getHeadersCount() << std::endl;
	
	exit(0);
}