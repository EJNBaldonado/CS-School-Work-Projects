clear all
set more off
/*
local files: dir "D:\Econ108FinalData" files "*.xls"

foreach file in `files' {
	clear
	import excel `file', firstrow
	save `file', replace
}
*/

cd "D:\Econ108FinalData" 
use Edu_AttainmentFinal

//save Edu_AttainmentFinal.dta, replace

local files 2006.xls.dta 2007.xls.dta 2008.xls.dta 2009.xls.dta 2010.xls.dta
//local varlist Year State Population Edu_Attainment ViolentCrime ViolentCrimeRatePer100k
//local updatelist Population Edu_Attainment ViolentCrime ViolentCrimeRatePer100k

foreach file in `files'{
	merge 1:1 Year State using `file', nogen update
}

//append using `files'

* HAVE TO RUN EACH MERGE SEPARATELY

merge 1:1 Year State using "2006.xls.dta", nogen update
merge 1:1 Year State using "2007.xls.dta", nogen update
merge 1:1 Year State using "2008.xls.dta", nogen update
merge 1:1 Year State using "2009.xls.dta", nogen update
merge 1:1 Year State using "2010.xls.dta", nogen update
merge 1:1 Year State using "2011.xls.dta", nogen update
merge 1:1 Year State using "2012.xls.dta", nogen update
merge 1:1 Year State using "2013.xls.dta", nogen update
merge 1:1 Year State using "2014.xls.dta", nogen update
merge 1:1 Year State using "2015.xls.dta", nogen update
merge 1:1 Year State using "2016.xls.dta", nogen update
merge 1:1 Year State using "2017.xls.dta", nogen update
merge 1:1 Year State using "2018.xls.dta", nogen update
merge 1:1 Year State using "2019.xls.dta", nogen update

drop if Population==.

save EduAtt_ViolentCrime, replace
