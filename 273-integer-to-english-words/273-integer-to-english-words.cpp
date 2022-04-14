class Solution {
private:
    vector<string>words={"Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    vector<string>tensWords={"","Ten ","Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    string fn(string value, int num){
        string ans="";
        int hundreds=num/100;
        int tens=(num%100)/10;
        int ones=num%10;
        if(hundreds>0){
            ans+=words[hundreds];
            ans+="Hundred ";
        }
        if(ones==0){
            ans+=tensWords[tens];
        }else{
            if(tens!=1){
                ans+=tensWords[tens]+words[ones];
            }else{
                ans+=words[10+ones];
            }
        }
        if(num>0)
            ans+=value;
        return ans;
    } 
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        int billions=num/1000000000;
        int millions=(num%1000000000)/1000000;
        int thousands=(num%1000000)/1000;
        int ones=num%1000;
        string ans="";
        ans+=fn("Billion ",billions);
        ans+=fn("Million ",millions);
        ans+=fn("Thousand ",thousands);
        ans+=fn("",ones);
        return ans.substr(0,ans.size()-1);
    }
};