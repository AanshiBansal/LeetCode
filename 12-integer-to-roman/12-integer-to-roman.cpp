class Solution {
private:
    string digit(string one, string five, string ten, int mod){
        string ans="";
        switch(mod){
            case(1):{
                ans=one;
                break;
            }
            case(2):{
                ans=one+one;
                break;
            }
            case(3):{
                ans=one+one+one;
                break;
            }
            case(4):{
                ans=one+five;
                break;
            }
            case(5):{
                ans=five;
                break;
            }
            case(6):{
                ans=five+one;
                break;
            }
            case(7):{
                ans=five+one+one;
                break;
            }
            case(8):{
                ans=five+one+one+one;
                break;
            }
            case(9):{
                ans=one+ten;
                break;
            }
            default:
                break;
        }
        return ans;
    }
public:
    string intToRoman(int num) {
        if(num<1 || num>3999)
            return "";
        int thousandth=num/1000;
        int hundredth=(num%1000)/100;
        int tens=(num%100)/10;
        int ones=num%10;
        string ans="";
        ans+=digit("M","","",thousandth);
        ans+=digit("C","D","M",hundredth);
        ans+=digit("X","L","C",tens);
        ans+=digit("I","V","X",ones);
        return ans;
    }
};