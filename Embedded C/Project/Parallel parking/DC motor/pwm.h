#include <lpc214x.h>
void pwm_init(void);
// Function to initialize PWM
void pwm_init(void) {
    // Configure PWM pins ( PWM1.2)
    // Set PWM frequency and duty cycle
    // Initialize PWM peripheral
    PINSEL0 |= (1 << 14);   // Configure P0.7 as PWM1.2
    PWMTCR = (1 << 1);      // Reset PWM TC & PR
    PWMPR = 0;              // Prescaler = 0
    PWMMCR = (1 << 1);      // Reset PWMTC on MR0 match
    PWMMR0 = 1000;          // PWM Period = 1000 (adjust as needed)
    PWMMR2 = 1;           // Initial PWM Duty Cycle = 50% (adjust as needed)
    PWMLER = (1 << 0) | (1 << 2); // Enable PWM1.2 Latch
    PWMPCR = (1 << 10);     // Enable PWM2 output
    PWMTCR = (1 << 0) | (1 << 3); // Enable PWM, Reset PWM TC & PR
}

// Function to set motor speed (adjust PWM duty cycle)
void set_motor_speed(unsigned int duty_cycle) {
    PWMMR2 = duty_cycle;    // Set PWM duty cycle (0-1000)
    PWMLER = (1 << 2);      // Enable PWM1.2 Latch
}

