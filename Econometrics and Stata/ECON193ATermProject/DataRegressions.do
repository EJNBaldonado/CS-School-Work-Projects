clear all
set more off

*This do file will generate summary statistics for my estimation sample

cd "D:\ECON193ATermProject"
use "NEW_idhs_final.dta"

*List of Covariate to Summarize
local Covariates "hwhazwho kidcurage urban educlvl age wealthq weightfem heightfem electrc bhcpermit bhcmoney bhcdistance bhcalone"
//
sum `Covariates'

*Post summary stats by group
estpost tabstat `Covariates', by(low_caste) ///
	statistics(mean sd) columns(statistics) listwise nototal
	
	*You can export that last table using "esttab" after the "estpost"
	esttab , cells("mean(fmt(a2))") nostar unstack label ///
	nonote nonumber title("Sample Summary Statistics by Group")
	
	esttab using DraftSumStats.csv, cells("mean(fmt(a2))") nostar unstack label ///
	nonote nonumber title("Sample Summary Statistics by Group") replace
	
*Generate indicator/dummy (0/1) variables for EACH category of EACH categorical variables

levelsof delpl, l(delpllvl)
foreach x in `delpllvl'{
    gen delpl_`x' = delpl==`x'
}

levelsof educlvl, l(snedulvl)
foreach x in `snedulvl'{
	gen educlvl_`x' = educlvl==`x'
}	

levelsof wealthq, l(wealthqlvl)
foreach x in `wealthqlvl'{
	gen wealthq_`x' = wealthq==`x'
}	

levelsof drinkwtr, l(wtrlvl)
foreach x in `wtrlvl'{
    gen drinkwtr_`x' = drinkwtr==`x'
}

levelsof toilettype, l(toiletlvl)
foreach x in `toiletlvl'{
    gen ttype_`x' = toilettype==`x'
}


levelsof wall, l(walllvl)
foreach x in `walllvl'{
    gen wall_`x' = wall==`x'
}

levelsof floor, l(floorlvl)
foreach x in `floorlvl'{
    gen floor_`x' = floor==`x'
}

levelsof roof, l(rooflvl)
foreach x in `rooflvl'{
    gen roof_`x' = roof==`x'
}

levelsof bhcmoney, l(bhcmoneylvl)
foreach x in `bhcmoneylvl'{
    gen bhcmoney_`x' = bhcmoney==`x'
}

levelsof bhcdistance, l(bhcdistancelvl)
foreach x in `bhcdistancelvl'{
    gen bhcdistance_`x' = bhcdistance==`x'
}

levelsof bhcalone, l(bhcalonelvl)
foreach x in `bhcalonelvl'{
    gen bhcalone_`x' = bhcalone==`x'
}
	
*List Endowment and Investment related variables, using variable names from above (if categorical, regular var names for continuous variables)
local Endowments "age weightfem heightfem delpl_1100 delpl_1900 delpl_2100 delpl_2200 delpl_2410 delpl_2900 delpl_3100 delpl_3900 delpl_9995"

local Investments "wealthq_1 wealthq_2 wealthq_3 wealthq_4 wealthq_5 electrc educlvl_0 educlvl_1 educlvl_2 educlvl_3 bhcalone_0 bhcalone_1 treatwtryn"
	
/* wealthq_1 wealthq_2 wealthq_3 wealthq_4 wealthq_5 drinkwtr_1110 drinkwtr_1120 drinkwtr_1210 drinkwtr_2100 drinkwtr_2200 drinkwtr_2230 drinkwtr_3120 drinkwtr_5200 drinkwtr_5400 drinkwtr_6000 toilettype_0 toilettype_1210 toilettype_1250 toilettype_3200 toilettype_3300 toilettype_3400 toilettype_3450 wall_0 wall_110 wall_125 wall_210 wall_220 wall_232 wall_251 wall_260 wall_310 wall_320 wall_330 wall_340 wall_351 wall_360 wall_400 floor_111 floor_121 floor_220 floor_310 floor_320 floor_331 floor_340 floor_350 roof_0 roof_110 roof_230 roof_240 roof_310 roof_320 roof_331 roof_341 roof_351
*/

bysort low_caste: sum `Endowments' `Investments' psu

forvalues a = 0/4 {
    *Run Decomposition
	oaxaca hwhazwho `Endowments' `Investments' if kidcurage==`a' [pweight = perweight], by(low_caste) vce(cluster psu) weight(0) noisily ///
	detail(Endowment_Vars:`Endowments', Invest_Vars: `Investments') relax categorical(educlvl_0 educlvl_1 educlvl_2 educlvl_3, wealthq_1 wealthq_2 wealthq_3 wealthq_4 wealthq_5, delpl_1100 delpl_1900 delpl_2100 delpl_2200 delpl_2410 delpl_2900 delpl_3100 delpl_3900 delpl_9995, bhcalone_0 bhcalone_1)
}
/*
NOTE: I was getting omitted values/ out of range errors when including too many variables? I couldn't figure out a solution to this so I only included the following in categorical variables
, drinkwtr_1110 drinkwtr_1120 drinkwtr_1210 drinkwtr_2100 drinkwtr_2200 drinkwtr_2230 drinkwtr_3120 drinkwtr_5200 drinkwtr_5400 drinkwtr_6000, toilettype_0 toilettype_1210 toilettype_1250 toilettype_3200 toilettype_3300 toilettype_3400 toilettype_3450, wall_0 wall_110 wall_125 wall_210 wall_220 wall_232 wall_251 wall_260 wall_310 wall_320 wall_330 wall_340 wall_351 wall_360 wall_400, floor_111 floor_121 floor_220 floor_310 floor_320 floor_331 floor_340 floor_350, roof_0 roof_110 roof_230 roof_240 roof_310 roof_320 roof_331 roof_341 roof_351
*/

****Then input your age-specific results into Excel, to save them there, and then export back to Stata for graphing
	*You want to save "explained part"; "explained part by Endowments"; "explained part by Investments" and "difference", which is the group level differences
	*Your Excel sheet should have 
		*Rows that are ages in years (so 5 rows, one for each age)
		*columns for each piece of information you need for each age (the explained parts and difference mentioned above).

	