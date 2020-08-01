#!/bin/bash
#sh generate_new_flex_table.sh
phpize
CFLAGS="-O3" ./configure
make
