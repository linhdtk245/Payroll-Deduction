#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void FedTax(float *federaltax, float income){ // ham tinh thue lien bang cua canada
	if (income <= 35595){
		*federaltax = (income*16)/100;
	}else if (income > 35595 && income <= 71190){
		*federaltax = ((income*22)/100) - 2136;
	}else if (income > 71190 && income <= 155739){
		*federaltax = ((income*26)/100) - 4983;
	}else{
		*federaltax = ((income*29)/100) - 8455;
	}
	if (*federaltax < 0){
		*federaltax = 0;
	}
}
void PersonalCredit(float *pcredit, float claimedcredit){
	*pcredit = claimedcredit * (16.0/100); // ham tinh so tin dung ca nhan
}
void Cpp(float *cppcredit, int payperiod, float income, float CppMax){// ham tinh luong huu canada
	float cppcontri;
	cppcontri = (income - (3500.0/payperiod)) * (4.95/100);
	if (cppcontri > 1861.20){
		cppcontri = 1861.20; // dong gop luong huu khong vuot qua 1861.20
	}else if (cppcontri < 0){
		cppcontri = 0; // dong gop luong huu luon luon >= 0
	}
	*cppcredit = cppcontri * (16.0/100);
	if (*cppcredit > CppMax){
		*cppcredit = CppMax;
	}
}
void EmploymentInsurance(float *eicredit, float income, float EiMax){ // ham tinh bao hiem viec lam
	float eipremium;
	eipremium = income * (195.0/10000);
	if (eipremium > 760.50){
		eipremium = 760.50; // tin dung viec lam khong vuot qua 760.50
	}
	*eicredit = eipremium * (16.0/100);
	if (*eicredit > EiMax){
		*eicredit = EiMax;
	}
}
void LabourShare(float *labourcredit, float share){ // ham tinh co phieu lao dong tai tro
	*labourcredit = share * (15.0/100);
	if (*labourcredit > 750){
		*labourcredit = 750;
	}
}
void BasicFedTax(float *basicfedtax, float *federaltax, float *pcredit, float *cppcredit, float *elcredit){
	*basicfedtax = *federaltax - *pcredit - *cppcredit - *elcredit;
}
void AnnualFedTax(float *annualfedtax, float *basicfedtax, float *labourcredit){
	*annualfedtax = *basicfedtax - *labourcredit;
}
void FedTaxPerPeriod(float *fedtaxperperiod, float *annualfedtax, int payperiod){
	*fedtaxperperiod = (*annualfedtax/payperiod);
}
/*void output(float *federaltax, float income){
	printf("Gross income: %.2f\n", income);
	printf("Deductions: \n");
	printf("Federal Tax %.2f\n", *federaltax);
}*/
int main(int argc, char *argv[]) {
	float income;
	float federaltax = 0;
	int payperiod;
	float pcredit = 0;
	float claimedcredit = 0;
	float CppMax = 0;
	float cppcredit = 0;
	float EiMax = 0;
	float elcredit = 0;
	float labourcredit = 0;
	int share = 0;
	float basicfedtax = 0;
	float annualfedtax = 0;
	float fedtaxperperiod = 0;
	float ppcontri = 0;
	printf("Please enter the employee's pay period information :");
	printf("\n Income for the current pay period     :");
	scanf("%f", &income);
	printf("\n Registered Pension Plan contributions :");
	scanf("%f", &ppcontri);
	printf("\nPlease enter the employee's annual information :");
	printf("\n Number of pay periods this year       :");
	scanf("%d", &payperiod);
	printf("\n Federal tax credits (as per TD1 form) :");
	scanf("%f", &claimedcredit);
	printf("\nPlease enter the employee's year-to-date information :");
	printf("\n CPP contributions year-to-date        :");
	scanf("%f", &CppMax);
	printf("\n EI premiums paid year-to-date         :");
	scanf("%f", &EiMax);
	FedTax(&federaltax, income);
	PersonalCredit(&pcredit, claimedcredit);
	Cpp(&cppcredit, payperiod, income, CppMax);
	EmploymentInsurance(&elcredit, income, EiMax);
	LabourShare(&labourcredit,share);
	BasicFedTax(&basicfedtax, &federaltax, &pcredit, &cppcredit, &elcredit);
	AnnualFedTax(&annualfedtax, &basicfedtax, &labourcredit);
	FedTaxPerPeriod(&fedtaxperperiod, &annualfedtax, payperiod);
	printf("\nGross income:        %.2f", income);
	printf("\nDeductions: ");
	printf("\n Federal Tax          %.2f", fedtaxperperiod);
	printf("\n Canada pension plan  %.2f", cppcredit);
	printf("\n Employment Insurance %.2f", elcredit);
	printf("\n RRSP Contributions   %.2f", ppcontri);
	return 0;
}
