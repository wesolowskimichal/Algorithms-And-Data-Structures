#include <gtest/gtest.h>
#include "ONP_CONV.h"

TEST(tests, Conversion_To_ONP_ADDING){
  EXPECT_STREQ(conv_to_ONP("A+B").c_str(), "A B + ");
  EXPECT_STREQ(conv_to_ONP("A+A+B").c_str(), "A A + B + ");
  EXPECT_STREQ(conv_to_ONP("A+A+B+C").c_str(), "A A + B + C + ");
  EXPECT_STREQ(conv_to_ONP("A+B+C+D+E").c_str(), "A B + C + D + E + ");
}

TEST(tests, Conversion_To_ONP_SUBSTRACTION) {
	EXPECT_STREQ(conv_to_ONP("A-B").c_str(), "A B - ");
	EXPECT_STREQ(conv_to_ONP("A-A-B").c_str(), "A A - B - ");
	EXPECT_STREQ(conv_to_ONP("A-A-B-C").c_str(), "A A - B - C - ");
	EXPECT_STREQ(conv_to_ONP("A-B-C-D-E").c_str(), "A B - C - D - E - ");
}

TEST(tests, Conversion_To_ONP_MULTIPLICATION) {
	EXPECT_STREQ(conv_to_ONP("A*B").c_str(), "A B * ");
	EXPECT_STREQ(conv_to_ONP("A*A*B").c_str(), "A A * B * ");
	EXPECT_STREQ(conv_to_ONP("A*A*B-C+D*E^2").c_str(), "A A * B * C - D E 2 ^ * + ");
	EXPECT_STREQ(conv_to_ONP("((A+B)*C(E-D)^6*)*2+4").c_str(), "A B + C E D - 6 ^ * * 2 * 4 + ");
}

TEST(tests, Conversion_To_ONP_DIVISION) {
	EXPECT_STREQ(conv_to_ONP("A/B").c_str(), "A B / ");
	EXPECT_STREQ(conv_to_ONP("A/A/B").c_str(), "A A / B / ");
	EXPECT_STREQ(conv_to_ONP("A/A/B-C+D/E^2").c_str(), "A A / B / C - D E 2 ^ / + ");
	EXPECT_STREQ(conv_to_ONP("((A+B)/C(E-D)^6/)/2+4").c_str(), "A B + C E D - 6 ^ / / 2 / 4 + ");
}

TEST(tests, MIX) {
	EXPECT_STREQ(conv_to_ONP("-A+B").c_str(), "A - B + ");
	EXPECT_STREQ(conv_to_ONP("(((A+B)/C*D-(E*F)^G/6)/6*5^4-2)+E/F*G").c_str(), "A B + C / D * E F * G ^ 6 / - 6 / 5 4 ^ * 2 - E F / G * + ");
}