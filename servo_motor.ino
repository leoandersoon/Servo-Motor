#include <Servo.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

Servo servoMotorum;

int pos = 0; // declared the variable that can hold the servo position

void setup() {
  Serial.begin(9600);
  servoMotorum.attach(5);

  lcd.begin(16,2);
  lcd.print("Servo Motor");
  lcd.setCursor(0,1);
  lcd.print("App");
  delay(300);
}

void loop() {
  for (pos = 0; pos <= 180; pos++) {
    servoMotorum.write(pos);

    lcd.clear();
    lcd.print(0,1);
    lcd.print(pos);
    delay(100);
  }

  for (pos = 180; pos >= 0; pos--) {
    servoMotorum.write(pos);

    lcd.clear();
    lcd.print("Position: ");
    lcd.setCursor(0,1);
    lcd.print(pos);
    delay(100);
  }

}
