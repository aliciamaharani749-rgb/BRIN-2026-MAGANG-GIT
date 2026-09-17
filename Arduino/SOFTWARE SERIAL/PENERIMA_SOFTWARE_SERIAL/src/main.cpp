#include <Arduino.h>
#include <SoftwareSerial.h>

// Membuat jalur komunikasi Software Serial
// RX di Pin 10 (menerima dari TX Arduino 1)
// TX di Pin 11 (mengirim ke RX Arduino 1)
SoftwareSerial mySerial(10, 11);

void setup() {
  // Memulai komunikasi ke PC (Laptop)
  Serial.begin(9600);

  // Memulai komunikasi ke Arduino 1
  mySerial.begin(9600);

  // Pesan awal agar kita tahu Arduino 2 sudah menyala
  Serial.println("Arduino 2 Siap Mendengarkan Pesan dari Arduino 1...");
  Serial.println("--------------------------------------------------");
}

void loop() {
  // Jika ada pesan/data yang masuk dari Arduino 1 (melalui Pin 10)
  if (mySerial.available()) {
    // Baca pesan tersebut dan langsung cetak ke Serial Monitor laptop
    Serial.write(mySerial.read());
  }
}
