#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE("Factorials are computed", "[factorial]") // tag
{
    CHECK(Factorial(0) == 1); // assertion
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}
TEST_CASE("incrementing values in integer vector", "[addN]")
{
    std::vector<int> v{1, 2, 3, 5, 6, 7, 8, 10};
    SECTION("checking with +ve n")
    {
        int n = 5;
        std::vector<int> res = AddN(v, n);
        srand(time(NULL));
        int random = rand() % v.size();
        REQUIRE(v.size() == res.size());
        REQUIRE(res[0] == 6);
        REQUIRE(res[v.size() - 1] == 15);
        REQUIRE(res[random] == v[random] + n);
    }
    SECTION("checking with -ve n")
    {
        int n = -5;
        std::vector<int> res = AddN(v, n);
        srand(time(NULL));
        int random = rand() % v.size();
        REQUIRE(v.size() == res.size());
        REQUIRE(res[0] == -4);
        REQUIRE(res[v.size() - 1] == 5);
        REQUIRE(res[random] == v[random] + n);
    }
}

// Impl for Sign testing...
TEST_CASE("Sign returns -1 for negative and 1 otherwise", "[sign]")
{
    REQUIRE(Sign(-100.0) == -1.0);
    REQUIRE(Sign(-0.5) == -1.0);
    REQUIRE(Sign(0.0) == 1.0);
    REQUIRE(Sign(1.0) == 1.0);
    REQUIRE(Sign(42.0) == 1.0);
}

TEST_CASE("Split breaks strings on a separator", "[split]")
{
    SECTION("multiple parts")
    {
        std::vector<std::string> expected{"a", "b", "c"};
        REQUIRE(Split("a,b,c", ",") == expected);
    }
    SECTION("no separator in string")
    {
        std::vector<std::string> expected{"hello"};
        REQUIRE(Split("hello", ",") == expected);
    }
    SECTION("empty separator")
    {
        std::vector<std::string> expected{"whole"};
        REQUIRE(Split("whole", "") == expected);
    }
}

TEST_CASE("Join combines strings with glue", "[join]")
{
    SECTION("empty vector")
    {
        REQUIRE(Join(std::vector<std::string>{}, ",") == "");
    }
    SECTION("single piece")
    {
        REQUIRE(Join(std::vector<std::string>{"only"}, ",") == "only");
    }
    SECTION("multiple pieces")
    {
        std::vector<std::string> pieces{"a", "b", "c"};
        REQUIRE(Join(pieces, ", ") == "a, b, c");
    }
}

TEST_CASE("NthFibonacci returns 1-based sequence values", "[fibonacci]")
{
    REQUIRE(NthFibonacci(1) == 1);
    REQUIRE(NthFibonacci(2) == 1);
    REQUIRE(NthFibonacci(3) == 2);
    REQUIRE(NthFibonacci(6) == 8);
    REQUIRE(NthFibonacci(7) == 13);
}

TEST_CASE("Multiples builds n*1 through n*m", "[multiples]")
{
    SECTION("positive count")
    {
        std::vector<int> expected{2, 4, 6};
        REQUIRE(Multiples(2, 3) == expected);
        REQUIRE(Multiples(2, 3).size() == 3);
    }
    SECTION("zero count")
    {
        REQUIRE(Multiples(5, 0).empty());
    }
}

TEST_CASE("Sum adds all doubles in a vector", "[sum]")
{
    REQUIRE(Sum(std::vector<double>{}) == 0.0);
    REQUIRE(Sum(std::vector<double>{1.5, 2.5, 3.0}) == 7.0);
    REQUIRE(Sum(std::vector<double>{-1.0, 1.0}) == 0.0);
}

TEST_CASE("Product multiplies all doubles in a vector", "[product]")
{
    REQUIRE(Product(std::vector<double>{}) == 1.0);
    REQUIRE(Product(std::vector<double>{2.0, 3.0, 4.0}) == 24.0);
    REQUIRE(Product(std::vector<double>{-2.0, 3.0}) == -6.0);
}
