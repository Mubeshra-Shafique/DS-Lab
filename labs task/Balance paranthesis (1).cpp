#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(string &expression) {
        stack<char>stack; //declare the data type in stack to store character
    for (char c:expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } 
		else if (c == ')' || c == ']' || c == '}') {
       if (stack.empty()) {
                return false;  // Unbalanced: No matching opening parenthesis.
            }
    
      char top = stack.top();
           stack.pop();   //compare with current closing paranthesis

//       if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
//                return false;  // Unbalanced: Mismatched parentheses.
//            }
        }
    }

    return stack.empty();  // If the stack is empty at the end, it's balanced.
}

int main() {
    string exp;
    cout << "Enter an expression with parentheses: ";
    cin >> exp;
    if (isBalanced(exp)) {
    cout << "Balanced parentheses!" <<endl;
    } 
	else {
    cout << "Unbalanced parentheses!" <<endl;
    }

    return 0;
}