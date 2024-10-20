class Solution {
public:
    bool parseBoolExpr(string e) {
        stack<char> exp;
        stack<char> opr;

        for(auto & c : e){
            if(c == '|' || c == '&' || c == '!') opr.push(c);
            else if(c == ',') continue;
            else if(c == ')'){
                char res = exp.top();
                exp.pop();
                if(exp.top() == '('){
                    res = evaluate(res , opr.top(), ' ');
                }else{
                while(exp.top() != '('){
                    res = evaluate(exp.top(), opr.top() , res);
                    exp.pop();
                }
                }
               
                exp.pop();
                exp.push(res);
                opr.pop();
            }else{
                exp.push(c);
            }
        }
      return exp.top() == 't' ? true : false;
    }
    char evaluate(char e1 , char op, char e2){
        if(e2 == ' '){
           if(op == '&' || op == '|') return e1;
           else if(op == '!'){
              if(e1 == 't') return 'f';
              else return 't';
           }
        }else{
        if(e1 == 't' && op == '|') return 't';
        else if(e1 == 'f' && op == '&') return 'f';
        else if(e1 == 't' && op == '&' && e2 == 'f') return 'f';
        else if(e1 == 't' && op == '&' && e2 == 't') return 't';
        else if(e1 == 'f' && op == '|' && e2 == 'f') return 'f';
        else if(e1 == 'f' && op == '|' && e2 == 't') return 't';
    }
    return 't';
    }
};