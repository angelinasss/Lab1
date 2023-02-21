#pragma once
#include <iostream>

class Expression {
public:
	virtual double evaluate() = 0;
	virtual ~Expression() = default;
};

class Number : public Expression {
	double number;
public:
	Number(double numb) {
		number = numb;
	}
	double evaluate() override {
		return number;
	}
};

class  BinaryOperation : public Expression {
protected:
	Expression* left_operand;
	Expression* right_operand;
	char operation;
public:

	BinaryOperation(Expression* left_oper, char operate, Expression* right_oper) {
		left_operand = left_oper;
		right_operand = right_oper;
		operation = operate;
	}

	double evaluate() override {
		double left_new = left_operand->evaluate();
		double right_new = right_operand->evaluate();

		if (operation == '*')
			return left_new * right_new;
		else if (operation == '+')
			return left_new + right_new;
		else if (operation == '-')
			return left_new - right_new;
		else return left_new / right_new;
	}

	~BinaryOperation() override {
		delete left_operand;
		delete right_operand;
	}
};

bool check_equals(Expression const* left_operand, Expression const* right_operand) {
	bool result = (*((size_t*)left_operand) == *((size_t*)right_operand));
	return result;
} 