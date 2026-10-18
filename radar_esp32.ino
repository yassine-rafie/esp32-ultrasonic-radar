#define TRIG_PIN 12
#define ECHO_PIN 14

#define BUZZER_PIN 23

#define RED_LED 18
#define GREEN_LED 19

#define DISTANCE_LIMIT 10.0

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) {
    return -1.0;
  }

  return duration * 0.0343 / 2.0;
}

void loop() {
  float distance = getDistance();

  if (distance < 0) {
    Serial.println("Sin lectura");
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    noTone(BUZZER_PIN);
    delay(100);
    return;
  }

  Serial.print("Distancia: ");
  Serial.print(distance, 1);
  Serial.println(" cm");

  if (distance > DISTANCE_LIMIT) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER_PIN);
    delay(50);
  } else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER_PIN, 700);
    delay(300);
    noTone(BUZZER_PIN);
    delay(300);
  }
}
