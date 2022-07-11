int pot = A0;
int level = 0;
int brightSign = 2;
int buttonLight = 3;
int led = 9;



void setup() {
    Serial.begin(9600);
    pinMode(brightSign, INPUT);
    pinMode(pot, INPUT);
    pinMode(led, OUTPUT);
    pinMode(buttonLight, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int minLevel = analogRead(pot);
  //scale level to match 10-150.
  minLevel = map(minLevel, 0, 1023, 10, 150);
  // brightSign connects to GPIO of BrightSign, 1 input, 1 output
  int playing = digitalRead(brightSign);
  int fade = 5;
  if (playing == LOW && level <= 254) {
    analogWrite(led, level);
    delay(fade);
    level = level + 1;
    digitalWrite(buttonLight, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);

  }
  else if (playing == HIGH && level >= minLevel) {
    analogWrite(led, level);
    delay(fade);
    level = level - 1;
    digitalWrite(buttonLight, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    
    

  }

}
