#!/bin/bash
# my library
. ./mylib

food="HotDogs"
drink="Coca Cola"
go=`drink`
stop=`adds $drink $food`
echo "$food and $drink are yummy!"
echo "$go"
echo "$stop"
vargo=`numbers 15`
vargo1=`numbers 215`
vargo2=`numbers 2315`
vargo3=$(($vargo + $vargo2))

echo $vargo
echo $vargo1
echo $vargo2
echo $vargo3