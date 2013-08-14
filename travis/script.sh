#!/bin/sh
set -e

xctool -workspace ReactiveJackson -scheme ReactiveJackson build test
