#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdarg.h>

typedef struct names{
    char *name;
    struct names*next;
}names;

void login(){
    char user[30];
    int pass;
    printf("Enter your Username: ");
    gets(user);
    fflush(stdin);
    fflush(stdout);
    printf("Enter the password: ");
    scanf("%d",&pass);
    FILE *use = fopen("user.txt","a");
    if(!access("user.txt",F_OK)){
        fprintf(use,"%s",user);
        fprintf(use,"\t%d",pass);
        fprintf(use,"\n");
        fclose(use);
    }
    else{
        use = fopen("user.txt","w");
        fprintf(use,"%s",user);
        fprintf(use,"\t%d",pass);
        fclose(use);
    }
}
names *namelog = NULL;
void adduser(char *name){
    names *node;
    names *temp = malloc(sizeof(names));
    temp->name = name;
    temp->next = NULL;
    node = temp;
    node->next = namelog;
    namelog = node;

}
int players;
void showuser(){
    for(names *temp = namelog; temp!=NULL; temp = temp->next){
        printf("%s, ",temp->name);
    }
    printf("\n");
     while(namelog!=NULL){
        namelog= namelog->next;
        players++;
    }
}
void game(){
    printf("The number of players playing are-> %d\n",players);
    if(players == 2){
        
    }
    else if(players == 4){

    }
    else {
        printf("Only valid number of players can play the game (2,4)");
    }
}

int main(int argc, char**argv){
    login();
    adduser("mizuhara");
    adduser("mai san");
    adduser("kaori");
    showuser();
    printf("Press any button to continue\n");
    getchar();
    system("cls");
    game();
    sleep(10);
    return 0;
}