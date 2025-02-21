#include <iostream>
#include <ctime>
#include <cstdlib>
void printer(char grid[10][10]);
bool place(char ships[10][10], int a, int b, int len, bool orient);
void clearConsole() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");  // for the others
#endif
}
int main() {
    char grid[10][10];
    char ships[10][10];
    int remaining_ships = 0;
    int guesses = 30;
    char e;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = '-';
            ships[i][j] = '-';
        }
    }

    srand(time(NULL));
    int lengths[] = {5, 4, 3, 3, 2};
    for (int i = 0; i < 5; i++) {
        bool places = false;
        while (!places) {
            int a = rand() % 10;
            int b = rand() % 10;
            bool orient = rand() % 2;
            places = place(ships, a, b, lengths[i], orient);
        }
        remaining_ships += lengths[i];
    }

    std::cout << "Map:" << std::endl;
    printer(ships);

    int row, col;
    int shots = 0;
    
    while(remaining_ships > 0 & guesses > 0){
        std::cout << "Shots taken: " << shots << std::endl;
        std::cout << "Spots remaining: " << remaining_ships << std::endl;
        std::cout << "Guesses Remaining: "<< guesses << std::endl;
        
        
       
        std::cout << "\nEnter target coordinates (column row): ";
        std::cin >> row >> col;

        if (row < 0 || row >= 10 || col < 0 || col >= 10) {
            std::cout << "that aint on the map(any to continue)";
            std::cin >> e;
            continue;
        }
        
        shots++;
        guesses--;

        if (ships[col][row] == 'S')
        {
            std::cout<<"target hit"<<std::endl;
        }


    }

    


    return 0;
}

void printer(char grid[10][10]) {
    // print column numbers
    std::cout << "   ";  
    for (int j = 0; j < 10; j++) {
        std::cout << j << "  ";
    }
    std::cout << std::endl;
    

    std::cout << "   ";
    for (int j = 0; j < 10; j++) {
        std::cout << "---";
    }
    std::cout << std::endl;
    
    // print row nymbers 
    for (int i = 0; i < 10; i++) {
        std::cout << i << " |";  
        for (int j = 0; j < 10; j++) {
            std::cout << " " << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// place the ships 
bool place(char ships[10][10], int a, int b, int len, bool orient) {
    if (orient) {
        if (b + len > 10) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            if (ships[a][b + i] != '-') {
                return false;
            }
        }
        for (int i = 0; i < len; i++) {
            ships[a][b + i] = 'S';
        }
    }
    else {
        if (a + len > 10) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            if (ships[a + i][b] != '-') {
                return false;
            }
        }
        for (int i = 0; i < len; i++) {
            ships[a + i][b] = 'S';
        }
    }
    return true;
}
