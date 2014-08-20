/**
* @file      EncoderTests.cpp
* @copyright (c) 2014 by Petr Zemek (s3rvac@gmail.com) and contributors
* @license   BSD, see the @c LICENSE file for more details
* @brief     Tests for the Encoder class.
*/

#include <gtest/gtest.h>

#include "BInteger.h"
#include "BList.h"
#include "BString.h"
#include "Encoder.h"

namespace bencoding {
namespace tests {

using namespace testing;

class EncoderTests: public Test {
protected:
	EncoderTests(): encoder(Encoder::create()) {}

protected:
	std::unique_ptr<Encoder> encoder;
};

//
// Integer encoding.
//

TEST_F(EncoderTests,
IntegerWithZeroValueIsCorrectlyEncoded) {
	std::shared_ptr<BItem> data(BInteger::create(0));

	EXPECT_EQ("i0e", encoder->encode(data));
}

TEST_F(EncoderTests,
IntegerWithPositiveValueIsCorrectlyEncoded) {
	std::shared_ptr<BItem> data(BInteger::create(13));

	EXPECT_EQ("i13e", encoder->encode(data));
}

TEST_F(EncoderTests,
IntegerWithNegativeValueIsCorrectlyEncoded) {
	std::shared_ptr<BItem> data(BInteger::create(-13));

	EXPECT_EQ("i-13e", encoder->encode(data));
}

//
// List encoding.
//

TEST_F(EncoderTests,
EmptyListIsEncodedCorrectly) {
	std::shared_ptr<BList> bList = BList::create();

	EXPECT_EQ("le", encoder->encode(bList));
}

TEST_F(EncoderTests,
ListContainingTwoStringsIsEncodedCorrectly) {
	std::shared_ptr<BList> bList = BList::create();
	bList->append(BString::create("test"));
	bList->append(BString::create("hello"));

	EXPECT_EQ("l4:test5:helloe", encoder->encode(bList));
}

//
// String encoding.
//

TEST_F(EncoderTests,
EmptyStringIsCorrectlyEncoded) {
	std::shared_ptr<BItem> data(BString::create(""));

	EXPECT_EQ("0:", encoder->encode(data));
}

TEST_F(EncoderTests,
NonemptyStringIsCorrectlyEncoded) {
	std::shared_ptr<BItem> data(BString::create("test"));

	EXPECT_EQ("4:test", encoder->encode(data));
}

//
// Other.
//

TEST_F(EncoderTests,
EncodeFunctionWorksAsCreatingEncoderAndCallingEncode) {
	std::shared_ptr<BItem> data(BInteger::create(0));

	EXPECT_EQ("i0e", encode(data));
}

} // namespace tests
} // namespace bencoding
