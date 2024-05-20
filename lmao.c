#include<stdio.h>
#include<string.h>
char* bro();
char* bro(int b){
    static char f[50];
    switch(b){

    case 1: strcpy(f ,"Blinding_lights.wav");
    break;
    case 2:   strcpy(f ,"Too_many_nights");
    break;
    case 3:   strcpy(f ,"Art_deco");
    break;
    case 4: strcpy(f ,"Night_changes");
    break;
    case 5: strcpy(f ,"Money_Trees");
    break;
    case 6: strcpy(f ,"Perfect");
    break;
    case 7:strcpy(f ,"Popular");
    break;
    case 8:strcpy(f ,"Ice_cream");
    break;
    case 9:strcpy(f ,"After_dark");
    break;
    case 10: strcpy(f ,"Calm_down");
    break;
    case 11:strcpy(f ,"Sdp-Interlude");
    break;
    }  
    return f;
}
int main(){
    int b;
    char* str;
    while(1){
    scanf("%d",&b);
    str = bro(b);
    //strcpy(str , bro(b));
    printf("%s",str);
    }   
    //printf("%d.%s\n",i, f);
    /*x = x->next;
    i++;
    }
    printf("Press '0' to go to main menu.\n");
    scanf("%d",&k);
    if(k==0){
        main_menu();
    }*/
    return 0;
}