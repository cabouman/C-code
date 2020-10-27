#!/usr/bin/env bash

BIN="../bin"

$BIN/RWExample img03.tif
mv green.tif output
mv color.tif output

$BIN/BtildeExample > output/data.txt

# Run this matlab script to plot the data
# matlab PlotData.m

