clear all 
set more off

cd "C:\ECON193A"
use "NEW_idhs_final"


*Generate blank variable for unconditional group differeces from regressions

gen GroupDiffUC = .
gen GroupDiffCond = .

*Generate blank variables for Standard Errors
gen UCse = .
gen Condse = .

*Set up variable list
*Probably still need to clean up covariates
local Covariates  "vacev educlvlsn ndrinkwtr electrchh"
*Note put "i." in front of categorical variables

*Collapse down into proper format
forvalues a=0/4{
*Run Unconditional Regressions (mean group differences)	
	reg hwhazwho low_caste if kidcurage==`a'
	replace GroupDiffUC = _b[low_caste] if kidcurage==`a'
replace UCse = _se[low_caste] if kidcurage==`a'
*Run Conditional Regresssions (adjusted group differences)
	reg hwhazwho low_caste `Covariates' if kidcurage==`a'
	replace GroupDiffCond = _b[low_caste] if kidcurage==`a'
replace Condse = _se[low_caste] if kidcurage==`a'
}

collapse GroupDiffUC GroupDiffCond UCse Condse, by(kidcurage)

	*Generate upper/lower bounds of Confidence Intervals
	gen LBUC = GroupDiffUC - 1.96 * UCse
	gen UPUC = GroupDiffUC + 1.96 * UCse
	
	gen LBC = GroupDiffCond - 1.96 * Condse
	gen UBC = GroupDiffCond + 1.96 * Condse

*Graph them
twoway (scatter GroupDiffUC kidcurage, c(l)) || ///
		(scatter GroupDiffCond kidcurage, c(l)) /// 
		(rcap LBUC UPUC kidcurage, lc(red)) || (rcap LBC UBC kidcurage, lc(blue)), ///
title("Regression Coefs") ///
	xtitle("age") ytitle("Group Difference") ///
	graphregion( color(white) ) plotregion( fcolor(white) ) ///
	yline(0) ///
	legend(order(1 "Unconditional" 2 "Conditional"))

* reg Y2 T i.epsgroup newX [pweight = perweight]
* collapse HAZ [pweight = perweight] by(T)
	




