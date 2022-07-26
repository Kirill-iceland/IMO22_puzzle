#include <bits/stdc++.h>
#define rep(i, a, b) for(typeof(b) i = a; i < b; i++)
using namespace std;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int, int> iiii;
typedef pair<pair<int, int>, int> iii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
int INF = ~(1 << 31);
#define fs first
#define sc second
#define _x first
#define _y second

// shapes:
//       #  #    #  
//  ###  #  #   ##  ##        ##   #  #   #
//   #   #  #   #   #   ##    #   ##  #   #
//   #   #  ##  #   ##  ###  ##   #   ##  ###

vector<ii> shapes [10][2][4] = {
    {
        {
            {{0, 0}, {1, 0}, {2, 0}, {1, 1}, {1, 2}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}},
            {{0, 0}, {1, 0}, {2, 0}, {1, -1}, {1, -2}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 1}, {-2, 1}}
        },
        {
            {{0, 0}, {1, 0}, {2, 0}, {1, 1}, {1, 2}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}},
            {{0, 0}, {1, 0}, {2, 0}, {1, -1}, {1, -2}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 1}, {-2, 1}}
        }
    },
    {
        {
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
            {},
            {}
        },
        {
            {},
            {},
            {},
            {}
        }
    },
    {
        {
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {-1, 0}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, -1}},
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {3, 1}}
        },
        {
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 0}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 1}},
            {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {-1, 3}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {3, -1}}
        }
    },
    {
        {
            {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {1, 3}},
            {{0, 0}, {1, 0}, {1, 1}, {2, 1}, {3, 1}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 3}, {1, 2}},
            {{0, 0}, {1, 0}, {2, 0}, {3, 1}, {2, 1}}
        },
        {
            {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}, {-1, 3}},
            {{0, 0}, {1, 0}, {1, -1}, {2, -1}, {3, -1}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 3}, {-1, 2}},
            {{0, 0}, {1, 0}, {2, 0}, {3, -1}, {2, -1}}
        }
    },
    {
        {
            {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {2, 1}},
            {{0, 0}, {1, 0}, {2, 0}, {0, -1}, {2, -1}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 0}, {-1, 2}}
        },
        {
            {},
            {},
            {},
            {}
        }
    },
    {
        {
            {{0, 0}, {0, 1}, {-1, 0}, {-1, 1}, {-2, 0}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}},
            {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 1}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 1}, {1, 2}}
        },
        {
            {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 0}, {-1, 1}},
            {{0, 0}, {0, 1}, {-1, 0}, {-1, 1}, {-2, 1}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 1}, {-1, 2}}
        }
    },
    {
        {
            {{0, 0}, {1, 0}, {2, 0}, {0, -1}, {2, 1}},
            {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {2, -1}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 0}, {1, 2}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {-1, 2}}
        },
        {
            {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {2, -1}},
            {{0, 0}, {1, 0}, {2, 0}, {0, -1}, {2, 1}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {-1, 2}},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 0}, {1, 2}}
        }
    },
    {
        {
            {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
            {{0, 0}, {1, 0}, {1, -1}, {2, -1}},
            {},
            {}
        },
        {
            {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
            {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
            {},
            {}
        }
    },
    {
        {
            {{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {-1, 0}},
            {{0, 0}, {1, 0}, {2, 0}, {2, -1}, {0, -1}},
            {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {1, 2}},
            {{0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 1}}
        },
        {
            {{0, 0}, {0, 1}, {0, 2}, {1, 0},},
            {{0, 0}, {1, 0}, {2, 0}, {0, 1},},
            {{0, 0}, {0, 1}, {0, 2}, {-1, 2},},
            {{0, 0}, {1, 0}, {2, 0}, {2, -1},}
        }
    },
    {
        {
            // {{0, 0}, {0, 1}, {0, 2}, {-1, 0}, {-2, 0}},
            // {{0, 0}, {1, 0}, {2, 0}, {0, -1}, {0, -2}*/},
            {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}},
            {{0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}}
        },
        {
            {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {2, 0}},
            {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {0, 2}},
            // {/*{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {-2, 2}*/},
            // {/*{0, 0}, {1, 0}, {2, 0}, {2, -1}, {2, -2}*/}
        }
    }
};




ll res = 1;
ll res2 = 1;

bool map_[8][7] = {
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0}
};

int type[8][7] = {
    {0, 0, 0, 0, 0, 0,-1},
    {0, 0, 0, 0, 0, 0,-1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 2, 2, 2, 2},
   {-1,-1,-1,-1, 2, 2, 2}
};

string values[8][7] = {
    {"Jan", "Feb", "Mar", "Apr", "May", "Jun", ""},
    {"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",""},
    {"1", "2", "3", "4", "5", "6", "7"},
    {"8", "9", "10", "11", "12", "13", "14"},
    {"15", "16", "17", "18", "19", "20", "21"},
    {"22", "23", "24", "25", "26", "27", "28"},
    {"29", "30", "31", "Sun", "Mon", "Thue", "Wed"},
    {"", "", "", "", "Thur", "Fri", "Sat"}
};

bool check(int x, int y, int shape, int rotation, int side){
    vii v = shapes[shape][side][rotation];

    rep(i, 0, v.size()){
        ii pos = v[i];
        int new_x = x + pos._x;
        int new_y = y + pos._y;

        if(new_y < 0 || new_x < 0 || new_x > 7 || new_y > 6){
            return false;
        }
        if(map_[new_x][new_y]){
            return false;
        }
    }
    return true;
};

void set_(int x, int y, int shape, int rotation, int side, bool val){
    vii v = shapes[shape][side][rotation];

    rep(i, 0, v.size()){
        ii pos = v[i];
        int new_x = x + pos._x;
        int new_y = y + pos._y;

        map_[new_x][new_y] = val;
    }
};

string find_res(){
    int i = 0;
    string res[3];
    rep(x, 0, 8){
        rep(y, 0, 7){
            if(!map_[x][y]){
                if(i != type[x][y]){
                    return "";
                }
                res[i] = values[x][y];
                i++;
            }
        }
    }
    return res[2] + ", " + res[0] + " " + res[1];
}

void f(int c){
    
    // // shapes[9][0][0] = {{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {-1, 0}, {-2, 0}};
    // shapes[9][0][0].push_back({0, 0});
    // shapes[9][0][0].push_back({0, 1});
    // shapes[9][0][0].push_back({0, 2});
    // shapes[9][0][0].push_back({-1, 0});
    // shapes[9][0][0].push_back({-2, 0});
    // // shapes[9][0][1] = {{0, 0}, {1, 0}, {2, 0}, {2, -1}, {0, -1}, {0, -2}};
    // shapes[9][0][0].push_back({0, 0});
    // shapes[9][0][0].push_back({1, 0});
    // shapes[9][0][0].push_back({2, 0});
    // shapes[9][0][0].push_back({0, -1});
    // shapes[9][0][0].push_back({0, -2});
    // // shapes[9][1][2] = {{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {-2, 2}};
    // shapes[9][0][0].push_back({0, 0});
    // shapes[9][0][0].push_back({0, 1});
    // shapes[9][0][0].push_back({0, 2});
    // shapes[9][0][0].push_back({-1, 2});
    // shapes[9][0][0].push_back({-2, 2});
    // // shapes[9][1][3] = {{0, 0}, {1, 0}, {2, 0}, {2, -1}, {2, -2}};
    // shapes[9][0][0].push_back({0, 0});
    // shapes[9][0][0].push_back({1, 0});
    // shapes[9][0][0].push_back({2, 0});
    // shapes[9][0][0].push_back({2, -1});
    // shapes[9][0][0].push_back({2, -2});
    if(c == 3){
        cout << "b---" << res << " " << res2 << "---" << endl;
    }
    rep(i, 0, 2){
        rep(j, 0, 4){
            if(!shapes[c][i][j].size()){
                continue;
            }

            rep(x, 0, 8){
                rep(y, 0, 7){
                    if(!check(x, y, c, j, i)){
                        continue;
                    }
                    set_(x, y, c, j, i, 1);
                    if(c < 5){
                        res *= 10;
                        res += x;
                        res *= 10;
                        res += y;
                        res *= 10;
                        res += i * 4 + j;
                    }else{
                        res2 *= 10;
                        res2 += x;
                        res2 *= 10;
                        res2 += y;
                        res2 *= 10;
                        res2 += i * 4 + j;
                    }
                    if(c == 9){
                        string r = find_res();
                        if(r != ""){
                            cout << res << " " << res2 << " " << r << endl;
                        }
                    }else{
                        f(c + 1);
                    }
                    if(c < 5){
                        res /= 1000;
                    }else{
                        res2 /= 1000;
                    }
                    set_(x, y, c, j, i, 0);
                }
            }
        }
    }
    if(c == 3){
        cout << "e---" << res << " " << res2 << "---" << endl;
    }
}

int main(){
    f(0);
}