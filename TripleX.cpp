#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    // Print welcome messages to the terminal
    std::cout << "You are a secret agent breaking into a " << Difficulty;
    
    std::cout << " secure server room!!...\nEnter the correct code to continue...";
}


bool PlayGame(int Difficulty) {
    
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
  

    int GuessSum = GuessA + GuessB + GuessC;
    int GeussProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GeussProduct == CodeProduct) {
        std::cout << "You win!";
        return true;
    } else {
        std:: cout << "You lose!";
        return false;
    }
}




int main() {

    srand(time(NULL)); // Create new random sequence based on time of day
    int levelDifficulty = 1;
    int const MaxDifficulty = 5;
    while (levelDifficulty <= MaxDifficulty) {
        
        bool bLevelCompleted = PlayGame(levelDifficulty);
        
        std::cin.clear(); // Clean any error
        std::cin.ignore(); // Discard the buffer

        if (bLevelCompleted) {
            // Increase the level difficulty
            levelDifficulty++;
        }
    }
    
    
    return 0;    
}