clear all
set more off

cd "D:\Econ108FinalData"
use EduAtt_ViolentCrime

cap log close

log using Econ108Project, replace
preserve
encode State, gen(StateNum)
 
reg ViolentCrimeRatePer100k Edu_Attainment, robust
outreg2 using FinalRegTable, word replace

reg ViolentCrimeRatePer100k Edu_Attainment i.StateNum, robust
outreg2 using FinalRegTable, word keep(Edu_Attainment) addtext(State FE, Y, Year FE, N) cttop(DV)

reg ViolentCrimeRatePer100k Edu_Attainment i.StateNum i.Year, robust
outreg2 using FinalRegTable, word keep(Edu_Attainment) addtext(State FE, Y, Year FE, Y) cttop(DV)

twoway (scatter ViolentCrimeRatePer100k Edu_Attainment, mcolor(gray) msize (small)) (lfit ViolentCrimeRatePer100k Edu_Attainment, lcolor(red))

graph export ViolentCrimeEdu_AttGraph.pdf, replace

restore


log close