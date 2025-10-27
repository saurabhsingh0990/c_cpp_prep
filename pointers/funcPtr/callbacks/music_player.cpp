#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void onSongEnd(){
    printf("\n Song ended !");
}

void onError(){
    printf("\nError in playing song");
}

void play(const char* song, void (*onSongEnd)(), void (*onError)()){
    printf("\n Now Playing: %s", song);
    int val = rand()%2;
    if (val) onSongEnd();
    else onError();

}
int main(){
    srand(time(NULL));
    play("Fix You - Coldplay", onSongEnd, onError);
    return 0;
}