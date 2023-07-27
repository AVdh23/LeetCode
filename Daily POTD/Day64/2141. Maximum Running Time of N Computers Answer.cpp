class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) { 
        sort(b.begin(),b.end());
        long long count = b[b.size()-n];
        long long extra = accumulate(b.begin(),b.begin()+b.size()-n,0ll);
        vector<long long> diff;
        for(int i = b.size()-n; i<b.size()-1; i++){
            diff.push_back(((long long)(i-b.size()+n+1))*(b[i+1]-b[i]));
        }
        int index = 0;
        while(extra>0&&index<diff.size()){
            extra-=diff[index++];
            if(extra>=0)count=b[index+b.size()-n];
            else{ count+=(extra+diff[index-1])/(index);}
        }
        if(extra>0){
            count=extra/n+b.back();
        }
        return count;
    }
};