//!
//! @file 			EraseTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-09-13
//! @brief 			Makes sure the String::Erase() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{

	MTEST(BasicEraseTest)
	{
		MbeddedNinja::MString myString("Hello, world!");

		// Erase everything after "Hello"
		myString.Erase(5);

		CHECK_EQUAL(myString, "Hello");
	}

	MTEST(LengthCorrectCheckTest)
	{
		MbeddedNinja::MString myString("Hello, world!");

		myString.Erase(5);

		// Make sure only 5 characters are left
		CHECK_EQUAL(myString.GetLength(), 5);
	}

	MTEST(EraseMiddleSectionTest)
	{
		MbeddedNinja::MString myString("Hello, world!");

		// Erase the comma and space
		myString.Erase(5, 2);

		CHECK_EQUAL(myString, "Helloworld!");
		CHECK_EQUAL(myString.GetLength(), 11);
	}

	MTEST(EraseBeyondLengthTest)
	{
		MbeddedNinja::MString myString("Hello, world!");

		// Atempt to erase characters beyond the length of the string, this
		// should do nothing
		myString.Erase(30);

		CHECK_EQUAL(myString, "Hello, world!");
		CHECK_EQUAL(myString.GetLength(), 13);
	}

	MTEST(EraseBeyondLengthTestWithNum)
	{
		MbeddedNinja::MString myString("Hello, world!");

		// Atempt to erase characters beyond the length of the string, this
		// should do nothing
		myString.Erase(30, 10);

		CHECK_EQUAL(myString, "Hello, world!");
		CHECK_EQUAL(myString.GetLength(), 13);
	}

	MTEST(SpecifyTooManyCharsToEraseTest)
	{
		MbeddedNinja::MString myString("Hello, world!");

		// Try and erase 30 chars starting from pos 5, should just erase what we can
		myString.Erase(5, 30);

		CHECK_EQUAL(myString, "Hello");
	}

	MTEST(EraseAllTest)
	{
		MbeddedNinja::MString myString("Hello, world!");

		// Erase all characters
		myString.Erase(0);

		CHECK_EQUAL(myString, "");

		// Lets try and erase again, should do nothing
		myString.Erase(10);

		CHECK_EQUAL(myString, "");
	}

	MTEST(EraseNegativeNumberTest1)
	{
		MbeddedNinja::MString myString("Hello, world!");

		// Insert negative number, as Erase() uses a uint32_t, this will be seen
		// as a really big number and should be out of bounds, hence nothing will
		// be erased
		myString.Erase(-2);

		// Make sure nothing was erased
		CHECK_EQUAL(myString, "Hello, world!");
	}

	MTEST(EraseNegativeNumberTest2)
	{
		MbeddedNinja::MString myString("Hello, world!");

		// Insert two negative numbers, as Erase() uses a uint32_t, these will be seen
		// as a really big numbers and should be out of bounds, hence nothing will
		// be erased
		myString.Erase(-2, -3);

		// Make sure nothing was erased
		CHECK_EQUAL(myString, "Hello, world!");
	}

} // namespace StringTestsNs
