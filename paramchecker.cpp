bool is_bpm_ok(float bpm)
{
  if(bpm < 70 || bpm > 150) {
    return false;
  }
  return true;
}

bool is_resp_rate_ok(float respRate)
{
   if(respRate < 30 || respRate > 60) {
    return false;
  }
  
  return true;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  if(!is_bpm_ok(bpm) || spo2 < 80 || !is_resp_rate_ok(respRate)) {
    return false;
  }
  return true;
}
