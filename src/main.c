#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED_builtIn DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_builtIn, gpios);

int gpio_init(void)
{
    int ret;
    // khoi tao gpio
	if (!gpio_is_ready_dt(&led)) {
		return 0;
	}
    // gpio - output
	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    // kiem tra loi
	if (ret < 0) {
		return 0;
	}
    
    return ret;
}

int main(void)
{
    int ret;
    bool led_state = 1;

    ret = gpio_init(); 

    while (1)
    {
        ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return 0;
		}

		led_state = !led_state;
        k_msleep(5000);
    }
    return 0;
}
