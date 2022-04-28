// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
long long int closestPalindrome(long long int num){
    long long digits = 0, n1 = num;
    while(n1) {
        digits++;
        n1 /= 10;
    }
    if(digits == 1) return num;
    vector<long long> candidates;
    candidates.push_back(pow(10, digits-1)-1);
    candidates.push_back(pow(10, digits)+1);
    long long mid = (digits+1)/2;
    long long prefix = num / pow(10, digits-mid);
    vector<long long> v = {prefix, prefix-1, prefix+1};
    for(long long i:v) {
        string postfix = to_string(i);
        if(digits%2 != 0) postfix.pop_back();
        reverse(postfix.begin(),postfix.end());
        string c=to_string(i)+postfix;
        candidates.push_back(stol(c));
    }
    long long minDiff = LLONG_MAX, res;
    for(long long c:candidates) {
        if(abs(c-num) < minDiff) {
            minDiff = abs(c-num);
            res = c;
        } else if(abs(c-num) == minDiff) {
            res = min(res, c);
        }
    }
    return res;
}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends