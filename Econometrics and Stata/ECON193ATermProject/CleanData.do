clear all
set more off

*This Do file will take raw, downloaded ipums data and generate the Analysis sample

*Load Data
cd "D:\ECON193ATermProject"
use "idhs_final.dta"

*CHILD Covariates - hwhazwho kidcurage kidcuragemo i.delpl ethnicitysn
/*gen kidcurage = .
	replace kidcurage = 0 if kidcuragemo <12
	replace kidcurage = 1 if kidcuragemo <24 & kidcuragemo > 12
	replace kidcurage = 2 if kidcuragemo <36 & kidcuragemo >24
	replace kidcurage = 3 if kidcuragemo <48 & kidcuragemo >36
	replace kidcurage = 4 if kidcuragemo <60 & kidcuragemo >48
*/

*Dropping Impossible/Wrong values
drop if hwhazwho>600
*drop if hwwhzwho>600

*MATERNAL Covariates: age educlvl weightfem heightfem
drop if weightfem>9000
drop if heightfem>9000

*HOUSEHOLD Covariates: wealthq treatwtryn wall floor roof toilettype urban bhcpermit bhcmoney bhcdistance bhcalone
replace bhcalone=0 if bhcalone==10
replace bhcalone=1 if bhcalone==20
replace bhcpermit=0 if bhcpermit==10
replace bhcpermit=1 if bhcpermit==20
replace bhcdistance=0 if bhcdistance==10
replace bhcdistance=1 if bhcdistance==20
replace bhcmoney=0 if bhcmoney==10
replace bhcmoney=1 if bhcmoney==20
replace urban=0 if urban==2

*TECHNICAL : psu perweight



*Describe Endowment vars and Investment vars

*local EndowmentVars = "age delpl weightfem heightfem educlvl"

*local InvestVars = "wealthq treatwtryn drinkwtr toiletplace electrc"


* Define groups of interest WOLOF / JIOLA
gen low_caste=0
	replace low_caste=1 if ethnicitysn==5

keep if ethnicitysn==1 | ethnicitysn==5

//gen high_caste=0
//	replace high_caste=1 if ethnicitysn==1
	


save "NEW_idhs_final.dta", replace
