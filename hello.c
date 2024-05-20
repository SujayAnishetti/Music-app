#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_SONG_POOL 120
#define MAX_STRING_SIZE 75
typedef struct Song *songptr;
typedef struct Song
{
    char title[MAX_STRING_SIZE];
    char album[MAX_STRING_SIZE];
    char uri[MAX_STRING_SIZE];
    char id[MAX_STRING_SIZE];
    short int year;
    double duration;
} Song;
typedef struct PlaylistNode *node_ptr;
typedef struct PlaylistNode
{
    songptr song;
    node_ptr prev_song;
    node_ptr next_song;
} PlaylistNode;

void main_menu()
{
    printf("\n----------------------------------------------------------------------\n");
    printf("                              MAIN MENU\n");
    printf("----------------------------------------------------------------------\n");

    if (now_playing == NULL || now_playing->song == NULL)
    {
        printf("                          NO TRACK SELECTED\n");
    }
    else
    {
        printf("    NOW    |   %s\n", now_playing->song->title);
        printf("  PLAYING  |   %0.2lf minutes\n", now_playing->song->duration);
    }
    printf("----------------------------------------------------------------------\n");
    printf("   #   |  Action   \n");
    printf("----------------------------------------------------------------------\n");
    printf("   1   |  Create a new song\n");
    printf("   2   |  Display all available songs\n");
    if (does_playlist_exist())
        printf("   3   |  Delete playlist\n");
    else
        printf("   3   |  Create a new playlist\n");
    printf("   4   |  Add a song to the playlist\n");
    printf("   5   |  Show playlist\n");
    printf("   6   |  Play previous track\n");
    printf("   7   |  Play next track\n");
    if (now_playing != NULL && now_playing->song != NULL)
        printf("   8   |  Show more information about the song playing\n");
    printf("  -1   |  Exit music player\n");
    printf("----------------------------------------------------------------------\n");
    printf("                        Enter your choice below\n");
}