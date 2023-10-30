#include <bits/stdc++.h>

using namespace std;

void dfs(int r, int c, vector<vector<char>> &mat, vector<vector<bool>> &visit, int ra[], int ca[]){

    visit[r][c] = true;

    for(int i=0;i<4;i++){

        int nr = r + ra[i];
        int nc = c + ca[i];

        if(nr>=0 && nr< mat.size() && nc>=0 &&nc < mat[0].size() && mat[nr][nc]=='.' && visit[nr][nc] == false){

            dfs(nr, nc, mat, visit, ra, ca);
        }
    }

}

int main (){

    ios::sync_with_stdio(0);
    cin.tie(0);

    // TC : O(N*M ) + O(n*m) + O(N*m)
    // SC : O(N*M) + O(N*M)

    int n , m;

    cin >> n >>m;

    vector<vector<char>> mat(n , vector<char>(m, ' '));

    for(int i =0;i<n;i++){

        string s;
        cin >> s;

        for(int j=0;j<m;j++){

            mat[i][j] = s[j];
        }
    }

    vector<vector<bool>> visit(n , vector<bool>(m, false));

    int count =0;

    int ra[4] = {-1,0,1,0};
    int ca[4] = {0,1,0,-1};

    for(int  i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(mat[i][j] == '.' && visit[i][j] == false){

                dfs(i,j,mat,visit, ra,ca);

                count++;
            }
        }
    }

    cout << count << '\n';
}