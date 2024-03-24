@echo off
ruff --version
ruff --fix .
ruff format .
ruff format --check .
ruff check --output-format=github .
