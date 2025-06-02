#include <stdio.h>
#include <math.h>

int is_triangle(double a, double b, double c);
double get_area(double a, double b, double c);

int main(void) {
    printf("Please input three numbers tp compose triangular: ");
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);
    if(is_triangle(a, b, c)) {
        printf("the area of this triangular is %lf\n", get_area(a, b, c));
    } else {
        printf("Sorry, these three numbers cannot compose a triangular.\n");
    }

    return 0;
}

int is_triangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double get_area(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}