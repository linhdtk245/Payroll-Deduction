#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void FedTax(float *federaltax, float income){ // ham tinh thue lien bang cua canada
	if (income <= 35595){
		*federaltax = (income*16)/100;
	}else if (income > 35595 && income < 71190){
		*federaltax = ((income*22)/100) - 2136;
	}else if (income > 71190 && income < 155739){
		*federaltax = ((income*26)/100) - 4983;
	}else if (income > 115739){
		*federaltax = ((income*29)/100) - 8455;
	}
	if (*federaltax < 0){
		*federaltax = 0;
	}
}
void Cpp(float *cppcredit, int payperiod, float income){// ham tinh luong huu canada
	float cppcontri;
	cppcontri = (income - (3500.0/payperiod)) * (495.0/100);
	if (cppcontri > 1861.20){
		cppcontri = 1861.20; // dong gop luong huu khong vuot qua 1861.20
	}else if (cppcontri < 0){
		cppcontri = 0; // dong gop luong huu luon luon >= 0
	}
	*cppcredit = cppcontri * (16.0/100);
	if (*cppcredit < 0){
		*cppcredit = 0; // luong huu luon luon >= 0
	}
}
void EmploymentInsurance(float *elcredit, float income){ // ham tinh bao hiem viec lam
	float elpremium;
	elpremium = income * (195.0/10000);
	if (elpremium > 760.50){
		elpremium = 760.50; // tin dung viec lam khong vuot qua 760.50
	}
	*elcredit = elpremium * (16.0/100);
}
/*void output(float *federaltax, float income){
	printf("Gross income: %.2f\n", income);
	printf("Deductions: \n");
	printf("Federal Tax %.2f\n", *federaltax);
}*/
int main(int argc, char *argv[]) {
	float income;
	float federaltax = 0;
	float cppcredit = 0;
	float elcredit = 0;
	int payperiod;
	printf("Please enter the employee's pay period information :");
	printf("\nIncome for the current pay period :");
	scanf("%f", &income);
	printf("\nPlease enter the employee's annual information :");
	printf("\nNumber of pay periods this year :");
	scanf("%d", &payperiod);
	printf("\nPlease enter the employee's year-to-date information :");
	FedTax(&federaltax, income);
	Cpp(&cppcredit, payperiod, income);
	EmploymentInsurance(&elcredit, income);
	printf("\nGross income:        %.2f", income);
	printf("\nDeductions: ");
	printf("\nFederal Tax          %.2f", federaltax);
	printf("\nCanada pension plan  %.2f", cppcredit);
	printf("\nEmployment Insurance %.2f", elcredit);
	return 0;
}
