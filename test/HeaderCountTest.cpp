#include "HeaderCountTest.h"

void HeaderCountTest::constr()
{
	HeaderCount header_count_class;
	CPPUNIT_ASSERT_MESSAGE("expected behavior: constructor defines regular expression", header_count_class.main_regular_expression != "");
}

void HeaderCountTest::getHeadersCount()
{
	HeaderCount header_count_class;
	int header_count = header_count_class.getHeadersCount();
	CPPUNIT_ASSERT_MESSAGE("expected 10", header_count == 10);
}