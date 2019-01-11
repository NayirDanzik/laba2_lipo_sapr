#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <pcrecpp.h>	
#include <iostream>	
#include "../src/HeaderCount.h"

class HeaderCountTest : public CppUnit::TestCase
{
	public:
		void constr();
		void getHeadersCount();
		
		CPPUNIT_TEST_SUITE( HeaderCountTest );
		CPPUNIT_TEST( constr );
		CPPUNIT_TEST( getHeadersCount );
		CPPUNIT_TEST_SUITE_END();
};