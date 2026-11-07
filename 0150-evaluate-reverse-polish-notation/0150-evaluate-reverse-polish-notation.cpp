class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>operand;
        for(string &exp: tokens){
            if(exp=="+" || exp=="-" || exp=="*" || exp=="/"){
                int operand1 = operand.top(); operand.pop();
                int operand2 = operand.top(); operand.pop();
                if(exp=="+") operand.push(operand2+operand1);
                else if(exp=="-") operand.push(operand2-operand1);
                else if(exp=="*") operand.push(operand2*operand1);
                else operand.push(operand2/operand1);
            }
            else{
                operand.push(stoi(exp));
            }
        }
        return operand.top();    
    }
};