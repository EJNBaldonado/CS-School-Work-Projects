*===========*
* Econ108(32)
* Eugene Baldonado
* Lab Assignment 4
*===========*

cd "C:\econ108\Lab4"
cap log close

log using econ108_32_lab4, t replace
use "lab3_data", replace


*A OLS
reg violentrate uerate, robust
outreg2 using econ108_32_lab4, excel replace cttop (OLS)

*B  Dummy Variable Fixed Effects
reg violentrate uerate i.fips, robust
outreg2 using econ108_32_lab4, excel keep(uerate) addtext(State FE, Y, Year FE, N) cttop(DV)

reg violentrate uerate i.year, robust
outreg2 using econ108_32_lab4, excel keep(uerate) addtext(State FE, N, Year FE, Y) cttop(DV)

reg violentrate uerate i.fips i.year, robust
outreg2 using econ108_32_lab4, excel keep(uerate) addtext(State FE, Y, Year FE, Y) cttop(DV)

*C xi
xi : reg violentrate uerate i.fips i.year, robust
outreg2 using econ108_32_lab4, excel keep(uerate) addtext(State FE, N, Year FE, Y) cttop(xi)

*D areg
areg violentrate uerate, absorb(fips) robust
outreg2 using econ108_32_lab4, excel keep(uerate) addtext(State FE, Y, Year FE, N) cttop(areg)

areg violentrate uerate i.year, absorb(fips) robust
outreg2 using econ108_32_lab4, excel keep(uerate) addtext(State FE, Y, Year FE, Y) cttop(areg)

*E-F .xtreg
xtset fips year

xtreg violentrate uerate, fe robust
outreg2 using econ108_32_lab4, excel keep(uerate) addtext(State FE, Y, Year FE, N) cttop(xtreg)

xtreg violentrate uerate i.year, fe robust
outreg2 using econ108_32_lab4, excel keep(uerate) addtext(State FE, Y, Year FE, Y) cttop(xtreg)

log close

