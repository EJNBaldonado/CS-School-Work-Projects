clear all 
set more off 

cd "C:\ECON193A"
use "NEW_idhs_final"

*** This Do File will create unconditional regression estimates by age
	* That is, report mean group-differences for each age group-differences


gen kidcurage = .
	replace kidcurage = 0 if kidcuragemo <12
	replace kidcurage = 1 if kidcuragemo <24 & kidcuragemo > 12
	replace kidcurage = 2 if kidcuragemo <36 & kidcuragemo >24
	replace kidcurage = 3 if kidcuragemo <48 & kidcuragemo >36
	replace kidcurage = 4 if kidcuragemo <60 & kidcuragemo >48 
*Generate Age Groups (compute means this way, if you want)
preserve
collapse hwhazwho, by(kidcurage low_caste)
twoway (scatter hwhazwho kidcurage if low_caste==0, c(l)) || (line hwhazwho kidcurage if low_caste==1, c(1)), ///
	legend(order(1 "High Caste" 2 "Low Caste"))
restore


*Run Regressions and Save Coefficients (better way to get mean differences)

regress kidcuragemo low_caste 

*the additional effect of being in the lowcaste group .5 is delta (coef is the highcaste haz, cons lowcaste group)
	

//regress kidcuragemo low_caste = kidcurage==0

//regress kidcuragemo low_caste = kidcurage==3

*for age 0
/*
gen age1 = 0
	replace age1=1 if age_yrs
	*/
*Alt way of writing the above for 0/1 variables in Stata

gen Nage1 = (kidcurage==1)
gen age0 = (kidcurage==0)
gen age1 = (kidcurage==1)
gen age2 = (kidcurage==2)
gen age3 = (kidcurage==3)
gen age4 = (kidcurage==4)
*Generate covariate for interactions for group differences at each age
gen Tage0 = age0*low_caste
gen Tage1 = age1*low_caste
gen Tage2 = age2*low_caste
gen Tage3 = age3*low_caste
gen Tage4 = age4*low_caste

reg hwhazwho age0 age1 age2 age3 age4 Tage0 Tage1 Tage2 Tage3 Tage4


* BETTER WAY
regress hwhazwho i.kidcurage

*Splits coefficient for each of the different years, and make a series of dummy variables to show summations

* MAKE SURE TO USE cluster(psu)
* gen cover = 1, replace cover = 0 if 
	
*Graph Regressions

*Output Tables