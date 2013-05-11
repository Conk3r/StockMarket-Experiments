#include<stdio.h>
#include<stdlib.h>
#include"StMkt.h"



int main(){
	/*Data Field*/

float startCapital = 10000;
int count = 0;	
int dailyData = 0;		//Switch that activates Data Output for every day

/*Value of the Siemens Stock from 28.03.13 to the end of April*/

float siemensValue [21] = {84.10, 85.6, 83.7, 83.32,81.52,81.42,80.96,82.14,82.15,80.99, 79.10, 79.18,78.20,77.08,76.35,76.85,78.14,79.20,79.56,79.04,79.89,79.20};	

float memory[21]; 		//Remembers the win/ loss the programm made that day

struct share myStock;
struct share *pointer;
pointer = &myStock;

/* Set myStock */
pointer->capital = startCapital;
pointer->amount = 0;
for(int k = 0; k < 21; k++)
{	
	memory[k] = 0;
	pointer->value[k] = siemensValue[k];
}

for(int k = 0; k < 101; k++)
{
printf("%d#\n",k);
for(int today = 0; today < 21; today++)
	{
	if(dailyData)
		printf("%d# DAY\n",today+1); 
	if(today-1 >= 0)
		{
		if( myStock.value[today] - myStock.value[today-1] > myStock.value[today]/k )//ConditionToBuy
			{
			invest(pointer, today);
			count = 0;
			}
		else
			{
			sell(pointer,today);
			count ++;
			}
		} 
	memory[today] = totalProfit(pointer, today);
if(dailyData){

			printf("amount: %d \t capital: %.2f $ \t ", pointer->amount, pointer->capital );
			if(today >= 1 )
				printf("total: %.2f $\t difference: %.2f\n\n",pointer->capital + pointer->amount * 					pointer->value[today],memory[today] -memory[today-1]);
			else
			printf("\n\n");
			}
	}
	


//printf("You own %d shares and have %.2f $ left.\n\n", myStock.amount, myStock.capital);
//printf("Your share is %.2f $ Worth \n",myStock.amount * myStock.value[21]);



printf("You made profit of %.2f $ \n",myStock.capital + myStock.amount * myStock.value[20] -10000 );
}
}

//printDailyresults(

/*
float dailyProfit(float memo[], int day){
	
		return memo[day] - memo[day-1];

}
*/
int totalWealth(struct share *stock, int day)
	{
	return (stock->capital + stock->value[day] * stock->amount);
	}

int totalProfit(struct share *stock, int day)
	{
		return (totalWealth(stock, day) - 10000);
	}
	
void sell(struct share *stock, int day){
		stock->capital =  stock->amount * stock->value[day] + stock->capital;
		stock->amount = 0;
		printf("SELL\n");
}
void invest(struct share *stock, int day){
	for(int i = 0; (*stock).capital > 0; i++)
		{
		stock->capital = stock->capital - stock->value[day];
		stock->amount++;
		
		}
		stock->amount--;
		stock->capital= stock->capital + stock->value[day];
		
			printf("INVEST \n");
}


//Strategy Number 1 if((myStock.value[today-1] - myStock.value[today-2] > 0 && myStock.value[today] - myStock.value[today-1] > 0 )|| count == 6 )
