// Atharva and Matthew
// 2D Array Game
// 2/25
// Extra: Color Output

#include <iostream>
#include <ctime>
#include <cstdlib>

char e;
void printer(char grid[10][10]);
bool place(char ships[10][10], int a, int b, int len, bool orient);

// Clear console
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");  
#endif
}

int main() {
    std::cout << "Instructions" << std::endl;
    std::cout << "Enter your guess in (row, column) format. Please do not include parenthesis." << std::endl;
    std::cout << "You have 40 guesses to sink all 5 ships" << std::endl;
    std::cout << "Enter anything to continue" << std::endl;
    std::cin >> e;
    char grid[10][10];
    char ships[10][10];
    int remaining_ships = 0;
    int guesses = 30;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = '-';
            ships[i][j] = '-';
        }
    }

    // Place ships 
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

    
    int row, col;
    int shots = 0;
    
    while (remaining_ships > 0 && shots < guesses) {
        clearConsole();
        std::cout << "Shots taken: " << shots << " (Max: " << guesses << ")" << std::endl;
        std::cout << "Ships remaining: " << remaining_ships << std::endl;
        std::cout << "\nYour guesses:\n";
        printer(grid);
        
    
        std::cout << "\nEnter target coordinates (row column): ";
        std::cin >> row >> col;
        
  
        if (row < 0 || row >= 10 || col < 0 || col >= 10) {
            std::cout << "not on the map press any key to continue";
            std::cin >> e;
            continue;
        }
        
        // Already guessed this location
        if (grid[row][col] != '-') {
            std::cout << "alreayd guessed press any key to continue";
            std::cin >> e;
            continue;
        }
        
        shots++;
        
        // Check if hit
        if (ships[row][col] == 'S') {
            grid[row][col] = 'X'; 
            ships[row][col] = 'X'; 
            remaining_ships--;
            std::cout << "HIT";
            std::cout<<" Enter anything then enter to next guess"<<std::endl;
        } else {
            grid[row][col] = 'M'; 
            std::cout << "Miss";
            std::cout<<" Enter anything then enter to next guess"<<std::endl;
        }
        std::cin >> e;
    }
    
    // Game over
    clearConsole();
    if (remaining_ships == 0) {
        std::cout << "You sunk all the ships in " << shots << " shots!\n";
    } else {
        std::cout << "You've used all " << guesses << " guesses.\n";
        std::cout << "Ships remaining: " << remaining_ships << "\n";
        
        // Show ship locations
        std::cout << "\nHere were the ship locations:\n";
        printer(ships);
    }
    
    std::cout << "\nYour final board:\n";
    printer(grid);
    
    std::cout << "\nPress any key to exit";
    std::cin >> e;
    return 0;
}

void printer(char grid[10][10]) {
    //numbers
    std::cout << "   ";
    for (int j = 0; j < 10; j++) {
        std::cout << j << "  ";
    }
    std::cout << std::endl;
    
    // line
    std::cout << "   ";
    for (int j = 0; j < 10; j++) {
        std::cout << "---";
    }
    std::cout << std::endl;
    
    // numbers
    for (int i = 0; i < 10; i++) {
        std::cout << i << " |";
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == 'X') {
                // Red 
                std::cout << " \033[1;31mX\033[0m ";
            } else if (grid[i][j] == 'M') {
                // Blue 
                std::cout << " \033[1;34mM\033[0m ";
            } else if (grid[i][j] == 'S') {
                // Green
                std::cout << " \033[1;32mS\033[0m ";
            } else {
                // Default
                std::cout << " " << grid[i][j] << " ";
            }
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
