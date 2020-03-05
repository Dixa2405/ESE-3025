#include<stdlib.h>
#include<stdio.h>
int comparator(void *pa ,void *pb)
{
	int a =*((int*)pa);
	int b=*((int*)pb);
	int ret=0;
	if(a<b)
		ret=-1;
	else if (a>b)
		ret=1;
	return ret ;
}
 int main()
{
	 printf("Before sorting = ");
    int myarr[] = {33,-25,100,11,55};

    size_t L=sizeof(myarr)/sizeof(int);

    for (int n = 0 ; n < sizeof(myarr)/sizeof(int); n++)
            printf ("%d  ", myarr[n]);

    printf("\n");

    printf("result after soring =");

    qsort (myarr,L, sizeof(int),comparator);
    for (int i = 0 ; i < sizeof(myarr)/sizeof(int); i++)
        printf ("%d ", myarr[i]);

    return 0;
}
