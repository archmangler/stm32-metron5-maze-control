//LED pins: PA6, PA7, PB6, PC7
//Button pins: PA0, PA1, PA2, PA3

#define PERIPH_BASE (0x40000000UL)
#define AHB1PERIPH_OFFSET (0x00020000UL)
#define AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET) //0x4000 0000 + 0x0002 0000 = 0x4002 0000
#define GPIOA_OFFSET (0x0000U) // 0x0000 0000 ...the zeroes AFTER matter. The zeroes before, don't.
#define GPIOA_BASE (AHB1PERIPH_BASE + GPIOA_OFFSET)
#define GPIOB_OFFSET (0x0400U)
#define GPIOB_BASE (AHB1PERIPH_BASE + GPIOB_OFFSET)
#define GPIOC_OFFSET (0x0800U)
#define GPIOC_BASE (AHB1PERIPH_BASE + GPIOC_OFFSET)

#define RCC_OFFSET (0x3800UL) //The buses are transporters of clock signal. RCC module (Reset Clock Control), allows clock signal to the GPIO port via the bus.
#define RCC_BASE (AHB1PERIPH_BASE + RCC_OFFSET)

#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
#define SYSCFG_BASE (APB2PERIPH_BASE + 0x3800UL)
#define EXTI_BASE (APB2PERIPH_BASE + 0x3C00UL)

#define AHB1EN_R_OFFSET (0x30UL)
#define RCC_AHB1EN_R (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
#define RCC_APB2ENR (*(volatile unsigned int *)(RCC_BASE + 0x44UL)) // APB2 peripheral clock enable register

#define SYSCFG_EXTICR1 (*(volatile unsigned int *)(SYSCFG_BASE + 0x08UL)) // External interrupt configuration register 1 (pins 0-3)
#define SYSCFG_EXTICR2 (*(volatile unsigned int *)(SYSCFG_BASE + 0x0CUL)) // External interrupt configuration register 2 (pins 4-7)
#define SYSCFG_EXTICR4 (*(volatile unsigned int *)(SYSCFG_BASE + 0x14UL)) // External interrupt configuration register 4 (pins 12-15)

#define EXTI_IMR (*(volatile unsigned int *)(EXTI_BASE + 0x00UL)) // Interrupt mask register
#define EXTI_RTSR (*(volatile unsigned int *)(EXTI_BASE + 0x08UL)) // Rising trigger selection register
#define EXTI_FTSR (*(volatile unsigned int *)(EXTI_BASE + 0x0CUL)) // Falling trigger selection register
#define EXTI_PR (*(volatile unsigned int *)(EXTI_BASE + 0x14UL))   // Pending register

#define NVIC_ISER0 (*(volatile unsigned int *)(0xE000E100UL)) // NVIC interrupt set enable register 0
#define NVIC_ISER1 (*(volatile unsigned int *)(0xE000E104UL)) // NVIC interrupt set enable register 1

#define MODE_R_OFFSET  (0x00UL)
#define GPIOA_MODE_R (*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))
#define GPIOB_MODE_R (*(volatile unsigned int *)(GPIOB_BASE + MODE_R_OFFSET))
#define GPIOC_MODE_R (*(volatile unsigned int *)(GPIOC_BASE + MODE_R_OFFSET))

#define PUPDR_R_OFFSET (0x0CUL)
#define GPIOA_PUPDR_R (*(volatile unsigned int *)(GPIOA_BASE + PUPDR_R_OFFSET))
#define GPIOB_PUPDR_R (*(volatile unsigned int *)(GPIOB_BASE + PUPDR_R_OFFSET))
#define GPIOC_PUPDR_R (*(volatile unsigned int *)(GPIOC_BASE + PUPDR_R_OFFSET))

#define AFR_LOW_R_OFFSET (0x20UL)  // Alternate function low register (pins 0-7)
#define GPIOA_AFRL_R (*(volatile unsigned int *)(GPIOA_BASE + AFR_LOW_R_OFFSET))
#define GPIOC_AFRL_R (*(volatile unsigned int *)(GPIOC_BASE + AFR_LOW_R_OFFSET))

#define IDR_R_OFFSET (0x10UL)
#define GPIOA_IDR_R (*(volatile unsigned int *)(GPIOA_BASE + IDR_R_OFFSET))
#define GPIOB_IDR_R (*(volatile unsigned int *)(GPIOB_BASE + IDR_R_OFFSET))
#define GPIOC_IDR_R (*(volatile unsigned int *)(GPIOC_BASE + IDR_R_OFFSET))

/*
 * (1U<<10) Set ONLY bit 10 to 1
 * &=~(1U<<11) Set ONLY bit 11 to 0  */

#define OD_R_OFFSET (0x14UL)
#define GPIOA_OD_R (*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))
#define GPIOB_OD_R (*(volatile unsigned int *)(GPIOB_BASE + OD_R_OFFSET))
#define GPIOC_OD_R (*(volatile unsigned int *)(GPIOC_BASE + OD_R_OFFSET))

#define GPIOAEN (1U<<0) //Enable GPIOA clock (bit 0)
#define GPIOBEN (1U<<1) //Enable GPIOB clock (bit 1)
#define GPIOCEN (1U<<2) //Enable GPIOC clock (bit 2)

//Button pins: PA0, PA1, PA3, PA4, PC2, PC13 (B1 USER button)
#define BTN0_PIN (1U<<0)  //PA0
#define BTN1_PIN (1U<<1)  //PA1
#define BTN_PA3_PIN (1U<<3)  //PA3
#define BTN2_PIN (1U<<4)  //PA4 (replaced PA2)
#define BTN3_PIN (1U<<2)  //PC2 (replaced PA3)
#define BTN_USER_PIN (1U<<13)  //PC13 (B1 USER button)

//LED pins: PA5 (onboard LED), PA6, PA7, PB6, PC7, PB9, PB10, PB12, PB13, PC0, PC1
#define LED_ONBOARD_PIN (1U<<5)  //PA5 (onboard LED LD2)
#define LED0_PIN (1U<<6)  //PA6
#define LED1_PIN (1U<<7)  //PA7
#define LED2_PIN (1U<<6)  //PB6
#define LED3_PIN (1U<<7)  //PC7
#define LED4_PIN (1U<<9)  //PB9
#define LED5_PIN (1U<<10)  //PB10
#define LED6_PIN (1U<<12)  //PB12
#define LED7_PIN (1U<<13)  //PB13
#define LED_A_PIN (1U<<0)  //PC0
#define LED_B_PIN (1U<<1)  //PC1
#define LED_C_PIN (1U<<5)  //PC5
#define LED_D_PIN (1U<<6)  //PC6

