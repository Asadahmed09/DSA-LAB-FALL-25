#include <iostream>
#include <cstring>
using namespace std;
int idq[200];
int pq[200];
int qf = 0;
int qr = -1;

int stid[200];
int stp = -1;

bool isQEmpty()
{
    return qr < qf;
}

bool isQFull()
{
    return qr - qf + 1 >= 200;
}

void qEnq(int id, int pr)
{
    if (isQFull()) return;
    qr++;
    idq[qr] = id;
    pq[qr] = pr;
}

int qDeqId()
{
    if (isQEmpty()) return -1;
    int v = idq[qf];
    qf++;
    return v;
}

int qDeqPr()
{
    if (isQEmpty()) return -1;
    int v = pq[qf];
    qf++;
    return v;
}

void sPush(int id)
{
    stid[++stp] = id;
}

int sPop()
{
    if (stp == -1) return -1;
    return stid[stp--];
}

void schedule()
{
    int tmpid[200];
    int tmppr[200];
    int tcnt = 0;
    while (!isQEmpty())
    {
        int id = qDeqId();
        int pr = qDeqPr();
        if (pr >= 5)
        {
            sPush(id);
        }
        else
        {
            tmpid[tcnt] = id;
            tmppr[tcnt] = pr;
            tcnt++;
        }
    }
    for (int i = 0; i < tcnt; i++)
    {
        qEnq(tmpid[i], tmppr[i]);
    }
    while (stp != -1)
    {
        int x = sPop();
        cout << "Executing high-priority process " << x << " (from stack)\n";
    }
    while (!isQEmpty())
    {
        int x = qDeqId();
        cout << "Executing normal process " << x << " (from queue)\n";
    }
}

int main()
{
    qEnq(1, 3);
    qEnq(2, 7);
    qEnq(3, 4);
    qEnq(4, 9);
    qEnq(5, 2);
    cout << "Arrival order (id:priority):";
    cout << endl;
    for (int i = qf; i <= qr; i++) cout << idq[i] << ":" << pq[i] << " " << endl;
    cout << "Scheduling and execution:\n";
    schedule();
}
