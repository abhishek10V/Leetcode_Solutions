class Solution {
public:
    string fractionAddition(string exp) {
       int i = 0;
       int n = exp.length();
       int nume = 0;
       int deno = 1;

       while(i < n){
         int currNume = 0;
         int currDeno = 0;
         int flag = (exp[i] == '-');

         if(exp[i] == '+' || exp[i] == '-'){
            i++;
         }

         while(i < n && isdigit(exp[i])){
            int val = exp[i] - '0';
            currNume = (currNume * 10) + val;
            i++;
         }

         if(flag == true) currNume = -currNume;

         i++;

          while(i < n && isdigit(exp[i])){
            int val = exp[i] - '0';
            currDeno = (currDeno * 10) + val;
            i++;
         }

         nume = nume * currDeno + deno * currNume;
         deno = deno * currDeno;

       }
         int GCD = abs(__gcd(nume , deno));

         nume /= GCD;
         deno /= GCD;
         
         return to_string(nume) + "/" + to_string(deno);
    }
};