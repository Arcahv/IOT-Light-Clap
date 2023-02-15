#define ITERATION 10000
#define DELAY 2
#define FAULT_DELAY 100
#define RED_PIN 3
#define GREEN_PIN 6
#define BLUE_PIN 5
#define ANALOG_INP A0
#define SOUND_PIN 2

// Define variables
int numberSounds = 0;
int rawValue = 0;
int numberClaps = 0;
int lightOn = 0;
int uniqueClapMinTime = 100;

unsigned long soundDetectedTime = 0;
unsigned long previousSoundDetectedTime = 0;
unsigned long previousClapTime = 0;
unsigned long currentClapTime = 0;
unsigned long maxTimeBetweenClaps = 2000;

double totalValue = 0;
int count = 0;

int counter = 1;

int rBr = 0;
int bBr = 0;
int gBr = 0;

boolean state = false;
int lastClap = 2;

// Setup function runs once when the board is powered on or reset
void setup()
{
    // Set pin modes
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(ANALOG_INP, INPUT);
    pinMode(SOUND_PIN, INPUT);

    // Turn on the light
    state = true;
}

// Returns whether the sound is part of a unique clap or not
int isSoundPartOfUniqueClap()
{
    int result = 0;
    unsigned long elapsedTime =
        soundDetectedTime -
        previousSoundDetectedTime;
    if (elapsedTime >= uniqueClapMinTime)
    {
        result = 1;
    }
    return result;
}

// Checks whether to turn on/off the light based on clap pattern
int checkTurnOnOffLight()
{
    int result = 0;
    unsigned long elapsedTime =
        currentClapTime - previousClapTime;
    if (elapsedTime <= maxTimeBetweenClaps)
    {
        if (numberClaps == 2)
        {
            result = 1;
            numberClaps = 0;
        }
    }
    else
    {
        numberClaps = 1;
    }
    return result;
}

// Turns on all colors at max brightness
void turnOn()
{
    analogWrite(RED_PIN, 255);
    analogWrite(GREEN_PIN, 255);
    analogWrite(BLUE_PIN, 255);
}

// Turns off all colors
void turnOff()
{
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
}

// Changes the color of the light based on hsv value
void changeColor(int value)
{
    int redValue, greenValue, blueValue;
    if (value >= 850)
    {
        redValue = 255;
        greenValue = 0;
        blueValue = map(value, 851, 1024, 255, 0);
    }
    else if (value >= 680)
    {
        redValue = map(value, 681, 850, 0, 255);
        greenValue = 0;
        blueValue = 255;
    }
    else if (value >= 510)
    {
        redValue = 0;
        greenValue = map(value, 511, 680, 255, 0);
        blueValue = 255;
    }
    else if (value >= 340)
    {
        redValue = 0;
        greenValue = 255;
        blueValue = map(value, 341, 510, 0, 255);
    }
    else if (value > 170)
    {
        redValue = map(value, 171, 340, 255, 0);
        greenValue = 255;
        blueValue = 0;
    }
    else
    {
        redValue = 255;
        greenValue = map(value, 0, 170, 0, 255);
        blueValue = 0;
    }

    analogWrite(RED_PIN, redValue);
    analogWrite(GREEN_PIN, greenValue);
    analogWrite(BLUE_PIN, blueValue);
}
  
