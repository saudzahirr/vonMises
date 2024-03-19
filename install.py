import subprocess
import time
import shlex

wheel_cmd = shlex.split("python -m pip wheel . -v -w dist ")
install_cmd = shlex.split("python -m pip install -e . -v")

with open("build.log", "w") as log:
    subprocess.run("cd build", stdout=log, stderr=log)
    subprocess.run("cmake ..", stdout=log, stderr=log)
    subprocess.run("make", stdout=log, stderr=log)

time.sleep(2)

with open("build.log", "a") as log:
    rv = subprocess.Popen(wheel_cmd, stdout=log, stderr=log)
    while rv.poll() is None:
        time.sleep(0.5)
    subprocess.run(install_cmd, stdout=log, stderr=log)
