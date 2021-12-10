/** 
 *  Sensor Watch Firmware Flasher
 *  
 *  This sketch is meant to run on an Adafruit PyRuler or Trinket.
 *  Connect the SWD, SWC and RST pads on the watch to pins 0, 1 and 3.
 *  Connect V+ on the watch to 3V, and GND to GND.
 *  This will power the watch from the Trinket so you don't need to plug the watch in to USB.
 *  Hit reset on the PyRuler / Trinket to begin the flashing process.
 *  The Trinket's red LED will blink slowly when the bootloader has been successfully written.
 */

#include "Adafruit_DAP.h"
#include "bootloader.h"

#define SWDIO 0
#define SWCLK 1
#define SWRST 3

#define BUFSIZE 256       //don't change!
//uint8_t buf[BUFSIZE];

//create a DAP for programming Atmel SAM devices
Adafruit_DAP_SAM dap;

// Function called when there's an SWD error
void error(const char *text) {
  Serial.println(text);
  while (1);
}


void setup(void) {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
//  while(!Serial) {
//    delay(1);         // will pause the chip until it opens serial console
//  }

  dap.begin(SWCLK, SWDIO, SWRST, &error);
  
  Serial.print("Connecting...");  
  if (! dap.dap_disconnect())                      error(dap.error_message);
  
  char debuggername[100];
  if (! dap.dap_get_debugger_info(debuggername))   error(dap.error_message);
  Serial.print(debuggername); Serial.print("\n\r");
  
  if (! dap.dap_connect())                         error(dap.error_message);
  
  if (! dap.dap_transfer_configure(0, 128, 128))   error(dap.error_message);
  if (! dap.dap_swd_configure(0))                  error(dap.error_message);
  if (! dap.dap_reset_link())                      error(dap.error_message);
  if (! dap.dap_swj_clock(50))               error(dap.error_message);
  dap.dap_target_prepare();

  uint32_t dsu_did;
  if (! dap.select(&dsu_did)) {
    Serial.print("Unknown device found 0x"); Serial.print(dsu_did, HEX);
    error("Unknown device found");
  }
  for (device_t *device = dap.devices; device->dsu_did > 0; device++) {
    if (device->dsu_did == dsu_did) {
      Serial.print("Found Target: ");
      Serial.print(device->name);
      Serial.print("\tFlash size: ");
      Serial.print(device->flash_size);
      Serial.print("\tFlash pages: ");
      Serial.println(device->n_pages);
      //Serial.print("Page size: "); Serial.println(device->flash_size / device->n_pages);
    }
  }
        
  Serial.println(" done.");

  Serial.print("Erasing... ");
  dap.erase();
  Serial.println(" done.");
  
  Serial.print("Programming... ");
  unsigned long t = millis();
  uint32_t addr = dap.program_start();

  while(addr < sizeof(binfile)){
    dap.programBlock(addr, binfile + addr);
    addr += BUFSIZE;
  }
  
  Serial.println(millis() - t);
  Serial.println("\nDone!");

  Serial.print("Fuses... ");
  dap.fuseRead(); //MUST READ FUSES BEFORE SETTING OR WRITING ANY
  Serial.println("read.");
  dap._USER_ROW.bit.BOOTPROT = 0x2;
  Serial.println("Setting BOOTPROT to 0x2 for 8192 byte bootloader");
  dap.fuseWrite();
  Serial.println("\nDone!!");

  dap.dap_set_clock(50);

  dap.deselect();
  dap.dap_disconnect();
}

void loop(void) {
  //blink led on the host to show we're done
  digitalWrite(13, HIGH);
  delay(500); 
  digitalWrite(13, LOW);
  delay(500);  
}
