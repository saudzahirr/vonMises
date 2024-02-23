import subprocess
import time


with open("build.log", "w") as log:
    process = subprocess.Popen("python build.py", stdout=log, stderr=log)

while True:
    if process.poll() is not None:
        break
    time.sleep(0.1)

time.sleep(2)

with open("build.log", "a") as log:
    subprocess.run("python -m pip install -e .", stdout=log, stderr=log)
