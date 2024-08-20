/**
 * Author: Zakaria HAMMAL
 * email: hammalzakaria06@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num = 0; 

int myRand(int max, int min) {
    if(min == max )
    {
        return min;
    }

    if(min > max)
    {
        return -1;
    }

    if(num == 0)
    {
        time_t t = time(NULL); // Returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp) in seconds
        t = t * 1103515245 + 12345;
        num = t % (max - min) + min;
    }

    int a = num * 1103515245 + 12345;
    
    a = abs(a);

    num = a % (max - min) + min;
    
    return num;
}

int main(int argc, char* argv[])
{
    int max = 100; // Default Value
    int min = 1; // Default Value
    char again = 'y';

    while (again == 'y')
    {
        printf("Select the the max value :\t");
        scanf("%d", &max);
        printf("Select the the min value :\t");
        scanf("%d", &min);
            
        printf("%d\n", myRand(max, min));

        printf("Enter 'y' to try again :\t");
        getchar();
        scanf("%c", &again);
    } 

    return EXIT_SUCCESS;
}