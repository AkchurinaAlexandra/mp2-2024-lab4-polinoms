//
// TODO

#include <iostream>
#include <string>
#include "Polynomial.h"

int main() {
    std::cout << "Input format:\n"
                 "1. Each monomial is a string of the form: KxAyBzC:\n"
                 "\t K - coefficient (double)\n"
                 "\t A, B, C - power of each variable (non-negative integers)\n"
                 "2. Monomials are separated by '+' or '-'\n"
                 "3. Spaces in monomials are not allowed\n"
                 "4. Maximal power of each variable is 9\n"
                 "5. Resulting polynomial cannot have power of a variable more than 9\n"
                 "6. Example of a polynomial: 2x3y4z1 + 3x2y3z4 - 4x3y4z5\n\n";
    while (true) {
        try {
            std::cout << "Choose an operation\n"
                         "\t1. Add two polynomials\n"
                         "\t2. Subtract two polynomials\n"
                         "\t3. Multiply two polynomials\n"
                         "\t4. Multiply a polynomial by a number\n";
            int choice;
            std::cin >> choice;
            std::string s1, s2;
            std::cout << "Enter the first polynomial:\n";
            std::cin.ignore();
            std::getline(std::cin, s1);
            Polynomial p1(s1);
            std::cout << "Enter the second polynomial:\n";
            std::getline(std::cin, s2);
            Polynomial p2(s2);
            Polynomial result;
            switch (choice) {
                case 1:
                    result = p1 + p2;
                    break;
                case 2:
                    result = p1 - p2;
                    break;
                case 3:
                    result = p1 * p2;
                    break;
                case 4:
                    double s;
                    std::cout << "Enter the number:\n";
                    std::cin >> s;
                    result = s * p1;
                    break;
                default:
                    std::cerr << "Invalid choice of an operation.\n";
                    continue;
            }
            std::cout << "result = " << result.toString() << std::endl;
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}