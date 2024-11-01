

const uint8_t PinReset = 7;
const uint8_t PinStrobe = 4;
const uint8_t PinAudioIn = A0; 
int filter = 80;

unsigned bands[7];

void readMSEQ7() {
  digitalWrite(PinReset, HIGH);
  digitalWrite(PinReset, LOW);
  delayMicroseconds(75);

  for (int i = 0; i < 7; ++i) {
    digitalWrite(PinStrobe, LOW);
    delayMicroseconds(40);

    bands[i] = analogRead(PinAudioIn);
    bands[i] = constrain(bands[i], filter, 1023);
    bands[i] = map(bands[i], filter, 1023, 0, 255);
    Serial.print(bands[i]);
    Serial.print(" ");

    digitalWrite(PinStrobe, HIGH);
    delayMicroseconds(40);
  }
  Serial.println();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PinReset, OUTPUT);
  pinMode(PinStrobe, OUTPUT);
  pinMode(PinAudioIn, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readMSEQ7();
  const int lower = 30;
  if (bands[0] > lower) {
    analogWrite(3, bands[0]);
  } else {
    analogWrite(3, 0);
  }
  
  if (bands[1] > lower) {
    analogWrite(3, bands[1]);
  } else {
    analogWrite(3, 0);
  }

  if (bands[3] > 40) {
    analogWrite(5, bands[3]);
  } else {
    analogWrite(5, 0);
  }

  if (bands[4] > lower) {
    analogWrite(5, bands[4]);
  } else {
    analogWrite(5, 0);
  }

  if (bands[5] > lower) {
    analogWrite(6, bands[5]);
  } else {
    analogWrite(6, 0);
  }

  if (bands[6] > lower) {
    analogWrite(6, bands[6]);
  } else {
    analogWrite(6, 0);
  }
}
