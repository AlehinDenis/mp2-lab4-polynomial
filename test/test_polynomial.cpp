#include "polynomial.h"

#include <gtest.h>

TEST(Monom, monom_can_be_created_by_numbers)
{
	ASSERT_NO_THROW(Monom m(1.2, 1));
	Monom m(1.2, 1);
	EXPECT_EQ(1.2, m.getCoeff());
	EXPECT_EQ(1, m.getPower());
}

TEST(Monom, monom_can_be_created_by_strings)
{
	ASSERT_NO_THROW(Monom m("1.2", "1"));
	Monom m("1.2", "1");
	EXPECT_EQ(1.2, m.getCoeff());
	EXPECT_EQ(1, m.getPower());
}

TEST(Monom, monom_can_copy_itself)
{
	Monom m1(1.2, 1);
	ASSERT_NO_THROW(Monom m2(m1));
	Monom m2(m1);
	EXPECT_EQ(1.2, m2.getCoeff());
	EXPECT_EQ(1, m2.getPower());
}

TEST(Monom, monom_can_set_and_get)
{
	Monom m1(0,0);
	m1.setCoeff(1.2);
	m1.setPower(1);
	EXPECT_EQ(1.2, m1.getCoeff());
	EXPECT_EQ(1, m1.getPower());
}

TEST(Polynomial, polynom_can_be_created)
{
	ASSERT_NO_THROW(Polynomial p);
	Polynomial p;
	EXPECT_EQ(0, p.getSize());
}

TEST(Polynomial, polynom_can_be_copy)
{
	Polynomial p1;
	ASSERT_NO_THROW(Polynomial p2(p1));
	Polynomial p2(p1);
	EXPECT_EQ(0, p2.getSize());
}

TEST(Polynomial, polynom_can_be_read)
{
	Polynomial p;
	std::cin >> p;
	EXPECT_EQ(2, p.getSize());
}