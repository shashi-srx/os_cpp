#include <iostream>
#include <climits>
using namespace std;

struct process {
    int id, at, bt, tat, wt, x, rt, res;
};

int main() {
    int n, comp = 0, tq, i, small, sat;
    float x = 0, y = 0;

    cout << "Enter No of processes and Time Quantum = ";
    cin >> n >> tq;

    process p[n];
    for (i = 0; i < n; i++) {
        cout << "Enter AT and BT of process " << i << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i;
        p[i].x = p[i].at;
        p[i].rt = p[i].bt;
        p[i].res = -1;
    }

    // Sorting processes based on arrival time using bubble sort
    for (int j = n - 2; j >= 0; j--) {
        for (i = 0; i <= j; i++) {
            if (p[i].at > p[i + 1].at) {
                process temp = p[i];
                p[i] = p[i + 1];
                p[i + 1] = temp;
            }
        }
    }

    small = 0;
    sat = small;
    int time = 0;
    
    while (comp != n) {
        int m;
        for (i = 0; i < n; i++) {
            if (p[i].x <= time && p[i].rt && p[small].x > p[i].x) {
                small = i;
            }
        }

        if (p[small].res < 0) {
            p[small].res = time - p[small].at;
        }

        if (p[small].rt >= tq) {
            m = tq;
        } else {
            m = p[small].rt;
        }

        p[small].rt -= m;
        time += m;

        for (i = 0; i < n; i++) {
            if (p[i].x <= time && p[i].rt && p[sat].x < p[i].x) {
                sat = i;
            }
        }

        if (sat != small) {
            p[small].x = p[sat].x + 1;
        }

        cout << "|P" << p[small].id << "| ";

        if (p[small].rt == 0) {
            comp++;
            p[small].tat = time - p[small].at;
            p[small].wt = p[small].tat - p[small].bt;
            x += p[small].tat;
            y += p[small].wt;
            p[small].x = INT_MAX;
        }
    }

    cout << "\npid\tat\tbt\ttat\twt\trt\n";
    for (i = 0; i < n; i++) {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].res << "\n";
    }

    cout << "Avg WT = " << y / n << " and Avg TAT = " << x / n << endl;

    return 0;
}
