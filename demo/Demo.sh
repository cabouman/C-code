#!/bin/bash

../bin/RWExample img03.tif
mv green.tif output
mv color.tif output

../bin/BtildeExample > output/data.txt

# Run this matlab script to plot the data
# matlab PlotData.m