// Timer value for LED C (1.5 seconds)
// With main loop delay of 10000, we need approximately 1500 iterations for 1.5 seconds
#define LED_C_ON_DURATION 1500

// Timer value for LED D (2 seconds)
// With main loop delay of 10000, we need approximately 2000 iterations for 2 seconds
#define LED_D_ON_DURATION 2000

// Pause duration between LED C and LED D activations (1 second)
#define LED_CD_PAUSE_DURATION 1000

// Number of LED C/D diagnostic cycles per test run
#define LED_CD_TEST_CYCLES 1

// State machine definitions for LED C/D random test routine
#define LED_CD_STATE_IDLE 0
#define LED_CD_STATE_START_C 1
#define LED_CD_STATE_WAIT_C 2
#define LED_CD_STATE_PAUSE_AFTER_C 3
#define LED_CD_STATE_START_D 4
#define LED_CD_STATE_WAIT_D 5
#define LED_CD_STATE_PAUSE_AFTER_D 6


// Interrupt handler function declarations
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);  // PC2 uses EXTI2
void EXTI3_IRQHandler(void);  // PA3 uses EXTI3
void EXTI4_IRQHandler(void);  // PA4 uses EXTI4
void EXTI15_10_IRQHandler(void); // Shared interrupt for EXTI10-15 (PC13 uses EXTI13)

// LED timer tracking variables
// Decrementing counters (0 = LED should be off, >0 = LED is on, countdown to 0)
volatile unsigned int led0_timer = 0;  // PA6
volatile unsigned int led1_timer = 0;  // PA7
volatile unsigned int led2_timer = 0;  // PB6
volatile unsigned int led3_timer = 0;  // PC7
volatile unsigned int led_onboard_timer = 0;  // PA5
volatile unsigned int led4_timer = 0;  // PB9
volatile unsigned int led5_timer = 0;  // PB10
volatile unsigned int led6_timer = 0;  // PB12
volatile unsigned int led7_timer = 0;  // PB13
volatile unsigned int led_a_timer = 0;  // PC0
volatile unsigned int led_b_timer = 0;  // PC1
volatile unsigned int led_c_timer = 0;  // PC5
volatile unsigned int led_d_timer = 0;  // PC6

// Cooldown tracking variables - track last activation time for each LED
// Incrementing counter (tracks time since last activation)
volatile unsigned int led0_last_activation = 0;  // PA6
volatile unsigned int led1_last_activation = 0;  // PA7
volatile unsigned int led2_last_activation = 0;  // PB6
volatile unsigned int led3_last_activation = 0;  // PC7
volatile unsigned int led_onboard_last_activation = 0;  // PA5
volatile unsigned int led4_last_activation = 0;  // PB9
volatile unsigned int led5_last_activation = 0;  // PB10
volatile unsigned int led6_last_activation = 0;  // PB12
volatile unsigned int led7_last_activation = 0;  // PB13
volatile unsigned int led_a_last_activation = 0;  // PC0
volatile unsigned int led_b_last_activation = 0;  // PC1
volatile unsigned int led_c_last_activation = 0;  // PC5
volatile unsigned int led_d_last_activation = 0;  // PC6

// LED C/D random test control variables
volatile unsigned int led_cd_test_state = LED_CD_STATE_IDLE;
volatile unsigned int led_cd_test_cycle = 0;
volatile unsigned int led_cd_pause_start = 0;

// Global time counter (increments in main loop)
volatile unsigned int global_time_counter = 0;

// Interrupt processing lock - ensures only one button interrupt is handled at a time
volatile unsigned int interrupt_processing = 0;

// Timer value for 0.1 seconds
// With main loop delay of 10000, we need approximately 100 iterations for 0.1 seconds
// Adjust based on actual timing: if loop takes ~1ms, then 100 loops = ~100ms
#define LED_ON_DURATION 100

// Timer value for 0.6 seconds (PIR motion LEDs) - doubled from 0.3 seconds
// With main loop delay of 10000, we need approximately 600 iterations for 0.6 seconds
#define PIR_LED_ON_DURATION 600

// Helper functions to control LED C and D with mutual exclusion
// These ensure LED C and D are never on at the same time
static void turn_on_led_c(void)
{
	// Turn off LED D first (mutual exclusion)
	GPIOC_OD_R &=~ LED_D_PIN;
	led_d_timer = 0;
	// Turn on LED C
	GPIOC_OD_R |= LED_C_PIN;
	led_c_timer = LED_C_ON_DURATION;
	led_c_last_activation = global_time_counter;
}

static void turn_on_led_d(void)
{
	// Turn off LED C first (mutual exclusion)
	GPIOC_OD_R &=~ LED_C_PIN;
	led_c_timer = 0;
	// Turn on LED D
	GPIOC_OD_R |= LED_D_PIN;
	led_d_timer = LED_D_ON_DURATION;
	led_d_last_activation = global_time_counter;
}

// Simple 16-bit LFSR pseudo-random generator
static unsigned int generate_random_value(void)
{
	static unsigned int lfsr = 0xACE1u;
	unsigned int lsb = lfsr & 1u;
	lfsr >>= 1u;
	if(lsb)
	{
		lfsr ^= 0xB400u;
	}
	return lfsr;
}

// Cooldown period: 1 second between LED activations
// With main loop delay of 10000, we need approximately 1000 iterations for 1 second
#define LED_COOLDOWN_PERIOD 1000

