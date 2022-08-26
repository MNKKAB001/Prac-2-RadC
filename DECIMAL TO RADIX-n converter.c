//********************************************************************
//*                    EEE2046S C template                           *
//*==================================================================*
//* WRITTEN BY:KABELO MANAKE    	                 		               *
//* DATE CREATED:22 JUNE 2022                                        *
//* MODIFIED: KABELO MANAKE                                          *
//*==================================================================*
//* PROGRAMMED IN:C                                                  *
//* TARGET:                                                          *
//*==================================================================*
//* DESCRIPTION:Converting decimal to any radix i                    *
//*                                                                  *
//********************************************************************
// INCLUDE FILES
//====================================================================
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h> //malloc,free
#include <string.h>//strlen
//====================================================================
// GLOBAL CONSTANTS
//====================================================================
#define ASCII "*****************************"
#define TITLE "DECIMAL TO RADIX-i converter"
#define NAME  "KABELO MANAKE"
#define YEAR  "2022"
//====================================================================
// GLOBAL VARIABLES
//====================================================================

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================
char* Dec2RadixI(int decValue, int radValue)
{
    char numbers[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; //Array list
    int remainder =1,i=0,newDecimal, Log = log(decValue)/log(radValue);// Initialization
    char rad[Log];// Intialize a pointer to rad
    //rad = numbers;

    while((decValue>0) && (remainder >= 0)) // Loop
    {
        remainder = decValue%radValue;
        newDecimal = decValue/radValue;
        //rad = numbers;
        rad[i] = numbers[remainder];//Take value of remainder and putting it in position i of rad
        decValue= newDecimal;
        i++;
    }
    rad[i] = '\0';

    char*reversed = (char*)malloc(sizeof(char)*strlen(rad)+1);
    int j = 0;
    for (int i =strlen(rad)-1;i>=0;i--,j++)
    {
        reversed[j] = rad[i]; // A loop that reverses the radix-i value created
    }
    reversed[j] = '\0'; //Reverse the char from the pointer
    return reversed; // return the reverse final value or character

}
//====================================================================
// MAIN FUNCTION
//====================================================================
int main (void)
{
    printf("%s\n",ASCII);
    printf("%s\n",TITLE);
    printf("Written by:%s\n",NAME);
    printf("Date:%s\n",YEAR);
    printf("%s\n",ASCII);

    int decimal;
    int radix;
    int divide;
    int remainder;

    printf("Enter a decimal number: ");// Prompt the use for a decimal
    scanf("%d",&decimal);

    while(decimal >= 0) // A loop that only take only positive value entered by the user
    {
        printf("The decimal number you have entered is %d\n",decimal);

        printf("Enter a radix for the converter between 2 and 16: "); // Restricting the user from which numbers to enter
        scanf("%d",&radix);
        printf("The radix you have entered is %d",radix);

        printf("\nThe log2 of the number is %.2f",(log(decimal)/log(2)));// convert the number into printing float number
        divide = decimal/radix;

        printf("\nThe integer result of the number divided by %d is %d",radix,divide);
        remainder = decimal%radix;
        printf("\nThe remainder is %d",remainder);

        printf("\nThe radix-%d value is %s\n",radix,Dec2RadixI(decimal,radix)); // Calling the fuction Dec2Radix with its argument
        printf("Enter a decimal number: ");
        scanf("%d",&decimal);


    }
    printf("EXIT");




	return 0;
}							// End of main

//********************************************************************
// END OF PROGRAM
//********************************************************************

