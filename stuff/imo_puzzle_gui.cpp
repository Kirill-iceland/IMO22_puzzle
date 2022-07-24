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
//       #  #     #  
//  ###  #  #    ##  ##  ##    ##   #  #   #
//   #   #  #    #   #   ##    #   ##  #   #
//   #   #  ###  #   ##  ###  ##   #   ##  ###


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

string map_[8][7] = {
    {"JA", "FE", "MA", "AP", "MA", "JN", "##"},
    {"JL", "AU", "SE", "OC", "NO", "DE", "##"},
    {"01", "02", "03", "04", "05", "06", "07"},
    {"08", "09", "10", "11", "12", "13", "14"},
    {"15", "16", "17", "18", "19", "20", "21"},
    {"22", "23", "24", "25", "26", "27", "28"},
    {"29", "30", "31", "SU", "MO", "TE", "WE"},
    {"##", "##", "##", "##", "TR", "FR", "SA"}
};

bool map__[8][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

int main(){
    
    
    // shapes[9][0][0] = {{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {-1, 0}, {-2, 0}};
    shapes[9][0][0].push_back({0, 0});
    shapes[9][0][0].push_back({0, 1});
    shapes[9][0][0].push_back({0, 2});
    shapes[9][0][0].push_back({-1, 0});
    shapes[9][0][0].push_back({-2, 0});
    // shapes[9][0][1] = {{0, 0}, {1, 0}, {2, 0}, {2, -1}, {0, -1}, {0, -2}};
    shapes[9][0][0].push_back({0, 0});
    shapes[9][0][0].push_back({1, 0});
    shapes[9][0][0].push_back({2, 0});
    shapes[9][0][0].push_back({0, -1});
    shapes[9][0][0].push_back({0, -2});
    // shapes[9][1][2] = {{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {-2, 2}};
    shapes[9][0][0].push_back({0, 0});
    shapes[9][0][0].push_back({0, 1});
    shapes[9][0][0].push_back({0, 2});
    shapes[9][0][0].push_back({-1, 2});
    shapes[9][0][0].push_back({-2, 2});
    // shapes[9][1][3] = {{0, 0}, {1, 0}, {2, 0}, {2, -1}, {2, -2}};
    shapes[9][0][0].push_back({0, 0});
    shapes[9][0][0].push_back({1, 0});
    shapes[9][0][0].push_back({2, 0});
    shapes[9][0][0].push_back({2, -1});
    shapes[9][0][0].push_back({2, -2});
    ll a;
    cin >> a;
    for(int i = 5; i < 10; i++){
        int b = a % 10;
        int d = b % 4;
        b /= 4;
        a /= 10;
        int y = a %10;
        a /= 10;
        int x = a %10;
        a /= 10;
        
        vii dir = shapes[9 - i][b][d];
        cout << i << " " << b << " " << d << " " << x << " " << y << endl;
        for(int j = 0; j < dir.size(); j++){
            int new_x = x + dir[j]._x;
            int new_y = y + dir[j]._y;
            
            map_[new_x][new_y] = "0" + to_string(9 - i);
            map__[new_x][new_y] = 1;
        }
    }
    cin >> a;
    for(int i = 0; i < 5; i++){
        int b = a % 10;
        int d = b % 4;
        b /= 4;
        a /= 10;
        int y = a %10;
        a /= 10;
        int x = a %10;
        a /= 10;
        
        vii dir = shapes[9 - i][b][d];
        cout << i << " " << b << " " << d << " " << x << " " << y << endl;
        for(int j = 0; j < dir.size(); j++){
            int new_x = x + dir[j]._x;
            int new_y = y + dir[j]._y;
            
            map_[new_x][new_y] = "0" + to_string(9 - i);
            map__[new_x][new_y] = 1;
        }
    }
    rep(x, 0, 8){
        cout << endl << "|";
        rep(y, 0, 7){
            if(!map__[x][y]){
                cout << map_[x][y] << "|";
            }else{
                if(x == 7 || map_[x][y] != map_[x + 1][y]){
                    cout << "__";
                }else{
                    cout << "  "; //map_[x][y];
                }
                if(y == 6 || map_[x][y] != map_[x][y + 1]){
                    cout << "|";
                }else{
                    cout << " ";
                }
            }
        }
    }
}