/*****************************************************************************
File name: Back
Description: 回文字符串
Author: 熊康
Version: V1.0
Date: 2022.3.26
*****************************************************************************/
#include<iostream>
//#include<string>
#include<cstring>
//#include<deque>
//#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);

    int T;cin>>T;
    while(T--){
        int n;string s;cin>>n>>s;
        for(int i=0; i<n; i++){
            string pre,post;
            for(int j=i; j<n; j++) pre+=s[j];
            post=pre;
            reverse(post.begin(),post.end());
            if(pre==post){
                for(int k=0; k<i; k++) cout<<s[k];
                cout<<pre;
                for(int k=i-1; k>=0; k--) cout<<s[k];
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}