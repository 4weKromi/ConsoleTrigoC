/* trigonometry v0.2 [right-angled triangle]
by 4weKromi */

#include "mainhead.h"

int main(){
	char prompt;
	while (1){
		display_diag();
		take_input();
		printf("\n\n quit? 'Y' : ");
		prompt=getche();
		if (prompt == 'y' || prompt == 'Y')
			break;
	}
	return 0;
}
