import shlex
import shutil
import subprocess
import sys
from argparse import ArgumentParser
from pathlib import Path

wheel_cmd = shlex.split("python -m build -n -x --wheel")
build_cmd = shlex.split("pip wheel . -v -w dist ")
install_cmd = shlex.split("pip install . -v")
develop_cmd = shlex.split("pip install -e . -v")


def main(args=sys.argv[1:]):
    prog = ArgumentParser(prog="Build vonMises")
    prog.add_argument(
        "mode",
        help="""Build mode:
        wheel -- only builds the wheel
        develop -- creates an editable install
        install -- performs a normal install
        clean -- removes all build data""",
        type=str,
        choices=["wheel", "install", "develop", "clean"],
    )

    args = prog.parse_args(args)

    # Log to a file
    log_file = "build.log"

    def run_command(command, log_file=log_file):
        with open(log_file, "w") as log:
            subprocess.run(command, check=True, stdout=log, stderr=log)

    if args.mode == "wheel":
        print("Starting wheel build")
        run_command(build_cmd)

    elif args.mode == "install":
        print("Starting install")
        run_command(install_cmd)

    elif args.mode == "develop":
        print("Starting development build")
        run_command(develop_cmd)
        print("Finished development build")

    elif args.mode == "clean":
        print("Starting cleanup")
        subprocess.run(shlex.split("python -m pip uninstall vonMises -y"), check=True)
        subprocess.run(shlex.split("git clean -xdff"), cwd="src", check=True)

        for entry in Path("").iterdir():
            if entry.name in [
                "_skbuild",
                "dist",
                "build",
                ".pytest_cache",
            ] or entry.name.endswith("egg-info"):
                print(f"Removing '{entry}'")
                shutil.rmtree(entry)
            if entry.suffix == ".log":
                print(f"Removing '{entry}'")
                entry.unlink()
        print("Finished cleanup")


if __name__ == "__main__":
    main()
