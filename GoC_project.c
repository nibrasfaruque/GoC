/*
 Game of Craps 
 Name: Nibras Faruque
 */

#include<stdio.h>
#include <stdlib.h> // srandom()
#include <time.h> // time()

// prints the two dice (d1 and d2)
// returns the sum of two dice
int rolling() {
    int d1,d2;
    char enter;
    srandom((unsigned int)(time(NULL)));
    
    printf("\nContinue to press enter to roll dice");
    sscanf("%c",&enter);
    
    d1 = rand()%6+1;
    d2 = rand()%6+1;
    
    printf("\nDie 1: %d", d1);
    printf("\nDie 2: %d", d2);
    return d1+d2;
    }

// main() will pass in bankroll
// returns the updated bankroll
int playing(int amount)
{
    char choice;
    int count,sum,bet,point,newBankroll;

    printf("\nBet for or against yourself?\n(F/f is for yourself and A/a is for against yourself) ");
    scanf("%c", &choice);

    do
    {
        
        printf("\nEnter the amount you want to bet ");
        scanf("%d",&bet);

        if (bet > amount)
            printf("\nYou do not have enough...Reenter your bet ");
        
    }while(bet > amount);

    if (choice =='F' || choice == 'f')
    {
        sum = rolling();
        printf("\nYou rolled  %d", sum);

        switch(sum)
        {
            case 7:
            case 11:
                count = 1;
                printf("\nYou won $%d", bet);
                break;
                
            case 2:
            case 3:
            case 12:
                count = 0;
                printf("\nYou lost $%d", bet);
                break;
                
            default:
                
                point = sum;
                choice = 'n';
                
                
                if ((bet*2) <= amount)
                {
                    printf("\nDo you want to double your bet? (Y/y is yes and N/n is no) ");
                    scanf("%c", &choice);
                }

                if (choice == 'Y' || choice == 'y')
                    bet = bet*2;

                do
                {
                    sum = rolling();
                    if (sum == point)
                    {
                        count = 1;
                        printf("\nYou won $%d", bet);
                        break;
                        
                    }
                }while(sum != 7);

            if (sum == 7)
            {
                printf("\nYou have sevened out and lost $%d", bet);
            }
        }
    }
    else
    {
        sum = rolling();
        printf("\nYou rolled %d", sum);

        switch(sum)
        {
            case 7:
            case 11:
                count = 0;
                printf("\n You lost $%d",bet);
                break;

            case 2:
            case 3:
            case 12:
                count = 1;
                printf("\nYou won $%d",bet);
                break;

            default:
                
                point = sum;
                choice = 'n';
                
                if ((bet*2) <= amount)
                {
                    printf("\nDo you want to double your bet? (Y/y is yes and N/n is no) ");
                    scanf("%c", &choice);
                }

                if (choice == 'Y' || choice == 'y')
                    bet = bet*2;

                do
                {
                    sum = rolling();
                    if (sum == 7)
                    {
                        count = 1;
                        printf("\nYou won $%d",bet);
                        break;
                    }
                }while(sum != point);
            if (sum == 7)
            {
                printf("\nYou lost $%d",bet);
            }
        }
    }
    
    if (count == 1)
    {
        newBankroll = amount+bet;
    }
    if (count == 0)
    {
        newBankroll = amount-bet;
    }
    return newBankroll;
}

// initialize bankroll to 100
// run a while loop if the user wishes to continue to play
int main(){
    
    printf("Welcome to the Game of Craps!");
    
    int bankroll = 100;
    char option;
    
    do{
        bankroll = playing(bankroll);

        if (bankroll == 0 || bankroll < 0){
        
            printf("\nYou have no money! ");
            return 0;
        }

        printf("\nAs of now, Current Bankroll Balance is $%d", bankroll);
        printf("\nDo you want to play again? (Enter for yes or N/n for no) ");
        scanf("%c", &option);
        
    }
    while (option != 'N' && option != 'n');
}
