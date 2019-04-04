/*Making changes in Code segment*/
#include <stdio.h>
int main(void)
{
    char *ptr = "Linux";
    *ptr = 'T';               // Attempt to change the 
                              // strind stored in read only segment
    
    printf("\n [%s] \n",ptr);
    
    return 0;

}
