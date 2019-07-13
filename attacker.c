#include <math.h>
#include <stdio.h>

double probability(double q, int z)
{
        double p = 1 - q;
        double lambda = z * (p / q);
        double sum = 1;
        int i;

        for (int k = 0; k <= z; k++) {
                double poisson = exp(-lambda);
                for (i = 1; i <= k; i++)
                        poisson *= lambda / i;
                sum -= poisson * (1 - pow(q / p, z - k));
        }
        return sum;
}

int main()
{
        for (int i = 0; i < 10; i++) {
                double P = probability(Q, i);
                printf("[%d] %f\n", i, P);
        }
}
