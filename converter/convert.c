/*
Ankit Das
convert decimal to desired base (2,8,16)
28 July 2020
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *tostr(int n){                                      // return a number in string type i.e int 1 becomes char '1'
    char *result = malloc(32*sizeof(char));
    sprintf(result,"%d",n);
    return result;
}

char *strrev(char *string)                               // reverse string on its axis
{
    if (!string || ! *string)
        return string;

    int i = strlen(string) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = string[i];
        string[i] = string[j];
        string[j] = ch;
        i--;
        j++;
    }
    return string;
}
 
char* convert(int decimal,int base)                     // takes the decimal and the base to convert to
{
 const char *hex[] = {"A","B","C","D","E","F"};         // dictionary of hex values greater than 9
 unsigned int current = 0;
 char* result = malloc(32*sizeof(char));

 while(decimal){   
  switch(base)
  {
      case 16:                                           // to convert into hex
           current = decimal % base;                                       
           decimal /= base;
           if(current > 9){
             current -= 10;
             strncat(result,hex[current],1); 
           }

           else{
               strcat(result,tostr(current));
           }
           break;
      
      case 2:                                            // to convert into binary or octal
      case 8:
           current = decimal % base;
           decimal /= base;
           strcat(result,tostr(current));
           break;

      case 10                                            // to convert into decimal
           strcat(result,tostr(decimal));
           return result;
           break;
      
      default:                                         
           printf("\n\nBaseError: Unsupported base!");
           return 0;
           break;       
  }
 }  
  return strrev(result);                               // return reverse of the result
}


int main()
{
   unsigned int number,base;
   printf("<number> <base>\n");
   scanf("%d %d",&number,&base);
   printf("\n\nRESULT: %s\n",convert(number,base));
   return 0; 
}
