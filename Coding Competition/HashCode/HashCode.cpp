#include <bits/stdc++.h>
using namespace std;


/*=================================================================
Global Variables Start 
=================================================================*/
int C, P;

struct Contributor{
    string name;
    int n;
    unordered_map<string, int> skills;
    void read(){
        cin >> name >> n;
        for(int i = 0; i < n; i++){
            string t; int val; cin >> t >> val;
            skills[t] = val;
        }
    }
};

struct Project{
    string name;
    int D, S, B, R, L = -1e9;
    vector<string> RoleName;
    vector<int> RoleLevel;
    void read(){
        cin >> name >> D >> S >> B >> R;
        for(int i = 0; i < R; i++){
            string t; int val; cin >> t >> val;
            RoleName.push_back(t);
            RoleLevel.push_back(val);
            L = max(L, val);
        }
    }
};

vector<Contributor> contributors;
vector<Project> projects;

vector<vector<string>> resC;
vector<string> resP;
int FinalScore = 0;

/*=================================================================
Global Variables End
=================================================================*/


// take all input here only
void takeInput(){
    
}


// print here whatever you have to print for final answer
void outputResult(int score = 0){ 
    cout << resP.size() << endl;
    for(int i = 0; i < resP.size(); i++){
        cout << resP[i] << endl;
        for(int j = 0; j < resC[i].size(); j++){
            cout << resC[i][j] << " ";
        }
        cout << endl;
    }
}

// string createNewFile(int score = 0){
//     fstream file;
//     string fileName = "out" + to_string(score) + ".txt";
//     file.open(fileName, ios::out);
//     file.close();
//     return fileName;
// }

// void outputInFile(int score = 0){
//     string s = createNewFile(score);
//     char *fileName = new char[s.size() + 1];
//     strcpy(fileName, s.c_str());
//     freopen(fileName, "w", stdout);
//     outputResult(score);
// }

// // score given by hashcode system
// int findScore(){
//     return FinalScore;
// }

/*
1) increasing Lk
2) B/D min
3) score max

*/


void solve(){ // logic

    sort(projects.begin(), projects.end(), [&](auto &a, auto &b){
        // return a.L - 1.25* a.S + 2*a.B < b.L - 1.25 * b.S + 2*b.B;
        // return a.L - 1.5987 * a.S + 0.78 * a.B + a.D < b.L - 1.5987 * b.S + 0.78 * b.B + a.D;
        // return 1.5987 * a.S  - 0.53783 * a.L >  1.5987 * b.S - 0.53783 * a.L;
        // return a.S > b.S;
        return 3.835638 * a.L - a.S * a.S < 3.835638 * a.L - b.S * b.S;
        // return a.B < b.B;
        // return 1.893456 * a.S 0.78 * a.B > 1.893456 * b.S + 0.78 * a.B;
    });


    int Time = 0;

    // for(Project &currProject: projects){
    for(int kk = 0; kk < projects.size();){
        vector<int> candidateTaken(C, 0);
        int j = kk;
        int CurrT = Time;
        for(; j < projects.size(); j++){
            Project currProject = projects[j];

            int currScore = currProject.S - (Time + currProject.D - currProject.B);
            if(currScore <= 0){
                continue;
            }
            if(Time + currProject.D <= currProject.B){
                currScore = currProject.S;
            }

            vector<string> &RoleName = currProject.RoleName;
            vector<int> &RoleLevel = currProject.RoleLevel;
            vector<pair<int, vector<int>>> possibleCandidate(RoleName.size());
            int k = 0;
            for(int i = 0; i < RoleName.size(); i++){
                string topic = RoleName[i];
                int level = RoleLevel[i];
                vector<int> tmp;
                for(int i = 0; i < C; i++){
                    if(contributors[i].skills[topic] >= level){
                        tmp.push_back(i);
                    }
                }
                possibleCandidate[k] = {k, tmp};
                k++;
            }

            sort(possibleCandidate.begin(), possibleCandidate.end(), [&](auto &a, auto &b){
                return a.second.size() < b.second.size();
            });

            vector<int> candidateChoosen(RoleName.size(), 0);
            for(int i = 0; i < RoleName.size(); i++){
                for(int candIdx: possibleCandidate[i].second){
                    if(candidateTaken[candIdx] == 0){
                        int role = possibleCandidate[i].first;
                        candidateChoosen[role] = candIdx;
                        candidateTaken[candIdx] = 1;
                        break;
                    }
                }
            }

            bool isAssigned = true;
            for(int i = 0; i < RoleName.size(); i++){
                if(candidateChoosen[i] == 0){
                    isAssigned = false;
                    break;
                }
            }

            if(isAssigned){
                for(int i = 0; i < RoleName.size(); i++){
                    int role = i;
                    int candIdx = candidateChoosen[i];
                    string name = currProject.RoleName[role];
                    if(contributors[candIdx].skills[name] == currProject.RoleLevel[role]){
                        contributors[candIdx].skills[name] += 1;
                    }
                }
            }


            if(isAssigned){
                FinalScore += currScore;
                // Time += currProject.D;
                CurrT = max(CurrT, Time + currProject.D);
            }

            if(isAssigned){
                resP.push_back(currProject.name);
                resC.push_back(vector<string>());
                for(int &candIdx: candidateChoosen){
                    resC.back().push_back(contributors[candIdx].name);
                }
            }

            if(isAssigned == 0){
                break;
            }
        }
        if(j == kk) kk++;
        else kk = j;
        Time = CurrT;
    }
    outputResult();
}


int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("in6.txt", "r", stdin);
    freopen("out6.txt", "w", stdout);
    cin >> C >> P;
    contributors = vector<Contributor>(C);
    projects = vector<Project>(P);
    for(int i = 0; i < C; i++){
        contributors[i].read();
    }
    for(int i = 0; i < P; i++){
        projects[i].read();
    }
    solve();
}