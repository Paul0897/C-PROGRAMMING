#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is a perfect square
int isPerfectSquare(double num) {
    double sqrtNum = sqrt(num);
    return (sqrtNum == (int)sqrtNum);
}

int main() {
    double a, b, c, discriminant, root1, root2;

    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Check if it's a quadratic equation
    if (a == 0) {
        printf("Not a quadratic equation.\n");
        return 0;
    }

    discriminant = b * b - 4 * a * c;

    // Check for perfect square discriminant
    if (discriminant >= 0 && isPerfectSquare(discriminant)) {
        // Calculate real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);

        // Print roots rounded to integers if necessary
        printf("Roots are real and integers.\n");
        printf("Root 1 = %.0lf\n", root1);
        printf("Root 2 = %.0lf\n", root2);
    } else if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real but not guaranteed to be integers.\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and same.\n");
        printf("Root = %.2lf\n", root1);
    } else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and different.\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imagPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imagPart);
    }

    return 0;
}
