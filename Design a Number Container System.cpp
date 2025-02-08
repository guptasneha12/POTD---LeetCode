class NumberContainers {
public:
unordered_map<int,int> mp;
unordered_map<int,set<int>> mpp;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // if number is already present then update its index
        if(mp.find(index)!=mp.end() && mp[index]!=number){
            // update the index
            mpp[mp[index]].erase(index);
            if(mpp[mp[index]].empty()) mpp.erase(mp[index]);
        }
        mp[index]=number;
        mpp[number].insert(index);

    }
    
    int find(int number) {
        return mpp[number].empty()?-1:*mpp[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */