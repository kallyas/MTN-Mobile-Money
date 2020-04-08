/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

MTN Mobile Money Replica By Iden.

Note: change system("clear") to system("cls")
I used system("clear") because the compiler is running on a unix system
so for windows, you have to use system("cls).

Started this program today evening, Implying most of the menu options are not yet worked on!

for testing purposes, try option 1

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//menus (proto types/ Functions)
int menuMain();
int sendMoney();
int airtimeBundles();
int momoPay();
int payements();
int savingsLoans();
int financialServices();
int withdrawMoney();
int myAccount();
int eastAfrica();
int airtelTanzania();
int restOfAfrica();
int choice;
int ammount;
char phoneNumber[14]; //used char for phoneNumber because we want to include zero(0) at coutry code eg. +256
int mobileMoney = 1000000; //Mobile money value set to 1Million
int balance;

int main()
{
    menuMain(); //call main menu

    return 0;
}

int menuMain() {
    printf("MTN Mobile Money:\n");
    printf("1) Send Money\n");
    printf("2) Airtime & Bundles\n");
    printf("3) MomoPay\n");
    printf("4) Payements\n");
    printf("5) Savings & Loans\n");
    printf("6) Financial Services\n");
    printf("7) Withdraw Money\n");
    printf("8) My Account\n");
    
    do {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                sendMoney();
                break;
            case 2:
                airtimeBundles();
                break;
            case 3:
                momoPay();
                break;
            case 4:
               payements();
               break;
            case 5:
                savingsLoans();
                break;
            case 6:
                financialServices();
                break;
            case 7:
                withdrawMoney();
                break;
            case 8:
                myAccount();
                break;
            default :
                puts("Invalid Input! Try again");
        }
    } while(choice != 8);
        //system("pause");
    //return 1;
}

//sending money function
int sendMoney() {
    system("clear");
    printf("Send Money\n");
    puts("1) Mobile User");
    puts("2) East Africa");
    puts("3) Rest Of Africa");
    puts("4) Send With Care");
    puts("5) Donations");
    puts("0) Back");
    scanf("%d", &choice);
    
    //using if else if statements to select options
    if (choice == 1) {
        printf("Enter the number you're sending to\n");
        scanf("%s", phoneNumber);
        printf("Enter Ammount\n");
        scanf("%d", &ammount);
        
        //calculate the balance
        balance = mobileMoney - ammount;
        
        //check if the ammount to be sent is not bigger than Mobile Money Balnce
        if (ammount <= mobileMoney) {
            printf("You have sent %d shs to %s and your balance is %d", ammount, phoneNumber, balance);
        } else {
            printf("You have Insufficient balance on your account");
        }
        //exit when the transaction finishes
        exit(0);
    } else if(choice == 2) {
        
        puts("East Africa");
        //call eastAfrica() function to load the menu
        system("clear"); // clears console screen. On windows use system("cls");
        eastAfrica();
    } else if(choice == 3) {
        puts("Rest of Africa");
        //call restOfAfrica() function to load the menu
        system("clear");
        restOfAfrica();
        
    }else if(choice == 4) {
        
    } else if(choice == 5) {
        
    }else if(choice == 0) {
        system("clear"); // clears console screen. On windows use system("cls");
        menuMain();
        
    } else {
        printf("Invalid choice! Please try again");
    }
}

//sending money to eastAfrica
int eastAfrica() {
    printf("1) Safaricom MPesa\n");
    printf("2) MTN Rwanda\n");
    printf("3) Tanzania\n");
    printf("4) Ecocash Burundi\n");
    printf("0) Back\n");
    scanf("%d", &choice);
    
    //use if else if statements to select choices
    if(choice == 1) {
        system("clear");//clear console screen
        puts("Send to Kenya:");
        printf("Enter Recipient Number with countru code eg. 254xxx\n");
        scanf("%s", phoneNumber);
        printf("Enter Ammount");
        scanf("%d", &ammount);
        
        //calculate the balance
        balance = mobileMoney - ammount;
        
        //check if the ammount to be sent is not bigger than Mobile Money Balnce
        if (ammount <= mobileMoney) {
            printf("You have sent %d shs to %s and your balance is %d", ammount, phoneNumber, balance);
        } else {
            printf("You have Insufficient balance on your account");
        }
        //exit when the transaction finishes
        exit(0);
        
    } else if(choice == 2) {
        puts("Send to Rwanda:");
        printf("Enter Recipient Number with countru code eg. 250xxx\n");
        scanf("%s", phoneNumber);
        printf("Enter Ammount");
        scanf("%d", &ammount);
        
        //calculate the balance
        balance = mobileMoney - ammount;
        
        //check if the ammount to be sent is not bigger than Mobile Money Balnce
        if (ammount <= mobileMoney) {
            printf("You have sent %d shs to %s and your balance is %d", ammount, phoneNumber, balance);
        } else {
            printf("You have Insufficient balance on your account");
        }
        //exit when the transaction finishes
        exit(0);
        
    } else if(choice == 3) {
        system("clear"); // claer screen. On windows use system("cls");
        //Tanzania
        puts("Airtel Tanzania");
        //load Airtel Tanzania Menu
        airtelTanzania();
    } else if(choice == 4) {
        system("clear");
        puts("Send to Burundi:");
        printf("Enter Recipient Number with countru code eg. 257xxx\n");
        scanf("%s", phoneNumber);
        printf("Enter Ammount");
        scanf("%d", &ammount);
        
        //calculate the balance
        balance = mobileMoney - ammount;
        
        //check if the ammount to be sent is not bigger than Mobile Money Balnce
        if (ammount <= mobileMoney) {
            printf("You have sent %d shs to %s and your balance is %d", ammount, phoneNumber, balance);
        } else {
            printf("You have Insufficient balance on your account");
        }
        //exit when the transaction finishes
        exit(0);
        
    } else if(choice == 0) {
        sendMoney();
    } else {
        printf("Invalid choice! Please try again!");
    }
}


