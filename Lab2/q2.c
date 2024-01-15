#include<stdio.h>
#define MAX 1024
int opcount = 0;
typedef struct{
   int size;
   int factor[MAX + 1];
   int exponent[MAX + 1];
} F;
void FindFactors(int x, F* F){
   int i, j = 1;
   int n = x, c = 0;
   int k = 1;
   F->factor[0] = 1;
   F->exponent[0] = 1;
   for (i = 2; i <= n; i++) {
   		opcount++;
		c = 0;
		while (n % i == 0) {
			 c++;
			 n = n / i;
		}
		if (c > 0) {
			 F->exponent[k] = c;
			 F->factor[k] = i;
			 k++;
		}
   }
   F->size = k - 1;
}
void DisplayFactors(int x, F F){
	int i;
  	printf("The prime factors of %d are: \n",x);
	for (i = 0; i <= F.size; i++) {
		printf("%d",F.factor[i]);
		if (F.exponent[i] > 1)
			printf("^%d",F.exponent[i]);
		if (i < F.size)
			printf("*");
		else
			printf("\n");
   }
}
int gcdMiddleSchoolProcedure(int m, int n){
   F mF, nF;
   int r, mi, ni, i, k, x = 1, j;
   FindFactors(m, &mF);
   DisplayFactors(m, mF);
   FindFactors(n, &nF);
   DisplayFactors(n, nF);
   int min;
   i = 1;
   j = 1;
   while (i <= mF.size && j <= nF.size) {
		if (mF.factor[i] < nF.factor[j])
			 i++;
		else if (nF.factor[j] < mF.factor[i])
			 j++;
		else{
			 min = mF.exponent[i] > nF.exponent[j] ? nF.exponent[j] :mF.exponent[i];
			 x = x * mF.factor[i] * min;
			 i++;
			 j++;
		}
   }
	printf("Operation count= %d\n", opcount); 
	return x;
}
int main(){
   	unsigned int m,n;
	printf("Enter the two numbers whose GCD has to be calculated: ");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("sum of numbers = %d\n",m+n);
  	printf("GCD of two numbers %d and %d using Middle School Procedure method is %d \n",
	m,n,gcdMiddleSchoolProcedure(m,n)); 
   return (0);
}
