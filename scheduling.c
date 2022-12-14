#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 500
int p[MAX], a[MAX], b[MAX], w[MAX], ta[MAX], prior[MAX], re[MAX], t1, quant;

int initialize();

int main()
{
    printf("\n\n///////////////////////// FCFS ////////////////////////////\n\n");
    fcfs();
    printf("\n\n///////////////////////// SJF NON PREEMPTİVE ////////////////////////////\n\n");
    sjfNon();
    printf("\n\n///////////////////////// SJF PREEMPTİVE ////////////////////////////\n\n");
    sjfPre();
    printf("\n\n///////////////////////// ROUND ROBİN ////////////////////////////\n\n");
    roundRobin();
    printf("\n\n///////////////////////// PRIORİTY ////////////////////////////\n\n");
    Priority();
}

int fcfs()
{
    initialize();

    int n, avwt = 0, avtat = 0, i, j, pos, max, temp, sum = 0;
    n = t1;
    // Taking the Input from the User
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }

    // Sorting all the Processes according to their Arrival Time

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[pos])
            {
                pos = j;
            }
        }

        temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;

        temp = b[i];
        b[i] = b[pos];
        b[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    w[0] = 0;
    // Calculating Waiting and Response Time
    for (i = 1; i < n; i++)
    {
        sum = sum + b[i - 1];
        w[i] = sum - a[i];
        if (w[i] < 0)
            w[i] = 0;
        re[i] = w[i];
    }

    printf("\nProcess\t\tArrival Time\tBurst Time\tResponse Time\tWaiting Time\tTurnaround Time");

    // Calculating Turn Around Time and Printing the Table
    for (i = 0; i < n; i++)
    {
        ta[i] = b[i] + w[i];
        avwt += w[i];
        avtat += ta[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], a[i], b[i], re[i], w[i], ta[i]);
    }

    avwt /= i;
    avtat /= i;
    printf("\n\nAverage Waiting Time:%d", avwt);
    printf("\nAverage Turnaround Time:%d\n\n", avtat);

    return 0;
}

int sjfPre()
{
    initialize();
    int i, j, n, total = 0, pos, temp;
    float avg_waiting_time, avg_tat;

    n = t1;
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    // from here, burst times sorted
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (b[j] < b[pos])
                pos = j;
        }
        temp = b[i];
        b[i] = b[pos];
        b[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    w[0] = 0;
    for (i = 1; i < n; i++)
    {
        w[i] = 0;
        for (j = 0; j < i; j++)
            w[i] += b[j];
        total += w[i];
    }
    avg_waiting_time = (float)total / n;
    total = 0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        ta[i] = b[i] + w[i];
        total += ta[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d", p[i], b[i], w[i], ta[i]);
    }
    avg_tat = (float)total / n;
    printf("\n\n the average Waiting Time=%f", avg_waiting_time);
    printf("\n  the average Turnaround Time=%f\n", avg_tat);
}

int sjfNon()
{
    initialize();

    int pr[10];
    int n, i, j, temp, time = 0, count, over = 0, sum_wait = 0, sum_turnaround = 0, start;
    float avgwait, avgturn;
    n = t1;
    for (i = 0; i < n; i++)
    {
        pr[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
            }
        }
    }
    printf("\n\nProcess\t|Arrival time\t|Burst time\t|Response time\t|Waiting time\t|Turnaround time\n\n");
    while (over < n)
    {
        count = 0;
        for (i = over; i < n; i++)
        {
            if (a[i] <= time)
                count++;
            else
                break;
        }
        if (count > 1)
        {
            for (i = over; i < over + count - 1; i++)
            {
                for (j = i + 1; j < over + count; j++)
                {
                    if (b[i] > b[j])
                    {
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                        temp = b[i];
                        b[i] = b[j];
                        b[j] = temp;
                        temp = pr[i];
                        pr[i] = pr[j];
                        pr[j] = temp;
                    }
                }
            }
        }
        start = time;
        time += b[over];
        printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", pr[over],
               a[over], b[over], time, time - a[over] - b[over], time - a[over]);
        sum_wait += time - a[over] - b[over];

        sum_turnaround += time - a[over];
        over++;
    }
    avgwait = (float)sum_wait / (float)n;
    avgturn = (float)sum_turnaround / (float)n;
    printf("Average waiting time is %f\n", avgwait);
    printf("Average turnaround time is %f\n", avgturn);
    return 0;
}

