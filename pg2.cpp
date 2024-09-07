#include <iostream>
#include <climits>
using namespace std;

struct process {
    int id, at, bt, rt, tat, wt;
};

int main() {
    int n, i, comp = 0, small = 0;  // comp -> completed processes, small -> index of smallest remaining time
    float x = 0, y = 0;             // x -> total TAT, y -> total WT

    cout << "Enter the number of processes: ";
    cin >> n;

    process p[n];

    for (i = 0; i < n; i++) {
        cout << "Enter AT and BT of process " << i << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i;
        p[i].rt = p[i].bt;
    }

    int time = 0;
    small = 0;
    
    while (comp != n) {
        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt && p[small].rt > p[i].rt) {
                small = i;
            }
        }

        cout << "|P" << p[small].id << "| ";
        time += p[small].rt;
        p[small].tat = time - p[small].at;
        p[small].wt = p[small].tat - p[small].bt;
        x += p[small].tat;
        y += p[small].wt;
        p[small].rt = INT_MAX;  // Mark process as completed by setting its remaining time to INT_MAX
        comp++;
    }

    cout << "\npid\tat\tbt\ttat\twt\n";
    for (i = 0; i < n; i++) {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }

    cout << "Avg WT = " << y / n << " and Avg TAT = " << x / n << endl;

    return 0;
}
