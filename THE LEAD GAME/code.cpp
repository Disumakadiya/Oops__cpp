#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout<<"ENTER THE NUMBER  OF ROUNDS IN LEAD GAME:";
    cin >> n;

    if (n <= 0 || n > 1000) {
        cout << "Invalid number of rounds. N must be between 1 and 1000." << endl;
    } else {
        int maxLead = 0, winner = 0;
        int player1Total = 0, player2Total = 0;

        for (int i = 0; i < n; ++i) {
            int p1, p2;
            cin >> p1 >> p2;
            cout<<"the score of player 1::"<<p1<<endl;
            cout<<"the score of player 2::"<<p2<<endl;

            player1Total += p1;
            player2Total += p2;

            int currentLead = abs(player1Total - player2Total);
            if (currentLead > maxLead) {
                maxLead = currentLead;
                winner = (player1Total > player2Total) ? 1 : 2;
            }
        }

        cout <<"The winner among the two player is:player-"<< winner << endl<<"The lead score by which the player is won--" << maxLead << endl;
    }
    
    return 0;
}
