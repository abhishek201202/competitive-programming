/*
https://www.youtube.com/watch?v=IkLJVm_9k9k
https://leetcode.com/problems/erect-the-fence-ii/?envType=problem-list-v2&envId=xr7lznxj
*/

#include<bits/stdc++.h>
using namespace std;

bool isInside(vector<double> disk, vector<int> p) {
    // (x - h)^2 + (y - k)^2 - r^2 <= 0
    double insideVal = (p[0] - disk[0]) * (p[0] - disk[0]) + (p[1] - disk[1]) * (p[1] - disk[1]) - disk[2] * disk[2];
    return insideVal <= 1e-5;
}

vector<double> getCentre(long x1, long y1, long x2, long y2) {
    double h = y2 * (x1 * x1 + y1 * y1) - y1 * (x2 * x2 + y2 * y2);
    h /= 2.0 * (x1 * y2 - x2 * y1);

    double k = x2 * (x1 * x1 + y1 * y1) - x1 * (x2 * x2 + y2 * y2);
    k /= 2.0 * (x2 * y1 - x1 * y2);

    return vector<double>{(double)h, (double)k};
}

vector<double> getDiskFrom3Pts(vector<int> p1, vector<int> p2, vector<int> p3) {
    vector<double> centre = getCentre(p2[0] - p1[0], p2[1] - p1[1], p3[0] - p1[0], p3[1] - p1[1]);
    centre[0] += p1[0];
    centre[1] += p1[1];
    double r= sqrt(pow(centre[0] - p1[0], 2) + pow(centre[1] - p1[1], 2));
    return vector<double>{centre[0], centre[1], r};
}

vector<double> getDiskFrom2Pts(vector<int> p1, vector<int> p2) {
    double h = (p1[0] + p2[0]) / 2.0;
    double k = (p1[1] + p2[1]) / 2.0;
    double r = sqrt(pow(p1[0] - h, 2) + pow(p1[1] - k, 2));
    return vector<double>{h, k, r};
} 

vector<double> getDisk(vector<vector<int>> a) {
    if(a.size() == 0) return vector<double>{0.0, 0.0, 0.0};
    else if(a.size() == 1) return vector<double>{a[0][0]*1.0, a[0][1]*1.0, 0.0};
    else if(a.size() == 2) return getDiskFrom2Pts(a[0], a[1]);
    else return getDiskFrom3Pts(a[0], a[1], a[2]);
}

vector<double> welzl(vector<vector<int>> &pts, vector<vector<int>> onEdge, int idx) {
    if(idx == pts.size() || onEdge.size() == 3) {
        return getDisk(onEdge);
    }

    random_shuffle(pts.begin() + idx + 1, pts.end());
    vector<double> disk = welzl(pts, onEdge, idx + 1);
    if(isInside(disk, pts[idx])) return disk;

    onEdge.push_back(pts[idx]);
    random_shuffle(pts.begin() + idx + 1, pts.end());
    disk = welzl(pts, onEdge, idx + 1);
    onEdge.pop_back();

    return disk;
}

int main() {
    
}