********************
*Eugene Baldonado
*Lab Assignment 3
*S22_ECON108_32
********************
clear all 
set more off

cd "C:/Econ108/Lab3"
cap log close
log using Lab3_1_32, replace

*Data Transformation

/*

*Import excel
import excel "UnemploymentRate_76_13.xlsx", sheet("Sheet1") firstrow clear

*Reshape
reshape long uerate, i(fips) j(year)
save uerate, replace

import excel "ViolentCrime_76_13.xlsx", sheet("Sheet1") firstrow clear

reshape long violentrate, i(fips) j(year)
save violentrate, replace

*Merge
merge 1:1 fips year using uerate.dta
*Good practice to drop this variable
drop _merge

save lab3_data, replace

log close

*/


use lab3_data, clear
*A
twoway (scatter violentrate uerate)(lfit violentrate uerate)
graph export scatter.png, replace

twoway (scatter violentrate uerate)(lfit violentrate uerate) (scatter violentrate uerate if fips==6, mcolor(yellow))(lfit violentrate uerate if fips==6, lcolor(yellow))(scatter violentrate uerate if fips==11, mcolor(red))(lfit violentrate uerate if fips==11, lcolor(red))

*B
reg violentrate uerate, robust
outreg2 using lab3_1_32, excel replace

*D
preserve

collapse (mean)violentrate (mean)uerate, by(fips)

reg violentrate uerate, robust
outreg2 using lab3_1_32, excel replace

twoway (scatter violentrate uerate)(lfit violentrate uerate)
graph export scatter2.png, replace

restore

log close

