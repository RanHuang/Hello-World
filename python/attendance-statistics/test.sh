#!/usr/bin/env bash
set -eo pipefail

cd $(dirname ${BASH_SOURCE[0]})

PYTHON_HOME=venv
export PATH="$PYTHON_HOME/bin:$PATH"
export PYTHONPATH="${PYTHONPATH}:."

which python3

python3 label_weekend.py
python3 pretreat.py

python3 calc_over_time.py

python3 color_preprocess.py

python3 summary.py

python3 beLateAndLeaveEarly.py

python3 merge.py