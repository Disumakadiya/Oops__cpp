#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int n;
    string player1Name, player2Name;

    cout << "🎮 Welcome to the Enhanced Lead Game! 🎮\n";
    cout << "Enter name of Player 1: ";
    cin >> player1Name;
    cout << "Enter name of Player 2: ";
    cin >> player2Name;

    cout << "Enter the number of rounds (1 to 1000): ";
    cin >> n;

    if (n <= 0 || n > 1000) {
        cout << "❌ Invalid number of rounds. N must be between 1 and 1000.\n";
        return 1;
    }

    int maxLead = 0, winner = 0;
    int player1Total = 0, player2Total = 0;

    for (int i = 0; i < n; ++i) {
        int p1, p2;

        cout << "\n🔁 Round " << i + 1 << ":\n";
        cout << player1Name << "'s score: ";
        cin >> p1;
        cout << player2Name << "'s score: ";
        cin >> p2;

        // Input validation
        if (p1 < 0 || p2 < 0) {
            cout << "❌ Scores cannot be negative. Please re-enter the round.\n";
            --i; // Repeat this round
            continue;
        }

        player1Total += p1;
        player2Total += p2;

        int currentLead = abs(player1Total - player2Total);

        // Round Leader Info
        if (player1Total > player2Total) {
            cout << "🏁 " << player1Name << " leads by " << currentLead << " points.\n";
        } else if (player2Total > player1Total) {
            cout << "🏁 " << player2Name << " leads by " << currentLead << " points.\n";
        } else {
            cout << "⚖️ It's a tie after round " << i + 1 << "!\n";
        }

        // Visual Bar Graph using *
        cout << "\n📊 Total Scores:\n";
        cout << player1Name << ": " << string(player1Total / 10, '*') << " (" << player1Total << ")\n";
        cout << player2Name << ": " << string(player2Total / 10, '*') << " (" << player2Total << ")\n";

        // Update max lead
        if (currentLead > maxLead) {
            maxLead = currentLead;
            winner = (player1Total > player2Total) ? 1 : 2;
        }
    }

    string winnerName = (winner == 1) ? player1Name : player2Name;

    // Final Result
    cout << "\n\033[1;32m🏆 Final Result:\033[0m\n";
    cout << "🎉 Winner: " << winnerName << endl;
    cout << "🥇 Lead: " << maxLead << " points\n";

    // Save to file
    ofstream fout("lead_game_scoreboard.txt", ios::app);
    fout << "Winner: " << winnerName << " | Lead: " << maxLead << " | Rounds: " << n << endl;
    fout.close();

    cout << "📁 Game result saved to 'lead_game_scoreboard.txt'\n";
    cout << "🕹️ Thank you for playing!\n";

    return 0;
}
