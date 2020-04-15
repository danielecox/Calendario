#include<stdio.h>
#include<locale.h>
#include<stdbool.h>
/* Outro algoritmo de calend�rio
	Por Carlos Menezes (cedmenezes@gmail.com)
*/
bool bissexto(int ano)
{	if(ano%400==0) return true;
	else if(ano%100==0) return false;
	else if(ano%4==0) return true;
	else return false;
}
int main()
{	int i;
	int dia, mes, ano, resposta, diferenca1, diferenca2;
	/*
	diferenca1: � a diferen�a em dias da data
	   fornecida, DD/MM/AAAA, at� 01/01/AAAA
	diferenca2: � a diferen�a em dias da data
	   01/01/AAAA at� 01/01/2000, que foi um s�bado.
	*/	
	printf("\nDigite a data no formato DD/MM/AAAA: ");
	scanf("%d/%d/%d", &dia, &mes, &ano);

	int diasAcumulados[12]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	diferenca1 = (dia-1) + (diasAcumulados[mes-1]);
	if(bissexto(ano) && (mes>=3 || (mes==2 && dia==29)))
		diferenca1++;
	
	if(ano>=2000)
	{	diferenca2 = (ano-2000)*365;
		for(i=2000; i<ano; i+=4)
			if(bissexto(i)) diferenca2++;
		resposta = (diferenca1+diferenca2)%7;
	}
	else
	{	diferenca2 = (2000-ano)*365;
		for(i=1996; i>=ano; i-=4)
			if(bissexto(i)) diferenca2++;
		resposta = ((diferenca1-diferenca2)%7 + 7)%7;
	}
	
	switch(resposta){
		case 1: printf("\nDomingo"); break;
		case 2: printf("\nSegunda-feira"); break;
		case 3: printf("\nTer�a-feira"); break;
		case 4: printf("\nQuarta-feira"); break;
		case 5: printf("\nQuinta-feira"); break;
		case 6: printf("\nSexta-feira"); break;
		case 0: printf("\nS�bado"); //01/01/2000
	}	
	return 0;
}
