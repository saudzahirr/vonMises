import subprocess
import time
import shlex

build_cmd = shlex.split("python build.py")
wheel_cmd = shlex.split("python -m pip wheel . -v -w dist ")
install_cmd = shlex.split("python -m pip install -e . -v")

with open("build.log", "w") as log:
    subprocess.run(build_cmd, stdout=log, stderr=log)

time.sleep(2)

with open("build.log", "a") as log:
    rv = subprocess.Popen(wheel_cmd, stdout=log, stderr=log)
    while rv.poll() is None:
        time.sleep(0.5)
    subprocess.run(install_cmd, stdout=log, stderr=log)
