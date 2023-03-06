*Eugene Baldonado
*SID:862070316
*NetID: Ebald009 
*ECON108 Lab Assignment #1

clear all
set more off

cd "C:\ECON108\Lab1"
use "vote1.dta"

cap log close
log using labassignment1-2, replace

reg voteA expendA, robust
outreg2 using labassignment1-2, excel replace

reg voteA expendA shareA, robust
outreg2 using labassignment1-2, excel 

reg voteA expendA shareA prtystrA, robust
outreg2 using labassignment1-2, excel

reg voteA expendA shareA prtystrA expendB, robust
outreg2 using labassignment1-2, excel

reg voteA expendA shareA prtystrA expendB lexpendA, robust
outreg2 using labassignment1-2, excel

*Most comprehensive regression would primarily contain shareA and prtystrA, delta most likely being positive (higher shareA would cause a larger % vote for president)

log close