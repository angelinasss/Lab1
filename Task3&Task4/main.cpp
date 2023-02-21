#include <iostream>
#include "Header.h"

int main() {
	Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression* expr = new BinaryOperation(new Number(3), '+', sube);
	bool result = check_equals(expr, new Number(5));
	std::cout << expr->evaluate() << "\n" << result << "\n";
	delete expr;
}