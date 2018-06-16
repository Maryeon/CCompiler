#!bin/bash
SHELL_FOLDER=$(cd "$(dirname "$0")";pwd)
dot -Tjpg $SHELL_FOLDER/tree.dot -o $SHELL_FOLDER/tree.jpg
