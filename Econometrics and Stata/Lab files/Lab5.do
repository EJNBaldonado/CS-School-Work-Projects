clear all
set more off
cd "C:\Econ108\Lab5"

cap log close
log using econ108_lab5_32, t replace

use prekTulsa, replace

*B
bys cutoff: sum female white black hispanic freelunch

reg female cutoff age, robust
outreg2 using econ108_lab5_32, excel replace

foreach var of varlist white black hispanic freelunch {
    reg `var' cutoff age, robust
	outreg2 using econ108_lab5_32, excel
}

*C simple RD
reg wjtest01 cutoff age, robust
outreg2 using econ108_lab5_32, excel

*D RD with different slopes
gen cutoff_age = cutoff * age

reg wjtest01 cutoff age cutoff_age, robust
outreg2 using	econ108_lab5_32, excel


*E
local control = "female white black hispanic freelunch"

reg wjtest01 cutoff age cutoff_age `control', robust
outreg2 using	econ108_lab5_32, excel

*F
twoway (scatter wjtest01 age if cutoff==0, mcolor(black) msize(small)) ///
	   (lfit wjtest01 age if cutoff==0, lcolor(blue)) ///
	   (scatter wjtest01 age if cutoff==1,mcolor(black) msize(small)) ///
	   (lfit wjtest01 age if cutoff==1, lcolor(red)), ///
	   xline(0, lc(gray) lpattern(-)) ///
	   legend(order(1 "CG(scatter)" 2 "CG" 3 "TG(scatter)" 4 "TG"))
	   
graph export scatter_prek.png, replace

log close