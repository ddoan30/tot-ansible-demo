import serial
import requests
import subprocess
import threading
import time

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
URL = "https://192.168.122.158" # vm2.lab.local loopback addr

# arduino prints "sixseven" when light turns off
# httpd service syncs with light status 
def listen_to_arduino():
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode("utf-8").strip()
            if line == "sixseven":
                print("Light is OFF: Stopping httpd...")
                subprocess.run(["sudo", "systemctl", "stop", "httpd"]) 
                # this will trigger EDA rulebook to remediate 

# checks if loopback address is up or down
def check_web_server():
    while True:
        try:
            print("Checking web server status...")
            response = requests.get(URL, verify=False, timeout=5)
            if response.status_code == 200:
                ser.write(b'OK\n')
                print("httpd is UP - Light ON")
        except:
            print("httpd is DOWN")
            ser.write(b'DOWN\n')
        time.sleep(3) 

# Start both as separate threads
threading.Thread(target=listen_to_arduino, daemon=True).start()
threading.Thread(target=check_web_server, daemon=True).start()

# Keep main thread alive
while True:
    time.sleep(1)

            
