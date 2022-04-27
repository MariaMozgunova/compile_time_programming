#include <gtest/gtest.h>
#include "evaluate_poly.hpp"


TEST(PolynomialEvaluate, IntCoefficients) {
    constexpr int coef[] = {10, -2, 3};
    constexpr Polynomial<int, 3> p(coef);
    constexpr int res2 = evaluate(2, p);
    constexpr int res_17 = evaluate(-17, p);
    // static_assert(res2 == 18);
    // static_assert(res_17 == 911);
    EXPECT_EQ(res2, 18);
    EXPECT_EQ(res_17, 911);
}


TEST(PolynomialEvaluate, UIntCoefficients) {
    constexpr unsigned int coef[] = {0, 2, 31, 1};
    constexpr Polynomial<unsigned int, 4> p(coef);
    constexpr int res0 = evaluate((unsigned int)0, p);
    constexpr int res112 = evaluate((unsigned int)112, p);
    // static_assert(res0 == 0);
    // static_assert(res112 == 1794016);
    EXPECT_EQ(res0, 0);
    EXPECT_EQ(res112, 1794016);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}