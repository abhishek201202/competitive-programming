// give all the starting occurance
// of string t in string s

vector<int> RabinKarp(string s, string t){
    if(s.size() < t.size()) return {};
    int n = s.size(), m = t.size();
    const int p = 163;
    const int mod = 99999998743;

    int hashS = 0, hashT = 0, powP = 1;
    for(int i = m - 1; i >= 0; i--){
        hashT = (hashT + ((t[i] - 'a') * powP)%mod)%mod;
        hashS = (hashS + ((s[i] - 'a') * powP)%mod)%mod;
        powP = (powP * p)%mod;
    }

    vector<int> res;
    if(hashS == hashT) res.push_back(0);
    for(int i = m; i < n; i++){
        hashS = (hashS * p)%mod;
        hashS = (hashS + (s[i] - 'a') - ((s[i - m] - 'a')*powP)%mod + mod)%mod;
        if(hashS == hashT){
            res.push_back(i - m + 1);
        }
    }
    return res;
}