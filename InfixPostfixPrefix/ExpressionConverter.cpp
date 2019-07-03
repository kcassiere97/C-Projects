 #include "ExpressionConverter.h"
// Write all your functions here

string Infix2RPN(string infix){


istringstream infix_stream;
infix_stream.str(infix);

stack <char> opstack; //keep operator
string output = "";  //list for output
string token;

map<char,int> prec;
prec['*'] = 3;
prec['/'] = 3;
prec['+'] = 2;
prec['-'] = 2;
prec['('] = 1;

//tokenlist
while(infix_stream >> token)
{

  for(int i = 0; i < token.length(); i++){

   if(isdigit(token[i])){

            
   output+=(token[i]);

  }
  else if(token[i] == '('){
      opstack.push(token[i]);

    } else if(token[i] == ')'){


       while(opstack.top() != '('){

            output += (opstack.top());
            opstack.pop();

       }
       opstack.pop();
    } else{
        while(!opstack.empty() && (prec[opstack.top()] >= prec[token[i]])){

          output += (opstack.top());

        }
          opstack.push(token[i]);
    }
}
if(output[output.length()-1] != ' '){

    output+= " ";

}
}
while(!opstack.empty()){
   output += (opstack.top());
    opstack.pop();
  }

return output;
}

///////////////////////////////////////////////////////////////

string RPN2Infix(string rpn){

string infix_;

ArithNode * ptr = RPN2ExpressionTree(rpn);

infix_ = RPN2InfixHelper(ptr);

return infix_;

}

 string RPN2InfixHelper(ArithNode * helpIN){

   if(helpIN -> left == NULL && helpIN -> right == NULL){

     return to_string(helpIN -> operand);
   } else{

     return "( " + RPN2InfixHelper(helpIN -> left) + " "+ helpIN -> binaryOperator + " " + RPN2InfixHelper( helpIN -> right) + " )";

   }
}


////////////////////////////////////////
ArithNode *Infix2ExpressionTree(string infix){

  string rpn_input = Infix2RPN(infix);
  return RPN2ExpressionTree(rpn_input);

}
////////////////////////////////////////
ArithNode *RPN2ExpressionTree(string rpn){

stack <ArithNode*> mystack; //store pointers into the stack
stringstream expression_input;
expression_input.str(rpn);
string tree_;
ArithNode* last;


while(expression_input >> tree_){

          if(tree_[0] == '+'|| tree_ [0]== '-' || tree_[0] == '/' ||tree_[0] == '*'){

            for(int i = 0; i < tree_.length(); i++){

              ArithNode* node = new ArithNode(tree_[i]);
              node -> right = mystack.top();
              mystack.pop();
              node -> left = mystack.top();
              mystack.pop();
              mystack.push(node);
            }
            continue;
          }


            mystack.push(new ArithNode(stoi(tree_)));

}
return mystack.top();
}

////////////////////////////////////////
int EvaluateInfix(string infix){

  string rpn_input = Infix2RPN(infix);
  return EvaluateRPN(rpn_input);

}

///////////////////////////////////////

int EvaluateRPN(string rpn){

stack <int> operandStack;
stringstream solveRPN;
solveRPN.str(rpn);
string token;
int solvedRPN;


while(solveRPN >> token){

     if ((token[0] == '+') || (token [0]== '-') || (token[0] == '*') || (token[0] == '/')) {
          // pop two numbers off the stack
          for (int i = 0; i <token.length(); i ++){

          int a = operandStack.top();
          operandStack.pop();
          int b = operandStack.top();
          operandStack.pop();
          // evaluate result
          switch (token[i]) {
          case '+': solvedRPN = b + a ; break;

          case '-': solvedRPN = b - a ; break;

           case '*': solvedRPN = b * a; break;

           case '/': solvedRPN = b / a; break;

          }
          operandStack.push(solvedRPN);
                //push the answers to the stack
        }


      } else {
         operandStack.push(stoi(token));
      }

 }
 return operandStack.top();
}
