# purpose: to ensure httpd service on VM2 is synchonrized with the status of the lightbulb 

import serial
import subprocess

# Ensure the port matches your Arduino connection
ser = serial.Serial('/dev/ttyV0', 9600)

print("Listening for Lightbulb signals...")

while True:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').strip()
        
        if line == "Service off":
            print("Light is OFF: Stopping httpd...")
            subprocess.run(["sudo", "systemctl", "stop", "httpd"])
            
        if line == "Fixed":
            print("Remediation in place...")
            subprocess.run(["sudo", "systemctl", "start", "httpd"])
            
