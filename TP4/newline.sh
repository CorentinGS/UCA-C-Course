#
# Copyright (c) 2022.
#
# PROJECT                                ______   _______      _______.
# file.c                                /      | /  _____|    /       |
#                                      |  ,----'|  |  __     |   (----`
# By: CorentinGS                       |  |     |  | |_ |     \   \
# <c.giaufersaubert@outlook.com>       |  `----.|  |__| | .----)   |
#                                       \______| \______| |_______/
# Created: 2022/11/05 by CorentinGS
# LICENCE: BSD 3-Clause License
#

# Add a newline at the end of every file in the current directory and its subdirectories (recursively) that do not already have one.
# file must be a .c or .h file

find . -type f -name "*.c" -exec sed -i -e '$a\' {} \; -exec echo "Added newline to {}" \; -o -name "*.h" -exec sed -i -e '$a\' {} \; -exec echo "Added newline to {}" \;