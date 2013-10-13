#include <stdio.h>
#include <math.h>

double average(double ns[], long n)
{
    double sum = ns[0];
    for (long i = 1; i < n; ++i) {
        sum += ns[i];
    }
    return sum / n;
}

double stddev(double ns[], long n)
{
    double avg = average(ns, n);
    double sum = 0;
    for (long i = 0; i < n; ++i) {
        sum += (ns[i] - avg) * (ns[i] - avg);
    }
    return sqrt(sum / n);
}

void minmax(double ns[], long n, double *min, double *max)
{
    *min = *max = ns[0];
    for (long i = 1; i < n; ++i) {
        if (ns[i] < *min) {
            *min = ns[i];
        }
        if (ns[i] > *max) {
            *max = ns[i];
        }
    }
}

int main()
{
    double ns[10000];
    long i = 0;
    while (scanf("%lf", &ns[i]) != EOF) {
        ++i;
    }
    double avg = average(ns, i);
    double st = stddev(ns, i);
    double min, max;
    minmax(ns, i, &min, &max);
    printf("Minimum: %lf\nMaximum: %lf\nAverage: %lf\nStd. Dev.: %lf\n", min, max, avg, st);
    return 0;
}
