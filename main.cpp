#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#define block_w 4
#define block_h 4

class Block {
public:
    string type;
    int Pos_x, Pos_y;
    int data[block_h][block_w] = {0};
    int blocktype[20][block_h][block_w] = {
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0}},
        {{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 1, 0}},
        {{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 0, 0},{1, 0, 0, 0}},
        {{0, 0, 0, 0},{1, 0, 0, 0},{1, 0, 0, 0},{1, 1, 0, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 1},{1, 0, 0, 0}},
        {{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 1, 0},{1, 1, 1, 0}},
        {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 1, 0}},
        {{0, 0, 0, 0},{1, 1, 0, 0},{1, 0, 0, 0},{1, 0, 0, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{0, 0, 1, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{0, 1, 1, 0},{1, 1, 0, 0}},
        {{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 1, 0}},
        {{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0},{1, 0, 0, 0}},
        {{1, 0, 0, 0},{1, 0, 0, 0},{1, 0, 0, 0},{1, 0, 0, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 1}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 0, 0},{1, 1, 0, 0}},
        {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}}};
    string t[19] = { "T1","T2","T3","T4","L1","L2","L3","L4","J1","J2","J3","J4","S1","S2","Z1","Z2","I1","I2","O" };
    Block(){}
    Block(string name, int y, int x) 
    {
        Pos_x = x; Pos_y = y;
        for (int i = 0; i < 19; i++)
            if (name == t[i])
                getdata(i);
    }
    ~Block(){}
    void getdata(int value)
    {
        for (int h = 0; h < 4; h++)
            for (int w = 0; w < 4; w++)
                data[h][w] = blocktype[value][h][w];
    }
};

class Map {
public:
    int MapWidth, MapHeight;
    int** map;
    Map(){}
    Map(int H, int W) :MapWidth(W), MapHeight(H)
    {
        map = new int* [H];
        for (int i = 0; i < H; i++)
        {
            map[i] = new int[W];
            for (int j = 0; j < W; j++)
                map[i][j] = 0;
        }
    }
};

int main()
{
    int w, h;
    string filename; 
    cin >> filename;
    fstream file;
    string testcase;

    file.open(filename.c_str(), ios::in);
    file >> w >> h;
    Map Tetris(h+1, w+1);

    while (file >> testcase)
    {
        if (testcase == "End")
        {
            file.close();
            break;
        }  
        else
        {
            int StartPos, Move;
            file >> StartPos >> Move;
            Block newblock(testcase, 0, StartPos);
        }
    }

    return 0;
}

