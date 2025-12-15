#include<stdio.h>
#include"menu_ui.h"
#ifndef NAC_H
#include"nac.h"
#endif
int main() {
	prod* p=NULL;
	initialiser_regions();
	me_pri(p);
	if (p != NULL){
	   free(p);
	}
	return (0);
}