int main(void)
{
	/*1. Enable clock access to GPIOA, GPIOB, and GPIOC*/
	RCC_AHB1EN_R |= GPIOAEN;
	RCC_AHB1EN_R |= GPIOBEN;
	RCC_AHB1EN_R |= GPIOCEN;

	/*2. Configure LED pins as outputs*/
	// PA5: mode bits 10-11 (pin 5 * 2 = 10) - Onboard LED
	GPIOA_MODE_R |= (1U<<10);  //set bit 10 to 1
	GPIOA_MODE_R &=~ (1U<<11); //set bit 11 to 0 (output mode: 01)
	
	// PA6: mode bits 12-13 (pin 6 * 2 = 12)
	GPIOA_MODE_R |= (1U<<12);  //set bit 12 to 1
	GPIOA_MODE_R &=~ (1U<<13); //set bit 13 to 0 (output mode: 01)
	
	// PA7: mode bits 14-15 (pin 7 * 2 = 14)
	GPIOA_MODE_R |= (1U<<14);  //set bit 14 to 1
	GPIOA_MODE_R &=~ (1U<<15); //set bit 15 to 0 (output mode: 01)
	
	// PB6: mode bits 12-13 (pin 6 * 2 = 12)
	GPIOB_MODE_R |= (1U<<12);  //set bit 12 to 1
	GPIOB_MODE_R &=~ (1U<<13); //set bit 13 to 0 (output mode: 01)
	
	// PC7: mode bits 14-15 (pin 7 * 2 = 14)
	GPIOC_MODE_R |= (1U<<14);  //set bit 14 to 1
	GPIOC_MODE_R &=~ (1U<<15); //set bit 15 to 0 (output mode: 01)
	
	// PB9: mode bits 18-19 (pin 9 * 2 = 18)
	GPIOB_MODE_R |= (1U<<18);  //set bit 18 to 1
	GPIOB_MODE_R &=~ (1U<<19); //set bit 19 to 0 (output mode: 01)
	
	// PB10: mode bits 20-21 (pin 10 * 2 = 20)
	GPIOB_MODE_R |= (1U<<20);  //set bit 20 to 1
	GPIOB_MODE_R &=~ (1U<<21); //set bit 21 to 0 (output mode: 01)
	
	// PB12: mode bits 24-25 (pin 12 * 2 = 24)
	GPIOB_MODE_R |= (1U<<24);  //set bit 24 to 1
	GPIOB_MODE_R &=~ (1U<<25); //set bit 25 to 0 (output mode: 01)
	
	// PB13: mode bits 26-27 (pin 13 * 2 = 26)
	GPIOB_MODE_R |= (1U<<26);  //set bit 26 to 1
	GPIOB_MODE_R &=~ (1U<<27); //set bit 27 to 0 (output mode: 01)
	
	// PC0: mode bits 0-1 (pin 0 * 2 = 0) - LED A (PIR motion)
	// Clear alternate function for PC0 (bits 0-3 in AFRL) - ensure GPIO mode
	GPIOC_AFRL_R &=~ (0xFU << 0);  // Clear bits 0-3 (alternate function 0 = GPIO)
	GPIOC_MODE_R |= (1U<<0);  //set bit 0 to 1
	GPIOC_MODE_R &=~ (1U<<1); //set bit 1 to 0 (output mode: 01)
	
	// PC1: mode bits 2-3 (pin 1 * 2 = 2) - LED B (PIR motion)
	// Clear alternate function for PC1 (bits 4-7 in AFRL) - ensure GPIO mode
	GPIOC_AFRL_R &=~ (0xFU << 4);  // Clear bits 4-7 (alternate function 0 = GPIO)
	GPIOC_MODE_R |= (1U<<2);  //set bit 2 to 1
	GPIOC_MODE_R &=~ (1U<<3); //set bit 3 to 0 (output mode: 01)
	
	// PC5: mode bits 10-11 (pin 5 * 2 = 10) - LED C
	// Clear alternate function for PC5 (bits 20-23 in AFRL) - ensure GPIO mode
	GPIOC_AFRL_R &=~ (0xFU << 20);  // Clear bits 20-23 (alternate function 0 = GPIO)
	GPIOC_MODE_R |= (1U<<10);  //set bit 10 to 1
	GPIOC_MODE_R &=~ (1U<<11); //set bit 11 to 0 (output mode: 01)
	
	// PC6: mode bits 12-13 (pin 6 * 2 = 12) - LED D
	// Clear alternate function for PC6 (bits 24-27 in AFRL) - ensure GPIO mode
	GPIOC_AFRL_R &=~ (0xFU << 24);  // Clear bits 24-27 (alternate function 0 = GPIO)
	GPIOC_MODE_R |= (1U<<12);  //set bit 12 to 1
	GPIOC_MODE_R &=~ (1U<<13); //set bit 13 to 0 (output mode: 01)

	/*3. Configure button pins as inputs with pull-up*/
	// PA0: mode bits 0-1 (pin 0 * 2 = 0)
	GPIOA_MODE_R &=~ (1U<<0);  //set bit 0 to 0
	GPIOA_MODE_R &=~ (1U<<1);  //set bit 1 to 0 (input mode: 00)
	// PA0: pull-up bits 0-1 in PUPDR
	GPIOA_PUPDR_R |= (1U<<0);  //set bit 0 to 1 (pull-up)
	GPIOA_PUPDR_R &=~ (1U<<1); //set bit 1 to 0 (pull-up: 01)
	
	// PA1: mode bits 2-3 (pin 1 * 2 = 2)
	GPIOA_MODE_R &=~ (1U<<2);  //set bit 2 to 0
	GPIOA_MODE_R &=~ (1U<<3);  //set bit 3 to 0 (input mode: 00)
	// PA1: pull-up bits 2-3 in PUPDR
	GPIOA_PUPDR_R |= (1U<<2);  //set bit 2 to 1 (pull-up)
	GPIOA_PUPDR_R &=~ (1U<<3); //set bit 3 to 0 (pull-up: 01)
	
	// PA4: mode bits 8-9 (pin 4 * 2 = 8)
	GPIOA_MODE_R &=~ (1U<<8);  //set bit 8 to 0
	GPIOA_MODE_R &=~ (1U<<9);  //set bit 9 to 0 (input mode: 00)
	// PA4: pull-up bits 8-9 in PUPDR
	GPIOA_PUPDR_R |= (1U<<8);  //set bit 8 to 1 (pull-up)
	GPIOA_PUPDR_R &=~ (1U<<9); //set bit 9 to 0 (pull-up: 01)
	
	// PC2: mode bits 4-5 (pin 2 * 2 = 4) - Replaced PA3
	GPIOC_MODE_R &=~ (1U<<4);  //set bit 4 to 0
	GPIOC_MODE_R &=~ (1U<<5);  //set bit 5 to 0 (input mode: 00)
	// PC2: pull-up bits 4-5 in PUPDR
	GPIOC_PUPDR_R |= (1U<<4);  //set bit 4 to 1 (pull-up)
	GPIOC_PUPDR_R &=~ (1U<<5); //set bit 5 to 0 (pull-up: 01)
	
	// PC13: mode bits 26-27 (pin 13 * 2 = 26) - B1 USER button
	GPIOC_MODE_R &=~ (1U<<26);  //set bit 26 to 0
	GPIOC_MODE_R &=~ (1U<<27);  //set bit 27 to 0 (input mode: 00)
	// PC13: pull-up bits 26-27 in PUPDR
	GPIOC_PUPDR_R |= (1U<<26);  //set bit 26 to 1 (pull-up)
	GPIOC_PUPDR_R &=~ (1U<<27); //set bit 27 to 0 (pull-up: 01)
	
	// PA3: mode bits 6-7 (pin 3 * 2 = 6)
	GPIOA_MODE_R &=~ (1U<<6);  //set bit 6 to 0
	GPIOA_MODE_R &=~ (1U<<7);  //set bit 7 to 0 (input mode: 00)
	// PA3: pull-up bits 6-7 in PUPDR
	GPIOA_PUPDR_R |= (1U<<6);  //set bit 6 to 1 (pull-up)
	GPIOA_PUPDR_R &=~ (1U<<7); //set bit 7 to 0 (pull-up: 01)

	// PB0: mode bits 0-1 (pin 0 * 2 = 0) - Motor override input
	GPIOB_MODE_R &=~ (1U<<0);  // set bit 0 to 0
	GPIOB_MODE_R &=~ (1U<<1);  // set bit 1 to 0 (input mode: 00)
	// PB0: pull-up bits 0-1 in PUPDR
	GPIOB_PUPDR_R |= (1U<<0);  // set bit 0 to 1 (pull-up)
	GPIOB_PUPDR_R &=~ (1U<<1); // set bit 1 to 0 (pull-up: 01)

	// PB1: mode bits 2-3 (pin 1 * 2 = 2) - Motor override input
	GPIOB_MODE_R &=~ (1U<<2);  // set bit 2 to 0
	GPIOB_MODE_R &=~ (1U<<3);  // set bit 3 to 0 (input mode: 00)
	// PB1: pull-up bits 2-3 in PUPDR
	GPIOB_PUPDR_R |= (1U<<2);  // set bit 2 to 1 (pull-up)
	GPIOB_PUPDR_R &=~ (1U<<3); // set bit 3 to 0 (pull-up: 01)
	
	/*4. Configure EXTI (External Interrupt) for interrupt-driven button detection*/
	// Enable SYSCFG clock (required for EXTI configuration)
	RCC_APB2ENR |= (1U<<14); // SYSCFG clock enable (bit 14)
	
	// Configure SYSCFG to route PA0, PA1, PA3, PA4, PC2 to EXTI0, EXTI1, EXTI3, EXTI4, EXTI2
	// EXTI0: PA0 (bits 0-3 = 0000 for Port A)
	SYSCFG_EXTICR1 &=~ (0xFU << 0);  // Clear bits 0-3, set to 0000 (Port A)
	
	// EXTI1: PA1 (bits 4-7 = 0000 for Port A)
	SYSCFG_EXTICR1 &=~ (0xFU << 4);  // Clear bits 4-7, set to 0000 (Port A)
	
	// EXTI2: PC2 (bits 8-11 = 0010 for Port C)
	SYSCFG_EXTICR1 &=~ (0xFU << 8);  // Clear bits 8-11
	SYSCFG_EXTICR1 |= (0x2U << 8);   // Set bits 8-11 to 0010 (Port C)
	
	// EXTI3: PA3 (bits 12-15 = 0000 for Port A)
	SYSCFG_EXTICR1 &=~ (0xFU << 12);  // Clear bits 12-15, set to 0000 (Port A)
	
	// EXTI4: PA4 (bits 0-3 in EXTICR2 = 0000 for Port A)
	SYSCFG_EXTICR2 &=~ (0xFU << 0);  // Clear bits 0-3, set to 0000 (Port A)
	
	// EXTI13: PC13 (bits 4-7 in EXTICR4, pin 13 uses bits 4-7 = 0010 for Port C)
	SYSCFG_EXTICR4 &=~ (0xFU << 4);  // Clear bits 4-7
	SYSCFG_EXTICR4 |= (0x2U << 4);   // Set bits 4-7 to 0010 (Port C)
	
	// Clear any existing pending flags before configuring
	EXTI_PR |= (1U<<0);  // Clear EXTI0 pending
	EXTI_PR |= (1U<<1);  // Clear EXTI1 pending
	EXTI_PR |= (1U<<2);  // Clear EXTI2 pending
	EXTI_PR |= (1U<<3);  // Clear EXTI3 pending
	EXTI_PR |= (1U<<4);  // Clear EXTI4 pending
	EXTI_PR |= (1U<<13); // Clear EXTI13 pending
	
	// Configure EXTI for falling edge detection (button press pulls pin LOW)
	EXTI_FTSR |= (1U<<0);  // Enable falling edge trigger for EXTI0 (PA0)
	EXTI_FTSR |= (1U<<1);  // Enable falling edge trigger for EXTI1 (PA1)
	EXTI_FTSR |= (1U<<2);  // Enable falling edge trigger for EXTI2 (PC2)
	EXTI_FTSR |= (1U<<3);  // Enable falling edge trigger for EXTI3 (PA3)
	EXTI_FTSR |= (1U<<4);  // Enable falling edge trigger for EXTI4 (PA4)
	EXTI_FTSR |= (1U<<13); // Enable falling edge trigger for EXTI13 (PC13)
	
	// Unmask interrupts (enable EXTI lines)
	EXTI_IMR |= (1U<<0);  // Unmask EXTI0
	EXTI_IMR |= (1U<<1);  // Unmask EXTI1
	EXTI_IMR |= (1U<<2);  // Unmask EXTI2
	EXTI_IMR |= (1U<<3);  // Unmask EXTI3 (PIR sensor)
	EXTI_IMR |= (1U<<4);  // Unmask EXTI4
	EXTI_IMR |= (1U<<13); // Unmask EXTI13
	
	// Enable interrupts in NVIC
	// EXTI0 = IRQ 6, EXTI1 = IRQ 7, EXTI2 = IRQ 8, EXTI3 = IRQ 9, EXTI4 = IRQ 10
	// EXTI15_10 = IRQ 40 (shared interrupt for EXTI10-15, including EXTI13)
	NVIC_ISER0 |= (1U<<6);  // Enable EXTI0 interrupt
	NVIC_ISER0 |= (1U<<7);  // Enable EXTI1 interrupt
	NVIC_ISER0 |= (1U<<8);  // Enable EXTI2 interrupt
	NVIC_ISER0 |= (1U<<9);  // Enable EXTI3 interrupt
	NVIC_ISER0 |= (1U<<10); // Enable EXTI4 interrupt
	NVIC_ISER1 |= (1U<<(40-32)); // Enable EXTI15_10 interrupt (IRQ 40, bit 8 in ISER1)

	/*5. Diagnostic startup routine - test PIR motion LEDs*/
	// Delay value for 0.1 seconds (100ms) - doubled from 0.05 seconds
	volatile unsigned int delay_100ms_diag = 1000000; // 0.1 seconds (100ms) delay
	// Delay value for 0.5 seconds - doubled speed
	volatile unsigned int delay_500ms = 5000000; // 0.5 seconds delay
	// Delay value for 0.1 seconds (100ms) - for main startup routine
	volatile unsigned int delay_100ms = 1000000; // 0.1 seconds (100ms) delay
	// Delay value for 1 second - for main startup routine
	volatile unsigned int delay_1s = 10000000; // 1 second delay
	
	// Turn ON LED A (PC0) for 0.1 seconds (doubled from 0.05 seconds)
	GPIOC_OD_R |= LED_A_PIN;  // Turn ON PC0
	for(volatile unsigned int i = 0; i < delay_100ms_diag; i++){} // 0.1 seconds delay
	GPIOC_OD_R &=~ LED_A_PIN; // Turn OFF PC0
	
	// Wait 0.5 seconds (doubled speed)
	for(volatile unsigned int i = 0; i < delay_500ms; i++){}
	
	// Turn ON LED B (PC1) for 0.1 seconds (doubled from 0.05 seconds)
	GPIOC_OD_R |= LED_B_PIN;  // Turn ON PC1
	for(volatile unsigned int i = 0; i < delay_100ms_diag; i++){} // 0.1 seconds delay
	GPIOC_OD_R &=~ LED_B_PIN; // Turn OFF PC1
	
	// Wait 0.5 seconds before continuing with main startup routine (doubled speed)
	for(volatile unsigned int i = 0; i < delay_500ms; i++){}

	/*6. Test routine for LED C and LED D - LED C stays on 1.5 seconds, LED D stays on 2 seconds with 1 second pause between each, repeat 1 time*/
	for(int cycle = 0; cycle < 1; cycle++)
	{
		// Activate LED C (stays on for 1.5 seconds)
		turn_on_led_c();
		// Wait 1.5 seconds for LED C to stay on
		for(volatile unsigned int i = 0; i < delay_1s; i++){}
		for(volatile unsigned int i = 0; i < delay_500ms; i++){}
		// Turn off LED C manually (since we're not in main loop yet)
		GPIOC_OD_R &=~ LED_C_PIN;
		led_c_timer = 0;
		
		// Wait 1 second pause between activations
		for(volatile unsigned int i = 0; i < delay_1s; i++){}
		
		// Activate LED D (stays on for 2 seconds)
		turn_on_led_d();
		// Wait 2 seconds for LED D to stay on
		for(volatile unsigned int i = 0; i < delay_1s; i++){}
		for(volatile unsigned int i = 0; i < delay_1s; i++){}
		// Turn off LED D manually (since we're not in main loop yet)
		GPIOC_OD_R &=~ LED_D_PIN;
		led_d_timer = 0;
		
		// Wait 1 second pause before next cycle
		for(volatile unsigned int i = 0; i < delay_1s; i++){}
	}

	/*7. Startup LED blink test routine - blink each LED at 3 Hz for 1 second*/
	// At 3 Hz: ~100ms ON, ~233ms OFF = ~333ms per cycle
	// For 1 second: 3 cycles per LED (1 second / 0.333 seconds per cycle ≈ 3 cycles)
	// Using delay_100ms already defined in diagnostic routine above
	
	// Blink PA5 (Onboard LED) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOA_OD_R |= LED_ONBOARD_PIN;  // Turn ON PA5
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOA_OD_R &=~ LED_ONBOARD_PIN; // Turn OFF PA5
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}
	
	// Wait 1 second before next LED activation
	for(volatile unsigned int i = 0; i < delay_1s; i++){}
	
	// Blink PA6 (LED0) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOA_OD_R |= LED0_PIN;  // Turn ON PA6
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOA_OD_R &=~ LED0_PIN; // Turn OFF PA6
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}
	
	// Wait 1 second before next LED activation
	for(volatile unsigned int i = 0; i < delay_1s; i++){}
	
	// Blink PA7 (LED1) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOA_OD_R |= LED1_PIN;  // Turn ON PA7
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOA_OD_R &=~ LED1_PIN; // Turn OFF PA7
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}
	
	// Wait 1 second before next LED activation
	for(volatile unsigned int i = 0; i < delay_1s; i++){}
	
	// Blink PB6 (LED2) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOB_OD_R |= LED2_PIN;  // Turn ON PB6
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOB_OD_R &=~ LED2_PIN; // Turn OFF PB6
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}
	
	// Wait 1 second before next LED activation
	for(volatile unsigned int i = 0; i < delay_1s; i++){}
	
	// Blink PC7 (LED3) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOC_OD_R |= LED3_PIN;  // Turn ON PC7
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOC_OD_R &=~ LED3_PIN; // Turn OFF PC7
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}
	
	// Wait 1 second before next LED activation
	for(volatile unsigned int i = 0; i < delay_1s; i++){}
	
	// Blink PB9 (LED4) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOB_OD_R |= LED4_PIN;  // Turn ON PB9
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOB_OD_R &=~ LED4_PIN; // Turn OFF PB9
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}
	
	// Wait 1 second before next LED activation
	for(volatile unsigned int i = 0; i < delay_1s; i++){}
	
	// Blink PB10 (LED5) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOB_OD_R |= LED5_PIN;  // Turn ON PB10
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOB_OD_R &=~ LED5_PIN; // Turn OFF PB10
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}
	
	// Wait 1 second before next LED activation
	for(volatile unsigned int i = 0; i < delay_1s; i++){}
	
	// Blink PB12 (LED6) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOB_OD_R |= LED6_PIN;  // Turn ON PB12
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOB_OD_R &=~ LED6_PIN; // Turn OFF PB12
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}
	
	// Wait 1 second before next LED activation
	for(volatile unsigned int i = 0; i < delay_1s; i++){}
	
	// Blink PB13 (LED7) for 1 second at 3 Hz
	for(int cycle = 0; cycle < 3; cycle++)
	{
		GPIOB_OD_R |= LED7_PIN;  // Turn ON PB13
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
		GPIOB_OD_R &=~ LED7_PIN; // Turn OFF PB13
		for(volatile unsigned int i = 0; i < delay_100ms; i++){} // 0.1 seconds delay
	}

	/*6. Main loop - interrupts handle button presses, main loop handles LED timers*/
	while(1)
	{
		// Increment global time counter for cooldown tracking
		global_time_counter++;
		
		// Decrement LED timers and turn off when they reach 0
		
		// Check LED0 (PA6) timer - turn off after 0.1 seconds
		if(led0_timer > 0)
		{
			led0_timer--;
			if(led0_timer == 0)
			{
				GPIOA_OD_R &=~ LED0_PIN; // Turn OFF PA6
			}
		}
		
		// Check LED1 (PA7) timer - turn off after 0.1 seconds
		if(led1_timer > 0)
		{
			led1_timer--;
			if(led1_timer == 0)
			{
				GPIOA_OD_R &=~ LED1_PIN; // Turn OFF PA7
			}
		}
		
		// Check LED2 (PB6) timer - turn off after 0.1 seconds
		if(led2_timer > 0)
		{
			led2_timer--;
			if(led2_timer == 0)
			{
				GPIOB_OD_R &=~ LED2_PIN; // Turn OFF PB6
			}
		}
		
		// Check LED3 (PC7) timer - turn off after 0.1 seconds
		if(led3_timer > 0)
		{
			led3_timer--;
			if(led3_timer == 0)
			{
				GPIOC_OD_R &=~ LED3_PIN; // Turn OFF PC7
			}
		}
		
		// Check onboard LED (PA5) timer - turn off after 0.1 seconds
		if(led_onboard_timer > 0)
		{
			led_onboard_timer--;
			if(led_onboard_timer == 0)
			{
				GPIOA_OD_R &=~ LED_ONBOARD_PIN; // Turn OFF PA5
			}
		}
		
		// Check LED4 (PB9) timer - turn off after 0.1 seconds
		if(led4_timer > 0)
		{
			led4_timer--;
			if(led4_timer == 0)
			{
				GPIOB_OD_R &=~ LED4_PIN; // Turn OFF PB9
			}
		}
		
		// Check LED5 (PB10) timer - turn off after 0.1 seconds
		if(led5_timer > 0)
		{
			led5_timer--;
			if(led5_timer == 0)
			{
				GPIOB_OD_R &=~ LED5_PIN; // Turn OFF PB10
			}
		}
		
		// Check LED6 (PB12) timer - turn off after 0.1 seconds
		if(led6_timer > 0)
		{
			led6_timer--;
			if(led6_timer == 0)
			{
				GPIOB_OD_R &=~ LED6_PIN; // Turn OFF PB12
			}
		}
		
		// Check LED7 (PB13) timer - turn off after 0.1 seconds
		if(led7_timer > 0)
		{
			led7_timer--;
			if(led7_timer == 0)
			{
				GPIOB_OD_R &=~ LED7_PIN; // Turn OFF PB13
			}
		}
		
		// Check LED A (PC0) timer - turn off after 0.6 seconds, then turn on LED B
		if(led_a_timer > 0)
		{
			led_a_timer--;
			if(led_a_timer == 0)
			{
				GPIOC_OD_R &=~ LED_A_PIN; // Turn OFF PC0 (LED A)
				// Turn on LED B for 0.6 seconds
				GPIOC_OD_R |= LED_B_PIN;  // Turn ON PC1 (LED B)
				led_b_timer = PIR_LED_ON_DURATION;
				led_b_last_activation = global_time_counter;
			}
		}
		
		// Check LED B (PC1) timer - turn off after 0.6 seconds
		if(led_b_timer > 0)
		{
			led_b_timer--;
			if(led_b_timer == 0)
			{
				GPIOC_OD_R &=~ LED_B_PIN; // Turn OFF PC1 (LED B)
			}
		}
		
		// Check LED C (PC5) timer - turn off after duration, ensure LED D is off
		if(led_c_timer > 0)
		{
			led_c_timer--;
			if(led_c_timer == 0)
			{
				GPIOC_OD_R &=~ LED_C_PIN; // Turn OFF PC5 (LED C)
				// Ensure LED D is also off (mutual exclusion - never on at same time)
				GPIOC_OD_R &=~ LED_D_PIN;
				led_d_timer = 0;
			}
		}
		
		// Check LED D (PC6) timer - turn off after duration, ensure LED C is off
		if(led_d_timer > 0)
		{
			led_d_timer--;
			if(led_d_timer == 0)
			{
				GPIOC_OD_R &=~ LED_D_PIN; // Turn OFF PC6 (LED D)
				// Ensure LED C is also off (mutual exclusion - never on at same time)
				GPIOC_OD_R &=~ LED_C_PIN;
				led_c_timer = 0;
			}
		}

		// Motor override: PB0/PB1 as direction-change inputs
		// PB0 or PB1 pulled LOW (button pressed / contact closed) while motor running
		// will stop current direction and start the opposite direction
		if( (GPIOB_IDR_R & (1U<<0)) == 0 || (GPIOB_IDR_R & (1U<<1)) == 0 )
		{
			// If LED C (forward) is active, stop it and start LED D (reverse)
			if(led_c_timer > 0 || (GPIOC_OD_R & LED_C_PIN))
			{
				GPIOC_OD_R &=~ LED_C_PIN;
				led_c_timer = 0;
				turn_on_led_d();
			}
			// Else if LED D (reverse) is active, stop it and start LED C (forward)
			else if(led_d_timer > 0 || (GPIOC_OD_R & LED_D_PIN))
			{
				GPIOC_OD_R &=~ LED_D_PIN;
				led_d_timer = 0;
				turn_on_led_c();
			}
		}
		
		// Randomly initiate LED A/B sequence (in addition to PA3 button trigger)
		if(led_a_timer == 0 && led_b_timer == 0)
		{
			unsigned int time_since_last_a = global_time_counter - led_a_last_activation;
			unsigned int time_since_last_b = global_time_counter - led_b_last_activation;
			if((time_since_last_a >= LED_COOLDOWN_PERIOD || led_a_last_activation == 0) &&
			   (time_since_last_b >= LED_COOLDOWN_PERIOD || led_b_last_activation == 0))
			{
				unsigned int rand_val = generate_random_value();
				if((rand_val & 0x3FFU) == 0U) // Approximately once per 1024 iterations
				{
					// Turn ON LED A (PC0) for 0.6 seconds
					GPIOC_OD_R |= LED_A_PIN;
					led_a_timer = PIR_LED_ON_DURATION;
					led_a_last_activation = global_time_counter;
					led_b_last_activation = global_time_counter;
				}
			}
		}
		
		// Randomly initiate LED C/D diagnostic sequence
		if(led_cd_test_state == LED_CD_STATE_IDLE)
		{
			unsigned int rand_val = generate_random_value();
			if((rand_val & 0x3FFU) == 0U) // Approximately once per 1024 iterations
			{
				led_cd_test_state = LED_CD_STATE_START_C;
				led_cd_test_cycle = 0;
			}
		}
		
		// LED C/D diagnostic state machine
		switch(led_cd_test_state)
		{
			case LED_CD_STATE_START_C:
				turn_on_led_c();
				led_cd_test_state = LED_CD_STATE_WAIT_C;
				break;
			
			case LED_CD_STATE_WAIT_C:
				if(led_c_timer == 0 && (GPIOC_OD_R & LED_C_PIN) == 0)
				{
					led_cd_pause_start = global_time_counter;
					led_cd_test_state = LED_CD_STATE_PAUSE_AFTER_C;
				}
				break;
			
			case LED_CD_STATE_PAUSE_AFTER_C:
				if((global_time_counter - led_cd_pause_start) >= LED_CD_PAUSE_DURATION)
				{
					led_cd_test_state = LED_CD_STATE_START_D;
				}
				break;
			
			case LED_CD_STATE_START_D:
				turn_on_led_d();
				led_cd_test_state = LED_CD_STATE_WAIT_D;
				break;
			
			case LED_CD_STATE_WAIT_D:
				if(led_d_timer == 0 && (GPIOC_OD_R & LED_D_PIN) == 0)
				{
					led_cd_pause_start = global_time_counter;
					led_cd_test_state = LED_CD_STATE_PAUSE_AFTER_D;
				}
				break;
			
			case LED_CD_STATE_PAUSE_AFTER_D:
				if((global_time_counter - led_cd_pause_start) >= LED_CD_PAUSE_DURATION)
				{
					led_cd_test_cycle++;
					if(led_cd_test_cycle >= LED_CD_TEST_CYCLES)
					{
						led_cd_test_state = LED_CD_STATE_IDLE;
					}
					else
					{
						led_cd_test_state = LED_CD_STATE_START_C;
					}
				}
				break;
			
			default:
				break;
		}
		
		// Delay to control loop speed and timing accuracy
		// This delay determines the timing resolution
		for(volatile unsigned int i = 0; i < 10000; i++){}
	}

}

