clear all
set more off
cd "C:\ECON108\Midterm"

use "teachingevals.dta"

cap log close

log using midterm, replace

*A
reg A19 female othergender COURSEENROLLMENT response, robust
outreg2 using midterm, word replace

sum A19 if female==1
sum A19 if othergender==1
sum A19 if female==0

*B
reg A19 female othergender COURSEENROLLMENT response white, robust
outreg2 using midterm, word

*C
reg A19 female othergender COURSEENROLLMENT response white business education engineering socialsciences hardsciences publicpolicy, robust
outreg2 using midterm, word

*D
reg A19 female othergender COURSEENROLLMENT response white business education engineering socialsciences hardsciences publicpolicy i.term, robust
outreg2 using midterm, word

log close
