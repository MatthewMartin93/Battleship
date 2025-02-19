#include <iostream>
#include <ctime>
void print(char grid[10][10]);
bool place(char grid[10][10], int a, int b, int len, bool orient);
int main(){
    char grid[10][10];
    char ships[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            grid[i][j] = '-';
            ships[i][j] = '-';
        }
    }
    srand(time(NULL));
    int lengths[] = {5, 4, 3, 3, 2};
    for(int i = 0; i < 5; i++){
        bool places = false;
        while (!places){
            int a = rand() % 10;
            int b = rand() % 10;
            bool orient = rand() % 2;
            places = place(grid, a, b, lengths[i], orient);
        }
    }
    std::cout << "Map:" << std::endl;
    print(grid);
    return 0;
}
void print(char grid[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            std::cout << grid[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}
bool place(char grid[10][10], int a, int b, int len, bool orient){
    if(orient){
        if (b + len > 10){
            return false;
        }
        for (int i = 0; i < len; i++){
                if (grid[a][b+i] != '-'){
                    return false;
                }
        }
        for (int i = 0; i < len; i++){
            grid[a][b + i] = 'S';
        }
    }
    else{
        if (a + len > 10){
            return false;
        }
        for (int i = 0; i < len; i++){
            if (grid[a + i][b] != '-'){
                return false;
            }
        }
    }
    return 0;
}
