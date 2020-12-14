#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
// #include <curses.h>
#include <unistd.h>

//define data size
//#define DATA_SIZE 1000

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
int sendWithCare();
int favorites();
int manageFavourites();
int choice;
int ammount;
char phoneNumber[14]; //used char for phoneNumber because we want to include zero(0) at coutry code eg. +256
int mobileMoney = 1000000; //1000000; //Mobile money value set to 1Million
int balance;
int saveData();

// //variable to store data
// char data[DATA_SIZE];

//  /* File pointer to hold reference to our file */
//     FILE * fPtr;

//create manageFavourites() using struct

struct createFavourite {
    char name[15];
    char phoneNumber[14];
} fav;


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
        system("clear"); //clear screen#
        
        sendWithCare(); //call the function to load the menu
        
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


//send with care menu function

int sendWithCare() {
    
    puts("Send with Care");
    puts("1) Mobile User");
    puts("2) Favorites");
    puts("3) School Fees");
    puts("4) MyCaretaker");
    puts("5) AYO send with care Balances or Claim");
    puts("0) Back");
    scanf("%d", &choice);
    
    //use if statement to make selection options
    if(choice == 1) {
        system("clear");
        puts("Enter Number you're sending to");
        scanf("%s", phoneNumber);
        puts("Enter Ammount");
        scanf("%d", &ammount);
        
        //calculate balance
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
        system("clear"); //clear screen
        
        //load favorites menu
        favorites();
    } else if(choice == 3) {
      system("clear"); //clear screen
      puts("Yello. Thank you for trying out our new Services \nThis service will be available very soon");
      sleep(2); // sleep for two seconds before quiting
      exit(0);    
    } else if(choice == 4) {
        
    } else if(choice == 5) {
        
    } else if(choice == 0) {
        
    } else {
        printf("Invalid Input! Please try Again!\n");
        
        //load the menu Again after one second
        sleep(1);
        sendWithCare();
    }
}


//create favorites array

//int favorites[i]
//favorites menu

int favorites() {
    puts("Favorites");
    puts("1) Find Number");
    puts("2) Select Number");
    puts("3) Manage Favorites");
    puts("0) Back");
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("Please Enter your favorites Number\n");
        scanf("%s",phoneNumber);
        puts("Enter Ammount");
        scanf("%d", &ammount);
        
        //calculate balance
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
         printf("Please Enter your favorites Number\n");
        scanf("%s",phoneNumber);
        puts("Enter Ammount");
        scanf("%d", &ammount);
        
        //calculate balance
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
        
        manageFavourites();
        
    } else if(choice == 0) {
        
    } else {
        puts("Invalid Input! Please Try again!");
        
        //sleep for one second
        sleep(1);
        sendWithCare();
    }
}

//manageFavourites()

int manageFavourites() {
    system("clear");// clear screen
    puts("Manage Favorites");
    puts("1) Create Contact");
    puts("2) Delete Contact");
    puts("0) Back");
    scanf("%d", &choice);
    
    if(choice == 1) {
        puts("Enter Name");
        scanf("%s", fav.name);
        puts("Enter Number");
        scanf("%s", fav.phoneNumber);
        puts("Creating Contact...");
        //sleep
        sleep(1);
        puts("contact created successfully!");
        
        //exit program
        exit(0);
    } else if(choice == 2) {
        
        //set the variables to empty string
        // fav.name = NULL;
        // fav.phoneNumber = NULL;
        
        puts("contact Deleted successfully!");
    
        //exit program
        exit(0);
    } else if(choice == 0) {
        
        //go back to favorites()
        favorites();
    } else {
        puts("Invalid Input! Please Try again!");
    
        //exit program
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
