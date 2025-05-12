#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

struct Player
{
    string name;
    int totalScore = 0;
    vector<int> roundScores;
};

int main() 
{
    int numPlayers, numRounds;
    vector<Player> players;

    cout << "\n Welcome to the Multi-Player Lead Game! \n";
    cout << "Enter number of players (2 or more):";
    cin >> numPlayers;

    if (numPlayers < 2)
    {
        cout << "At least 2 players required to play the game.\n";
        return 1;
    }

    players.resize(numPlayers);

    for (int i = 0; i < numPlayers; ++i) 
    {
        cout << "Enter name of Player " << i + 1 << ": ";
        cin >> players[i].name;
        players[i].roundScores.resize(0); // Clear previous scores if any
    }

    cout << "Enter number of rounds (1 to 1000): ";
    cin >> numRounds;

    if (numRounds <= 0 || numRounds > 1000) 
    {
        cout << "Invalid number of rounds.\n";
        return 1;
    }

    // Open file to write logs
    ofstream fout("lead_game_scoreboard.txt", ios::app);
    fout << "\n=== New Match ===\n";
    fout << "Players: ";
    for (auto& p : players) fout << p.name << " ";
    fout << "\nRounds: " << numRounds << "\n";

    // Start game
    for (int round = 0; round < numRounds; ++round)
    {
        cout << "\n===== Round " << round + 1 << "=====\n";
        fout << "\nRound " << round + 1 << ":\n";

        for (int i = 0; i < numPlayers; ++i) 
        {
            int score;
            cout << players[i].name << "'s score: ";
            cin >> score;

            if (score < 0) 
            {
                cout << "Score cannot be negative. Please re-enter.\n";
                --i; // repeat for same player
                continue;
            }

            players[i].totalScore += score;
            
            players[i].roundScores.push_back(score);
            fout << players[i].name << ": " << score << "\n";
        }

        // Find round leader
        int maxScore = -1;
        string roundLeader;
        for (const auto& p : players) 
        {
            if (p.totalScore > maxScore) 
            {
                maxScore = p.totalScore;
                roundLeader = p.name;
            }
        }
        cout << "\n Leader after Round " << round + 1 << ": " << roundLeader << " with " << maxScore << " points.\n";

        // Show bar chart
        cout << "\nScores Bar Graph:\n";
        for (const auto& p : players)
        {
            cout << p.name << ": " << string(p.totalScore / 10, '*') << " (" << p.totalScore << ")\n";
        }
    }

    // Find final winner
    int maxTotal = -1;
    string finalWinner;
    for (const auto& p : players) 
    {
        if (p.totalScore > maxTotal) 
        {
            maxTotal = p.totalScore;
            finalWinner = p.name;
        }
    }

    // Display final results
    cout << "\n Final Result:\n";
    cout << "\n" << left << setw(15) << "Player" << setw(10) << "Score" << endl;
    cout << "-------------------------\n";
    for (const auto& p : players)
    {
        cout << left << setw(15) << p.name << setw(10) << p.totalScore << endl;
    }
    cout << "\n🎉 Winner: " << finalWinner << " with " << maxTotal << " points!\n";

    // Final log to file
    fout << "\nFinal Scores:\n";
    fout << left << setw(15) << "Player" << setw(10) << "Total" << " | Round-wise Scores\n";
    fout << "--------------------------------------------------\n";
    for (const auto& p : players)
    {
        fout << left << setw(15) << p.name << setw(10) << p.totalScore << " | ";
        for (int s : p.roundScores) fout << s << " ";
        fout << "\n";
    }
    fout << "Winner: " << finalWinner << "\n";
    fout.close();

    cout << "\nFull round-wise result saved to 'lead_game_scoreboard.txt'\n";
    cout << "\nThank you for playing!\n";
    return 0;
}
