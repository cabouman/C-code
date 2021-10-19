#!/bin/bash

# Run demo that shows how to read and write color and gray scale images
echo "Running demo of reading, writting, and processing of tif images"
../bin/ImageReadWriteExample img03.tif
mv green.tif output
mv color.tif output
echo ""

# Run demo that shows how use solve function to root equation
echo "Running demo of solve function"
../bin/SolveExample
echo ""

# Run demo that shows how use surrogate functions with qGGMRF prior
echo "Running demo of surrogate functions with qGGMRF prior"
../bin/SurrogateFunctionExample > output/data.txt
echo ""

# Run this matlab script to plot the data
# matlab PlotData.m

