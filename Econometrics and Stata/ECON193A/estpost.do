clear all
set more off

*This do file will generate summary statistics for my estimation sample

*Load cleaned data (saved from previous do file)
cd "C:\ECON193A"
use "NEW_idhs_final.dta"

*Summarize all variables for missing values
sum ethnicitysn hwhazwho kidcuragemo delpl vacev cheb wealths educlvl religion


*MAKE SURE TO Add kidcurage months 

*Drop missing values if there are empty values/not 
drop if hwhazwho == .
drop if ethnicitysn == .
drop if age5year == .
*tab delpl
*tab vacev
*tab cheb
*tab wealths
*tab educlvl
*tab religion


*help estout
*findit estout
*install estout

*Make summary statistics variables by group

*this is how you make a variable!

local Covariates "hwhazwho ethnicitysn kidcuragemo delpl vacev cheb wealths educlvl religion"

di "`Covariates'"

sum `Covariates'

*Post summary stats by group
estpost tabstat `Covariates', by (low_caste) ///
		statistics (mean sd) columns(statistics) listwise nototal
		
		*can do esttab using name.csv to save the data into a .csv file
		* You can export that last table using "esttab" after the "estpost"
		esttab , cells("mean(fmt(a2))") nostar unstack label ///
		nonote number title("Sample Summary Statistics by Group")


collapse hwhazwho, by(kidcuragemo low_caste)
*Replace age5year with kidcurage
twoway (line hwhazwho kidcuragemo if low_caste==0) || (line hwhazwho kidcuragemo if low_caste==1), ///
	title("HAZ by Age and Caste group") legend(order(1 "Upper Caste" 2 "Low Caste")) ///
	xtitle("age") ytitle("HAZ") ///
	graphregion( color(white) ) plotregion( color(white) )
