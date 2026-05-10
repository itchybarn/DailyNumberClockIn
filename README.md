Repo used for my Daily Number Clock-In Arduino Project.

**Setup**:

From the Raspberry Pi, create a virtual environment and install the correct dependencies:

```
python3 -m venv ~/daily-number-env
source ~/daily-number-env/bin/activate
pip install requests pyserial
```

Then, clone the repo and use `python countdown.py` to send the daily number over to the arduino!
