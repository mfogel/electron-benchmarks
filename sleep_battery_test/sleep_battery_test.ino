int measurement_interval_sec = 15*60;
//CellularData cell_data;
//CellularSignal cell_sig;
FuelGauge fuel;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing...");

  //Cellular.getDataUsage(cell_data);
  //Serial.println(cell_data);

  //cell_sig = Cellular.RSSI();
  //Serial.println(cell_sig);
}

void loop() {
  float soc, vcell;
  String soc_str, vcell_str;

  soc = fuel.getSoC();
  vcell = fuel.getVCell();

  soc_str = String(soc);
  vcell_str = String(vcell);

  Serial.println(soc_str);
  Serial.println(vcell_str);

  Particle.publish("soc", soc_str, PRIVATE, NO_ACK);
  Particle.publish("vcell", vcell_str, PRIVATE, NO_ACK);

  //Cellular.getDataUsage(cell_data);
  //Serial.println(cell_data);

  //cell_sig = Cellular.RSSI();
  //Serial.println(cell_sig);

  System.sleep(A0, RISING, measurement_interval_sec, SLEEP_NETWORK_STANDBY);
}
