#include <iostream>
#include <stack>
#include <string>

using namespace std;



bool IsOperator(char C){
    if(C=='+' || C=='-' || C=='*' || C=='/'){
        return true;
    }
    return false;
}



bool IsNumber(char C){
    if(C>='0' && C<='9'){
        return true;
    }
    return false;
}



int GetOperatorWeight(char op){
    int weight = -1;
    
    switch(op) {
        
        case '+':
        case '-':
            weight = 1;
            break;
            
        case '*':
        case '/':
            weight = 2;
            break;
    }
    
    return weight;
}



bool HasHigherPrecedence(char op1, char op2){
    int op1weight = GetOperatorWeight(op1);
    int op2weight = GetOperatorWeight(op2);
    
    return op1weight >= op2weight ? true : false;
}



int PerformOperation(char operation, int op1, int op2){
    if(operation == '+'){
        return op1 + op2;
    }
    else if(operation == '-'){
        return op1 - op2;
    }
    else if(operation == '*'){
        return op1 * op2;
    }
    else if(operation == '/'){
        return op1 / op2;
    }
    else{
        
        return -1;
    }
}



int EvaluateInfix(string exp){
    stack<char> operator_stack;
    stack<int> number_stack;
    
    for(int i=0 ; i<exp.length() ; i++){
        
        if(exp[i] == ' ' || exp[i] == ','){
            continue;
        }
        
        
        else if (IsNumber(exp[i])){
            int operand;
            operand = exp[i] - '0';
            number_stack.push(operand);
        }
        
        
        else if(exp[i] == '('){
            operator_stack.push(exp[i]);
        }
        
        
        else if (IsOperator(exp[i])){
            
            while(!operator_stack.empty() && operator_stack.top() != '(' && HasHigherPrecedence(operator_stack.top(), exp[i])  ){
                int op2 = number_stack.top();
                number_stack.pop();
                
                int op1 = number_stack.top();
                number_stack.pop();
                    
                char operation = operator_stack.top();
                operator_stack.pop();
                
                int result = PerformOperation(operation, op1, op2);
                    
                number_stack.push(result);
                
                }
                
            operator_stack.push(exp[i]);
            }
            
        
        
        
        else if (exp[i] == ')'){
            while(!operator_stack.empty() && operator_stack.top() != '('){
                
                int op2 = number_stack.top();
                number_stack.pop();
                
                int op1 = number_stack.top();
                number_stack.pop();
                
                char operation = operator_stack.top();
                operator_stack.pop();
                
                int result = PerformOperation(operation, op1, op2);
                number_stack.push(result);
                
            }
            operator_stack.pop();
        }
    }
    
    
    //sometimes even after the evaluation of entire expression, operator stack is not empty
    while(!operator_stack.empty()){
        int op2 = number_stack.top();
        number_stack.pop();
                
        int op1 = number_stack.top();
        number_stack.pop();
                
        char operation = operator_stack.top();
        operator_stack.pop();
                
        int result = PerformOperation(operation, op1, op2);
        number_stack.push(result);
    }
    
    return number_stack.top();
}



int main(){
    string exp;
    cout << "Enter infix expression to evaluate: \n";
    getline(cin, exp);
    int ans = EvaluateInfix(exp);
    cout << "Output: " << ans;
}


//for explanation watch youtube vdo by Pepcoding