/* Interrupt Handler Functions */

// EXTI0 interrupt handler - PA0 button press
void EXTI0_IRQHandler(void)
{
	// Check if another interrupt is already being processed
	if(interrupt_processing)
	{
		// Clear pending flag and ignore this interrupt
		EXTI_PR |= (1U<<0);
		return;
	}
	
	// Check if EXTI0 interrupt is pending
	if(EXTI_PR & (1U<<0))
	{
		// Set processing flag to prevent other interrupts
		interrupt_processing = 1;
		
		// Clear pending flag
		EXTI_PR |= (1U<<0);
		
		// Check cooldown period - only activate if at least 1 second has passed
		unsigned int time_since_last = global_time_counter - led0_last_activation;
		if(time_since_last >= LED_COOLDOWN_PERIOD || led0_last_activation == 0)
		{
			// Turn ON LED0 (PA6) and set timer
			GPIOA_OD_R |= LED0_PIN;
			led0_timer = LED_ON_DURATION;
			led0_last_activation = global_time_counter;
			
			// Turn ON diagnostic LED4 (PB9) and set timer
			GPIOB_OD_R |= LED4_PIN;
			led4_timer = LED_ON_DURATION;
			led4_last_activation = global_time_counter;
		}
		
		// Simple debounce delay
		for(volatile unsigned int i = 0; i < 100000; i++){}
		
		// Clear processing flag to allow other interrupts
		interrupt_processing = 0;
	}
}

