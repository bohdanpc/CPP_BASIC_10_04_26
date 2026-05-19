#include <iostream>
#include <algorithm>    //std::sort
#include <functional>   //std::greater<int>()

int main()
{
    //Enter the number of players
    //enter scoreboard 
    //Top 3 -> players, grant them rewards

    unsigned numberOfPlayers = 0;
    std::cout << "Enter number of players: ";
    std::cin >> numberOfPlayers;

    int* scores = new int [numberOfPlayers]{0};

    std::cout << "Enter " << numberOfPlayers << " scores with space\n";

    for (int i = 0; i < numberOfPlayers; i++)
    {
        std::cin >> scores[i];
    }

    std::sort(scores, scores + numberOfPlayers, std::greater<int>());

    std::cout << "Top 3 players with rewards: ";
    const int numberOfRewardedPlayers = 3;
    for (int i = 0; i < numberOfRewardedPlayers; i++)
    {
        std::cout << scores[i] << " ";
    }

    int* bestScoresOnly = new int[numberOfRewardedPlayers];

    for (int i = 0; i < numberOfRewardedPlayers; i++)
    {
        bestScoresOnly[i] = scores[i];
    }

    delete[] scores;    //Free not needed anymore memory on Heap

    return 0;
}
