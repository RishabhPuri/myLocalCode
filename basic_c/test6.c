#include<stdio.h>

int main(int argc, char **argv)
{
printf("\n the number of the arguments entered is %d",argc);
while(argc){
printf(" \n arguments entered by user %s \n",*argv[argc]);argc--;}
return 0;
}

