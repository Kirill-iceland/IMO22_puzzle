#include <bits/stdc++.h>
#define rep(i, a, b) for(typeof(b) i = a; i < b; i++)
using namespace std;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int, int> iiii;
typedef pair<pair<int, int>, int> iii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ll, ii> shape_;
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

//1010100042252222 1647304430505023 Wed, Jan 28

int month_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
string week_days[7] = {"Sun", "Mon", "Thue", "Wed", "Thur", "Fri", "Sat"};
int c = 2562;
bool check[2604];
pair<ll, ll> res[2604];
int main(){
    memset(check, false, sizeof(check));
    ll a, b;
    int d;
    string w, m;
    while(c != 0){
        cin >> a;
        cin >> b;
        cin >> w;
        cin >> m;
        cin >> d;
        w = w.substr(0, w.length() - 1);
        // cout << a << b << w << m << ' ' << d << endl;
        int w_, m_;
        rep(i, 0, 7){
            if(w == week_days[i]){
                w_ = i;
                break;
            }
        }
        rep(i, 0, 12){
            if(m == months[i]){
                m_ = i;
                break;
            }
        }

        int index = 84 * (d - 1) + 7 * m_ + w_;
        // cout << check[index];
        if(!check[index]){
            // cout << w << m << d;
            check[index] = true;
            res[index] = {a, b};
            c--;
        }
    }
    rep(w_, 0, 7){
        rep(m_, 0, 12){
            rep(d_, 0, month_days[m_]){
                int index = 84 * d_ + 7 * m_ + w_;
                cout << res[index].fs << " " << res[index].sc << " " << week_days[w_] << ", " << months[m_] << " " << d_ + 1 << endl;
            }
        }
    }
}