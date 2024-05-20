#include <stdio.h>
#include <windows.h>

int main() {
    const char* audioFile = "test.wav"; // Replace with the path to your WAV file

    // Open the audio file
    char command[256];
    snprintf(command, sizeof(command), "open \"%s\" type waveaudio alias audio", audioFile);
    mciSendString(command, NULL, 0, NULL);

    // Play the audio file in the background
    mciSendString("play audio notify", NULL, 0, NULL);

    // Wait for the audio to finish playing (optional)
    // Sleep(5000); // Uncomment this line to wait for 5 seconds (5000 milliseconds) before ending the program

    // Close the audio file
    mciSendString("close audio", NULL, 0, NULL);

    return 0;
}
