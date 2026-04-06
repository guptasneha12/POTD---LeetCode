class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st; // to store obstacles
        for(vector<int> &obs: obstacles){
            string str=to_string(obs[0])+"_"+to_string(obs[1]);
            st.insert(str);
        }
        int x=0;
        int y=0;
        int maxi=0;  // max distance
        pair<int,int> dir={0,1};
        for(int i=0;i<commands.size();i++){
            // left 90 degree
            if(commands[i]==-2){
                dir={-dir.second,dir.first};
            }
            // right 90 degree
            else if(commands[i]==-1){
                dir={dir.second,-dir.first};
            }
            // move each step forward
            else{
                for(int steps=0;steps<commands[i];steps++){
                    int newx=x+dir.first;
                    int newy=y+dir.second;
                    string newstring = to_string(newx)+"_"+to_string(newy);
                    // check if it obstacle or not by checking it in set present or not
                    if(st.find(newstring)!=st.end()){
                        break;
                    }
                    x=newx;
                    y=newy;
                }
            }
            maxi=max(maxi,x*x+y*y);
        }
        return maxi;
    }
};