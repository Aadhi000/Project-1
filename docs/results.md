# 📊 Results and Performance

The system was tested using controlled LPG gas release to observe its response. 

| Condition | Sensor Reading | System Response |
|------------|----------------|-----------------|
| Normal (Safe) | 150–200 ppm | All systems normal; power supply ON |
| Moderate Leak | 300–400 ppm | Warning; buzzer ON |
| Critical Leak | >500 ppm | Power tripped; exhaust fan ON; Blynk alert sent |

### Observations:
- **Response Time:** 1–2 seconds after detection.  
- **Alert Accuracy:** 100% under test conditions.  
- **Power Consumption:** < 2W (excluding fan).  
- **Reliability:** Stable for continuous 48-hour testing.  

### Output Screens:
- **Blynk Dashboard:** Displayed live gas concentration and system status.
- **LED Indicators:** Signaled alert status during testing.
- **Buzzer:** Sounded continuously during unsafe gas levels.

The system performed effectively in both indoor and simulated leakage scenarios.
