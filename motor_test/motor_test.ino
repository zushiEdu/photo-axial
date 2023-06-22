  int rightValue;
  int leftValue;

  int lCal;
  int rCal;

void setup() {
    Serial.begin(9600);
  // right motor
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  // left motor
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(A5, INPUT);
  pinMode(A4, INPUT);

  lCal = analogRead(A4);
  rCal = analogRead(A5);
}

void loop() {
  rightValue = analogRead(A5);
    Serial.println(rightValue - rCal); 
  leftValue = analogRead(A4);
    Serial.println(leftValue - lCal); 
    
    Serial.println(); 

  if (leftValue > lCal + 7){
    // turn on left motor only
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  } 
  if (rightValue > rCal + 14){
    // turn on right motor only
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  delay(100);
}
