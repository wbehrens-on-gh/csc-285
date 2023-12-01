/*
D$ && The Cents - Project 3
problem #4

*Must put in postfix expression with spaces between
*ex. 3 4 * 5 6 * +

Arth Patel
*/
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
//function to evaluate a pstfix expression
int evaluatePostfix(const std::string &expression) {

    std::stack<int> stack;//hold

    std::istringstream iss(expression);//parse

    std::string token;//hold token
    //loop through each token
    while (iss >> token) {

        if (isdigit(token[0])) {

            stack.push(std::stoi(token));
        //if token is operator
        } else {

            int val2 = stack.top();//get 2nd operand from stack
            stack.pop();

            int val1 = stack.top();

            stack.pop();//rm first operand

            switch (token[0]) {

                case '+': stack.push(val1 + val2); break;

                case '-': stack.push(val1 - val2); break;

                case '*': stack.push(val1 * val2); break;
                // no division by 0
                case '/': stack.push(val1 / val2); break;

            }

        }

    }

    return stack.top();

}

int main() {

    std::string expression;

    std::cout << "Enter a postfix expression: ";

    getline(std::cin, expression);

    int result = evaluatePostfix(expression);

    std::cout << "The value of the expression is: " << result << std::endl;

    return 0;

}
