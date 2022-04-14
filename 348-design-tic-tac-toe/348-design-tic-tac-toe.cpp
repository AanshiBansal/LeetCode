class TicTacToe {
private:
    vector<int>rows;
    vector<int>columns;
    int d1;
    int d2;
    int n;
public:
    TicTacToe(int n) {
        this->n=n;
        d1=0;
        d2=0;
        rows=vector<int>(n,0);
        columns=vector<int>(n,0);
    }
    
    int move(int row, int col, int player) {
        if(player==1){
            rows[row]++;
            columns[col]++;
            if(row==col)
                d1++;
            if(row+col==n-1)
                d2++;
        }else{
            rows[row]--;
            columns[col]--;
            if(row==col)
                d1--;
            if(row+col==n-1)
                d2--;
        }
        if(rows[row]==n || columns[col]==n || d1==n || d2==n)
            return 1;
        if(rows[row]==-n || columns[col]==-n || d1==-n || d2==-n)
            return 2;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */