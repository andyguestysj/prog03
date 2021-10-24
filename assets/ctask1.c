#include <stdio.h>
#include <stdalign.h>

int main(void) {

int integer1=1;
short short2=2;
int integer3=3;

printf("integer1 =%d Memory address%p\n",integer1,&integer1);
printf("short2 =%d Memory address%p\n",short2,&short2);
printf("integer3 =%d Memory address%p\n",integer3,&integer3);


// Exercise Tasks
// 1 Run this code and take note of the addresses. Run it again and compare the addresses.
//    Why might they be different each time you run the code?
// 2 Add a char and a float variable, print out the value and address as above
// 3 Extend each printf to also print out the size of each variable type.
// 4 Rearrange the variable declaration order and see if it has an effect on the addresses
//   You may want to rearrange your printfs to match the order of your declarations




return 0;
}