// not yet tested
struct PT{
    int a, y;
};
bool CCW(PT a , PT b , PT c) { 
    return (c.x-b.x)*(b.y-a.y)<(c.y-b.y)*(b.x-a.x); 
}
bool IsCollinear(PT a , PT b , PT c){ 
    return (c.x-b.x)*(b.y-a.y)==(c.y-b.y)*(b.x-a.x); 
}
vector<PT> GrahamScan(vector<PT> &P) {
    PT p0 = *min_element(P.begin(), P.end(), [&](PT &a, PT &b) {
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });
    sort(P.begin(), P.end(), [&](PT &a, PT &b){
        if(IsCollinear(p0, a, b)){
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        }
        return CCW(p0, a, b);
    });
    vector<PT> res;
    for (int i = 0; i < P.size(); i++) {
        while(res.size() > 1 && !CCW(res[res.size()-2], res.back(), P[i]))
            res.pop_back();
        res.push_back(P[i]);
    }
    return res;
}