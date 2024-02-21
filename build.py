import platform
import subprocess


with open("build.log", "w") as log:
    if platform.system() == "Windows":
        subprocess.run("build.bat", stdout=log, stderr=log)

    elif platform.system() == "Linux":
        subprocess.run("chmod +x .\build.sh", stdout=log, stderr=log)
        subprocess.run(".\build.sh", stdout=log, stderr=log)
