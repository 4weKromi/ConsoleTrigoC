
#include <math.h>
#include <stdlib.h>
#include "mainhead.h"

const double PI = 3.14159265;

int take_input()
{
	char tri_var;
	int deg_symbol=167;
	float x_degr, y_degr, x_rads, y_rads, res_rads, res_degr;
	float side_ab, side_bc, side_ac;
	int deg_flag = 0, a_flag, b_flag, c_flag;
	while (1)
	{
		printf("\n Enter variable ( A, B, C, X, Y) : ");
		tri_var=getche();
		if (tri_var == 'x' || tri_var == 'X')
		{
			printf("\n Enter x degrees : ");
			scanf("%f", &x_degr);
			if (deg_flag == 2)
			{
				printf("\n Y%c ignored, Using X%c", deg_symbol, deg_symbol);
				deg_flag = 0;
			}
			if (x_degr < 90)
			{
				printf("\n %c = %.2f%c \n", tri_var, x_degr, deg_symbol);
				y_degr = 90 - x_degr;
				printf("\n x : %.2f%c\n y : %.2f%c", x_degr, deg_symbol, y_degr, deg_symbol);
				x_rads = x_degr * PI / 180.0;
				y_rads = y_degr * PI / 180.0;
				deg_flag = 1;
			}
			else
			{
				printf("\n cannot be >= 90");
				x_degr = 0;
				y_degr = 0;
			}
		}
		else if (tri_var == 'y' || tri_var == 'Y')
		{
			printf("\n Enter y degrees : ");
			scanf("%f", &y_degr);
			if (deg_flag == 1)
			{
				printf("\n X%c ignored, using Y%c ", deg_symbol, deg_symbol);
				deg_flag = 0;
			}
			
			if (y_degr < 90)
			{
				printf("\n %c = %.2f%c \n", tri_var, y_degr, deg_symbol);
				x_degr = 90 - y_degr;
				printf("\n x : %.2f%c\n y : %.2f%c", x_degr, deg_symbol, y_degr, deg_symbol);
				x_rads = x_degr * PI / 180.0;
				y_rads = y_degr * PI / 180.0;
				deg_flag = 2;
			}
			else
			{
				printf("\n cannot be 90 or greater");
				y_degr = 0;
				x_degr = 0;
			}
		}
		else if (tri_var == 'A' || tri_var == 'a' || tri_var == 'B' || tri_var == 'b' || tri_var == 'C' || tri_var == 'c')
		{
			printf("\n Enter %c value : ", tri_var);
			if (tri_var == 'A' || tri_var == 'a')
			{
				scanf("%f", &side_ab);
				if (((side_ab >= side_ac) || (side_bc >= side_ac)) && c_flag == 1)
				{
					printf("\n Point a' to c' is always greater. \n A value not stored");
					side_ab = 0;
					a_flag = 0;
				}
				else
					a_flag = 1;
			}
			else if (tri_var == 'B' || tri_var == 'b')
			{
				scanf("%f", &side_bc);
				if (((side_ab >= side_ac) || (side_bc >= side_ac)) && c_flag == 1)
				{
					printf("\n Point a' to c' is always greater. \n B value not stored");
					side_bc = 0;
					b_flag = 0;
				}
				else
					b_flag = 1;
			}
			else
			{
				scanf("%f", &side_ac);
				if ((side_ab >= side_ac) || (side_bc >= side_ac))
				{
					printf("\n Point a' to c' is always greater. \n C value not stored");
					side_ac = 0;
					c_flag = 0;
				}
				else
					c_flag = 1;
			}
		}
		else if (tri_var == 'S' || tri_var == 's')
		{
			if (a_flag == 1 && b_flag == 1)
				break;
			else if (b_flag == 1 && c_flag == 1)
				break;
			else if (a_flag == 1 && c_flag == 1)
				break;
			else if (deg_flag != 0 && (a_flag == 1 || b_flag == 1 || c_flag == 1))
				break;
			else
				printf("\n Need atleast two values \n");
		}
		else if(tri_var == 'Q' || tri_var == 'q')
		{
			exit(0);
		}	
		else
		{
			printf("\n Invalid entry \n");
		}
	}
	// solving with sides
	if (a_flag == 1 && b_flag == 1)
	{
		display_line();
		printf("\n When,\n a' to b' : %.4f \n b' to c' : %.4f\n", side_ab, side_bc);
		res_rads = atan(side_bc / side_ab);
		res_degr = res_rads * 180.0 / PI;
		printf("\n x : %.2f%c ", res_degr, deg_symbol);
		res_rads = atan(side_ab / side_bc);
		res_degr = res_rads * 180.0 / PI;
		printf("\n y : %.2f%c", res_degr, deg_symbol);
		printf("\n Point a' to c' : %.4f ", side_ab / sin(res_rads));
		display_line();
	}
	else if (a_flag == 1 && c_flag == 1)
	{
		display_line();
		printf("\n When,\n a' to b' : %.4f \n a' to c' : %.4f\n", side_ab, side_ac);
		res_rads = acos(side_ab / side_ac);
		res_degr = res_rads * 180.0 / PI;
		printf("\n x : %.2f%c ", res_degr, deg_symbol);
		res_rads = asin(side_ab / side_ac);
		res_degr = asin(side_ab / side_ac) * 180.0 / PI;
		printf("\n y : %.2f%c ", res_degr, deg_symbol);
		printf("\n Point b' to c' : %.4f ", side_ab / tan(res_rads));
		display_line();
	}
	else if (b_flag == 1 && c_flag == 1)
	{
		display_line();
		printf("\n When,\n b' to c' : %.4f \n a' to c' : %.4f\n", side_bc, side_ac);
		res_rads = asin(side_bc / side_ac);
		res_degr = res_rads * 180.0 / PI;
		printf("\n x : %.2f%c ", res_degr, deg_symbol);
		res_rads = acos(side_bc / side_ac);
		res_degr = res_rads * 180.0 / PI;
		printf("\n y : %.2f%c", res_degr, deg_symbol);
		printf("\n Point a' to b' : %.4f ", side_bc * tan(res_rads));
		display_line();
	}
	// solving with degree
	else if (deg_flag == 1 && a_flag == 1)
	{
		display_line();
		printf("\n When a' to b' : %.4f \n X : %.2f%c", side_ab, x_degr, deg_symbol);
		side_bc = side_ab * tan(x_rads);
		side_ac = side_ab / cos(x_rads);
		printf("\n Point b' to c' : %.4f \n Point a' to c' : %.4f \n y = %.2f%c", side_bc, side_ac, y_degr, deg_symbol);
		display_line();
	}
	else if (deg_flag == 2 && a_flag == 1)
	{
		display_line();
		printf("\n When a' to b' : %.4f \n Y : %.2f%c", side_ab, y_degr, deg_symbol);
		side_bc = side_ab / tan(y_rads);
		side_ac = side_ab / sin(y_rads);
		printf("\n Point b' to c' : %.4f \n Point a' to c' : %.4f \n x = %.2f%c", side_bc, side_ac, x_degr, deg_symbol);
		display_line();
	}
	else if (deg_flag == 1 && b_flag == 1)
	{
		display_line();
		printf("\n When b' to c' : %.4f \n X : %.2f%c", side_bc, x_degr, deg_symbol);
		side_ab = side_bc / tan(x_rads);
		side_ac = side_bc / sin(x_rads);
		printf("\n Point a' to b' : %.4f \n Point a' to c' : %.4f \n y = %.2f%c", side_ab, side_ac, y_degr, deg_symbol);
		display_line();
	}
	else if (deg_flag == 2 && b_flag == 1)
	{
		display_line();
		printf("\n When b' to c' : %.4f \n Y : %.2f%c", side_bc, y_degr, deg_symbol);
		side_ab = side_bc * tan(y_rads);
		side_ac = side_bc / cos(y_rads);
		printf("\n Point a' to b' : %.4f \n Point a' to c' : %.4f \n x = %.2f%c", side_ab, side_ac, x_degr, deg_symbol);
		display_line();
	}
	else if (deg_flag == 1 && c_flag == 1)
	{
		display_line();
		printf("\n When a' to c' : %.4f \n X : %.2f%c", side_ac, x_degr, deg_symbol);
		side_ab = side_ac * cos(x_rads);
		side_bc = side_ac * sin(x_rads);
		printf("\n Point a' to b' : %.4f \n Point b' to c' : %.4f \n y = %.2f%c", side_ab, side_bc, y_degr, deg_symbol);
		display_line();
	}
	else if (deg_flag == 2 && c_flag == 1)
	{
		display_line();
		printf("\n When a' to c' : %.4f \n y : %.2f%c", side_ac, y_degr, deg_symbol);
		side_ab = side_ac * sin(y_rads);
		side_bc = side_ac * cos(y_rads);
		printf("\n Point a' to b' : %.4f \n Point b' to c' : %.4f \n x = %.2f%c", side_ab, side_bc, x_degr, deg_symbol);
		display_line();
	}
	else
	{
		printf("\n err \n");
	}
	return 0;
}
