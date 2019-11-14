

// resistance at 25 degrees C
#define THERMISTORNOMINAL 10000
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3700
// the value of the 'other' resistor
#define SERIESRESISTOR 10000

float
measure_adc(void)
{
    uint16_t samples[NUMSAMPLES];
    uint8_t  i;
    float    average;

    uint16_t adc_value;
    // take N samples in a row, with a slight delay
    for (i = 0; i < NUMSAMPLES; i++) {
        adc_value  = get_adc_value();
        samples[i] = adc_value;
        _delay_ms(10);
    }

    // average all the samples out
    average = 0;
    for (i = 0; i < NUMSAMPLES; i++) {
        average += samples[i];
    }
    average /= NUMSAMPLES;

    return average;
}

float
convert_to_resistance(float average)
{
    average = 1023 / average - 1;
    average = SERIESRESISTOR / average;
    return average;
}

float
calculate_steinhart(float average)
{
    float steinhart;
    steinhart = average / THERMISTORNOMINAL;          // (R/Ro)
    steinhart = log(steinhart);                       // ln(R/Ro)
    steinhart /= BCOEFFICIENT;                        // 1/B * ln(R/Ro)
    steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
    steinhart = 1.0 / steinhart;                      // Invert
    steinhart -= 273.15;                              // convert to C
    return steinhart;
}

int
main(void)
{
    char string[62];
    char fstr[20];
    uart_start();
    set_adc_prescaler(ADC_DIV_128);
    set_adc_channel(ADC0);
    set_adc_vref(REF_AVCC);
    ADCSRA |= _BV(ADIE);  // Enable interrupt
    ADCSRA |= _BV(ADATE); // Free running mode
    ADCSRA |= _BV(ADEN);  // Enable ADC
    sei();
    ADCSRA |= _BV(ADSC); // Start conversion
    while (1) {
        float average = measure_adc();
        dtostrf(average, 3, 2, fstr);
        sprintf(string, "Average %s\r\n", fstr);
        uart_write(string);

        average = convert_to_resistance(average);
        dtostrf(average, 3, 2, fstr);
        sprintf(string, "Thermistor resistance %s\r\n", fstr);
        uart_write(string);

        float steinhart = calculate_steinhart(average);
        dtostrf(steinhart, 3, 2, fstr);
        sprintf(string, "Steinhart %s\r\n", fstr);
        uart_write(string);

        _delay_ms(1000);
    }
}