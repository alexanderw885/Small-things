#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

#define numProcesses 2

// Loops through numbers, checking if each one is an active process
// If it is, compares to list of names
// Closes all processes that match the given names
void ClosePrograms(char** names)
{
    for(int i = 0; i < 1000000; i++)
    {
        char filename[64];
        sprintf(filename, "/proc/%d/status", i);

        FILE* file;
        file = fopen(filename, "r");
        if(file == NULL)
            continue;
        
        char line[128];
        fgets(line, 128, file);
        
        for(int j = 0; j < numProcesses; j++)
        {
            if(strstr(line, names[j]) !=0)
                kill(i, SIGTERM);
        }
        fclose(file);
    }
    pthread_exit(0);
}

// Runs any given program in build directory
void run_script(char* name)
{
    char fullname[64];
    sprintf(fullname, "./build/%s", name);
    system(fullname);
    pthread_exit(0);
}

int main()
{
    pthread_t chrome;
    pthread_t obsidian;
    pthread_t killproc;

    int error = 0;
    error = pthread_create(&chrome, NULL, (void*)run_script, "SetChrome.sh");
    if(error)
    {
        printf("error initializing chrome\n");
        exit(1);
    }
    error = pthread_create(&obsidian, NULL, (void*)run_script, "SetObsidian.sh");
    if(error)
    {
        printf("error initializing obsidian\n");
        exit(1);
    }

    // Spotify is lower case for some reason
    char* toKill[numProcesses] = {"spotify", "Steam"};
    error = pthread_create(&killproc, NULL, (void*)ClosePrograms, toKill);
    if(error)
    {
        printf("error terminating processes\n");
        exit(1);
    }

    pthread_join(chrome, NULL);
    pthread_join(obsidian, NULL);
    pthread_join(killproc, NULL);


}