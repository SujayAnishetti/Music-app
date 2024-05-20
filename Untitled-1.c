#include <stdio.h>
#include<conio.h>
#include <Windows.h>
#include<dirent.h>
#include<mmsystem.h>
void song(char str[50]){
    const char* audioFile = str; // Replace with the path to your audio file
    printf("%o",audioFile);
    system(audioFile);
}
int main() {
    int ch;
    char str[50];
    while(ch!=3){
    scanf("%d",&ch);
    switch(ch){
        case 1:   strcpy(str,"Blinding_lights.wav") ;
        break;
        case 2:    strcpy(str,"test.wav");
        break;
        case 4:
        break;
        case
    case :exit(0);
    };
    song(str);
    }
    /*const char* audioFile = "Blinding_Lights.wav"; // Replace with the path to your audio file
    printf("%o",audioFile);
    system(audioFile);
    sleep(5000);*/
    // Play the audio file using PlaySound()

    //system("C:\Users\power\OneDrive\Documents\c programming");
    //system("")
   //PlaySound(TEXT("test.wav"),NULL,SND_ASYNC);
//printf("hi");/

    return 0;
}
