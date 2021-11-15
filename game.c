#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct names{
    char *name;
    struct names*next;
}names;

names *namelog = NULL;

void login(){
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
}
void adduser(char *name){
    names *node;
    names *temp = malloc(sizeof(names));
    temp->name = name;
    temp->next = NULL;
    node = temp;
    node->next = namelog;
    namelog = node;

}
void showuser(){
    for(names *temp; temp!=NULL; temp = temp->next){
        printf("%s, ",temp->name);
    }
}
int main(int argc, char**argv){
    login();
    adduser("mizuhara");
    adduser("mai san");
    adduser("kaori");
    showuser();
    

    return 0;
}