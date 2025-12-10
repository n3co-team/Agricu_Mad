#include <stdio.h>
#include<stdlib.h>
#ifndef PROD_H
#include"prod.h"
#endif

prod* bdfull() {
prod*  bd;
prod* t=tubercule();
prod* r=racine();
prod* f=fruit();
int n= t[0].ntp + r[0].ntp + f[0].ntp;
int i,j;
bd=malloc(n*sizeof(prod));
for(i=0;i<t[0].ntp;i++)
    bd[i]=t[i];

for(j=0;j<r[0].ntp;j++) {
    bd[i]=r[j];
    i++;
}

for(j=0;j<f[0].ntp;j++) {
    bd[i]=f[j];
    i++;
}

for(i=0;i<n;i++)
bd[i].ntp=n;
    return bd;
}
