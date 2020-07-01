vector<string>split(string IP, char separator){
    vector<string>ans;
    string help="";
    for(int i=0;i<IP.size();i++){
        if(IP[i]==separator){
            ans.push_back(help);
            help="";
        }
        else
            help+=IP[i];
    }
    ans.push_back(help);
    return ans;
}

bool IPv4(string IP){
    vector<string>group=split(IP,'.');
    if(group.size()!=4)
        return false;
    for(int i=0;i<4;i++){
        if(group[i].length()<1 || group[i].length()>3)
            return false;
        int val=0;
        for(int j=0;j<group[i].length();j++){
            if(group[i][j]>='0'&&group[i][j]<='9'){
                val*=10;
                val+=group[i][j]-'0';
            }
            else
                return false;
        }
        if(group[i].length()==2){
            if(val>=10 && val<=99);
            else
                return false;
        }
        if(group[i].length()==3){
            if(val>=100 && val<=255);
            else
                return false;
        }
    }
    return true;
}

bool IPv6(string IP){
    vector<string>group=split(IP,':');
    if(group.size()!=8)
        return false;
    for(int i=0;i<8;i++){
        if(group[i].length()<1 || group[i].length()>4)
            return false;
        for(int j=0;j<group[i].length();j++){
            if((group[i][j]>='0'&&group[i][j]<='9')||(group[i][j]>='a'&&group[i][j]<='f')
               ||(group[i][j]>='A'&&group[i][j]<='F'));
            else
                return false;
        }
    }
    return true;
}

string validIPAddress(string IP) {
    if(IPv4(IP))
        return "IPv4";
    if(IPv6(IP))
        return "IPv6";
    return "Neither";
}