// EXTI1 interrupt handler - PA1 button press
void EXTI1_IRQHandler(void)
{
	// Check if another interrupt is already being processed
	if(interrupt_processing)
	{
		// Clear pending flag and ignore this interrupt
		EXTI_PR |= (1U<<1);
		return;
	}
	
	// Check if EXTI1 interrupt is pending
	if(EXTI_PR & (1U<<1))
	{
		// Set processing flag to prevent other interrupts
		interrupt_processing = 1;
		
		// Clear pending flag
		EXTI_PR |= (1U<<1);
		
		// Check cooldown period - only activate if at least 1 second has passed
		unsigned int time_since_last = global_time_counter - led1_last_activation;
		if(time_since_last >= LED_COOLDOWN_PERIOD || led1_last_activation == 0)
		{
			// Turn ON LED1 (PA7) and set timer
			GPIOA_OD_R |= LED1_PIN;
			led1_timer = LED_ON_DURATION;
			led1_last_activation = global_time_counter;
			
			// Turn ON diagnostic LED5 (PB10) and set timer
			GPIOB_OD_R |= LED5_PIN;
			led5_timer = LED_ON_DURATION;
			led5_last_activation = global_time_counter;
		}
		
		// Simple debounce delay
		for(volatile unsigned int i = 0; i < 100000; i++){}
		
		// Clear processing flag to allow other interrupts
		interrupt_processing = 0;
	}
}

