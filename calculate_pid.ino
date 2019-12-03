void calculate_pid(void) {
  error = gyro_input_yaw - setpoint_yaw;
  p_yaw = p_gain * error;
  i_yaw += i_gain * error;
  i_yaw = (i_yaw > max_yaw) ? max_yaw : ( (i_yaw < max_yaw*-1) ? max_yaw*-1:i_yaw );
  d_yaw = d_gain * (error - prev_error)
  prev_error = error;

  output_yaw = p_yaw + i_yaw + d_yaw;
  output_yaw = (output_yaw > max_yaw) ? max_yaw : ( (output_yaw < max_yaw *-1) ? max_yaw*-1:output_yaw )
}

