class ATM {
private:
    vector<long long>atm;
    vector<int>mp;
public:
    ATM() {
        atm=vector<long long>(5,0);
        mp=vector<int>{20,50,100,200,500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++)
            atm[i]+=banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        int i=4;
        vector<long long>temp=atm;
        vector<int>ans(5,0);
        while(amount>0 && i>=0){
            if(temp[i]==0){
                i--;
                continue;
            }
            long long count=amount/mp[i];
            int curr=min(count,temp[i]);
            temp[i]-=curr;
            ans[i]=curr;
            amount-=(curr*mp[i]);
            i--;
        }
        if(amount>0)
            return {-1};
        atm=temp;
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */