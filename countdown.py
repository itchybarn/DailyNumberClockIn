import requests
import serial
import time

SERIAL_PORT = '/dev/ttyUSB0'
BAUD_RATE = 9600

def get_daily_number():
	response = requests.get('https://itchybarn.com/api/dailynumber')
	return response.json()['number']

def main():
	arduino = serial.Serial(SERIAL_PORT, BAUD_RATE)
	time.sleep(2)

	number = get_daily_number()
	print(f"Got daily number: {number}")

	arduino.write(f"{number}\n".encode())
	print("Sent to Arduino!")

	arduino.close()

if __name__ == "__main__":
	main()
