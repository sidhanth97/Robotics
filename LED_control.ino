void red_led(int8_t level) {
  if (flip32)
  	digitalWrite(PB4, !level);    		//If a Flip32 is detected invert the output.
  else 
  	digitalWrite(PB4, level);           //When using the BluePill the output should not be inverted.
}

void green_led(int8_t level) {
  if (flip32)
  	digitalWrite(PB3, !level);    		//If a Flip32 is detected invert the output.
  else 
  	digitalWrite(PB3, level);           //When using the BluePill the output should not be inverted.
}
