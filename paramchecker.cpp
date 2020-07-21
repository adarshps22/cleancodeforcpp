bool is_bpm_ok(float bpm)
{
  return bpm < 70 || bpm > 150;
}

bool is_resp_rate_ok(float respRate)
{
   return respRate < 30 || respRate > 60;
}

bool is_spo2_ok(float spo2)
{
  return  spo2 < 80;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  bool status = true;
  
  status = status && is_bpm_ok(bpm);
  status = status && is_resp_rate_ok(spo2);
  status = status && is_spo2_ok(respRate);
  
  return status;
}
