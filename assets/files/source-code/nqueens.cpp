#include <bits/stdc++.h>

using namespace std;

void print_board(vector<int> q) {
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == q[i]) {
                printf("Q ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void place_queen(vector<int> &q, int row, int n, int &n_sol) {
    if (row == n) {
        ++n_sol;
        print_board(q);
        return;
    }

    for (int j = 0; j < n; j++) {
        bool legal = true;
        for (int i = 0; i < row; ++i) {
            if (q[i] == j || q[i] == j + row - i || q[i] == j - row + i )
                legal = false;
        }
        if (legal) {
            q[row] = j;
            place_queen(q, row + 1, n, n_sol);
        }
    }

}

int main () {
    int n;
    cin >> n;

    // solution is an array q of size n where q[i] = position of a queen in the row i of the grid
    // we better initialize q with -1;

    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        q[i] = -1;
    }

    // We place the queens one row at a time starting from the top
    // To place the rth queen, we loop over the n cases of the rth row
    // if any case is attacked by an erlier queen, we ignore it;
    // otherwise we tentatively place a queen on that place and recursively grope for consistent placements of the queens in later row;

    int n_sol = 0;
    place_queen(q, 0, n, n_sol);

    cout << "There are " << n_sol << " solutions\n";


    return 0;

}
