#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

// вариант 2 в методичке лабы 8

double f(double x) {
	return pow(x, 2) - pow(cos(M_PI * x), 2);
}

int main() {
	setlocale(LC_ALL, ".UTF8");

	double a[100];
	double x = 1.0, step = 0.02;
	double s_pol = 0, s_otr = 0, sr = 0;
	int c_pol = 0, c_otr = 0;

	for (int i = 0; i < 100; i++) {
		a[i] = f(x);
		x += step;
		if (a[i] > 0) { 
			s_pol += a[i]; 
			c_pol++; 
		}
		if (a[i] < 0) { 
			s_otr += a[i]; 
			c_otr++; 
		}
	}

	if (c_pol > 0) sr = s_pol / c_pol;

	printf("массив a | сумма полож = %lf, сумма отриц = %lf |\n         | кол-во полож = %d, кол-во отриц = %d              |\n         | среднее полож = %lf                         |\n",
		s_pol, s_otr, c_pol, c_otr, sr);

	return 0;
}