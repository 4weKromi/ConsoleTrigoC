
#include "mainhead.h"

void display_line(){
	printf("\n_____________________________\n");
}

void display_diag(){
	int i, j;
	int deg_symbol=167;
	printf("\n Trigonometry v0.2 [right-angled triangle]");
	printf("\n\n\n\ta'");
	for (i = 0; i < 21; i++){
		if (i == 12)
			printf(" A");
		printf("\t");
		for (j = i; j != 0; j--){
			if (i == 5 && j == 3){
				printf("X%c", deg_symbol);
				continue;
			}
			if (i == 18 && j == 4){
				printf("Y%c", deg_symbol);
				continue;
			}
			printf(". ");
		}
		if (i == 10)
			printf("\tC");
		printf("\n");
	}
	printf("\n\tb'\t\t\t\t\tc'");
	printf("\n\t\t\tB\n");
	printf("\n\n 'Q' to Quit or 'S' to solve problem ");
}