// EXTI4 interrupt handler - PA4 button press
void EXTI4_IRQHandler(void)
{
	// Check if another interrupt is already being processed
	if(interrupt_processing)
	{
		// Clear pending flag and ignore this interrupt
		EXTI_PR |= (1U<<4);
		return;
	}
	
	// Check if EXTI4 interrupt is pending
	if(EXTI_PR & (1U<<4))
	{
		// Set processing flag to prevent other interrupts
		interrupt_processing = 1;
		
		// Clear pending flag
		EXTI_PR |= (1U<<4);
		
		// Check cooldown period - only activate if at least 1 second has passed
		unsigned int time_since_last = global_time_counter - led2_last_activation;
		if(time_since_last >= LED_COOLDOWN_PERIOD || led2_last_activation == 0)
		{
			// Turn ON LED2 (PB6) and set timer
			GPIOB_OD_R |= LED2_PIN;
			led2_timer = LED_ON_DURATION;
			led2_last_activation = global_time_counter;
			
			// Turn ON diagnostic LED6 (PB12) and set timer
			GPIOB_OD_R |= LED6_PIN;
			led6_timer = LED_ON_DURATION;
			led6_last_activation = global_time_counter;
		}
		
		// Simple debounce delay
		for(volatile unsigned int i = 0; i < 100000; i++){}
		
		// Clear processing flag to allow other interrupts
		interrupt_processing = 0;
	}
}

