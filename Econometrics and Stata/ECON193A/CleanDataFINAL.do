clear all
set more off

*This Do file will take raw, downloaded ipums data and generate the Analysis sample

*Load Data
cd "D:\ECON193A"
use "idhs_final.dta"

*CHILD Covariates - hwhazwho kidcurage kidcuragemo i.delpl ethnicitysn
gen kidcurage = .
	replace kidcurage = 0 if kidcuragemo <12
	replace kidcurage = 1 if kidcuragemo <24 & kidcuragemo > 12
	replace kidcurage = 2 if kidcuragemo <36 & kidcuragemo >24
	replace kidcurage = 3 if kidcuragemo <48 & kidcuragemo >36
	replace kidcurage = 4 if kidcuragemo <60 & kidcuragemo >48 

*Dropping Impossible/Wrong values
drop if hwhazwho>600
*drop if hwwhzwho>600

*MATERNAL Covariates: age educlvlsn 

*HOUSEHOLD Covariates: wealthq treatwtryn wall floor roof toiletplace urban bhcpermit bhcmoney bhcdistance bhcalone
drop if toiletplace==99

*TECHNICAL : psu perweight



*Describe Endowment vars and Investment vars

*local EndowmentVars = "age delpl educlvlsn"

*local InvestVars = "wealthq treatwtryn drinkwtr toiletplace"

* Define groups of interest WOLOF / FRENCH

gen high_caste=0
	replace high_caste=1 if ethnicitysn==1

gen low_caste=0
	replace low_caste=1 if ethnicitysn==5
	


save "\ECON193A\NEW_idhs_final.dta", replace