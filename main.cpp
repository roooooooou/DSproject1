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
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0}}, //T1
        {{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0}}, //T2
        {{0, 0, 0, 0},{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 1, 0}}, //T3
        {{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 0, 0},{1, 0, 0, 0}}, //T4
        {{0, 0, 0, 0},{1, 0, 0, 0},{1, 0, 0, 0},{1, 1, 0, 0}}, //L1
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{1, 0, 0, 0}}, //L2
        {{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0}}, //L3
        {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 1, 0},{1, 1, 1, 0}}, //L4
        {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0}}, //J1
        {{0, 0, 0, 0},{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 1, 0}}, //J2
        {{0, 0, 0, 0},{1, 1, 0, 0},{1, 0, 0, 0},{1, 0, 0, 0}}, //J3
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
    Block(){
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                data[i][j] = 0;
    }
    Block(string name, int x, int y) 
    {
        Pos_x = x; Pos_y = y;
        for (int i = 0; i < 19; i++)
            if (name == t[i])
                getdata(i);
    }
    Block(const Block& block)
    {
        Pos_x = block.Pos_x;
        Pos_y = block.Pos_y;
        for (int i = 0; i < block_h; i++)
            for (int j = 0; j < block_w; j++)
                data[i][j] = block.data[i][j];
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
    friend Block;
public:
    int MapWidth, MapHeight;
    int** map;
    bool gameover = false;
    Map() { MapWidth = 0; MapHeight = 0; }
    Map(int H, int W) :MapWidth(W), MapHeight(H)
    {
        map = new int* [H+1];
        for (int i = 0; i <= H; i++)
        {
            map[i] = new int[W+1];
            for (int j = 0; j <= W; j++)
                map[i][j] = 0;
        }
    }
    void blockFall(Block& block)
    {     
        while(checkBarrier(block.Pos_y + 1, block))
            block.Pos_y++;
    }
    bool checkBarrier(int next_y, Block& block)
    {
        bool stop = true;
        if (next_y > MapHeight)
            stop = false;
            
        for (int j = block_h-1; j >= 0; j--)
        {
            if (!stop) break;
            for (int k = 0; k < block_w; k++)
            {
                if (block.data[j][k] == 1)
                {
                    if (next_y - (block_h - 1 - j) < 0) break;
                    if (map[next_y - (block_h - 1 - j)][block.Pos_x + k] == 1)
                    {
                        stop = false;
                        break;
                    }
                } 
            }
        }
        return stop;
    }
    void updateMap(Block& block)
    {
        for (int i = block_h - 1; i >= 0; i--)
        {
            for (int j = 0; j < block_w; j++)
            {
                if (block.Pos_y - (block_h - 1 - i) <= 0)
                {
                    clearLine();
                    blockFall(block);
                    updateMap(block);
                }
                else 
                {
                    if (block.data[i][j] == 0) continue;
                    map[block.Pos_y - (3 - i)][block.Pos_x + j] = 1;
                    block.data[i][j] = 0;
                }
            }  
        }
        clearLine();
    }
    void clearLine()
    {
        for (int i = MapHeight; i > 0; i--)
        {
            bool full = true;
            for (int j = 1; j <= MapWidth; j++)
            {
                if (map[i][j] != 1)
                {
                    full = false;
                    break;
                }
            }
            if (full)
            {
                for (int k = i; k >= 1; k--)
                {
                    for (int j = 1; j <= MapWidth; j++)
                        map[k][j] = map[k - 1][j];
                }
                for (int k = 1; k <= MapWidth; k++)
                    map[1][k] = 0;
                i++;
            }
        }
    }
};


int main(int argc, char* argv[])
{
    int w, h;
    fstream file;
    string testcase;
    file.open("10806123_proj1.data", ios::in);
    //file.open(argv[1], ios::in);
    file >> h >> w;
    Map Tetris(h, w);
    bool gameover = false;
    while (file >> testcase)
    {
        if (testcase == "End")
            break;
        else
        {
            int StartPos, Move;
            file >> StartPos >> Move;
            Block newblock(testcase, StartPos, 0);

            Tetris.blockFall(newblock);
            newblock.Pos_x += Move;
            Tetris.blockFall(newblock);
            Tetris.updateMap(newblock);
        }
    }
    file.close();
    fstream final;

    final.open("final.final", ios::out);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
            final << Tetris.map[i][j] << ' ';
        final << '\n';
    }  
    final.close();
    return 0;
}

