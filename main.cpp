#include <iostream>
#include <ctime>

int main(){
    char grid[10][10];
    char ships[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            grid[i][j] = '-';
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            ships[i][j] = '-';
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            std::cout << grid[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    srand(time(NULL));
    int orient = rand() % 2;

    return 0;
}
