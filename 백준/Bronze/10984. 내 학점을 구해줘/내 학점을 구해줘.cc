#include <stdio.h>

int main()
{
    int t, n, i, j, c= 0, cr = 0;

	double g = 0.0, gr = 0.0;

	

	scanf("%d", &t);

	

	for(i = 0; i < t; i++){

		

		scanf("%d", &n);

		

		for(j = 0; j < n; j++){

			

			scanf("%d %lf", &c, &g);

			

			cr += c;

			gr += (c * g);

		}

		

		printf("%d %.1lf\n", cr, gr / cr);

		

		cr = 0;

		gr = 0.0;

	}
}