sleep 4s && sudo chmod a+rw /dev/ttyACM0 && avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:crkbd_rev1_default.hex
