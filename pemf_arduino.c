#define AD9850_CLOCK 125000000

#define W_CLK 8
#define FQ_UD 9
#define DATA  10
#define RESET 11
#define Mete = 1


#define pulseHigh(pin) {digitalWrite(pin, HIGH); digitalWrite(pin, LOW); }

void tfr_byte(byte data) {
  for (int i = 0; i < 8; i++, data >>= 1) {
    digitalWrite(DATA, data & 0x01);
    pulseHigh(W_CLK);
  }
}

void sendFrequency(double frequency)
{
  int32_t freq1 = frequency * 4294967295/AD9850_CLOCK;
  for (int b = 0; b < 4; b++, freq1 >>= 8)
  {
    tfr_byte(freq1 & 0xFF);
  }
  tfr_byte(0x000);
  pulseHigh(FQ_UD);
}
void setup()
{
  pinMode(FQ_UD, OUTPUT);
  pinMode(W_CLK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(RESET, OUTPUT);

  pulseHigh(RESET);
  pulseHigh(W_CLK);
  pulseHigh(FQ_UD);
}

void loop()
{

long unsigned int freq1 = 220;
long unsigned int freqOld1 = freq1;
sendFrequency(freq1);
delay(600000);
long unsigned int freq2 = 10000;
long unsigned int freqOld2 = freq2;
sendFrequency(freq2);
delay(300000);
long unsigned int freq3 = 880;
long unsigned int freqOld3 = freq3;
sendFrequency(freq3);
delay(300000);
long unsigned int freq4 = 787;
long unsigned int freqOld4 = freq4;
sendFrequency(freq4);
delay(420000);
long unsigned int freq5 = 727;
long unsigned int freqOld5 = freq5;
sendFrequency(freq5);
delay(420000);
}