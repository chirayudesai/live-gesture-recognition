#!/usr/bin/env bash

make || exit "Build failed."
cd bin
./initialize || exit "Failed to initialize."
./gesture