//Airtel Tanzania Menu
int airtelTanzania() {
    puts("1) Airtel Tanzania");
    puts("2) Vodacom Tanzania");
    puts("0) Back");
    scanf("%d", &choice);
    
    //using if else if statements select options
    if(choice == 1) {
        system("clear");//clear console screen
        puts("Send to Airtel Tanzania:");
        printf("Enter Recipient Number with countru code eg. 25568xxx\n");
        scanf("%s", phoneNumber);
        printf("Enter Ammount");
        scanf("%d", &ammount);
        
        //calculate the balance
        balance = mobileMoney - ammount;
        
        //check if the ammount to be sent is not bigger than Mobile Money Balnce
        if (ammount <= mobileMoney) {
            printf("You have sent %d shs to %s and your balance is %d", ammount, phoneNumber, balance);
        } else {
            printf("You have Insufficient balance on your account");
        }
        //exit when the transaction finishes
        exit(0);
        
    } else if(choice == 2) {
        system("clear");//clear console screen
        puts("Send to Vodacom Tanzania:");
        printf("Enter Recipient Number with countru code eg. 25574xxx\n");
        scanf("%s", phoneNumber);
        printf("Enter Ammount");
        scanf("%d", &ammount);
        
        //calculate the balance
        balance = mobileMoney - ammount;
        
        //check if the ammount to be sent is not bigger than Mobile Money Balnce
        if (ammount <= mobileMoney) {
            printf("You have sent %d shs to %s and your balance is %d", ammount, phoneNumber, balance);
        } else {
            printf("You have Insufficient balance on your account");
        }
        //exit when the transaction finishes
        exit(0);
    } else if(choice == 0) {
        //load east Africa menu if selected option is 0
        eastAfrica();
    } else {
        puts("Invalid Input! Please try again!");
    }
}


//sending money to Rest of Africa | restOfAfrica();

int restOfAfrica() {
    puts("1) MTN Zambia");
    puts("0) Back");
    scanf("%d", &choice);
    
    //if to make options
    if(choice == 1) {
        system("clear");//clear screen
        puts("Vodacom Zambia");
        puts("1) Send Money");
        puts("0) Back");
        scanf("%d", &choice);
        
        if(choice == 1) {
            system("clear");//clear console screen
            puts("Send to Vodacom Zambia:");
            printf("Enter Recipient Number with country code eg. 260xxx\n");
            scanf("%s", phoneNumber);
            printf("Enter Ammount");
            scanf("%d", &ammount);
            
            //calculate the balance
            balance = mobileMoney - ammount;
            
            //check if the ammount to be sent is not bigger than Mobile Money Balnce
            if (ammount <= mobileMoney) {
                printf("You have sent %d shs to %s and your balance is %d", ammount, phoneNumber, balance);
            } else {
                printf("You have Insufficient balance on your account");
            }
            //exit when the transaction finishes
            exit(0);
            
        } else if(choice == 0) {
            
            restOfAfrica();
            
        } else {
            printf("Invalid Input! Please try again\n!");
            exit(0);
        }
        
    } else if(choice == 0) {
        
        sendMoney();
        
    } else {
        printf("Invalid Input! Please try again!\n");
        exit(0);
    }
}


//airtimeBundles function
int airtimeBundles() {
    
    printf("airtime bundles");
}
int momoPay() {
    printf("momo pay");
}
int payements() {
    printf("payements");
}
int savingsLoans() {
    printf("Savings");
}
int financialServices() {
    printf("Hello");
}
int withdrawMoney() {
    printf("Withdraw money");
}
int myAccount() {
    printf("My Account");
}
