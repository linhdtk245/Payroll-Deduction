#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void FedTax(float *federaltax, float income, int payperiod){ // ham tinh thue lien bang cua canada
	float annualincome = income * payperiod;
	if (annualincome <= 35595){
		*federaltax = (annualincome*0.16);
	}else if (annualincome > 35595 && annualincome <= 71190){
		*federaltax = (annualincome*0.22) - 2136.0;
	}else if (annualincome > 71190 && annualincome <= 155739){
		*federaltax = (annualincome*0.26) - 4983.0;
	}else{
		*federaltax = (annualincome*0.29) - 8455.0;
	}
	if (*federaltax < 0){
		*federaltax = 0;
	}
}
void PersonalCredit(float *pcredit, float claimedcredit){
	*pcredit = claimedcredit * 0.16; // ham tinh so tin dung ca nhan
}
void Cpp(float *cppcredit, float *cppcontri, int payperiod, float income, float CppMax){// ham tinh luong huu canada
	*cppcontri = (income - (3500.0/payperiod)) * (4.95/100);
	if (*cppcontri > 1861.20){
		*cppcontri = 1861.20; // dong gop luong huu khong vuot qua 1861.20
	}else if (*cppcontri < 0){
		*cppcontri = 0; // dong gop luong huu luon luon >= 0
	}
	*cppcredit = *cppcontri * (16.0/100);
	if (*cppcredit > CppMax){
		*cppcredit = CppMax;
	}else if(*cppcredit < 0){
		*cppcredit = 0;
	}
}
void EmploymentInsurance(float *eicredit, float *eipremium, float income, float EiMax){ // ham tinh bao hiem viec lam
	*eipremium = income * (195.0/10000);
	if (*eipremium > 760.50){
		*eipremium = 760.50; // tin dung viec lam khong vuot qua 760.50
	}else if (*eipremium < 0){
		*eipremium = 0;
	}
	*eicredit = *eipremium * (16.0/100);
	if (*eicredit > EiMax){
		*eicredit = EiMax;
	}else if (*eicredit < 0){
		*eicredit = 0;
	}
}
void LabourShare(float *labourcredit, float share){ // ham tinh co phieu lao dong tai tro
	*labourcredit = share * 0.15;
	if (*labourcredit > 750){
		*labourcredit = 750;
	}
}
void BasicFedTax(float *basicfedtax, float *federaltax, float *pcredit, float *cppcredit, float *eicredit){
	*basicfedtax = *federaltax - *pcredit - *cppcredit - *eicredit;
	if (*basicfedtax < 0){
		*basicfedtax = 0;
	}
}
void AnnualFedTax(float *annualfedtax, float *basicfedtax, float *labourcredit){
	*annualfedtax = *basicfedtax - *labourcredit;
	if (*annualfedtax < 0){
		*annualfedtax = 0;
	}
}
void FedTaxPerPeriod(float *fedtaxperperiod, float *annualfedtax, int payperiod){
	*fedtaxperperiod = (*annualfedtax/payperiod);
	if (*fedtaxperperiod < 0){
		*fedtaxperperiod = 0;
	}
}
int main(int argc, char *argv[]) {
	float income;
	float federaltax = 0;
	int payperiod;
	float pcredit = 0;
	float claimedcredit = 0;
	float CppMax = 0;
	float cppcontri = 0;
	float cppcredit = 0;
	float EiMax = 0;
	float eipremium = 0;
	float eicredit = 0;
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
	printf("\n Labour-sponsored share purchases      :");
	scanf("%f", &share);
	printf("\nPlease enter the employee's year-to-date information :");
	printf("\n CPP contributions year-to-date        :");
	scanf("%f", &CppMax);
	printf("\n EI premiums paid year-to-date         :");
	scanf("%f", &EiMax);
	
	FedTax(&federaltax, income, payperiod);
	PersonalCredit(&pcredit, claimedcredit);
	Cpp(&cppcredit, &cppcontri, payperiod, income, CppMax);
	EmploymentInsurance(&eicredit, &eipremium, income, EiMax);
	LabourShare(&labourcredit,share);
	BasicFedTax(&basicfedtax, &federaltax, &pcredit, &cppcredit, &eicredit);
	AnnualFedTax(&annualfedtax, &basicfedtax, &labourcredit);
	FedTaxPerPeriod(&fedtaxperperiod, &annualfedtax, payperiod);
	
	printf("\nGross income:        %.2f", income);
	printf("\nDeductions: ");
	printf("\n Federal Tax          %.2f", fedtaxperperiod);
	printf("\n Canada pension plan  %.2f", cppcontri);
	printf("\n Employment Insurance %.2f", eipremium);
	printf("\n RRSP Contributions   %.2f", ppcontri);
	return 0;
} 
