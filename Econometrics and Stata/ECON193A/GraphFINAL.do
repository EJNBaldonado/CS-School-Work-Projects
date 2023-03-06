clear all
set more off

cd "C:\Econ193A"
use "NEW_idhs_final"


preserve
collapse hwhazwho, by(kidcurage high_caste low_caste)

twoway (line hwhazwho kidcurage if high_caste==1) || (line hwhazwho kidcurage if low_caste==1), ///
	title("HAZ by Age and Caste Group") legend(order(1 "Upper Caste" 2 "Low Caste")) ///
	xtitle("age") ytitle("HAZ") ///
	graphregion( color(white) ) plotregion(  fcolor(white) )
restore

preserve
*Generate blank variable for unconditional group differences from regressions
gen GroupDiffUC = .
gen GroupDiffCond = .

*Gen blank variables for Standard Errors
gen UCse = .
gen Condse = .

forvalues a=0/4 {
    *Run Unconditional Regressions (mean group differences)
	reg hwhazwho lowcaste if 
}

