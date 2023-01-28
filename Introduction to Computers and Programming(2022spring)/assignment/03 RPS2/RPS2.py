#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
# Author:      세정
# Created:     16-03-2022
# Copyright:   (c) 세정 2022
# Licence:     <your licence>
#-------------------------------------------------------------------------------

RPS2 = input()
LA = RPS2.split()

SA = set(LA)


if len(SA) == 1 or len(SA) == 3 :
   print("D")


if SA == {"R", "P"} :
    print("P")

if SA == {"R", "S"} :
    print("R")

if SA == {"S", "P"} :
    print("S")


