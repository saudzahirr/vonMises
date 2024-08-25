import subprocess
import time
import shlex

wheel_cmd = shlex.split("python -m pip wheel . -v -w dist ")
install_cmd = shlex.split("python -m pip install -e . -v")
build_cmd = shlex.split("pip wheel . -v -w dist ")
build_cmd = shlex.split("pip install -e . -v")

with open("build.log", "w") as log:
    rv = subprocess.Popen(
        shlex.split("pip wheel . -v -w dist "), stdout=log, stderr=log
    )
    while rv.poll() is None:
        time.sleep(0.5)
    subprocess.run(shlex.split("pip install -e . -v"), stdout=log, stderr=log)
