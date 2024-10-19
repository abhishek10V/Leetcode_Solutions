class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        if(k == 1) return '0';
        n--;
        while(n-- > 0){
            string inv = inverse(s);
           
            s = s + "1" + reverseString(inv);
            
        }
        return s[k-1];
    }
    string reverseString(string & s){
        int l = 0 , r = s.length() - 1;
        while(l < r){
            char t = s[l];
            s[l] = s[r];
            s[r] = t;

            l++, r--;
        }
        return s;
    }
    string inverse(string & s){
        string inv = s;
        for(int i=0 ; i<inv.length(); i++){
            if(inv[i] == '0') inv[i] = '1';
            else inv[i] = '0';
        }
        return inv;
    }
};