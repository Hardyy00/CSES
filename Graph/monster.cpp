#include <bits/stdc++.h>

using namespace std;

bool dfs(int r, int c, int steps, string &ans, vector<vector<char>> &mat, vector<vector<int>> &dis, int ra[], int ca[] , char dir[]){

    if(r == 0 || r == mat.size()-1 || c == 0 || c == mat[0].size()-1) return true;

    char save = mat[r][c];
    mat[r][c] = '#';
    for(int i=0;i<4;i++){

        int nr = r + ra[i];
        int nc = c + ca[i];

        if(nr >=0 && nr < mat.size() && nc>=0 && nc < mat[0].size() && mat[nr][nc] !='#' && steps + 1 < dis[nr][nc]){
            ans.push_back(dir[i]);

            if(dfs(nr, nc, steps+1,ans, mat, dis, ra, ca, dir)) return true;

            ans.pop_back();

        }
    }

    mat[r][c] = save;
    return false;
}

int main (){

    int n,m;
    cin >> n >> m;

    vector<vector<int>> dis(n, vector<int>(m,1e8));  // to keep for the steps, monsters take to reach a cell
    queue<pair<int,int>> q;

    vector<vector<char>> mat(n,vector<char>(m));

    // to hold the A's position
    int sr = -1;
    int sc = -1;

    // using a multi source BFS , for the monsters
    for(int i=0;i<n;i++){
        string s;
        cin >> s;

        for(int j=0;j<m;j++){
            
            mat[i][j] = s[j];


            if(mat[i][j] == 'M') {
                q.push({i,j});
                dis[i][j] = 0;
            }else if( mat[i][j] == 'A'){
                sr = i;
                sc = j;
            }
        }
    }

    int ra[4] = {-1, 0, 1, 0};
    int ca[4] = {0, 1, 0, -1};
    char dir[4] = {'U', 'R', 'D' , 'L'};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        int d = dis[r][c];

        q.pop();

        for(int i=0;i<4;i++){
            int nr = r + ra[i];
            int nc = c + ca[i];

            if(nr >=0 && nr < n && nc>=0 && nc < m && mat[nr][nc]!='#' && d+1 < dis[nr][nc]){
                dis[nr][nc] = d + 1;
                q.push({nr,nc});
            }
        }
    }

    string ans="";

    

    if(dfs(sr,sc, 0, ans, mat, dis,ra,ca,dir) == false) cout << "NO" << endl;
    else {
        cout << "YES\n" << ans.size() << "\n" << ans;
    }
}