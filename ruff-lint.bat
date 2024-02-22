@echo off
ruff --version
ruff --fix .
ruff format .
ruff format --check .
