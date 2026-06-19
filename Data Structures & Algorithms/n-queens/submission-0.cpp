class Solution {
public:
    bool recur(vector<bool>&hor,vector<bool>&tlbr,vector<bool>&trbl,int i,vector<vector<char>>&board,vector<vector<string>>&ans){
        // for(auto i:board){
        //     for(auto j:i){
        //         cout<<j<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        if(hor.size()==i){
            vector<string>a;
            for(int idx=0;idx<hor.size();idx++){
                string s="";
                for(int jdx=0;jdx<hor.size();jdx++){
                    s+=board[idx][jdx];
                }
                a.push_back(s);
            }
            ans.push_back(a);
            return true;
        }
        for(int j=0;j<hor.size();j++){
            // cout<<i<<' '<<j<<' '<<hor[j]<<' '<<tlbr[i+j]<<' '<<trbl[i-j+((int)hor.size()-1)]<<endl;;
            if(!hor[j] && !tlbr[i+j] && !trbl[i-j+((int)hor.size()-1)]){
                // cout<<"yo"<<endl;
                board[i][j]='Q';
                hor[j]=true;
                tlbr[i+j]=true;
                trbl[i-j+((int)hor.size()-1)]=true;
                recur(hor,tlbr,trbl,i+1,board,ans);
                board[i][j]='.';
                hor[j]=false;
                tlbr[i+j]=false;
                trbl[i-j+((int)hor.size()-1)]=false;
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==1){
            return {{"Q"}};
        }
        vector<bool>hor(n,false),tlbr(2*n-2,false),trbl(2*n-2,false);
        vector<vector<char>>board(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        recur(hor,tlbr,trbl,0,board,ans);
        return ans;
    }
};
