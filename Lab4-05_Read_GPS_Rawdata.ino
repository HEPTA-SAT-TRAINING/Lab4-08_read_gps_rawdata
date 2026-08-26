#include "src/HeptaSat.h"

HeptaCdh    cdh;
HeptaEps    eps;
HeptaSensor sensor;

void setup() {
  cdh.begin();
  eps.init();
  sensor.begin();
}

void loop() {
  if (sensor.gps_is_data_available()) {
    int b = sensor.gps_read_byte();
    if (b >= 0) cdh.printf("%c", (char)b);
  }
}
