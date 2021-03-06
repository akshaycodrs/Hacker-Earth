#include <cstdio>
#include <vector>
using namespace std;

void precompute(vector <int> &largest_prime_factor, int LIMIT)
{
    for(int i = 2; i < LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int multiple = i; multiple < LIMIT; multiple += i)
                largest_prime_factor[multiple] = i;
        }
    }
}

void solve(vector <int> &largest_prime_factor, int MAX_STONES)
{
    vector <int> power_of(MAX_STONES, 0);

    int no_of_piles;
    scanf("%d", &no_of_piles);

    while(no_of_piles--)
    {
        int pile_i;
        scanf("%d", &pile_i);

        while(pile_i > 1)
        {
            power_of[largest_prime_factor[pile_i]]++;
            pile_i /= largest_prime_factor[pile_i];
        }
    }

    int total_nim_sum = 0;
    for(int i = 1; i < MAX_STONES; i++)
        total_nim_sum ^= power_of[i];

    printf(total_nim_sum == 0 ? "Liverbird\n" : "Mancunian\n");
}

int main()
{
    const int MAX_STONES = 1e6 + 1;
    vector <int> largest_prime_factor(MAX_STONES, 0);
    precompute(largest_prime_factor, MAX_STONES);

    int no_of_games;
    scanf("%d", &no_of_games);

    while(no_of_games--)
        solve(largest_prime_factor, MAX_STONES);

    return 0;
}

