/*
 *  Author: Sebastian Paszkowski (B1ackBeltDev)
 *  created: 15.02.2025 12:38
**/

#include <iostream>
#include <fstream>
using namespace std;

void ScaleDown(const string &inputFile, const string &outputFile, int ratio){
    // Read From InputFile
    ifstream fin;
    fin.open(inputFile);

    string t;
    fin >> t;

    int width, height;
    fin >> width >> height;

    int maxVal;
    fin >> maxVal;
    
    int img[width][height];
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            fin >> img[x][y];
        }
    }
    
    fin.close();

    // Process Image

    int outImg[width/ratio][height/ratio];

    for(int y = 0; y < height-ratio+1; y += ratio){
        for(int x = 0; x < width-ratio+1; x += ratio){
            int value = 0;
            for(int dy = 0; dy < ratio; dy++){
                for(int dx = 0; dx < ratio; dx++){
                    value += img[x+dx][y+dy];
                }
            }
            value /= (ratio*ratio);
            outImg[x/ratio][y/ratio] = value;
        }
    }

    height /= ratio;
    width /= ratio;

    // Output Image

    ofstream fout;
    fout.open(outputFile);

    fout << t << '\n';
    fout << width << ' ' << height << '\n';
    fout << maxVal << '\n';
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            fout << outImg[x][y] << ' ';
        }
        fout << '\n';
    }

    fout.close();
}

void Brightener(const string &inputFile, const string &outputFile, double ratio){
    // Read From InputFile
    ifstream fin;
    fin.open(inputFile);

    string t;
    fin >> t;

    int width, height;
    fin >> width >> height;

    int maxVal;
    fin >> maxVal;
    
    int img[width][height];
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            fin >> img[x][y];
        }
    }
    
    fin.close();

    // Process Image

    int outImg[width][height];
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            outImg[x][y] = min(maxVal, static_cast<int>(img[x][y] * ratio));
        }
    }

    // Output Image

    ofstream fout;
    fout.open(outputFile);

    fout << t << '\n';
    fout << width << ' ' << height << '\n';
    fout << maxVal << '\n';
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            fout << outImg[x][y] << ' ';
        }
        fout << '\n';
    }

    fout.close();
}


int main(){
    // ScaleDown("./input.pgm", "./output.pgm", 3);
    // Brightener("./input.pgm", "./output.pgm", 0.2);

    return 0;
}