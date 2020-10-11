#include <iostream>
#include <string>
using namespace std;
#define block_w 4
#define block_h 4

class Block {
public:
    string type;
    int data[block_h][block_w] = {0};
    Block(){}
    Block(string name) 
    {
        if (name == "T1") 
        {
            int bk[block_h][block_w] = 
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 1, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "T2")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "T3")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 1, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "T4")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 1, 0, 0},
                {1, 0, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "L1")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 1, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "L2")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {1, 0, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "L3")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "L4")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 1, 0},
                {1, 1, 1, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "J1")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "J2")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 1, 1, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "J3")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "J4")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 1, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "S1")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 1, 1, 0},
                {1, 1, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "S2")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "Z1")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 1, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "Z2")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {1, 0, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "I1")
        {
            int bk[block_h][block_w] =
            {
                {1, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0},
                {1, 0, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "I2")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 1, 1}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else if (name == "I2")
        {
            int bk[block_h][block_w] =
            {
                {0, 0, 0, 0},
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {1, 1, 0, 0}
            };
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = bk[i][j];
        }
        else {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    data[i][j] = 0;
        }
    }
};
class map {
public:
    int MapWidth, MapHeight;
};

int main()
{
    string b1;
    cin >> b1;
    Block block1(b1);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << block1.data[i][j];
        cout << '\n';
    }
        
    
}

