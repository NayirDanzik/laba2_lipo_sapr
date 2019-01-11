#include <cstdlib>
#include <iostream>
#include "stdio.h"
#include <pcrecpp.h>
#include <cstring>
#include "HeaderCountTest.h"

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( HeaderCountTest );

int main(int argc, char* argv[]) 
{
	CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    CppUnit::TextTestRunner runner;
	runner.addTest(test);
	
	runner.run();
	
	exit(0);
}