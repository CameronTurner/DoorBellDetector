

int millLast = 0;                    // Last time (in millis()) the doorbell was pressed
int pinDoorbell = D0;                // Button pin
int millDelay = 10000;               // How much time to wait until we allow another doorbell "ring" again
double tempC = 0.0;


void setup() {
    pinMode(pinDoorbell, INPUT_PULLUP);
    RGB.control(true);
}

void loop() {
    if(digitalRead(pinDoorbell)==LOW)
        dingdong();
    else
        RGB.color(0, 255, 0);
}


void dingdong() {
    if(millLast==0 || (millLast+millDelay)<millis()) {
        millLast = millis();
        Particle.publish("Doorbell", "Doorbell");
         Particle.publish("LIFX_TURN_ON_FDOOR_LIGHT");
        RGB.color(0, 0, 255);
        delay(1000);
    }
}
