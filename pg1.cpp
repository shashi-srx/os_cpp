#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

int main() {
    int n;
    float x = 0, y = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> p(n), at(n), bt(n), tat(n), wt(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter AT and BT of process " << i << ": ";
        cin >> at[i] >> bt[i];
        p[i] = i;
    }

    // Sorting based on arrival time and burst time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && bt[i] > bt[j])) {
                swap(p[i], p[j]);
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
            }
        }
    }

    cout << "Process order: ";
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        if (wt[i] < at[i]) {
            wt[i] = at[i];
        }
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i] - at[i];
    }

    for (int i = 0; i < n; i++) {
        x += tat[i];
        y += wt[i];
    }

    cout << "Turnaround times: ";
    for (int i = 0; i < n; i++) {
        cout << tat[i] << " ";
    }
    cout << endl;

    cout << "Waiting times: ";
    for (int i = 0; i < n; i++) {
        cout << wt[i] << " ";
    }
    cout << endl;

    cout << "\nAverage WT = " << y / n << " and TAT = " << x / n << endl;

    return 0;
}
