clear all
set more off

*This Do file will take raw, downloaded ipums data and generate ny:
	*Analysis sample

*Load Data
cd "C:\ECON193A"
use "idhs_final.dta"


* COVARIATES 
* endowment var: -maternal health -delivery care
* investment var: -sanitation -HH wealth -clinic visits
* local EndowmentVars "Var1 var2 .." 
* local InestVars "Var1 Var2"
* Gen age of kid in years

*CHILD Covariates - hwhazwho kidcurage kidcuragemo i.delpl ethnicitysn
gen kidcurage = .
	replace kidcurage = 0 if kidcuragemo <12
	replace kidcurage = 1 if kidcuragemo <24 & kidcuragemo > 12
	replace kidcurage = 2 if kidcuragemo <36 & kidcuragemo >24
	replace kidcurage = 3 if kidcuragemo <48 & kidcuragemo >36
	replace kidcurage = 4 if kidcuragemo <60 & kidcuragemo >48 

*Dropping Impossible/Wrong values
drop if hwhazwho>600
drop if hwwhzwho>600
*Not in universe


*MATERNAL Covariates: age educlvlsn 

*HOUSEHOLD Covariates: wealthq treatwtryn wall floor roof toiletplace urban bhcpermit bhcmoney bhcdistance bhcalone
drop if toiletplace==99

*TECHNICAL : psu perweight
*Going through variable by variable and see what are flagged and clean data


*Describe Endowment vars and Investment vars
*local EndowmentVars = "age delpl educlvlsn"

*local InvestVars = "wealthq treatwtryn drinkwtr toiletplace"

* Define groups of interest WOLOF / FRENCH

* Dropping observations in NEITHER group of interest
	*Note : "|" means "or"
	* "&" means "and"
*keep if ethnic==11 | ethnic

*save "...new.dta", replace
*keep if ehtnicitysn==1 | ethnicitysn==2
tab ethnicitysn
tab ethnicitysn, nolabel
gen low_caste=0
	replace low_caste=1 if ethnicitysn==2

*twoway (line HAZwho age if low_caste==0) || (line HAZwho age if lowcaste==1)
*new do file
*use "...new.dta"
*collapse HAZwho, by age(low_caste)
*example
*twoway (line hwhazwho age5year if ethnicitysn==2) || twoway (line hwhazwho age5year ethnicitysn==4)

sum hwhazwho kidcuragemo ethnicitysn

save "\ECON193A\NEW_idhs_final.dta", replace