// EXTI2 interrupt handler - PC2 button press
void EXTI2_IRQHandler(void)
{
	// Check if another interrupt is already being processed
	if(interrupt_processing)
	{
		// Clear pending flag and ignore this interrupt
		EXTI_PR |= (1U<<2);
		return;
	}
	
	// Check if EXTI2 interrupt is pending
	if(EXTI_PR & (1U<<2))
	{
		// Set processing flag to prevent other interrupts
		interrupt_processing = 1;
		
		// Clear pending flag
		EXTI_PR |= (1U<<2);
		
		// Check cooldown period - only activate if at least 1 second has passed
		unsigned int time_since_last = global_time_counter - led3_last_activation;
		if(time_since_last >= LED_COOLDOWN_PERIOD || led3_last_activation == 0)
		{
			// Turn ON LED3 (PC7) and set timer
			GPIOC_OD_R |= LED3_PIN;
			led3_timer = LED_ON_DURATION;
			led3_last_activation = global_time_counter;
			
			// Turn ON diagnostic LED7 (PB13) and set timer
			GPIOB_OD_R |= LED7_PIN;
			led7_timer = LED_ON_DURATION;
			led7_last_activation = global_time_counter;
		}
		
		// Simple debounce delay
		for(volatile unsigned int i = 0; i < 100000; i++){}
		
		// Clear processing flag to allow other interrupts
		interrupt_processing = 0;
	}
}

