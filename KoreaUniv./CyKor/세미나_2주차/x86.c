#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=67305985;
    int name;
    fgets(&name, 45, stdin);
    printf("\n[buf]: %s\n", &name);
    printf("[check] %p\n", a);
    
    if(a!=0x4030201)
    {
        puts("\nYou are on the right way!");
    }

    if(a==0xdeadbeef)
    {
        puts("Yeah dude! You win!\nOpening your shell...");
        system("/bin/dash/");
        puts("Shell closed! Bye.");
    }

    return 0;
}