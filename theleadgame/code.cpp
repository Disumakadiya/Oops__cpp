#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "ENTER THE NUMBER  OF ROUNDS IN LEAD GAME:";
    cin >> n;
    {
        int maxLead = 0, winner = 0;
        int player1Total = 0, player2Total = 0;

        for (int i = 1; i <= n; ++i)
        {
            int s1, s2;
            cout << "ENTER THE SCORE OF " << i << " ROUND:" << endl;
            cin >> s1 >> s2;
            cout << "the score of player 1::" << s1 << endl;
            cout << "the score of player 2::" << s2 << endl;

            player1Total += s1;
            player2Total += s2;

            int lead = player1Total - player2Total;
            int absLead = abs(lead);

            if (absLead > maxLead)
            {
                maxLead = absLead;
                winner = (lead > 0) ? 1 : 2;
            }
        }
        cout << "*****THE FINAL RESULT******" << endl;
        cout << "The winner among the two player is:player-" << winner << endl
             << "The lead score by which the player is won--" << maxLead << endl;
    }

    return 0;
}
