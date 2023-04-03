#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <N>\n";
        return 1;
    }
    int n = atoi(argv[1]);
    if (n < 1 || n > 999) {
        cerr << "N should be between 1 and 999\n";
        return 1;
    }

    vector<pair<int, int>> combinations;

    // loop through all possible values of X and Y
    for (int x = 0; x <= n; x++) {
        int y = n - x;
        combinations.emplace_back(x, y);
    }

    // sort combinations by X
    sort(combinations.begin(), combinations.end());

    // print all combinations
    for (const auto& p : combinations) {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }

    // print the maximum value of X*Y
    cout << combinations.back().first * combinations.back().second << endl;

    return 0;
}