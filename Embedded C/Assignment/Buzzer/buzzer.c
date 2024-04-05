#include <lpc214x.h>

#define BUZZER_PIN (1 << 20) // Assuming buzzer is connected to P0.20

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1000; j++); // Adjust this loop for your MCU clock speed
}

int main() {
    IO0DIR |= BUZZER_PIN; // Set P0.20 as output

    while (1) {
        IO0SET |= BUZZER_PIN; // Turn ON buzzer
        delay_ms(500);         // Delay for half a second
        IO0CLR |= BUZZER_PIN; // Turn OFF buzzer
        delay_ms(500);         // Delay for half a second
    }
    return 0;
}
