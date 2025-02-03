#include <bits/stdc++.h>

using namespace std;

double stringToDouble(const string& str) {
	double result = 0;
	int i = 0;
	while (i < str.length()) {
		if (isdigit(str[i])) {
			result = result * 10 + (str[i] - '0');
		} else {
			return 0;
		}
		i++;
	}
	return result;
}

class Stack {
private:
	static const int MAX_SIZE = 100;
	char data[MAX_SIZE];
	int top;

public:
	Stack() {
		top = -1;
	}
	bool isEmpty() {
		return (top == -1);
	}
	bool isFull() {
		return (top == MAX_SIZE - 1);
	}
	void push(char value) {
		if (isFull()) {
			cout << "Stack overflow!" << endl;
			return;
		}
		data[++top] = value;
	}
	char pop() {
		if (isEmpty()) {
			cout << "Stack underflow!" << endl;
			return '\0';
		}
		return data[top--];
	}
	
	char peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        return data[top];
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isRightAssociative(char op) {
    return (op == '^');
}

void infixToPostfix(const char* infix, char* postfix) {
	Stack s;
	int postfixIndex = 0;
	string numBuffer;
	for (int i = 0; infix[i] != '\0'; i++) {
		char c = infix[i];
		if (isdigit(c)) {
			numBuffer += c;
		} else {
			if (!numBuffer.empty()) {
				if (postfixIndex > 0) postfix[postfixIndex++] = ',';
				for (char numChar : numBuffer) {
					postfix[postfixIndex++] = numChar;
				}
				numBuffer.clear();
			}
			if (c == '(') {
				s.push(c);
			} else if (c == ')') {
				while (!s.isEmpty() && s.peek() != '(') {
					postfix[postfixIndex++] = ',';
					postfix[postfixIndex++] = s.pop();
				}
				if (!s.isEmpty() && s.peek() == '(') {
					s.pop();
				}
			} else if (isOperator(c)) {
				while (!s.isEmpty() && ((getPrecedence(c) < getPrecedence(s.peek())) ||
				                        (getPrecedence(c) == getPrecedence(s.peek()) && !isRightAssociative(c)))) {
					postfix[postfixIndex++] = ',';
					postfix[postfixIndex++] = s.pop();
				}
				s.push(c);
			}
		}
	}
	if (!numBuffer.empty()) {
		if (postfixIndex > 0) postfix[postfixIndex++] = ',';
		for (char numChar : numBuffer) {
			postfix[postfixIndex++] = numChar;
		}
	}
	while (!s.isEmpty()) {
		postfix[postfixIndex++] = ',';
		postfix[postfixIndex++] = s.pop();
	}
	postfix[postfixIndex] = '\0';
}

double evaluatePostfix(string exp) {
	stack<double> st;
	string val;
	for (int i = 0; i < exp.length(); i++) {
		if (isdigit(exp[i]) || exp[i] == '.') {
			val += exp[i];
		} else if (exp[i] == ',') {
			if (!val.empty()) {
				st.push(stod(val));
				val.clear();
			}
		} else if (isOperator(exp[i])) {
			if (!val.empty()) {
				st.push(stod(val));
				val.clear();
			}
			double val1 = st.top();
			st.pop();
			double val2 = st.top();
			st.pop();
			switch (exp[i]) {
			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val2 - val1);
				break;
			case '*':
				st.push(val2 * val1);
				break;
			case '/':
				st.push(val2 / val1);
				break;
			case '^':
				st.push(pow(val2, val1));
				break;
			}
		}
	}
	return st.top();
}


int main()
{
	const int MAX_SIZE = 100;
	char infixExpression[MAX_SIZE];
	char postfixExpression[MAX_SIZE];
	cout << "Enter an infix expression: ";
	cin.getline(infixExpression, MAX_SIZE);
	infixToPostfix(infixExpression, postfixExpression);
	cout << "Postfix expression: " << postfixExpression << endl;
	double ans = evaluatePostfix(postfixExpression);
	cout << "Postfix expression eval result: " << ans << endl;
	return 0;
}