// EXTI3 interrupt handler - PA3 button press
void EXTI3_IRQHandler(void)
{
	// Check if another interrupt is already being processed
	if(interrupt_processing)
	{
		// Clear pending flag and ignore this interrupt
		EXTI_PR |= (1U<<3);
		return;
	}
	
	// Check if EXTI3 interrupt is pending
	if(EXTI_PR & (1U<<3))
	{
		// Set processing flag to prevent other interrupts
		interrupt_processing = 1;
		
		// Clear pending flag
		EXTI_PR |= (1U<<3);
		
		// Diagnostic: Turn on onboard LED to verify interrupt is firing
		GPIOA_OD_R |= LED_ONBOARD_PIN;
		
		// Check cooldown period - only activate if at least 1 second has passed
		unsigned int time_since_last_a = global_time_counter - led_a_last_activation;
		unsigned int time_since_last_b = global_time_counter - led_b_last_activation;
		if((time_since_last_a >= LED_COOLDOWN_PERIOD || led_a_last_activation == 0) &&
		   (time_since_last_b >= LED_COOLDOWN_PERIOD || led_b_last_activation == 0))
		{
			// Turn ON LED A (PC0) for 0.6 seconds
			GPIOC_OD_R |= LED_A_PIN;
			led_a_timer = PIR_LED_ON_DURATION;
			led_a_last_activation = global_time_counter;
			
			// Note: LED B will be turned on automatically when LED A timer expires
			led_b_last_activation = global_time_counter;
		}
		
		// Simple debounce delay
		for(volatile unsigned int i = 0; i < 100000; i++){}
		
		// Diagnostic: Turn off onboard LED
		GPIOA_OD_R &=~ LED_ONBOARD_PIN;
		
		// Clear processing flag to allow other interrupts
		interrupt_processing = 0;
	}
}

// EXTI15_10 interrupt handler - Shared interrupt for EXTI10-15
// PC13 (B1 USER button) uses EXTI13
void EXTI15_10_IRQHandler(void)
{
	// Check if another interrupt is already being processed
	if(interrupt_processing)
	{
		// Clear pending flag and ignore this interrupt
		EXTI_PR |= (1U<<13);
		return;
	}
	
	// Check if EXTI13 interrupt is pending (PC13 button press)
	if(EXTI_PR & (1U<<13))
	{
		// Set processing flag to prevent other interrupts
		interrupt_processing = 1;
		
		// Clear pending flag
		EXTI_PR |= (1U<<13);
		
		// Check cooldown period - only activate if at least 1 second has passed
		unsigned int time_since_last = global_time_counter - led_onboard_last_activation;
		if(time_since_last >= LED_COOLDOWN_PERIOD || led_onboard_last_activation == 0)
		{
			// Turn ON onboard LED (PA5) and set timer
			GPIOA_OD_R |= LED_ONBOARD_PIN;
			led_onboard_timer = LED_ON_DURATION;
			led_onboard_last_activation = global_time_counter;
			
			// Turn ON diagnostic LED4 (PB9) and set timer
			GPIOB_OD_R |= LED4_PIN;
			led4_timer = LED_ON_DURATION;
			led4_last_activation = global_time_counter;
		}
		
		// Simple debounce delay
		for(volatile unsigned int i = 0; i < 100000; i++){}
		
		// Clear processing flag to allow other interrupts
		interrupt_processing = 0;
	}
}
