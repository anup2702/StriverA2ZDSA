class Solution {
public:
    int romanToInt(string s) {
    int sum=0;
    int n=s.length();
    map<char,int>mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='I' && s[i+1]=='V' || s[i]=='I' && s[i+1]=='X' ){
            sum-=1;
        }
        else if(s[i]=='X' && s[i+1]=='L' || s[i]=='X' && s[i+1]=='C' ){
            sum-=10;
        }
        else if(s[i]=='C' && s[i+1]=='D' || s[i]=='C' && s[i+1]=='M' ){
            sum-=100;
        }
        else{
        sum+=mp[s[i]];
        }
    }
    return sum;
    }
};