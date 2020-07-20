
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  if(bpm < 70 || bpm > 150 || spo2 < 80 || respRate < 30 || respRate > 60) {
    return false;
  }
  return true;
}
