const int led = 6;

void setup(){
pinMode(led, OUTPUT);

}

void loop(){
  analogWrite(led, 128);

}