#include <stdio.h>
#include <math.h>

// Function f(x) = x^2 - 3x + 7
double f(double x) {
    return x*x - 3*x + 7;
}

int main() {
    int n;
    double result = 0.0;

    // Gauss-Legendre weights & nodes
    double w1 = 2.0, x1 = 0.0;

    double w2[2] = {1.0, 1.0};
    double x2[2] = {-0.57735, 0.57735};

    double w3[3] = {0.55556, 0.88889, 0.55556};
    double x3[3] = {-0.77460, 0.0, 0.77460};

    printf("Enter order of Gauss Quadrature (1, 2, or 3): ");
    scanf("%d", &n);

    if (n == 1) {
        result = w1 * f(x1);
    } 
    else if (n == 2) {
        for (int i = 0; i < 2; i++) {
            result += w2[i] * f(x2[i]);
        }
    } 
    else if (n == 3) {
        for (int i = 0; i < 3; i++) {
            result += w3[i] * f(x3[i]);
        }
    } 
    else {
        printf("Invalid input! Only n=1,2,3 supported.\n");
        return 1;
    }

    printf("Approximate integral = %.6lf\n", result);
    return 0;
}
