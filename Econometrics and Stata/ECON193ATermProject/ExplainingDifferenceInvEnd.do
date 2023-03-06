clear all
set more off

cd "D:\Econ193ATermProject"

import excel "EndInvDiffExplanationPerAge", firstrow

twoway (line Explained Year), ///
	title("Difference explained for each Year") ///
	xtitle("Age in Years") ytitle("Explained Difference") ///
	graphregion( color(white) ) plotregion( fcolor(white) ) ///
	yline(0)
graph export EndInvDiffExplanationPerAgeGraph.png, replace

twoway (line difference Year), ///
	title("Difference between Groups for each Year") ///
	xtitle("Age in Years") ytitle("HAZ Difference") ///
	graphregion( color(white) ) plotregion( fcolor(white) ) ///
	yline(0)
graph export DiffPerAgeGraph.png, replace

twoway (line expByEndowments Year), ///
	title("Difference explained by Endowments for each Year") ///
	xtitle("Age in Years") ytitle("Explained by Endowment") ///
	graphregion( color(white) ) plotregion( fcolor(white) ) ///
	yline(0)
graph export EndDiffExplanationPerAgeGraph.png, replace

twoway (line expByInvestments Year), ///
	title("Difference explained by Investments for each Year") ///
	xtitle("Age in Years") ytitle("Explained by Investment") ///
	graphregion( color(white) ) plotregion( fcolor(white) ) ///
	yline(0)
graph export InvDiffExplanationPerAgeGraph.png, replace

twoway (line Explained difference expByEndowments expByInvestments Year), ///
	title("Final Results") ///
	xtitle("Age in Years") ytitle("HAZ Difference") ///
	graphregion( color(white) ) plotregion( fcolor(white) ) ///
	legend(order(1 "Total Explained" 2 "HAZ Difference" 3 "Explained by Endowments" 4 "Explained by Investments")) ///
	yline(0)
	
graph export results.png, replace