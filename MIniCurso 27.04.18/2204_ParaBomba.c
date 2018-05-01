//
// Created by WizIbk on 27/04/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main (){
    int n;
    char a[101], b[101];
    int resto;
    scanf("%d",&n);
    for (int i =0; i<n;i++){
        scanf("%s %s",a,b);
        if(stcmp(a,b)==0)
            printf("%s\n",b);
        else
            printf("%d\n",1);
    }
    return 0;
}