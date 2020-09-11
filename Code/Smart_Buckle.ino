#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

#define SW1 2
#define SW2 3

int henshincnt = 0;
int readycnt = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);

  Serial.begin (9600);
  mp3_set_serial (Serial);      //set Serial for DFPlayer-mini mp3 module
  delay(1);                     // delay 1ms to set volume
  mp3_set_volume (22);          // value 0~30
  delay(200); 
  mp3_play(1); //전원이 켜지면 들리는 사운드.
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(SW1) == LOW)&&(digitalRead(SW2) == HIGH)){
    readycnt = 0;
    henshincnt = 1; //변신 플래그로 전환
  }
  if(henshincnt == 1){
    mp3_play(2); //변신음
    delay(500);
  }
  if((digitalRead(SW2) == LOW)&&(digitalRead(SW1) == HIGH)){
    henshincnt = 0;
    readycnt = 1; //변신 대기 플래그로 전환
  }
  if(readycnt == 1){
    mp3_play(3); //변신해제음
    delay(500);
  }
}
