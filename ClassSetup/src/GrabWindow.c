#include  <stdlib.h>
#include <stdio.h>
#include <string.h>

// Expect input from wmctrl -l
// Loops through all lines in stdin, compares each to argument in argv
// Prints to stdout the full name of matching window
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("provide argument\n");
        exit(1);
    }

    // Looping through input
    char input[256];
    while(fgets(input, 256, stdin))
    {
        if((strstr(input, argv[1]) == 0))
            continue;
        
        // String matches, need to remove uneeded content from beginning of string
        input[strcspn(input, "\n")] = 0;
        char* token;
        char* delim = " ";
        token = strtok(input, delim);
        token = strtok(NULL, delim);
        token = strtok(NULL, delim);
        delim = "\n";
        token = strtok(NULL, delim);
        
        printf("%s", token);
        exit(0);
        
    }
}
