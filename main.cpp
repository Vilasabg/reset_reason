#include <Arduino.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

#define ADDR 0
#define NO_FAULT 0
#define FAULT 1

void setup() {
    lcd.begin(16, 2);

    byte lastFault = EEPROM.read(ADDR);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Reset: BOOT");

    lcd.setCursor(0, 1);
    lcd.print("Last: ");

    if (lastFault == NO_FAULT) {
        lcd.print("NONE");
    } else if (lastFault == FAULT) {
        lcd.print("POR/BOR/WDT");
    } else {
        lcd.print("UNKNOWN");
    }

    delay(3000);

    EEPROM.write(ADDR, NO_FAULT);
/*
    delay(2000);

    EEPROM.write(ADDR, FAULT);

    void (*resetFunc)(void) = 0;
    resetFunc();
*/
}

void loop() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Running...");
    delay(1000);
}