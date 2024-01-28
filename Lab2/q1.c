#include<stdio.h>
int min(int a, int b){
	int min;
	min = a<b?a:b;
	return min;
}
int ConsecIntegerGCD(int m, int n) {
	int t;
	int opcount = 1;// variable to count how many times the basic operation executes.
	t = min(m,n);
	
	while(t!=0) {
		opcount++;
		if((m%t==0) &&(n%t==0)){
			printf("Operation count= %d\n", opcount); 
			return t;
		}
		t-=1;
	}
}
int main() {
	int m,n;
	printf("Enter the two numbers whose GCD has to be calculated: ");
	scanf("%d", &m);
	scanf("%d", &n);
	printf("sum of numbers = %d\n",m+n);
	printf("GCD of two numbers %d and %d using Consecutive Integer method is %d \n",
	m,n,ConsecIntegerGCD(m,n)); 
	return 0;
}