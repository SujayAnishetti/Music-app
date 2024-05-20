#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <Windows.h>
struct node {
    int data;
    struct node *next;
};
int c = 0;
struct node *head;
struct node *x;
int b=0;
int pos=0;
int p=0;
int size =0;
int l;
int inf;
char str[50];
void list();
int create_playlist();
int display_playlist();
void play_search();
char* assign(int b);
void song();
void prev();
void next();
void delete();
void delete_playlist();
void info();
void main_menu()
{
    int c,d,key;
    printf("\n----------------------------------------------------------------------\n");
    printf("                              MAIN MENU\n");
    printf("----------------------------------------------------------------------\n");
    printf("   1   |  Display all available songs\n");
    printf("   2   |  Create a playlist\n");
    printf("   3   |  Show playlist\n");
    printf("   4   |  Play the music from the playlist\n");
    printf("   5   |  Add a song to the playlist\n");
    printf("   6   |  Play previous track\n");
    printf("   7   |  Play next track\n");
    printf("   8   |  Show more information about the song playing\n");
    printf("   9   |  Delete a song from the playlist\n");   
    printf("  -1   |  Exit music player\n");
    printf("----------------------------------------------------------------------\n");
    printf("                        Enter your choice below\n");
    //printf("%d",l);
    scanf("%d",&c);
    switch(c){
        case 1: system("cls"); 
        list();
        scanf("%d",&key);
        if(key==12){
            system("cls");
            main_menu();
        }
        break;
        case 2: system("cls");
        list();
        printf("Press '0' to stop adding\n" );
            while(1){
            create_playlist();
        }
        break;
        case 3: display_playlist();
            printf("Press '0' to direct to main menu.");
            scanf("%d",&key);
            if(key==0){
                system("cls");
                main_menu();
            }
        break;
        case 4: display_playlist(); 
        play_search();
        break;
        case 5 : printf("The playlist  currrently is:\n");
        display_playlist();
        printf("List of songs available is:\n");
        list();
        create_playlist();
        break;
        case 6: prev();
        break;
        case 7: next();
        break;
        case 8: printf("More info about the currently playing is..... %s\n",str);
        info();
        printf("\nPress '0' to direct to main menu. ");
        scanf("%d",&key);
        if(key == 0){
            system("cls");
            main_menu();
        }
        break;
        case 9: system("cls");
        display_playlist();
        delete();
            printf("Press '0' to direct to main menu.");
            scanf("%d",&key);
            if(key==0){
                system("cls");
                main_menu();
            }
        break;
        case -1: printf("Thank you for using our music player,\nPlease use us again....");
        exit(0);
        default: printf("Please selection a valid option.");
                main_menu();
    }
    while ( x != NULL)// check  this again
{
    size++;
    x= x->next;
}
}
void list(){
    int key;
    printf("----------------------------------------------------------------------\n");
    printf("1.Blinding Lights.\n2.Too_many_nights.\n3.Art_deco.\n4.Night_changes.\n5.Money_Trees.\n6.Perfect.\n7.Popular.\n8.Ice_cream.\n9.After_dark.\n10.Calm_down.\n11.Sdp-Interlude.\n12.Back To Main Menu.\n");
    printf("----------------------------------------------------------------------\n");
}
int create_playlist() {
    int p, i, n;
    struct node *list1 = (struct node *)malloc(sizeof(struct node));
    struct node *list2;
    printf("Enter The Song Index Number and Its Position:");
    scanf("%d", &n);
    if(n==0){
        system("cls");
        main_menu();

        return 0;
    }
if(n!=0){
    scanf("%d",&p);
    if (p <= 0 || p > c + 1 )
    {
    printf("Enter a valid position\n");
    main_menu();
    }
 
    else {
    c++;
    list1->data = n;
    list1->next = NULL;
    if (p == 1) {
    list1->next = head;
    head = list1;
    } 
    else {
    list2 = head;
    for (i = 0; i < p - 2; i++) {
    list2 = list2->next;
    }
    list1->next = list2->next;
    list2->next = list1;
    }
    }
}
    return 0;
}
int display_playlist(){
    int i=1,b,k,key;
    char *str;
    struct node *x = head;
    system("cls");
     if (x == NULL) {
     printf("PLayList is empty.\n");
     return 0;
    }
    while (x != NULL) {
    b = x->data;
    str = assign(b);
    printf("----------------------------------------------------------------------\n");
    printf("   %d   |  %s\n",i, str);
    printf("----------------------------------------------------------------------\n");
    x = x->next;
    i++;
    }
    return 0;
}
char* assign(int b){
    static char f[50];
    switch(b){
    case 1: strcpy(f ,"Blinding_lights.wav");
    break;
    case 2:  strcpy(f ,"Too_many_nights.wav");
    break;
    case 3:  strcpy(f ,"Art_deco.wav");
    break;
    case 4: strcpy(f ,"Night_changes.wav");
    break;
    case 5: strcpy(f ,"Money_Trees.wav");
    break;
    case 6: strcpy(f ,"Perfect.wav");
    break;
    case 7:strcpy(f ,"Popular.wav");
    break;
    case 8:strcpy(f ,"Ice_cream.wav");
    break;
    case 9:strcpy(f ,"After_dark.wav");
    break;
    case 10: strcpy(f ,"Calm_down.wav");
    break;
    case 11: strcpy(f ,"Sdp_Interlude.wav");
    break;
    }  
    return f;
}
void song(char str[50]){
    const char* audioFile = str;
    //printf("%o",audioFile);
    printf("The song Currently playing is %s",str);
    system(audioFile);

}
void play_search()
{
    int p=0,key;
    char* str;
    struct node *x=head;
    printf("Enter the Index of the song you want to play:\n");
    scanf("%d", &pos);
    while (x != NULL)
    {
        p++;
        //printf("%d", x-> data);
        //if(x -> data =pos)
        if(p == pos)
        {
        b=1;
        break;
        }
     x= x->next;
    }
    if ( b == 1)
    {
        str = assign(x -> data);
        song(str);
        inf = x->data;
    }
    l= p;
    main_menu();

}
void prev(){
    int n,k=0;
    char* str;
struct node *x=head;
if (l==0){
    printf("No song was played previously.");
}
else{
    while (x != NULL)
    {
        k++;
        if(l-1 == k)
        {
        n=x->data;
        str = assign(n);
        song(str);
        break;
        }
     x= x->next;
    }  
    //printf("%d\n",p);
    p--;
//printf("%d",l);
} 
    main_menu();
} 
void next(){
int n,k=0;
char* str;
struct node *x=head;

//printf("\n%d %d",l,size);
if (l==size){
    printf("This is the last song of the playlist.");
}
else{
    while (x != NULL)
    {
        k++;
        if(l+1 == k)
        {
        n=x->data;
        str = assign(n);
        song(str);
        break;
        }
     x= x->next;
    //printf("%d\n%d",p,l);
    p=p+1;
    }  
}
    main_menu();
}
void delete(){
    int p, i;
    struct node *temp1 = head, *temp2;
    printf("Enter the Index of the song you want to delete:");
    scanf("%d", &p);
    if ((p <= 0) || p > c) {
    printf("Enter a valid position\n");
 } 

 
 else {
    c--;
    if (p == 1) {
    head = temp1->next;
    free(temp1);
 } 
 else {
    for (i = 0; i < p - 2; i++) {
     temp1 = temp1->next;
 }
temp2 = temp1->next;
 temp1->next = temp2->next;
 free(temp2);

 }
 }
}
void delete_playlist(){
    int p=0, i;
    struct node *temp1 = head, *temp2;
    struct node *x=head;
    while(x !=NULL){
        p++;
    c--;
    if (p == 1) {
    head = temp1->next;
    free(temp1);
 } 
 else {
    for (i = 0; i < p - 2; i++) {
     temp1 = temp1->next;
 }
temp2 = temp1->next;
 temp1->next = temp2->next;
 free(temp2);
 }
    }
}
void info(){
    //printf("%d",inf);
    static char f[50];
    switch(inf){

    case 1: printf("Abel Makkonen Tesfaye (born February 16, 1990), known professionally as the Weeknd, is a Canadian singer, songwriter, and record producer.\n A prominent figure in contemporary popular music, he is noted for his unconventional music production, \nartistic reinventions, and his signature use of the falsetto register.\n His accolades include 4 Grammy Awards, 20 Billboard Music Awards, 22 Juno Awards, 6 American Music Awards, 2 MTV Video Music Awards, a Latin Grammy Award,\n and nominations for an Academy Award and a Primetime Emmy Award.");
    break;
    case 2:  printf("Leland Tyler Wayne (born September 16, 1993), known professionally as Metro Boomin, is an American record producer, record executive, and DJ.\n He is known for his dark production style and its influence on modern hip hop and trap.\n He is also notable in the music industry for his producer tags 'If Young Metro don't trust you, I'm gon' shoot you' and 'Metro Boomin want some more, nigga',\n respectively spoken by frequent collaborators Future and Young Thug; additional collaborators include The Weeknd, 21 Savage, Drake, \nTravis Scott, Swae Lee, and Kanye West.");
    break;
    case 3:  printf("Elizabeth Woolridge Grant (born June 21, 1985), known professionally as Lana Del Rey, is an American singer-songwriter.\n Her music is noted for its cinematic quality and exploration of tragic romance, glamour, and melancholia, with frequent references to contemporary pop culture and 1950s–1970s Americana.\n She is the recipient of various accolades, including two Brit Awards, two Billboard Women in Music, two MTV Europe Music Awards, and a Satellite Award, \nin addition to nominations for six Grammy Awards and a Golden Globe Award. Variety honored her at their Hitmakers Awards for being 'one of the most influential singer-songwriters of the 21st century'");
    break;
    case 4: printf("One Direction, often shortened to 1D, are an English-Irish pop boy band formed in London in 2010.\n The group is composed of Niall Horan, Liam Payne, Harry Styles, Louis Tomlinson, and previously Zayn Malik until his departure from the group in March 2015. \nThe group signed with Simon Cowell's record label Syco Records after forming and finishing third in the seventh series of the British televised singing competition The X Factor in 2010.");
    break;
    case 5: printf("Kendrick Lamar Duckworth (born June 17, 1987) is an American rapper and songwriter. \nKnown for his progressive musical styles and socially conscious songwriting, he is often considered one of the most influential hip hop artists of his generation.\n Born and raised in Compton, California, Lamar began his career as a teenager performing under the stage name K.Dot. \nHe quickly garnered local attention which led to him signing a recording contract with Top Dawg Entertainment (TDE) in 2005");
    break;
    case 6: printf("Edward Christopher Sheeran MBE (/ˈʃɪərən/; born 17 February 1991) is an English singer-songwriter. \nBorn in Halifax, West Yorkshire, and raised in Framlingham, Suffolk, he began writing songs around the age of eleven. \nIn early 2011, Sheeran independently released the extended play No. 5 Collaborations Project. He signed with Asylum Records the same year.");
    break;
    case 7: printf("Abel Makkonen Tesfaye (born February 16, 1990), known professionally as the Weeknd, is a Canadian singer, songwriter, and record producer.\n A prominent figure in contemporary popular music, he is noted for his unconventional music production, artistic reinventions, and his signature use of the falsetto register.\n His accolades include 4 Grammy Awards, 20 Billboard Music Awards, 22 Juno Awards, 6 American Music Awards, 2 MTV Video Music Awards, a Latin Grammy Award, and \nnominations for an Academy Award and a Primetime Emmy Award.");
    break;
    case 8:printf("Blackpink (Korean: 블랙핑크; RR: Beullaekpingkeu, stylized in all caps or as BLɅϽKPIИK) is a South Korean girl group formed by YG Entertainment,\n consisting of members Jisoo, Jennie, Rosé, and Lisa. The group debuted in August 2016 with their single album Square One, which featured 'Whistle' and 'Boombayah', their first number-one entries on South Korea's Gaon Digital Chart and\n the US Billboard World Digital Song Sales chart, respectively.");
    break;
    case 9:printf("Forrest Avery Carney (born March 24, 1992), better known as Mr.Kitty or Michael Kenneth Echo Strobes, is an American singer-songwriter, record producer, and DJ.\n His style is described as being synthwave, synthpop, new wave, witch house, and dark wave and has been said to awaken a nostalgic feeling in listeners.\n He is best known for his song 'After Dark', which was released in 2014 and went viral after a fan video was published on YouTube in 2019");
    break;
    case 10: printf("Selena Marie Gomez (/səˈliːnə ˈɡoʊmɛz/ sə-LEE-nə GOH-mez; born July 22, 1992) is an American singer, actress, producer, and businesswoman.\n Gomez began her acting career on the children's television series Barney & Friends (2002–2004). As a teenager, she rose to prominence for starring as Alex Russo on the \nDisney Channel television series Wizards of Waverly Place (2007–2012).");
    break;
    case 11: printf("Jacques Bermon Webster II (born April 30, 1991), better known by his stage name Travis Scott (formerly stylized as Travi$ Scott),\n is an American rapper, singer, songwriter, and record producer. His stage name is the namesake of a favorite uncle combined with the first name of one of his inspirations,\n Kid Cudi (whose real name is Scott Mescudi).");
    break;
    default: printf("No song is being played currently, please play a song to get more info");
    main_menu();
    }  
}
int main(){ 
    system("cls");
    int ch;
    while(ch){
        main_menu();
        scanf("%d",&ch);
    }
    return 0;

}