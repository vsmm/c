#include <wiringPi.h>
#include <stdio.h>

//Pin 11 on Raspberry Pi corresponds to BCM GPIO 17 and wiringPi pin 0
#define BeepPin 0

int esc = 1
char notes[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' }; // a space represents a rest
int beats[] = { 1 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(0, HIGH);
    delayMicroseconds(tone);
    digitalWrite(0, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}



int main(void)
{
  //Check wiringPi setup
  if(-1 == wiringPiSetup())
  {
    printf("setup wiringPi failed!");
    return 1;
  }

  //Prepare GPIO0
  pinMode(0, OUTPUT);
  //Play the Imperial March
  switch (esc)
  {
    case 0:
        playNote(notes[0], 300);
        break;
    case 1:
        playNote(notes[1], 300);
        break;
    case 2:
        playNote(notes[2], 300);
        break;
  }
  return 0;
}