int roundRobin()
{
    initialize();

    int i, j, n, time, remain, flag = 0, ts;
    int sum_wait = 0, sum_turnaround = 0, rt[10];
    n = t1;
    remain = n;
    for (i = 0; i < n; i++)
    {
        rt[i] = b[i];
    }
    ts = quant;
    printf("\n\nProcess\t|Arrival time|Burst time|Turnaround time|Waiting time|Response Time \n\n");
    for (time = 0, i = 0; remain != 0;)
    {
        if (rt[i] <= ts && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if (rt[i] > 0)
        {
            rt[i] -= ts;
            time += ts;
        }
        if (rt[i] == 0 && flag == 1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d|\t%d|\t%d|\t%d\n", i + 1, a[i], b[i], time - a[i], time - a[i] - b[i], rt[i]);
            sum_wait += time - a[i] - b[i];
            sum_turnaround += time - a[i];
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (a[i + 1] <= time)
            i++;
        else
            i = 0;
    }
    printf("\nAvg sum_wait = %f\n", sum_wait * 1.0 / n);
    printf("Avg sum_turnaround = %f\n", sum_turnaround * 1.0 / n);
    return 0;
}

int Priority()
{
    initialize();
    int n, i, j, temp, st[10], ft[10], wt[10], ta[10];
    int totwt = 0, totta = 0;
    float awt, ata;
    char pn[10][10], t[10];

    n = t1;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (prior[i] < prior[j])
            {
                temp = prior[i];
                prior[i] = prior[j];
                prior[j] = temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
                strcpy(t, pn[i]);
                strcpy(pn[i], pn[j]);
                strcpy(pn[j], t);
            }
        }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st[i] = a[i];
            wt[i] = st[i] - a[i];
            ft[i] = st[i] + b[i];
            ta[i] = ft[i] - a[i];
        }
        else
        {
            st[i] = ft[i - 1];
            wt[i] = st[i] - a[i];
            ft[i] = st[i] + b[i];
            ta[i] = ft[i] - a[i];
        }
        totwt += wt[i];
        totta += ta[i];
    }
    awt = (float)totwt / n;

    ata = (float)totta / n;
    printf("\nPname\tarrivaltime\tBurst Time\tpriority\twaitingtime\tTurnaround Time\tFinish Time");
    for (i = 0; i < n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d", pn[i], a[i], b[i], prior[i], wt[i], ta[i], ft[i]);
    printf("\nAverage waiting time is:%f", awt);
    printf("\nAverage turnaroundtime is:%f\n", ata);
}

int initialize()
{
    FILE *sf;              // Satır File
    FILE *fp;              // Dosyayı istenilen yerlere atama
    int n1, n2, n3, n = 0; // n1 = b time// n2 = a time // n3 = priority time
    int q, c = 0;          // a= quantum number c= contex switch
    int satir = 0;         // satır sayısını belirlemek için
    char ch;
    int z, k = 0; // k = satır sayısı

    sf = fopen("data.txt", "r");

    while (feof(sf) == NULL)
    {
        ch = getc(sf);
        if (ch == '\n')
        {
            k++;
        }
        z++;
    }
    k = k + 1;
    fclose(sf);

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    else
    {
        fscanf(fp, "%d\n", &q); // time quant
        printf("%d\n", q);
        quant = q;
        fscanf(fp, "%d\n", &c); // contex switch
        printf("%d\n", c);
    }

    for (int i = 0; i < k - 2; i++)
    {
        fscanf(fp, "%d,%d,%d,%d,\n", &n, &n1, &n2, &n3);
        p[i] = n;
        a[i] = n1;
        b[i] = n2;
        prior[i] = n3;
        printf("%d,%d,%d,%d\n", n, n1, n2, n3);
    }

    t1 = k - 2;

    fclose(fp);
    return 0;
}