import os
import subprocess
import time
import shlex

wheel_cmd = shlex.split("python -m pip wheel . -v -w dist ")
install_cmd = shlex.split("python -m pip install -e . -v")
setup_directory = os.getcwd()

with open("build.log", "w") as log:
    if not os.path.exists("build"):
        os.makedirs("build")
    os.chdir("build")
    subprocess.run("cmake ..", stdout=log, stderr=log, shell=True)
    subprocess.run("make", stdout=log, stderr=log, shell=True)

os.chdir(setup_directory)

with open("build.log", "a") as log:
    rv = subprocess.Popen(wheel_cmd, stdout=log, stderr=log)
    while rv.poll() is None:
        time.sleep(0.5)
    subprocess.run(install_cmd, stdout=log, stderr=log)
