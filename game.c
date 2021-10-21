#include<stdio.h>
#include<unistd.h>

int main(int argc, char**argv){
    char *user;
    int pass;
    printf("Enter the password: ");
    scanf("%d",&pass);
    printf("Enter your Username: ");
    scanf("%s",user);
    FILE *use = fopen("user.txt","a");
    if(!access("user.txt",F_OK)){
        fprintf(use,user);
        fprintf(use,"\t%d",pass);
        fprintf(use,"\n");
        fclose(use);
    }
    else{
        use = fopen("user.txt","w");
        fprintf(use,user);
        fprintf(use,"\t%d",pass);
        fclose(use);
    }   
    return 0;
}