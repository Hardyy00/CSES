#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int sr=-1, sc=-1, er = -1,ec =-1;
 
    int n , m;
 
    cin >>  n >> m;
 
    vector<vector<char>> mat(n, vector<char>(m, ' '));
 
 
    for(int i=0;i<n;i++){
        string s ;
        cin >> s;
        for(int j=0;j<m;j++){
 
            mat[i][j] = s[j];
 
            if(s[j] == 'A'){
                sr = i;
                sc = j;
            }else if ( s[j] == 'B'){
 
                er = i;
                ec = j;
            }
        }
 
    }
 
    if(sr == -1 || er == -1){
        cout << "NO";
        return 0;
    }
 
    // {{parent_row, parent_col}, {direction, distance}}
    vector<vector<pair<pair<int,int>,pair<char, int>>>> dis(n, vector<pair<pair<int,int>,pair<char, int>>>(m, {{-1,-1},{' ', 1e8}}));
 
    queue<pair<int,int>> q;
    pair<int, char> ra[4] = {{-1, 'U'}, {0, 'R'}, {1, 'D'}, {0, 'L'}};
 
    int ca[4] = {0, 1, 0, -1};
    dis[sr][sc].second.second = 0;
 
    q.push({sr, sc});
 
    while(q.empty() == false){
 
        int r = q.front().first;
        int c = q.front().second;
        int d = dis[r][c].second.second;
 
        q.pop();
 
        for(int i=0;i<4;i++){
 
            int nr = r + ra[i].first;
            int nc = c + ca[i];
            char direction = ra[i].second;
 
            if(nr>=0 && nr< n && nc>=0 && nc< m && mat[nr][nc] !='#' && d  + 1 < dis[nr][nc].second.second){
 
                dis[nr][nc].second.second = d +1;
                dis[nr][nc].first.first = r;
                dis[nr][nc].first.second = c;
                dis[nr][nc].second.first = direction;
 
                q.push({nr,nc});
            }
        }
 
    }
 
    if(dis[er][ec].second.second == 1e8) {
 
        cout <<  "NO";
        return 0;
    }
    
 
    int r = er;
    int c = ec;
    string ans = "";
    while(dis[r][c].first.first!=-1 ){
 
        ans.push_back(dis[r][c].second.first);
        
        int nr  = dis[r][c].first.first;
        int nc = dis[r][c].first.second;
 
        r = nr;
        c = nc;
    }
 
 
 
    reverse(ans.begin(), ans.end());
    cout << "YES\n" << dis[er][ec].second.second << "\n" << ans;
 
 
 
}
