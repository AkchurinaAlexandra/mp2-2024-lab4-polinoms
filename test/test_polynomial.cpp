#include <gtest.h>
#include "Polynomial.h"

TEST(PolynomialTest, default_polynomial) {
    Polynomial p;
    ASSERT_EQ(p.toString(), "0");
}

TEST(PolynomialTest, can_parse_zero) {
    Polynomial p("0");
    ASSERT_EQ(p.toString(), "0");
}

TEST(PolynomialTest, only_signs_bad_polynomial) {
    ASSERT_ANY_THROW(Polynomial("--"));
}

TEST(PolynomialTest, cannot_parse_invalid_monomials) {
    ASSERT_ANY_THROW(Polynomial("x1y2z3 + p"));
}

TEST(PolynomialTest, cannot_parse_with_power_more_than_9) {
    ASSERT_ANY_THROW(Polynomial("x1y2z3 + x10"));
}

TEST(PolynomialTest, single_monomial) {
    Polynomial p("2x2y3z1");
    ASSERT_EQ(p.toString(), "2x2y3z");
}

TEST(PolynomialTest, simple_polynomial) {
    Polynomial p("2x2y3z2 + 10x2y3z2");
    ASSERT_EQ(p.toString(), "12x2y3z2");
}

TEST(PolynomialTest, polynomial_sort) {
    Polynomial p("1 + y + x + z + xy + xz + yz + xyz");
    ASSERT_EQ(p.toString(), "xyz + xy + xz + yz + x + y + z + 1");
}

TEST(PolynomialTest, multiple_minus) {
    Polynomial p("1 - 2 - - 2x");
    ASSERT_EQ(p.toString(), "2x - 1");
}

TEST(PolynomialTest, polynomial_sum) {
    Polynomial p1("2x2y3z1");
    Polynomial p2("10x2y3z1");
    ASSERT_EQ((p1 + p2).toString(), "12x2y3z");
}

TEST(PolynomialTest, polynomial_mul_by_coeff) {
    Polynomial p("2x2y3z1 + 3x2y3z2");
    ASSERT_EQ((p * 3.5).toString(), "10.5x2y3z2 + 7x2y3z");
}

TEST(PolynomialTest, same_polynomial_diff) {
    Polynomial p("2x2y3z1 + 3x2y3z2 + 2 - - xyz");
    ASSERT_EQ((p - p).toString(), "0");
}

TEST(PolynomialTest, remove_zeros_test) {
    Polynomial p("xyz + 0 + 0xyz + 0x2 y - 0");
    ASSERT_EQ(p.toString(), "xyz");
}

TEST(PolynomialTest, inverse_polynomials_sum) {
    Polynomial p1("2x2y3z1 + 3x2y3z2 + 2 - - xyz");
    Polynomial p2("-2x2y3z1 - 3x2y3z2 - 2 - xyz");
    ASSERT_EQ((p1 + p2).toString(), "0");
}

TEST(PolynomialTest, polynomial_mul) {
    Polynomial p1("2x2y3z1 + 3x2y3z1");
    Polynomial p2("7x3y3z7 + 3x2y3z1");
    ASSERT_EQ((p1 * p2).toString(), "35x5y6z8 + 15x4y6z2");
}

TEST(PolynomialTest, polynomial_complex_mul) {
    Polynomial p1("2x2y3z1 + 3x2y3z1 - 2");
    Polynomial p2("7x3y3z7 + 3x2y3z1");

    ASSERT_EQ((p1 * p2).toString(), "35x5y6z8 + 15x4y6z2 - 14x3y3z7 - 6x2y3z");
}

TEST(PolynomialTest, polynomial_complex_mul_with_spaces) {
    Polynomial p1("2 x2 y3 z1 + 3x2y3z1 - 2");
    Polynomial p2("7 x3 y3 z7 + 3x2 y2 y z1");

    ASSERT_EQ((p1 * p2).toString(), "35x5y6z8 + 15x4y6z2 - 14x3y3z7 - 6x2y3z");
}

TEST(PolynomialTest, polynomial_complex_mul_with_spaces_and_minus) {
    Polynomial p1("2 x2 y3 z1 + 3x2y3z1 - 2");
    Polynomial p2("7 x3 y3 z7 + 3x2 y2 y z1 - 2");

    ASSERT_EQ((p1 * p2).toString(), "35x5y6z8 + 15x4y6z2 - 14x3y3z7 - 16x2y3z + 4");
}

TEST(PolynomialTest, cannot_multiply_with_overflow) {
    Polynomial p1("x5y1z3 - z3 + x5");
    Polynomial p2("x5 - z3");
    ASSERT_ANY_THROW(p1 * p2);
}