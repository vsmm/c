#include <wiringPi.h>
#include <stdio.h>

//Pin 11 on Raspberry Pi corresponds to BCM GPIO 17 and wiringPi pin 0
#define BeepPin 0

int esc = 0;
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(0, HIGH);
    delayMicroseconds(tone);
    digitalWrite(0, LOW);
    delayMicroseconds(tone);
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
  while(esc == 4){
  printf("Ingresa tono a escuchar 0 = DO, 1 = RE, 2 = MI, 3 = Fa, 4 = salir\n");
  scanf("%d", &esc);
  switch (esc)
  {
    case 0:
        playTone(1915, 500);
        break;
    case 1:
        playTone(1700, 500);
        break;
    case 2:
        playTone(1519, 500);
        break;
    case 3:
        playTone(1432, 500);
        break;
  }
}
  //playNote(notes[0], 300);

  return 0;
}
