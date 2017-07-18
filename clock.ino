unsigned long time;
int piezoPin = 10;
int sdemoAlarmTime = 50; 
bool buttonOff = 0; 

int buttonPin = 7; 

//triggerstate = 9


//alarm time 50 seconds
//start the alarm to ring for 10 seconds, user should wake up
//if the user does not press the button than print a "p"

int h = 0; 
int s = 0; 
int m = 0; 
int flag = 0; 

void setup(){
  Serial.begin(9600);
}
void loop(){
  //Serial.print("Time: ");
  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.println(s);
  time = millis();
  //prints time since program started
  //Serial.println(time);
  // wait a second so as not to send massive amounts of data
  s = millis()/1000-m*60;
  delay(1000);
  //Serial.print("Time: "+h+m+s);

 checkAlarm(sdemoAlarmTime); 
 
 if(s==60){
  s=0;
  m=m+1;
 }
 
 if(m==60)
 {
  m=0;
  h=h+1;
  flag=flag+1;
 }
 
 if(h==13)
 {
  h=1;
 }
  
}

void activateAlarm(int buzzTime){
  tone(piezoPin, 2000, buzzTime/1000);
}

void checkAlarm(int secuntilAlarm){
  if (s = secuntilAlarm){
    activateAlarm(10); 
//    if(buttonOff){
//      noTone(piezoPin); 
//    }
  }
}

void checkButton(){
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    buttonOff = 1
  } else {
    buttonOff = 0; 
  }
}

