#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265

int main() {
	int ch;

	while (1) {
		printf("\n\n\t\tEFFICIENT CALCULATOR..!");
		printf("\n\n\t\t\tMENU\n");
		printf("\n\t\t1. Simple arithmetic operations (+,-,*,/,%%)");
		printf("\n\t\t2. Matrix addition");
		printf("\n\t\t3. Matrix multiplication");
		printf("\n\t\t4. Matrix transpose");
		printf("\n\t\t5. Matrix symitric check");
		printf("\n\t\t6. Trignometric operations");
		printf("\n\t\t7. Cgpa calculator");
		printf("\n\t\t8. Algibraic equation solver");
		printf("\n\t\t9. Table(Addition,Subtraction,multiplication,Division)");
		printf("\n\t\t10. Exit");
		printf("\n\nSelect any option to perform operation..\n");
		printf("\n\nEnter your choice (1-10): ");
		scanf("%d", &ch);

		if (ch == 1) {
			int op, i, n, y, a, b;
			int sum = 0, sub = 0, mul = 1, div = 0;
			int nums[100];

			do {
				printf("\n-----ARITHMETIC OPERATIONS-----");
				printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulo\n");
				printf("Enter your choice: ");
				scanf("%d", &op);

				if (op >= 1 && op <= 4) {
					printf("How many numbers? ");
					scanf("%d", &n);
					for (i = 0; i < n; i++) {
						printf("Enter number %d: ", i + 1);
						scanf("%d", &nums[i]);
					}

					if (op == 1) {
						for (i = 0; i < n; i++) sum += nums[i];
						printf("Sum = %d\n", sum);
					} else if (op == 2) {
						sub = nums[0];
						for (i = 1; i < n; i++) sub -= nums[i];
						printf("Subtraction = %d\n", sub);
					} else if (op == 3) {
						for (i = 0; i < n; i++) mul *= nums[i];
						printf("Multiplication = %d\n", mul);
					} else if (op == 4) {
						div = nums[0];
						for (i = 1; i < n; i++) {
							if (nums[i] == 0) {
								printf("Error: Division by zero!\n");
								goto end_arith;
							}
							div /= nums[i];
						}
						printf("Division = %d\n", div);
					}
				} else if (op == 5) {
					printf("Enter two numbers: ");
					scanf("%d%d", &a, &b);
					if (b != 0)
						printf("Modulo = %d\n", a % b);
					else
						printf("Error: Modulo by zero!\n");
				} else {
					printf("Invalid choice!\n");
				}

				printf("\nDo you want to perform another arithmetic operation? (1 = Yes): ");
				scanf("%d", &y);
			} while (y == 1);
end_arith:
			;

		} else if (ch == 2) {
			int a[100][100], b[100][100], c[100][100];
			int i, j, m, n;
			printf("-----MATRIX ADDITION-----\n");
			printf("Enter rows: ");
			scanf("%d", &n);
			printf("Enter columns: ");
			scanf("%d", &m);

			printf("Enter elements of Matrix A:\n");
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
				     scanf("%d", &a[i][j]);
    
			printf("Enter elements of Matrix B:\n");
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
                     scanf("%d", &b[i][j]);
 

			printf("---Result Matrix:---\n");
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					c[i][j] = a[i][j] + b[i][j];
					printf("%d\t", c[i][j]);
				}
				printf("\n");
			}

		} else if (ch == 3) {
			int a[100][100], b[100][100], c[100][100];
			int i, j, k, r1, c1, r2, c2;
			printf("-----MATRIX MULTIPLICATION-----\n");
			printf("Enter rows and columns for Matrix A:\n ");
			scanf("%d%d", &r1, &c1);
			printf("Enter rows and columns for Matrix B:\n ");
			scanf("%d%d", &r2, &c2);

			if (c1 != r2) {
				printf("Matrix multiplication not possible!\n");
				continue;
			}

			printf("Enter elements for Matrix A:\n");
			for (i = 0; i < r1; i++)
				for (j = 0; j < c1; j++)
					scanf("%d", &a[i][j]);

			printf("Enter elements for Matrix B:\n");
			for (i = 0; i < r2; i++)
				for (j = 0; j < c2; j++)
					scanf("%d", &b[i][j]);

			for (i = 0; i < r1; i++)
				for (j = 0; j < c2; j++) {
					c[i][j] = 0;
					for (k = 0; k < c1; k++)
						c[i][j] += a[i][k] * b[k][j];
				}

			printf("---Result Matrix:---\n");
			for (i = 0; i < r1; i++) {
				for (j = 0; j < c2; j++)
					printf("%d\t", c[i][j]);
				printf("\n");
			}

		} else if (ch == 4) {
			int mat[10][10], trans[10][10], row, col, i, j;
			printf("-----MATRIX TRANSPOSE-----\n");
			printf("Enter rows and columns: ");
			scanf("%d%d", &row, &col);

			printf("Enter elements of the matrix:\n");
			for (i = 0; i < row; i++)
				for (j = 0; j < col; j++)
					scanf("%d", &mat[i][j]);
 
			for (i = 0; i < row; i++)
				for (j = 0; j < col; j++)
					trans[j][i] = mat[i][j];

			printf("---Transpose:---\n");
			for (i = 0; i < col; i++) {
				for (j = 0; j < row; j++)
					printf("%d\t", trans[i][j]);
				printf("\n");
			}

		} else if (ch == 5) {
			int mat[10][10], n, i, j, isSym = 1;
			printf("---CHECK FOR SYMMETRIC MATRIX---\n");
			printf("Enter order of square matrix: ");
			scanf("%d ", &n);

			printf("Enter elements:\n");
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					scanf("%d ", &mat[i][j]);

			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (mat[i][j] != mat[j][i]) {
						isSym = 0;
						break;
					}
				}
			}

			if (isSym)
				printf("Matrix is Symmetric.\n");
			else
				printf("Matrix is not Symmetric.\n");

		} else if (ch == 6) {
			int choice;
			double angle_deg, angle_rad, result;
			char cont;
			do {
				printf("\n--- TRIGONOMETRIC CALCULATOR ---\n");
				printf("1. Sine\n2. Cosine\n3. Tangent\n4. Cosecant\n5. Secant\n6. Cotangent\n");
				printf("Enter your choice: ");
				scanf("%d", &choice);
				printf("Enter angle in degrees: ");
				scanf("%lf", &angle_deg);
				angle_rad = angle_deg * (PI / 180.0);

				switch (choice) {
					case 1:
						result = sin(angle_rad);
						printf("sin(%.2lf) = %.4lf\n", angle_deg, result);
						break;
					case 2:
						result = cos(angle_rad);
						printf("cos(%.2lf) = %.4lf\n", angle_deg, result);
						break;
					case 3:
						if ((int)angle_deg % 180 == 90) printf("tan undefined\n");
						else {
							result = tan(angle_rad);
							printf("tan(%.2lf) = %.4lf\n", angle_deg, result);
						}
						break;
					case 4:
						if (sin(angle_rad) == 0) printf("cosec undefined\n");
						else {
							result = 1.0 / sin(angle_rad);
							printf("cosec(%.2lf) = %.4lf\n", angle_deg, result);
						}
						break;
					case 5:
						if (cos(angle_rad) == 0) printf("sec undefined\n");
						else {
							result = 1.0 / cos(angle_rad);
							printf("sec(%.2lf) = %.4lf\n", angle_deg, result);
						}
						break;
					case 6:
						if (tan(angle_rad) == 0) printf("cot undefined\n");
						else {
							result = 1.0 / tan(angle_rad);
							printf("cot(%.2lf) = %.4lf\n", angle_deg, result);
						}
						break;
					default:
						printf("Invalid choice!\n");
				}
				printf("\nDo another trig operation? (y/n): ");
				scanf(" %c", &cont);
			} while (cont == 'y' || cont == 'Y');

		} else if (ch == 7) {
			int semesters, subjects, i, j;
			float grades[10][20], credits[10][20], total_points = 0, total_credits = 0, cgpa;
			printf("CGPA CALCULATOR\n");
			printf("Enter number of semesters: ");
			scanf("%d", &semesters);

			for (i = 0; i < semesters; i++) {
				printf("Enter number of subjects for semester %d: ", i + 1);
				scanf("%d", &subjects);
				for (j = 0; j < subjects; j++) {
					printf("Subject %d - Grade: ", j + 1);
					scanf("%f", &grades[i][j]);
					printf("Subject %d - Credits: ", j + 1);
					scanf("%f", &credits[i][j]);
					total_points += grades[i][j] * credits[i][j];
					total_credits += credits[i][j];
				}
			}

			if (total_credits > 0) {
				cgpa = total_points / total_credits;
				printf("CGPA = %.2f\n", cgpa);
			} else {
				printf("Invalid credit values entered.\n");
			}

		}
		 else if (ch==8){
		 	 int choice;
             double a, b, c, d, r1, r2;
             char cont;

        do {
             printf("\n--- EQUATION SOLVER ---\n");
             printf("1. Solve Quadratic Equation (ax^2 + bx + c = 0)\n");
             printf("2. Solve Cubic Equation (ax^3 + bx^2 + cx + d = 0)\n");
             printf("Enter your choice (1 or 2): ");
             scanf("%d", &choice);

            if (choice == 1) {
                 printf("Enter coefficients a, b, c: ");
                 scanf("%lf%lf%lf", &a, &b, &c);

                 double discriminant = b * b - 4 * a * c;

                if (discriminant > 0) {
                     r1 = (-b + sqrt(discriminant)) / (2 * a);
                     r2 = (-b - sqrt(discriminant)) / (2 * a);
                     printf("Real and distinct roots: %.2lf , %.2lf\n", r1, r2);
                } else if (discriminant == 0) {
                     r1 = -b / (2 * a);
                     printf("Real and equal roots: %.2lf\n", r1);
                } else {
                     double real = -b / (2 * a);
                     double imag = sqrt(-discriminant) / (2 * a);
                     printf("Complex roots: %.2lf + %.2lfi , %.2lf - %.2lfi\n", real, imag, real, imag);
                }
            } else if (choice == 2) {
                 printf("Enter coefficients a, b, c, d: ");
                 scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

                 double f = ((3.0 * c / a) - ((b * b) / (a * a))) / 3.0;
                 double g = ((2.0 * b * b * b) / (a * a * a) - (9.0 * b * c) / (a * a) + (27.0 * d / a)) / 27.0;
                 double h = (g * g / 4.0) + (f * f * f / 27.0);

                if (h > 0) {
                     double r = -g / 2.0 + sqrt(h);
                     double s = cbrt(r);
                     double t = -g / 2.0 - sqrt(h);
                     double u = cbrt(t);
                     double root1 = (s + u) - (b / (3.0 * a));
                     printf("One real root: %.2lf\n", root1);
                } else if (f == 0 && g == 0 && h == 0) {
                     double root = -cbrt(d / a);
                      printf("Triple real root: %.2lf\n", root);
                } else {
                     double i = sqrt((g * g / 4.0) - h);
                     double j = cbrt(i);
                     double k = acos(-g / (2.0 * i));
                     double m = cos(k / 3.0);
                     double n = sqrt(3) * sin(k / 3.0);
                     double p = -b / (3.0 * a);
                     double root1 = 2 * j * m + p;
                     double root2 = -j * (m + n) + p;
                     double root3 = -j * (m - n) + p;
                     printf("Three real roots:\n");
                     printf("x1 = %.2lf\n", root1);
                     printf("x2 = %.2lf\n", root2);
                     printf("x3 = %.2lf\n", root3);
                } 
            } else {
                 printf("Invalid choice!\n");
            }

             printf("\nDo you want to solve another equation? (y/n): ");
             scanf(" %c", &cont);

            } while (cont == 'y' || cont == 'Y');
        }
        else if(ch==9){
        	int ch1,n1;
        	printf("\n\t\t1.Table of sum");
        	printf("\n\t\t2.Table of sub");
        	printf("\n\t\t3.Table of mul");
        	printf("\n\t\t4.Table of div");
        	printf("\n");
        	printf("\n\t\t Press 1 for sum");
        	printf("\n\t\t Press 2 for sub");
        	printf("\n\t\t Press 3 for mul");
        	printf("\n\t\t Press 4 for div");
        	printf("\n\t\tEnter your choice:");
        	scanf("%d",&ch1);
        	switch(ch1){
        		int i;
        		case 1:
        			printf("\n\tTable of sum:");
        			printf("\n\tEnter number for table of sum : ");
        			scanf("%d",&n1);
        			for(i=1;i<=20;i++)
        			{
        				printf("\n\t %d%s%d%s%d",i,"+",n1,"=",i+n1);
					}
					break;
				case 2:
        			printf("\n\tTable of sub:");
        			printf("\n\tEnter number for table of sub : ");
        			scanf("%d",&n1);
        			for(i=1;i<=20;i++)
        			{
        				printf("\n\t %d%s%d%s%d",i,"-",n1,"=",i-n1);
					}
					break;
				case 3:
					printf("\n\tTable of mul:");
        			printf("\n\tEnter number for table of mul : ");
        			scanf("%d",&n1);
        			for(i=1;i<=20;i++)
        			{
        				printf("\n\t %d%s%d%s%d",i,"*",n1,"=",i*n1);
					}
					break;
				case 4:
					printf("\n\tTable of div:");
        			printf("\n\tEnter number for table of div : ");
        			scanf("%d",&n1);
        			for(i=1;i<=20;i++)
        			{
        				printf("\n\t %d%s%d%s%d",i,"/",n1,"=",i/n1);
					}
					break;				
			}
		}
		else if (ch == 10) {
			 printf("Exiting calculator. Thank you!\n");
		 	 break;
		} else {
			printf("Invalid choice. Try again.\n");
		}
	}

	return 0;
}


