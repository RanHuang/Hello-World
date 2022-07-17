#!/usr/bin/env bash
set -e

cd `dirname ${BASH_SOURCE[0]}`

if [ ! -d venv ]; then
  echo "Start to create virtualenv environment"
  python3.7 -m venv venv
fi

echo "Start to install python dependency packages"
./venv/bin/pip3 install --upgrade pip
./venv/bin/pip3 install --upgrade setuptools
./venv/bin/pip3 install  -r requirements.txt

echo -e "\033[32m Install Python packages Done \033[0m"
