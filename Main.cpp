#include <iostream>
#include <vector>

int main() {
    int column;
    int row; 
    bool running = true;
    int iteration = 0;

    std::vector<char> l1 = {'-', '-', '-'};
    std::vector<char> l2 = {'-', '-', '-'};
    std::vector<char> l3 = {'-', '-', '-'};
    std::vector<std::vector<char>> matrix = {l1, l2, l3};



    while (running)
    {
        
        iteration++;

        for (char val : matrix[0]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        for (char val : matrix[1]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
        for (char val : matrix[2]) {
            std::cout << val << " ";
        }

        // Game end condition

        for (int i = 0; i < 3; ++i) {
            if (matrix[i][0] != '-' && matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) {
                running = false;
            }
            if (matrix[0][i] != '-' && matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
                running = false;
            }
        }
        if (matrix[0][0] != '-' && matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
            running = false;
        }
        if (matrix[0][2] != '-' && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
            running = false;
        }

        std::cout << std::endl;

        std::cout << "Play your move" << std::endl;
        std::cout << "Which row? (1-3): ";
        std::cin >> row;
        std::cout << "\n Which column? (1-3): ";
        std::cin >> column;

        if (row < 1 || row > 3 || column < 1 || column > 3 || matrix[row-1][column-1] != '-') {
        std::cout << "Invalid move. Try again.\n";
        iteration--;
        continue;
        }



        if (iteration % 2 == 1) {
            matrix[row - 1][column - 1] = 'X';
        } else {
            matrix[row - 1][column - 1] = 'O';
        }

        if (iteration == 9) {
            running = false;
        }
            

    }

}
