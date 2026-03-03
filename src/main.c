/*
 * Author: Sailaubayev Amir
 *
 * Description: Program to calculate the maximum radius of a circle
 * that can be cut from a rectangle inscribed in a given circle.
 * Based on variant 19: Given outer circle radius r and larger side a,
 * find the maximum circle radius that can be cut from the rectangle.
 */

#include <stdio.h>
#include <math.h>

/*
 * Function: calculate_second_side
 * -------------------------------
 * Calculates the second side of a rectangle inscribed in a circle.
 *   r: radius of the outer circle
 *   a: larger side of the rectangle
 * returns: the second side of the rectangle
 */
double calculate_second_side(double r, double a) {
		double diameter = 2 * r;
		return sqrt(diameter * diameter - a * a);
}

/*
 * Function: find_max_inscribed_circle_radius
 * -------------------------------------------
 * Finds the maximum radius of a circle that can be cut from a rectangle.
 *   a: first side of the rectangle
 *   b: second side of the rectangle
 * returns: half of the smaller side (max inscribed circle radius)
 */
double find_max_inscribed_circle_radius(double a, double b) {
		double min_side = (a < b) ? a : b;
		return min_side / 2.0;
}

int main() {
		double r, a;

		printf("Enter the radius of the outer circle 'r': ");
		if (scanf("%lf", &r) != 1) {
				printf("Input error\n");
				return 1;
		}

		printf("Enter the larger side of rectangle 'a': ");
		if (scanf("%lf", &a) != 1) {
				printf("Input error\n");
				return 1;
		}

		if (r <= 0 || a <= 0) {
				printf("Illegal argument: input values must be positive numbers\n");
				return 1;
		}

		double diameter = 2 * r;
		if (a > diameter) {
				printf("Illegal rectangle side: rectangle side (%.2f) must not be greater than circle diameter (%.2f)\n", a, diameter);
				return 1;
		}

		double b = calculate_second_side(r, a);
		double max_radius = find_max_inscribed_circle_radius(a, b);

		printf("\nResults:\n");
		printf("Outer circle radius: %.2f\n", r);
		printf("Rectangle sides: %.2f x %.2f\n", a, b);
		printf("Maximum circle radius that can be cut from rectangle: %.2f\n", max_radius);

		return 0;
}