#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
typedef long double ld;

void init_img(string &type, int &max_val, int &width, int &height, vector<vector<int>> &img){
    ifstream fin;
    fin.open("shapes.pgm");

    fin >> type >> width >> height >> max_val;
    img.resize(height, vector<int>(width));

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            fin >> img[y][x];
        }
    }

    fin.close();
}

vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool dfs(int y, int x, vector<pair<int, int>> &points, vector<pair<int, int>> &edges, vector<vector<bool>> &vis, const vector<vector<int>> &img, int max_val, int width, int height){
    if(!(0 <= y && y < height)) return false;
    if(!(0 <= x && x < width)) return false;

    if(img[y][x] == max_val) return true;
    if(vis[y][x]) return false;

    vis[y][x] = true;

    points.push_back({y, x});
    bool ok = false;
    for(pair<int, int> dir : dirs){
        if(dfs(y+dir.st, x+dir.nd, points, edges, vis, img, max_val, width, height) && !ok){
            edges.push_back({y, x});
            ok = true;
        }
    }
}

void visualize(string type, int max_val, int width, int height, vector<vector<int>> img){
    ofstream fout;
    fout.open("visualization.pgm");

    fout << type << '\n';
    fout << width << ' ' << height << '\n';
    fout << max_val << '\n';

    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            fout << img[y][x] << ' ';
        }
        fout << '\n';
    }

    fout.close();
}

int main(){
    // Init Img
    string type;
    int max_val;
    int width;
    int height;
    vector<vector<int>> img;

    init_img(type, max_val, width, height, img);

    int ans = 0;

    // Find Objects
    vector<vector<bool>> vis(height, vector<bool>(width, false));
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            if(vis[y][x]) continue;

            vector<pair<int, int>> points;
            vector<pair<int, int>> edges;
            dfs(y, x, points, edges, vis, img, max_val, width, height);

            if(points.size() == 0) continue;

            // Calculate Center
            ld x_mean = 0;
            ld y_mean = 0;
            for(pair<int, int> point : points){
                y_mean += (ld)point.st;
                x_mean += (ld)point.nd;
            }

            x_mean /= (ld) points.size();
            y_mean /= (ld) points.size();

            // Calculate min and max distance
            ld min_dist = LDBL_MAX;
            ld max_dist = LDBL_MIN;
            ld mean = 0;
            for(pair<int, int> point : edges){
                ld dist = (ld)sqrt((ld)pow((ld)point.st - y_mean, 2) + (ld)pow((ld)point.nd - x_mean, 2));
                mean += dist;
                min_dist = min(min_dist, dist);
                max_dist = max(max_dist, dist);
            }
            mean /= (ld)points.size();
            ld diff = (max_dist - min_dist) / mean;

            if(diff < 4.25){
                for(pair<int, int> point : points){
                    img[point.st][point.nd] = 200;
                }
                ans++;
            }
        }
    }

    visualize(type, max_val, width, height, img);
    cout << "Liczba kol: " << ans << '\n';
}
