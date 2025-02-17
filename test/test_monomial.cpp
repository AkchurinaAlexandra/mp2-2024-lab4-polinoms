#include <gtest.h>
#include "Monomial.h"

TEST(MonomialTest, default_monomial) {
    Monomial m;
    ASSERT_EQ(m.toString(), "0");
}

TEST(MonomialTest, zero_monomial) {
    Monomial m("0xyz");
    ASSERT_EQ(m.toString(), "0");
}

TEST(MonomialTest, single_one_monomial) {
    Monomial m("1");
    ASSERT_EQ(m.toString(), "1");
}


TEST(MonomialTest, single_number_monomial) {
    Monomial m("2.1");
    ASSERT_EQ(m.toString(), "2.1");
}

TEST(MonomialTest, simple_monomial_power_1_output) {
    Monomial m("2x1y2z3");
    ASSERT_EQ(m.toString(), "2xy2z3");
}

TEST(MonomialTest, monomial_with_power_overflow) {
    ASSERT_ANY_THROW(Monomial("2x10y2z3"));
}

TEST(MonomialTest, double_monomial) {
    Monomial m("2.152x2y");
    ASSERT_EQ(m.toString(), "2.152x2y");
}

TEST(MonomialTest, double_exp_monomial) {
    Monomial m("2.1e2x2y");
    ASSERT_EQ(m.toString(), "210x2y");
}

TEST(MonomialTest, monomial_sum) {
    Monomial m1("2x2y3z1");
    Monomial m2("10x2y3z1");
    ASSERT_EQ((m1 + m2).toString(), "12x2y3z");
}

TEST(MonomialTest, monomial_mul_by_coeff) {
    Monomial m1("2x2y3z1");
    ASSERT_EQ((m1 * 3.5).toString(), "7x2y3z");
}

TEST(MonomialTest, monomial_mul) {
    Monomial m1("2x2y3z1");
    Monomial m2("7x3y3z7");
    ASSERT_EQ((m1 * m2).toString(), "14x5y6z8");
}

TEST(MonomialTest, monomial_mul_overflow) {
    Monomial m1("2x2y3z1");
    Monomial m2("7x8y3z7");
    ASSERT_ANY_THROW(m1 * m2);
}

TEST(MonomialTest, monomial_diff) {
    Monomial m1("2x2y3z4");
    Monomial m2("10x2y3z4");
    ASSERT_EQ((m1 - m2).toString(), "-8x2y3z4");
}

TEST(MonomialTest, non_addable_monomials) {
    Monomial m1("2x2y1z4");
    Monomial m2("10x2y3z4");
    ASSERT_ANY_THROW(m1 - m2);
}

TEST(MonomialTest, compare_monomials) {
    Monomial m1("2x2y1z4");
    Monomial m2("10x2y3");
    ASSERT_TRUE(m1 > m2);
    ASSERT_TRUE(m2 < m1);
}

TEST(MonomialTest, compare_monomials_eq_by_power) {
    Monomial m1("2x2y1z4");
    Monomial m2("10x2y1z4");
    ASSERT_TRUE(m1 == m2);
}

TEST(MonomialTest, monomial_with_whitespace) {
    Monomial m1("2 x2 y1 z4");
    Monomial m2("2x2y1z4");
    ASSERT_EQ(m1.toString(), m2.toString());
}


