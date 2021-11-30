/**
 * Reverse string problem - version 1.00
 * --------------------------------------------------------
 * Created November 2021,
 * @author Earl John Abaquita (earl.abaquita@outlook.com)
 *
 * Description:
 * contains the main function
 *
 **/

#include "common_debug.h"
#include "solution.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <cassert>

#ifndef TEST_MODE

int main(){

	std::unique_ptr<solution> sol = std::make_unique<solution>();
	auto result = sol->reverse_string("Stri_ng;-%   2b$#e reversed");

	MESSAGE_LOG("origin = Stri_ng;-%   2b$#e reversed");
	VAR_LOG(result);
	assert(result.compare("irtS_gn;-%   b2$#e desrever")==0);

	return 0;
}

#endif
#ifdef TEST_MODE

TEST_MAIN()

TEST( test_required ){
	std::unique_ptr<solution> sol = std::make_unique<solution>();
	ASSERT_EQUAL("irtS_gn;-%   b2$#e desrever", sol->reverse_string("Stri_ng;-%   2b$#e reversed"));
}

TEST( test_solo_characters ){
	std::unique_ptr<solution> sol = std::make_unique<solution>();
	ASSERT_EQUAL("o", sol->reverse_string("o"));
	ASSERT_EQUAL("1", sol->reverse_string("1"));
	ASSERT_EQUAL("&", sol->reverse_string("&"));
	ASSERT_EQUAL(" ", sol->reverse_string(" "));
	ASSERT_EQUAL("" , sol->reverse_string(""));
}

TEST( test_basic_reversal ){
	std::unique_ptr<solution> sol = std::make_unique<solution>();
	ASSERT_EQUAL("olleH", sol->reverse_string("Hello"));
	ASSERT_EQUAL("EarL", sol->reverse_string("LraE"));
	ASSERT_EQUAL("johNNN", sol->reverse_string("NNNhoj"));
	ASSERT_EQUAL("basic string", sol->reverse_string("cisab gnirts"));
	ASSERT_EQUAL("     olleH  ", sol->reverse_string("     Hello  "));
}

TEST( test_basic_numbers_only ){
	std::unique_ptr<solution> sol = std::make_unique<solution>();
	ASSERT_EQUAL("1234567890", sol->reverse_string("0987654321"));
	ASSERT_EQUAL("5551 22234 4445533", sol->reverse_string("1555 43222 3355444"));
	ASSERT_EQUAL("1234 5678 1234 567890", sol->reverse_string("4321 8765 4321 098765"));
	ASSERT_EQUAL("1234567890", sol->reverse_string("0987654321"));
	ASSERT_EQUAL("   5551 22234 4445533   ", sol->reverse_string("   1555 43222 3355444   "));
}

TEST( test_no_alphanumeric ){
	std::unique_ptr<solution> sol = std::make_unique<solution>();
	ASSERT_EQUAL("!@#$%^&*()", sol->reverse_string("!@#$%^&*()"));
	ASSERT_EQUAL("!@    #$%     ^&*()", sol->reverse_string("!@    #$%     ^&*()"));
	ASSERT_EQUAL("....^^^^^^$$$$$...,,,..,,><", sol->reverse_string("....^^^^^^$$$$$...,,,..,,><"));
	ASSERT_EQUAL("     ", sol->reverse_string("     "));
}

TEST( test_alternate_characters ){
	std::unique_ptr<solution> sol = std::make_unique<solution>();
	ASSERT_EQUAL("1 a b c ! 1 a b c", sol->reverse_string("1 a b c ! 1 a b c"));
	ASSERT_EQUAL("12 ab bc cd !!! 12 ab bc cd", sol->reverse_string("21 ba cb dc !!! 21 ba cb dc"));
	ASSERT_EQUAL("1 boots &", sol->reverse_string("1 stoob &"));
	ASSERT_EQUAL("1 boots &abc", sol->reverse_string("1 stoob &cba"));
}

TEST( test_combination_multiple_words ){
	std::unique_ptr<solution> sol = std::make_unique<solution>();
	ASSERT_EQUAL("!!! earl !!!!", sol->reverse_string("!!! lrae !!!!"));
	ASSERT_EQUAL("test !!! earl !!!!", sol->reverse_string("tset !!! lrae !!!!"));
	ASSERT_EQUAL("xxx__yyy---!!!-bob-!!!!", sol->reverse_string("xxx__yyy---!!!-bob-!!!!"));
	ASSERT_EQUAL("!!! earl john earl john !!!!", sol->reverse_string("!!! lrae nhoj lrae nhoj !!!!"));
	ASSERT_EQUAL("!!! earl12345 !!!!", sol->reverse_string("!!! 54321lrae !!!!"));
}

#endif
