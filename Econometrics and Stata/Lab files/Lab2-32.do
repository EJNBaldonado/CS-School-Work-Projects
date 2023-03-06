* Eugene Baldonado
* SID: 862070316
* Lab 2 ECON108
clear all
set more off

cd "C:/ECON108/Lab2"

use "speeding_tickets_text", clear

cap log close
log using s22_lab2_32, replace

*Create Age^2 term
gen Age2 = Age^2

*Displaying two scatter plots
*twoway (scatter Amount Age)(lfit Amount Age)
*twoway (scatter Amount Age2)(lfit Amount Age2)

*Regressions with Age, and Age^2 with controls
reg Amount Age MPHover Female Black Hispanic, robust
outreg2 using s22_lab2_32, word replace

reg Amount Age Age2 MPHover Female Black Hispanic, robust
outreg2 using s22_lab2_32, word

local forAge = "(Not controlling for age^2) Given the person's age is: "
local forAge2 = "(Controlling for age^2) Given the person's age is: "
local output = "The expected value for the fine is: "

*Calculate expected fine for both regressions for individuals aged 20,30,40,50
*Given a white male is going 0 MPH over the speed limit
foreach x in 20 30 40 50 60{
    display "`forAge'"
	display `x'
	display "`output'"
	display 4.845118 + `x' * .0268202
	display "`forAge2'" 
	display `x'
	display "`output'"
	display 9.867176 + `x' * -0.264765
}

*Regress for out of towners / out of staters, see if there are differences in treatment
gen Town_State = OutTown * OutState
*Since it's impossible to be out of state and not be out of town, we can relay this interaction purely on OutTown and the interaction term
*Without controls
reg Amount Age Age2 OutTown Town_State, robust
outreg2 using s22_lab2_32, word

*With controls
reg Amount Age Age2 MPHover Female Black Hispanic OutTown Town_State, robust
outreg2 using s22_lab2_32, word



log close 