//2 pointer Approach
bool backspaceCompare(string S, string T) {
    int ptr1=0;
    int ptr2=0;
    for(int i=0;i<S.length();i++)
        if(S[i]=='#'){
            if(ptr1>0)
                ptr1--;
        }
        else
            S[ptr1++]=S[i];
    for(int i=0;i<T.length();i++)
        if(T[i]=='#'){
            if(ptr2>0)
                ptr2--;
        }
        else
            T[ptr2++]=T[i];
    if(ptr1!=ptr2)
        return false;
    for(int i=0;i<ptr1;i++)
        if(S[i]!=T[i])
            return false;
    return true;
}
