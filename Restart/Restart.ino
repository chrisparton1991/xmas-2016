#define DATA_PIN 2
#define LED_PIN 13
#define RESTART_PERIOD_MS 142000
#define RESTART_DELAY_MS 1000

uint32_t lastRestartMillis = 0;

void setup() {
  Serial.begin(9600);

  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(DATA_PIN, LOW);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  delay(5);
}

void loop() {
  uint32_t currentMs = millis();
  if (currentMs > lastRestartMillis) {
    Serial.println("Stopping power supply.");
    digitalWrite(DATA_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);

    delay(RESTART_DELAY_MS);

    Serial.println("Starting power supply.");
    digitalWrite(LED_PIN, LOW);
    digitalWrite(DATA_PIN, LOW);
    lastRestartMillis = millis() + RESTART_PERIOD_MS;
  }
}
