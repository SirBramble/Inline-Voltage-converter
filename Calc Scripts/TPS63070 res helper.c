#include <stdio.h>

int main(void){
	
	double R2_base = 10e3;
	double R1_min = 0.0;
	double R1_max = 0.0;
	double V_OUT_min = 0.0;
	double V_OUT_max = 5.0;
	double V_OUT_stellung = 0.0;
	double stellung = 0.96;
	
	int mittelabgriff = 0;
	
	if(mittelabgriff){
		V_OUT_min = ((R1_min/(R2_base + R1_max - R1_min)) + 1.0) * 0.8;
		V_OUT_max = ((R1_max/R2_base) + 1.0) * 0.8;
		V_OUT_stellung = ( ( (R1_max * stellung ) / (R2_base + (R1_max * (1.0 - stellung ) ) ) ) + 1.0) * 0.8;
		printf("Mit Mittelabgriff:\n");
		printf("V_OUT_min = %.2f V\n", V_OUT_min);
		printf("V_OUT_max = %.2f V\n", V_OUT_max);
		printf("V_OUT_stellung = %.2f V\n", V_OUT_stellung);
	}
	else if(R1_min == 0.0 && R1_max == 0.0){
		R1_min = R2_base * ((V_OUT_min/0.8) - 1.0);
		R1_max = R2_base * ((V_OUT_max/0.8) - 1.0);
		printf("R1_min = %.0f kohm\n", R1_min/1000.0);
		printf("R1_max = %.0f kohm\n", R1_max/1000.0);
	}
	else if(V_OUT_min == 0.0 && V_OUT_max == 0.0){
		V_OUT_min = ((R1_min/R2_base) + 1.0) * 0.8;
		V_OUT_max = ((R1_max/R2_base) + 1.0) * 0.8;
		printf("V_OUT_min = %.2f V\n", V_OUT_min);
		printf("V_OUT_max = %.2f V\n", V_OUT_max);
	}
	
	return 0;
}