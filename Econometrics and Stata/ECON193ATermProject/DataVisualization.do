clear all
set more off

cd "D:\ECON193ATermProject"
use "NEW_idhs_final.dta"


preserve
collapse hwhazwho [pweight = perweight], by(kidcurage low_caste)

twoway (line hwhazwho kidcurage if low_caste==1) || (line hwhazwho kidcurage if low_caste==0), ///
	title("HAZ by Age and Ethnic Group") legend(order(1 "Low Caste (Diola)" 2 "Upper Caste (Wolof)")) ///
	xtitle("Age") ytitle("HAZ") ///
	graphregion( color(white) ) plotregion( fcolor(white) )

graph export DemoHAZAgeProfiles.png, replace
restore

local Covariates "weightfem heightfem age i.educlvl i.wealthq i.delpl i.treatwtryn electrc i.bhcalone "

*Generate blank variable for unconditional group differences from regressions
gen GroupDiffUC = .
gen GroupDiffCond = .

*Gen blank variables for Standard Errors
gen UCse = .
gen Condse = .

*Run Unconditional regressions (mean group differences)
*Run CONDITIONAL regressions (adjusted group differences)

*NOTE: Added outreg2 using FinalRegTable, word keep(low_caste) to produce FinalRegTable
forvalues a=0/4 {
    reg hwhazwho low_caste [pweight = perweight] if kidcurage==`a'
	replace GroupDiffUC = _b[low_caste] if kidcurage==`a'
	replace UCse = _se[low_caste] if kidcurage==`a'
	
	reg hwhazwho low_caste `Covariates' [pweight = perweight] if kidcurage==`a'
	replace GroupDiffCond = _b[low_caste] if kidcurage==`a'
	replace Condse = _se[low_caste] if kidcurage==`a'
}

preserve
*Collapse down into proper format

collapse GroupDiffUC GroupDiffCond UCse Condse, by(kidcurage)
	*Generate Upper/Lower bounds of Confidence Intervals
	gen LBUC = GroupDiffUC - 1.96*UCse
	gen UBUC = GroupDiffUC + 1.96*UCse
	
	gen LBcon = GroupDiffCond - 1.96*Condse
	gen UBcon = GroupDiffCond + 1.96*Condse
	
*Graph them
twoway (scatter GroupDiffUC kidcurage, lc(red) mc(red) c(1)) || ///
		(scatter GroupDiffCond kidcurage, lc(blue) mc(blue) c(1)) || ///
		(rcap LBUC UBUC kidcurage, lc(red)) || (rcap LBcon UBcon kidcurage, lc(blue)), ///
	title("Unadjusted Regression Coefs") ///
	xtitle("Age") ytitle("Group Difference") ///
	graphregion( color(white) ) plotregion( fcolor(white) ) ///
	yline(0) ///
	legend(order(1 "Unconditional" 2 "Conditional"))

graph export UncondAndCondGroupDiff.png, replace	

restore 

